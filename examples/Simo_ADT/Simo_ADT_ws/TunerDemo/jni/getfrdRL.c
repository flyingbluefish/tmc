//File: getfrdRL.c 
//Generated by TMC Converter(C)2009-2013
#include "tmc.h"
#include "stdtmc.h"

#include "TestO.globals.h"

// User provided C-code header (must be included in include path):
#include "External_func.h"

// % Lines 1--4:
//function [PlantModel] = getfrdRL(PlantModel)

//%PlantModel = struct('R',pars(1),'L',pars(2),'Ts',pars(3),'Delay',pars(4));

//% calculate frequency-domain RL model: 1/(sL+R) with delay.

//PlantModel.F = logspace(0.1, log10( 0.49/PlantModel.Ts   ), 100);

void tmcgetfrdRL(int nargout, int nargin,tmsMatrix *PlantModel
,tmsMatrix *PlantModel__input__tmc) {
tmsMatrix **reg=tmcCreateRegFrame(47);
tmsMatrix *w=tmcNewMatrix();
tmsMatrix *s=tmcNewMatrix();
tmsMatrix *D=tmcNewMatrix();

tmcCopyMat(PlantModel,PlantModel__input__tmc);
TRY
TMC_DBG_PUSH_STACK_VAR("getfrdRL",5,
PlantModel__input__tmc,"PlantModel__input__tmc",
PlantModel,"PlantModel",
w,"w",
s,"s",
D,"D");

tmcScalar(reg[1],1.000000000000000e-001);
tmcScalar(reg[2],4.900000000000000e-001);

tmcGetByFieldHcode(reg[5],PlantModel,0x0a9f0000);/* Ts */
tmcDiv(reg[6],reg[2],reg[5]);
//CALL function
tmcReallocRegister(reg[7]);
tmclog10(1,1, reg[7], reg[6]);
tmcScalar(reg[8],1.000000000000000e+002);
//CALL function
tmcReallocRegister(reg[9]);
tmclogspace(1,3, reg[9], reg[1], reg[7], reg[8]);

tmcGetRefByFieldHcode(pRefHelper,PlantModel,0x00460000);/* F */
tmcAssign(pRefHelper,reg[9]);
//statement here,line 4

// % Lines 5--5:
//w = PlantModel.F*2*pi;


tmcGetByFieldHcode(reg[14],PlantModel,0x00460000);/* F */
tmcScalar(reg[15],2.000000000000000e+000);
tmcMul(reg[16],reg[14],reg[15]);
//CALL function
tmcReallocRegister(reg[17]);
tmcpi(1,0, reg[17]);
tmcMul(reg[18],reg[16],reg[17]);

tmcAssign(w,reg[18]);
//statement here,line 5

// % Lines 6--6:
//s  = j*w;

//CALL function
tmcReallocRegister(reg[20]);
tmcj(1,0, reg[20]);

tmcMul(reg[22],reg[20],w);

tmcAssign(s,reg[22]);
//statement here,line 6

// % Lines 7--7:
//D = exp(-s*PlantModel.Delay);


tmcNeg(reg[25],s);

tmcGetByFieldHcode(reg[28],PlantModel,0xc9630000);/* Delay */
tmcMul(reg[29],reg[25],reg[28]);
//CALL function
tmcReallocRegister(reg[30]);
tmcexp(1,1, reg[30], reg[29]);

tmcAssign(D,reg[30]);
//statement here,line 7

// % Lines 8--8:
//PlantModel.P = 1./(s*PlantModel.L + PlantModel.R) .* D;

tmcScalar(reg[32],1.000000000000000e+000);


tmcGetByFieldHcode(reg[36],PlantModel,0x004c0000);/* L */
tmcMul(reg[37],s,reg[36]);

tmcGetByFieldHcode(reg[40],PlantModel,0x00520000);/* R */
tmcAdd(reg[41],reg[37],reg[40]);
tmcDivScalar(reg[42],reg[32],reg[41]);

tmcMulScalar(reg[44],reg[42],D);

tmcGetRefByFieldHcode(pRefHelper,PlantModel,0x00500000);/* P */
tmcAssign(pRefHelper,reg[44]);
//statement here,line 8

// % Lines 9--10:
//

label_1: ; //end Function
FINALLY
tmcFreeLocalVar(D);
tmcFreeLocalVar(s);
tmcFreeLocalVar(w);
tmcFreeRegFrame(reg);

TMC_DBG_POP_STACK_VAR(5);

ENDFINALLY
}

//FUNCTION DEFINITION BEGIN
//statement here,line 10

// % Lines 11--11:
