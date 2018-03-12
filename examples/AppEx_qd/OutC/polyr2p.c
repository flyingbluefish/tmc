//File: polyr2p.c 
//Generated by TMC Converter(C)2009-2016
#include "tmc.h"
#include "stdtmc.h"

#include "TestO.globals.h"

// User provided C-code header (must be included in include path):
#include "External_func.h"

// % Lines 1--21:
//function c = polyr2p(x)

//%POLY Convert roots to polynomial.

//%   POLY(A), when A is an N by N matrix, is a row vector with

//%   N+1 elements which are the coefficients of the

//%   characteristic polynomial, DET(lambda*EYE(SIZE(A)) - A) .

//%

//%   POLY(V), when V is a vector, is a vector whose elements are

//%   the coefficients of the polynomial whose roots are the

//%   elements of V . For vectors, ROOTS and POLY are inverse

//%   functions of each other, up to ordering, scaling, and

//%   roundoff error.

//%

//%   ROOTS(POLY(1:20)) generates Wilkinson's famous example.

//%

//%   See also ROOTS, CONV, RESIDUE, POLYVAL.

//

//%   Original by J.N. Little 4-21-85.

//%   Copyright 1984-2002 The MathWorks, Inc.

//%   $Revision: 5.14 $  $Date: 2002/04/09 00:14:24 $

//

//[m,n] = size(x);

