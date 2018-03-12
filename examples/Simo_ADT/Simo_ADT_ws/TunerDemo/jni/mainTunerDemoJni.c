/// File: mainTunerDemoJni.c
/// Implements native methods of class com.tmc.tunerdemo.MainActivity
// located at:
//  src/com/tmc/tunerdemo/MainActivity.java
//
//contained in libTmcTunerDemo.so library:
//    public native String  runTmcTuning(float M);
//    public native int pidgetNumFreqs();
//    public native int pidgetTypeCrl();
//    public native int pidgetNumPlants();
//    public native int pidgetGetPlants(double [] a);
//    public native int pidgetNumCrl();
//    public native int pidgetGetCrl(double [] a);


#include <string.h>
#include <jni.h>
#include <stdlib.h>
#include <stdio.h>




// root tmc function caller.
void main_designer(double *err,double R,double L,double Ts);


// Data structure for tmc root function in/out
struct CPIDData
{
	int numFreqs;
	int  numPlants;
	int nCrl;
	int  typeCrl;
	double *plants;
	double *crl ;
	int dimCrl;
	int dimPlants;

};
struct CPIDData g_PIDData;


void storePIDData(int _numFreqs, int  _numPlants,  int _nCrl, int  _typeCrl, double* rData, double* iData,
		double* Fw,	double* ki,double* kp,double* kd,double* polew)
{
	int kk,m;

	if (_nCrl > 10000)
		_nCrl=10000;


	g_PIDData.numFreqs=_numFreqs;
	g_PIDData.numPlants=_numPlants;
	g_PIDData.nCrl=_nCrl;
	g_PIDData.typeCrl=_typeCrl;
	g_PIDData.dimPlants = (1+_numPlants * 2) * _numFreqs;
	g_PIDData.plants = (double*)malloc(g_PIDData.dimPlants * sizeof(double) );
	g_PIDData.dimCrl = 4 ;// KD,KP,KI,w
	g_PIDData.crl = (double*)malloc(g_PIDData.dimCrl * _nCrl * sizeof(double));


	for ( kk=0 ; kk<  _numFreqs; kk++)
	{
		g_PIDData.plants[kk]= Fw[kk];
		for (m=0;m<_numPlants;m++)
		{
			g_PIDData.plants[_numFreqs+m*_numFreqs*2+ kk]= rData[kk];
			g_PIDData.plants[_numFreqs+m*_numFreqs*2+  _numFreqs +kk]= iData[kk];//HAZARD: same plants
		}
		for (m=0;  m<  _nCrl;m++)
		{
			g_PIDData.crl[m]= kd[m];
			g_PIDData.crl[m + _nCrl]= kp[m];
			g_PIDData.crl[m + _nCrl*2]= ki[m];
			g_PIDData.crl[m + _nCrl*3]= polew[m];
		}
	}
}

jint Java_com_tmc_tunerdemo_MainActivity_pidgetNumFreqs(
                JNIEnv *env,
                jobject callingObject)
{
	return g_PIDData.numFreqs;
}
jint Java_com_tmc_tunerdemo_MainActivity_pidgetTypeCrl(
                JNIEnv *env,
                jobject callingObject)
{
	return g_PIDData.typeCrl;
}
jint Java_com_tmc_tunerdemo_MainActivity_pidgetNumPlants(
                JNIEnv *env,
                jobject callingObject)
{
	return g_PIDData.numPlants;
}

jint Java_com_tmc_tunerdemo_MainActivity_pidgetGetPlants(
                JNIEnv *env,
                jobject callingObject,
                jdoubleArray a)
{
	int kk;
/*
 * The last argument to the ReleaseByteArrayElements function above can have the following values:
 *  �0: Updates to the array from within the C code are reflected in the Java language copy.
    �JNI_COMMIT: The Java language copy is updated, but the local jbyteArray is not freed.
    �JNI_ABORT: Changes are not copied back, but the jbyteArray is freed.
     The value is used only if the array is obtained with a get mode of JNI_TRUE meaning the array is a copy.
 *
 */
	jdouble *element=(*env)->GetDoubleArrayElements(env,a, 0);

	     for(  kk=0; kk<g_PIDData.dimPlants; kk++) {
	        element[kk] = g_PIDData.plants[kk];
	     }
	return g_PIDData.dimPlants;
}

jint Java_com_tmc_tunerdemo_MainActivity_pidgetNumCrl(
                JNIEnv *env,
                jobject callingObject)
{
	return g_PIDData.nCrl;
}

jint Java_com_tmc_tunerdemo_MainActivity_pidgetGetCrl(
                JNIEnv *env,
                jobject callingObject,
                jdoubleArray a)
{
	int kk;

	jdouble *element=(*env)->GetDoubleArrayElements(env,a, 0);

	     for(  kk=0; kk<g_PIDData.dimCrl * g_PIDData.nCrl; kk++) {
	        element[kk] = g_PIDData.crl[kk];
	     }
	return g_PIDData.dimCrl* g_PIDData.nCrl;
}


/*
jobject Java_com_tmc_tunerdemo_MainActivity_objGetPlants(
                JNIEnv *env,
                jobject callingObject,
                jint param)
{
/// public PIDData(int _numFreqs, int _numPlants,  int _nCrl, int  _typeCrl,double [] _Plants, double [] _Crl )
	//	Signature Java Type
	//	Z boolean
	//	B byte
	//	C char
	//	S short
	//	I int
	//	J long
	//	F float
	//	D double
	//	L fully-qualified-class ;  fully-qualified-class
	//	[ type type[]
	//	( arg-types ) ret-type method type
	int _numFreqs=3;
	         int _numPlants=1;
	         int _nCrl=2;
	         int  _typeCrl=1;
	         double _Plants[]= {1,2,3, 100,10,1, 1,1,1};
	         double _Crl[]= {1,1,1,1, 2,2,2,2};

	jclass cls;
	jmethodID methodId;
	jobject obj=0;


		(*env)->GetJavaVM(env,&g_JavaVM);

          cls = (*env)->FindClass(env,"com/tmc/tunerdemo/PIDData");
          if (cls)
          {
          methodId = (*env)->GetMethodID(env,cls, "<init>", "(IIII[D[D)V");
        	  //methodId = (*env)->GetMethodID(env,cls, "<init>", "(I)V");
          	  if (methodId)
          	  {
          		obj = (*env)->NewObject(env,cls, methodId, _numFreqs,_numPlants,_nCrl,_typeCrl,_Plants,_Crl);
          	  }
          }



         return obj;
}
*/

extern jobject g_obj;
extern JNIEnv* g_env;
extern JavaVM* g_JavaVM;

jstring Java_com_tmc_tunerdemo_MainActivity_runTmcTuning(JNIEnv* env, jobject thiz, jfloat M0, jfloat R,jfloat L,jfloat Ts)
{

char buf[10000];


///////////
long m,n;
long k;
double err;

	//initJniGlobals(thiz,env);
g_obj = thiz;
g_env = env;

	InstallExcptHandler();

	(*env)->GetJavaVM(env,&g_JavaVM);

	// Input parameters. TODO: get from Java GUI
	//R= 0.1; // Ohm
	//L= 0.1e-3 ; // Hn
	//Ts = 5e-6; // sec
    main_designer(&err,R,L,Ts);
    sprintf(buf,"Calculations finished Ok, result in Download/Output.txt");
    return (*env)->NewStringUTF(env, buf );

}






