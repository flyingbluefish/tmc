#include <windows.h>
#include "tmc.h"

void tmcTestO(int nargout, int nargin,tmsMatrix *F,tmsMatrix *Mag,tmsMatrix *Ph
,tmsMatrix *f1,tmsMatrix *d1,tmsMatrix *f2,tmsMatrix *d2,tmsMatrix *NumFreqs) ;



void __stdcall FiltFreqResp(double w1,double d1,double w2,double d2, unsigned long NumFreqs, double* F,double* Mag,double *Ph)
{
	unsigned long k;

tmsMatrix *mF = tmcNewMatrix();
tmsMatrix *mMag= tmcNewMatrix();
tmsMatrix *mPh= tmcNewMatrix();
tmsMatrix *mf1= tmcNewMatrix();
tmsMatrix *md1= tmcNewMatrix();
tmsMatrix *mf2= tmcNewMatrix();
tmsMatrix *md2= tmcNewMatrix();
tmsMatrix *mNumFreqs= tmcNewMatrix();

// to create input matrix use: _tmcCreateMatrix(tmsMatrix *res,long M,long N,short bHasImagine)

tmcScalar(mf1,w1);
tmcScalar(md1,d1);
tmcScalar(mf2,w2);
tmcScalar(md2,d2);
tmcScalar(mNumFreqs,NumFreqs);


tmcTestO(3, 5,
		 mF,mMag,mPh, // [outputs]
 mf1,md1,mf2,md2,mNumFreqs) ; // [inputs]

	// copy outputs
	if (NumFreqs > tmcNumElem ( mF ))
	{
			NumFreqs = tmcNumElem ( mF );
	}
	for (k=0;k<NumFreqs;k++)
	{
		F[k]=mF->value.complx.rData[k];
		Mag[k]= mMag->value.complx.rData[k];
		Ph[k] = mPh->value.complx.rData[k];
	}

tmcFreeLocalVar(mNumFreqs);
tmcFreeLocalVar(md2);
tmcFreeLocalVar(mf2);
tmcFreeLocalVar(md1);
tmcFreeLocalVar(mf1);
tmcFreeLocalVar(mPh);
tmcFreeLocalVar(mMag);
tmcFreeLocalVar(mF);


}


///////////////////
extern   const struct CInit_funcs_table Init_funcs_table ;
void __stdcall InitDLL(void)
{
	//tmcInitLib(&Init_funcs_table);
}
void __stdcall UnInitDLL(void)
{
	//tmcFreeLib();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
				tmcInitLib(&Init_funcs_table);
   break;

	case DLL_THREAD_ATTACH:
	break;

	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		tmcFreeLib();
	break;

	//	break;
	}
    return TRUE;
}


