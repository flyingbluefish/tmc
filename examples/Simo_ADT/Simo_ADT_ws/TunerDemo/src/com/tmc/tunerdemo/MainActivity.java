package com.tmc.tunerdemo;

import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.text.InputType;
//import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;
import android.widget.TextView;
import android.widget.Toast;

//import  android.content.Context;


/*
public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
*/
//class SimoA4r implements Runnable
//{
//	static public String sResult;
//	private Context pare;
//	public SimoA4r(View p)
//	{
//		pare  = p.getContext();
//	}
//}


public class MainActivity extends Activity implements Runnable
{
 	static public String sResult;
	static public int bDone;
	static public String waitbarText;
	public PIDData mPIDData;
	public  boolean isTimerRunning;
	public Timer timer = new Timer();
	public  Button  button;
	private Button btnPlotNic;
	private double [] drawbuffer;
	public float R_Resistance,L_Inductance,Ts;
	//double [] debugbuf1 = new double [10];
	//double [] debugbuf2 = new double [10];
	
	//public  SimoA4r ru;
    /** Called when the activity is first created. */
	//Thread myThread;
	
	void getPIDresult()
	{
		int NumFreqs = pidgetNumFreqs();
		
	    int TypeCrl = pidgetTypeCrl();
	    int NumPlants = pidgetNumPlants();
	    double [] plants = new double[ (1+2*NumPlants)*NumFreqs];
	    pidgetGetPlants(plants);
	    int NumCrl = pidgetNumCrl();
	    double [] crl = new double[ 4 *  NumCrl ];
	    pidgetGetCrl(crl);
	    mPIDData = new PIDData(NumFreqs, NumPlants, NumCrl, TypeCrl, plants, crl);
	}
	
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
////        
        setContentView(R.layout.activity_main);


        final LinearLayout lm = (LinearLayout) findViewById(R.id.linearMain);

        // create the layout params that will be used to define how your
        // button will be displayed
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);


        // Create LinearLayout
        LinearLayout ly = new LinearLayout(this);
        ly.setOrientation(LinearLayout.VERTICAL);

        // Create LinearLayout
        LinearLayout ll = new LinearLayout(this);
        ll.setOrientation(LinearLayout.HORIZONTAL);

        // Create TextView
        final TextView labelR = new TextView(this);
        labelR.setText("Resistance [Ohm]:");
        ll.addView(labelR);

        final EditText parR = new EditText(this);
        parR.setText("1");
        parR.setInputType(InputType.TYPE_CLASS_NUMBER);
        parR.setHint("R_hint");
        final int idR = 2;
        parR.setId(idR);
        ll.addView(parR);
        ly.addView(ll);
/////
        LinearLayout llL = new LinearLayout(this);
        llL.setOrientation(LinearLayout.HORIZONTAL);

        // Create TextView
        final TextView labelL = new TextView(this);
        labelL.setText("Inductance [mH]:");
        llL.addView(labelL);

        final EditText parL = new EditText(this);
        parL.setText("1");
        parL.setInputType(InputType.TYPE_CLASS_NUMBER);
        parL.setHint("L_hint");
        final int idL = 2;
        parL.setId(idL);
        llL.addView(parL);
        ly.addView(llL);

        // Create Button
        final int j = 1;
   