void tmcpolyr2p(int nargout, int nargin,tmsMatrix *c
,tmsMatrix *x) {
tmsMatrix **reg=tmcCreateRegFrame(91);
tmsMatrix *m=tmcNewMatrix();
tmsMatrix *n=tmcNewMatrix();
tmsMatrix *e=tmcNewMatrix();
tmsMatrix *j_=tmcNewMatrix();

TRY
TMC_DBG_PUSH_STACK_VAR("polyr2p",6,
x,"x",
c,"c",
m,"m",
n,"n",
e,"e",
j_,"j_");


//CALL function
tmcReallocRegister(reg[2]);
tmcReallocRegister(reg[3]);
tmcsize(2,1, reg[2], reg[3], x,NULL);

tmcAssign(m,reg[2]);

tmcAssign(n,reg[3]);
//statement here,line 21

// % Lines 22--24:
//if m == n

//   % Characteristic polynomial (square x)

//   e = eig(x);



tmcEq(reg[8],m,n);
if(tmcIsFalse(reg[8])) goto label_3; // goto to the end of the clause if the expression is false

//CALL function
tmcReallocRegister(reg[10]);
tmcReallocRegister(reg[11]);
tmceig(1,1, reg[10], reg[11], x,NULL,NULL);

tmcAssign(e,reg[10]);
//statement here,line 24

// % Lines 25--26:
//elseif (m==1) | (n==1)

//   e = x;

goto label_2; //branch to end IF
label_3: ; //end IF clause

tmcScalar(reg[14],1.000000000000000e+000);
tmcEq(reg[15],m,reg[14]);

tmcScalar(reg[17],1.000000000000000e+000);
tmcEq(reg[18],n,reg[17]);
tmcOrScalar(reg[19],reg[15],reg[18]);
if(tmcIsFalse(reg[19])) goto label_4; // goto to the end of the clause if the expression is false


tmcAssign(e,x);
//statement here,line 26

// % Lines 27--28:
//else

//   error('Argument must be a vector or a square matrix.')

goto label_2; //branch to end IF
label_4: ; //end IF clause
tmcCreateString(reg[22],"Argument must be a vector or a square matrix.");
//CALL function
tmcReallocRegister(reg[23]);
tmcerror(0,1, reg[23], reg[22]);
//statement here,line 28

// % Lines 29--29:
//end

label_5: ; //end IF clause
label_2: ; //end IF
//statement here,line 29

// % Lines 30--33:
//

//% Strip out infinities

//%TMC:e = e( isfinite(e) );

//e = e(find( isfinite(e) ));



//CALL function
tmcReallocRegister(reg[26]);
tmcisfinite(1,1, reg[26], e);
//CALL function
tmcReallocRegister(reg[27]);
tmcReallocRegister(reg[28]);
tmcReallocRegister(reg[29]);
tmcfind(1,1, reg[27], reg[28], reg[29], reg[26],NULL,NULL);
tmcGetByIndex(reg[30],e,1,reg[27]);

tmcAssign(e,reg[30]);
//statement here,line 33

// % Lines 34--36:
//

//% Expand recursion formula

//n = length(e);


//CALL function
tmcReallocRegister(reg[33]);
tmclength(1,1, reg[33], e);

tmcAssign(n,reg[33]);
//statement here,line 36

// % Lines 37--37:
//c = [1 zeros(1,n)];

tmcScalar(reg[35],1.000000000000000e+000);
tmcScalar(reg[36],1.000000000000000e+000);

//CALL function
tmcReallocRegister(reg[38]);
tmczeros(1,2, reg[38], reg[36], n);
tmcCollectColumns(reg[39],2,reg[35],reg[38]);
tmcCollectRows(reg[40],1,reg[39]);

tmcAssign(c,reg[40]);
//statement here,line 37

// % Lines 38--39:
//for j_=1:n

//    c(2:(j_+1)) = c(2:(j_+1)) - e(j_).*c(1:j_);

tmcScalar(reg[42],1.000000000000000e+000);

tmcCreateColonBaseLimit(reg[44],reg[42],n);
tmcForIterInit(reg[45],reg[44],j_);
label_8: ; //FOR begin
if(tmcForIterNext(reg[45],reg[44])) goto label_7; // exit for

tmcScalar(reg[47],2.000000000000000e+000);

tmcScalar(reg[49],1.000000000000000e+000);
tmcAdd(reg[50],j_,reg[49]);
tmcCreateColonBaseLimit(reg[51],reg[47],reg[50]);
tmcGetByIndex(reg[52],c,1,reg[51]);


tmcGetByIndex(reg[55],e,1,j_);

tmcScalar(reg[57],1.000000000000000e+000);

tmcCreateColonBaseLimit(reg[59],reg[57],j_);
tmcGetByIndex(reg[60],c,1,reg[59]);
tmcMulScalar(reg[61],reg[55],reg[60]);
tmcSub(reg[62],reg[52],reg[61]);

tmcScalar(reg[64],2.000000000000000e+000);

tmcScalar(reg[66],1.000000000000000e+000);
tmcAdd(reg[67],j_,reg[66]);
tmcCreateColonBaseLimit(reg[68],reg[64],reg[67]);
tmcGetRefByIndex(pRefHelper,c,1,reg[68]);
tmcAssign(pRefHelper,reg[62]);
//statement here,line 39

// % Lines 40--40:
//end

label_6: ; //FOR end
goto label_8; //branch to FOR begin
label_7: ; //FOR exit
//statement here,line 40

// % Lines 41--44:
//

//% The result should be real if the roots are complex conjugates.

//if isequal(sort(e(imag(e)>0)),sort(conj(e(imag(e)<0))))

//    c = real(c);



//CALL function
tmcReallocRegister(reg[71]);
tmcimag(1,1, reg[71], e);
tmcScalar(reg[72],0.000000000000000e+000);
tmcGt(reg[73],reg[71],reg[72]);
tmcGetByIndex(reg[74],e,1,reg[73]);
//CALL function
tmcReallocRegister(reg[75]);
tmcReallocRegister(reg[76]);
tmcsort(1,1, reg[75], reg[76], reg[74],NULL);


//CALL function
tmcReallocRegister(reg[79]);
tmcimag(1,1, reg[79], e);
tmcScalar(reg[80],0.000000000000000e+000);
tmcLt(reg[81],reg[79],reg[80]);
tmcGetByIndex(reg[82],e,1,reg[81]);
//CALL function
tmcReallocRegister(reg[83]);
tmcconj(1,1, reg[83], reg[82]);
//CALL function
tmcReallocRegister(reg[84]);
tmcReallocRegister(reg[85]);
tmcsort(1,1, reg[84], reg[85], reg[83],NULL);
//CALL function
tmcReallocRegister(reg[86]);
tmcisequal(1,2, reg[86], reg[75], reg[84]);
if(tmcIsFalse(reg[86])) goto label_10; // goto to the end of the clause if the expression is false

//CALL function
tmcReallocRegister(reg[89]);
tmcreal(1,1, reg[89], c);

tmcAssign(c,reg[89]);
//statement here,line 44

// % Lines 45--45:
//end

goto label_9; //branch to end IF
label_10: ; //end IF clause
label_9: ; //end IF
//statement here,line 45

// % Lines 46--46:
label_1: ; //end Function
FINALLY
tmcFreeLocalVar(j_);
tmcFreeLocalVar(e);
tmcFreeLocalVar(n);
tmcFreeLocalVar(m);
tmcFreeRegFrame(reg);

TMC_DBG_POP_STACK_VAR(6);

ENDFINALLY
}

//FUNCTION DEFINITION ENDED
//statement here,line 46

// % Lines 47--47:
