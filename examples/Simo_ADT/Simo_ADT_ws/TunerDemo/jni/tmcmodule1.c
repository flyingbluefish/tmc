// Caller to TMC generated application
//#include "tmc_lib.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define	_O_RDONLY O_RDONLY
#define _O_BINARY 0  //O_BINARY
#define  _O_RDWR  O_RDWR
#define  _O_CREAT O_CREAT
#define	 _O_TRUNC O_TRUNC
#define	 _S_IREAD (S_IRUSR|S_IROTH)		// see sys/stat.h.
#define	 _S_IWRITE (S_IWUSR|S_IWOTH)

#include <stdio.h>

#include "tmc.h"

extern const struct CInit_funcs_table Init_funcs_table ;

// If needed initialize an additional MEX-library
//void InitSIMOLib();
//void UninitSIMOLib();

// Prototype from generated file stdtmc.h
void tmcTestO(int nargout, int nargin,tmsMatrix *plants,tmsMatrix *Fw,tmsMatrix *ki,tmsMatrix *kp,tmsMatrix *kd,tmsMatrix *polew
,tmsMatrix *pars) ;



///////////

extern void storePIDData(int _numFreqs, int  _numPlants,  int _nCrl, int  _typeCrl, double* rData, double* iData,
		double* Fw,	double* ki,double* kp,double* kd,double* polew);


void main_designer(double *err,double R,double L,double Ts)
{
int fh;
//char sBuf[]="/mnt/sdcard/download/costia.txt";

char InBuf[1024];
int kk;
long M,N,nCrl;

tmsMatrix *plants;
tmsMatrix *Fw,*ki,*kp,*kd,*polew;
tmsMatrix *pars;

tmcInitLib(&Init_funcs_table);

		// Create tmc root-function arguments
		pars = tmcNewMatrix();
		plants = tmcNewMatrix();
		Fw = tmcNewMatrix();
		ki = tmcNewMatrix();
		kp = tmcNewMatrix();
		kd = tmcNewMatrix();
		polew = tmcNewMatrix();


//InitSIMOLib();

// Test file I/O:
//fh = open(sBuf,_O_RDWR  | _O_CREAT | _O_TRUNC | _O_BINARY, _S_IREAD | _S_IWRITE );
//write(fh,"HOH",3);
//close(fh);

//fh = open(sBuf,_O_RDONLY | _O_BINARY);
//read( fh, InBuf, 3 ) ;
//*err = InBuf[0];

			// Initialize input argument
			_tmcCreateMatrix(pars,1,4,0);
			pars->m_rData[0] = R;
			pars->m_rData[1] = L;
			pars->m_rData[2] = Ts;
			pars->m_rData[3] = 0;


			tmcTestO(6, 1,plants,Fw,ki,kp,kd,polew,pars); // root function call

			// copy results from [out]plants to global structure
			M = _tmcGetM(plants);
			N = _tmcGetN(plants);
			nCrl = _tmcGetM(ki)*_tmcGetN(ki);

			storePIDData(N, M,  nCrl, 1, plants->m_rData, plants->m_iData, Fw->m_rData,
					ki->m_rData,kp->m_rData,kd->m_rData,polew->m_rData);


//UninitSIMOLib();

 	// free tmc root-function arguments
	tmcFreeLocalVar(Fw);
	tmcFreeLocalVar(ki);
	tmcFreeLocalVar(kp);
	tmcFreeLocalVar(kd);
	tmcFreeLocalVar(polew);

	tmcFreeLocalVar(plants);
	tmcFreeLocalVar(pars);
tmcFreeLib();

}


//////////////////
void tmcdbgPushStackVar(const char *fncname,short nVars,tmsMatrix* var1,const char *varname1,...)
{
}
void tmcdbgPopStackVar(short nVars)
{
}

void   MYFREE( void *memblock )
{
	free(memblock);
}