/////        
       
		bDone = 0;
		waitbarText = "Please wait, calculating...";
        /* Create a Button and set its content.
         * the text is retrieved by calling a native
         * function.
         */
        button = new Button(this);
		button.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v)
			{
				
				//button.setText( stringFromJNI(1));
				//ru = new SimoA4r(v);
				//myThread = new Thread(ru);
				//myThread.start();
				
				String sL =  parR.getText().toString();
				String sR =  parR.getText().toString();
				
				R_Resistance =  Float.valueOf(sR);
				L_Inductance =  Float.valueOf(sL)*1e-3f;
				Ts = 5e-6f;
				 
				//sResult = stringFromJNI(1);
				//getPIDresult();
				//button.setText( Float.toString((float)mPIDData.numFreqs) );
				
				startTmcThread(v);
			}
		});
		//final float nn = 1;
        //button.setText( stringFromJNI(0) );
		
        // Give button an ID
		button.setId(j);
		button.setText("Run");
        // set the layoutParams on the button
		button.setLayoutParams(params);
    
        ly.addView(button);
 /////////
        btnPlotNic = new Button(this);
        btnPlotNic.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v)
			{
				launchPlotNic(v);
			}
		});
        btnPlotNic.setId(j+1);
        btnPlotNic.setText("Show Nichols");
        btnPlotNic.setLayoutParams(params);
        ly.addView(btnPlotNic);       
 //////////       
        
        
        lm.addView(ly);		
		
		//button.setText("run");
        //setContentView(button);
		isTimerRunning = false;

		
    }
	 public Handler mHandler = new Handler()
		{
			public void handleMessage(Message msg)
			{
				if (bDone ==1)
				{
					stopTimer();
					//waitbarText="Finished, see results in Download/Out.mat";
					waitbarText="Finished, press the button to close";
					button.setText(waitbarText);
				}
				 
				Toast.makeText(getApplicationContext(),waitbarText,Toast.LENGTH_SHORT).show();
			}
		};

	public void startTmcThread(View clickedButton)
	{
	  if (bDone==2)
	  {
	    final String s = waitbarText;
	    Toast.makeText(getApplicationContext(),s,Toast.LENGTH_SHORT).show();
		return;
	  }
	  else
	    if (bDone==1)	
		{
			    //final String s = "Finished, see results in Download/Out.mat";
			    final String s = "Finished";
				Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
				finish();
				return;
		}

			    final String s = "Starting..";
				Toast.makeText(getApplicationContext(),s,Toast.LENGTH_SHORT).show();

				startTimer();
		bDone = 2;
		int poolSize = 3;
		ExecutorService taskList =
		Executors.newFixedThreadPool(poolSize);
		
					taskList.execute(this);
		 
	}


	public void showprogress(String s)
	{
		waitbarText = s;
		// final String s = "Please wait";
		// Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();

	
	//	 </activity> 
    //    <activity android:name=".CrashHandler" android:process=":CrashHandler" android:stateNotNeeded="true" android:exported="false" android:configChanges="keyboard|keyboardHidden|orientation"> 
    //     </activity> 


	}
	public void stopme(String s)
	{
		// Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
		waitbarText = s;
		 new RuntimeException(s).printStackTrace();
		 startActivity(new Intent(this, CrashHandler.class));
	}

	protected  void startTimer() {
		isTimerRunning = true; 
		timer.scheduleAtFixedRate(new TimerTask() {
			public void run() {
				// elapsedTime += 3; //increase every 3 sec
				mHandler.obtainMessage(1).sendToTarget();
			}
		}, 0, 3000);
	};
	protected  void stopTimer()
	{
			timer.cancel();
			timer.purge();
	}



	@Override
	public void run()
	{
	
	//final String s = Thread.currentThread().getName();
	//Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
			
		 sResult = runTmcTuning(1,R_Resistance,L_Inductance,Ts); 
		 getPIDresult();
/*		
			// Here initialize mPIDData by tuner results and pass it to plot
			double [] Plants = new double[] {
					0.1000 ,   0.5623 ,   3.1623,   17.7828 , 100.0000,//w
					-0.99999999998333,  -0.99999999947295,  -0.99999998333333,  -0.99999947295381,  -0.99998333341667,
					-9.99999999950000,  -1.77827940722722,  -0.31622775020545,  -0.05623404360509,  -0.00999950000417,
					
					0.09998999099590,   0.09968445369314,   0.09089999545470,   0.02394929469525,   0.00089104125453,
					-0.00100089990996,  -0.00561129219232,  -0.02877672526965,  -0.04276636548879,  -0.00991039587871
			
			};
			double  [] Crl = new double [] { 1,10,100,44, 2,20,200,88}; 
			final int nPlants = 2;
			final int nCrl = 2;
			final int nFreqs = 5;
			mPIDData = new PIDData(nFreqs, nPlants, nCrl, PIDData.PIDH, Plants, Crl);
		*/
		 
			
			try {
			Thread.currentThread().sleep(10);
			} catch (Exception e )
			{
			}
			bDone  = 1;
			

	}
    public void launchPlotNic(View clickedButton) {
        
    	// Example data
    	Intent activityIntent = 
                new Intent(this, PlotNic.class);

    	if (bDone==1)
    	{
 
    	   	    	   	
       		
    	   	
    	   	
            activityIntent.putExtra("numFreqs", mPIDData.numFreqs);
            activityIntent.putExtra("numPlants", mPIDData.numPlants);
    	   	activityIntent.putExtra("Plants", mPIDData.Plants);
  
    	   	activityIntent.putExtra("nCrl", mPIDData.nCrl);
            activityIntent.putExtra("typeCrl", mPIDData.typeCrl);
    	   	activityIntent.putExtra("dimCrl", mPIDData.dimCrl);
            activityIntent.putExtra("Crl",mPIDData.Crl ); 	
    
             	
        	
    	}
    	else
    	{
    	final int numplots  =2;
    	drawbuffer = new double[(1024*2+3)*numplots + 2];
    	
    	// File format:
    	// unsigned short numplots;
    	// unsigned short plottype;
    	// struct Ctmc_plot_inp  tmc_plot_inp[numplots];

    	//struct Ctmc_plot_inp
    	//{
//    		struct Ctmc_plot_inp_hdr hdr;
//    		double x[];
//    		double y[];
    	//};
  //  	class Ctmc_plot_inp_hdr
  //  	{
  //  		int len;
  //  		int mask; // 0: y only , 1: x present
  //  		int plot_color;
  //  	};
    	
    	int offs = PlotNic.StartNicholsPlot(drawbuffer);
    	
    	double [] w  = new double[1024];
    	double [] re = new double[1024];
    	double [] im = new double[1024];
    	
    	double [] re2 = new double[1024];
    	double [] im2 = new double[1024];
    	
    	double [] re3 = new double[1024];
    	double [] im3 = new double[1024];
    	
    	int len = 1000;
    	for (int kk=0;kk<len; kk++)
    	{
    		w[kk] = kk * 2 * Math.PI;
    	}
    	CtrlHelper.ones(len, re, im); // 1
    	CtrlHelper.j(len, re2, im2); // j
    	CtrlHelper.mult(len, re2, im2,w); // s=j*w
    	CtrlHelper.ones(len, re3, im3); // 1
    	CtrlHelper.add(len, re2, im2,re3,10); //  j*w + 10
    	CtrlHelper.div(len, re, im,re2,im2);
    	CtrlHelper.mult(len, re, im,10); // 10/(s+10)
    	
   	
    	offs = PlotNic.AddNicholsPlot(drawbuffer, offs, Color.BLUE, len, re, im);
    	
    	if (numplots>1)
    	{
       	CtrlHelper.ones(len, re, im); // 1
    	CtrlHelper.j(len, re2, im2); // j
    	CtrlHelper.mult(len, re2, im2,w); // s=j*w
    	CtrlHelper.ones(len, re3, im3); // 1
    	CtrlHelper.add(len, re2, im2,re3,20); //  j*w + 20
    	CtrlHelper.div(len, re, im,re2,im2);
    	CtrlHelper.mult(len, re, im,10); // w/(s+w)
   	
    	PlotNic.AddNicholsPlot(drawbuffer, offs, Color.RED, len, re, im);
    	}
    	
    	
   /* 	
    	final int numplots = 2;
    	final int plottype = 1;
    	final int len1 = 10;
    	final int mask1 = 1;
    	final int plot_color1 = Color.BLUE;
    	final int plot_color2 = Color.RED;
    	
    	int ind = 0;
    	drawbuffer[ind++]=numplots;
    	drawbuffer[ind++]=plottype;
    	drawbuffer[ind++]=len1;
    	drawbuffer[ind++]=mask1;
    	drawbuffer[ind++]=plot_color1;
    	    	
    	for (int uu=0; uu<10; uu++)
    	{
    		drawbuffer[ind++]=(uu-5);
    	}
    	for (int uu=0; uu<10; uu++)
    	{
    		drawbuffer[ind++]=(uu-5)*(uu-5);
    	}
 ////////
    	drawbuffer[ind++]=len1;
    	drawbuffer[ind++]=mask1;
    	drawbuffer[ind++]=plot_color2;
    	    	
    	for (int uu=0; uu<10; uu++)
    	{
    		drawbuffer[ind++]=(uu-5);
    	}
    	for (int uu=0; uu<10; uu++)
    	{
    		drawbuffer[ind++]=-(uu-5)*(uu-5);
    	}
 ///   	
    	*/
        activityIntent.putExtra("karmanbuf", drawbuffer);
        activityIntent.putExtra("buflen",(int)1024 );

    	}
    	
        
                
        startActivity(activityIntent);
    }

    /* Native methods implemented by the library libTmcTunerDemo.so,
     *  which is compiled from m-code:
     */
    public native String  runTmcTuning(float M,float R,float L, float Ts);
    public native int pidgetNumFreqs();
    public native int pidgetTypeCrl();
    public native int pidgetNumPlants();
    public native int pidgetGetPlants(double [] a);
    public native int pidgetNumCrl();
    public native int pidgetGetCrl(double [] a);
    
   
    static {
        System.loadLibrary("TmcTunerDemo");
    }
}

