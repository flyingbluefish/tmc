//File: forsub.c 
//Generated by TMC Converter(C)2009-2016
#include "tmc.h"
#include "stdtmc.h"

#include "TestO.globals.h"

// User provided C-code header (must be included in include path):
#include "External_func.h"

// % Lines 1--6:
//function x = forsub(A,b)

//%

//% assume A is an lower triangular matrix

//% forsub performs forward substitution to solve Ax=b

//%

//   n = size(A,1);

void tmcforsub(int nargout, int nargin,tmsMatrix *x
,tmsMatrix *A,tmsMatrix *b) {
tmsMatrix **reg=tmcCreateRegFrame(50);
tmsMatrix *n=tmcNewMatrix();
tmsMatrix *k=tmcNewMatrix();

TRY
TMC_DBG_PUSH_STACK_VAR("forsub",5,
A,"A",
b,"b",
x,"x",
n,"n",
k,"k");


tmcScalar(reg[2],1.000000000000000e+000);
//CALL function
tmcReallocRegister(reg[3]);
tmcsize(1,2, reg[3], A, reg[2]);

tmcAssign(n,reg[3]);
//statement here,line 6

// % Lines 7--7:
//   x = zeros(n,1);


tmcScalar(reg[6],1.000000000000000e+000);
//CALL function
tmcReallocRegister(reg[7]);
tmczeros(1,2, reg[7], n, reg[6]);

tmcAssign(x,reg[7]);
//statement here,line 7

// % Lines 8--9:
//   

//   x(1) = b(1)/A(1,1);


tmcScalar(reg[10],1.000000000000000e+000);
tmcGetByIndex(reg[11],b,1,reg[10]);

tmcScalar(reg[13],1.000000000000000e+000);
tmcScalar(reg[14],1.000000000000000e+000);
tmcGetByIndex(reg[15],A,2,reg[13],reg[14]);
tmcDiv(reg[16],reg[11],reg[15]);

tmcScalar(reg[18],1.000000000000000e+000);
tmcGetRefByIndex(pRefHelper,x,1,reg[18]);
tmcAssign(pRefHelper,reg[16]);
//statement here,line 9

// % Lines 10--11:
//   for k = 2:n

//       x(k) = (b(k) - A(k,1:k-1)*x(1:k-1))/A(k,k);

tmcScalar(reg[19],2.000000000000000e+000);

tmcCreateColonBaseLimit(reg[21],reg[19],n);
tmcForIterInit(reg[22],reg[21],k);
label_4: ; //FOR begin
if(tmcForIterNext(reg[22],reg[21])) goto label_3; // exit for


tmcGetByIndex(reg[25],b,1,k);


tmcScalar(reg[28],1.000000000000000e+000);

tmcScalar(reg[30],1.000000000000000e+000);
tmcSub(reg[31],k,reg[30]);
tmcCreateColonBaseLimit(reg[32],reg[28],reg[31]);
tmcGetByIndex(reg[33],A,2,k,reg[32]);

tmcScalar(reg[35],1.000000000000000e+000);

tmcScalar(reg[37],1.000000000000000e+000);
tmcSub(reg[38],k,reg[37]);
tmcCreateColonBaseLimit(reg[39],reg[35],reg[38]);
tmcGetByIndex(reg[40],x,1,reg[39]);
tmcMul(reg[41],reg[33],reg[40]);
tmcSub(reg[42],reg[25],reg[41]);



tmcGetByIndex(reg[46],A,2,k,k);
tmcDiv(reg[47],reg[42],reg[46]);


tmcGetRefByIndex(pRefHelper,x,1,k);
tmcAssign(pRefHelper,reg[47]);
//statement here,line 11

// % Lines 12--12:
//   end;

label_2: ; //FOR end
goto label_4; //branch to FOR begin
label_3: ; //FOR exit
//statement here,line 12

// % Lines 13--13:
label_1: ; //end Function
FINALLY
tmcFreeLocalVar(k);
tmcFreeLocalVar(n);
tmcFreeRegFrame(reg);

TMC_DBG_POP_STACK_VAR(5);

ENDFINALLY
}

//FUNCTION DEFINITION ENDED
//statement here,line 13

// % Lines 14--14:
