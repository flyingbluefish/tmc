//File: solvemyeq.c 
//Generated by TMC Converter(C)2009-2016
#include "tmc.h"
#include "stdtmc.h"

#include "TestO.globals.h"

// User provided C-code header (must be included in include path):
#include "External_func.h"

// % Lines 1--3:
//function S=solvemyeq(a,b,ep1)

//% S=solvemyeq(-10000,10000,1e-6)

//global ite;

void tmcsolvemyeq(int nargout, int nargin,tmsMatrix *S
,tmsMatrix *a,tmsMatrix *b,tmsMatrix *ep1__input__tmc) {
tmsMatrix **reg=tmcCreateRegFrame(91);
tmsMatrix *ep1=tmcNewMatrix();
tmsMatrix *y1=tmcNewMatrix();
tmsMatrix *y2=tmcNewMatrix();
tmsMatrix *x1=tmcNewMatrix();
tmsMatrix *x2=tmcNewMatrix();
tmsMatrix *x0=tmcNewMatrix();
tmsMatrix *y0=tmcNewMatrix();
tmsMatrix *xx=tmcNewMatrix();
tmsMatrix *rr=tmcNewMatrix();
tmsMatrix *yy=tmcNewMatrix();

tmcCopyMat(ep1,ep1__input__tmc);
TRY
TMC_DBG_PUSH_STACK_VAR("solvemyeq",14,
a,"a",
b,"b",
ep1__input__tmc,"ep1__input__tmc",
S,"S",
ep1,"ep1",
y1,"y1",
y2,"y2",
x1,"x1",
x2,"x2",
x0,"x0",
y0,"y0",
xx,"xx",
rr,"rr",
yy,"yy");

//statement here,line 3

// % Lines 4--4:
//ite=0;

tmcScalar(reg[1],0.000000000000000e+000);

tmcAssign(ite,reg[1]);
//statement here,line 4

// % Lines 5--7:
//

//if ep1 < eps*5

//    ep1=eps*5;


//CALL function
tmcReallocRegister(reg[4]);
tmceps(1,0, reg[4],NULL);
tmcScalar(reg[5],5.000000000000000e+000);
tmcMul(reg[6],reg[4],reg[5]);
tmcLt(reg[7],ep1,reg[6]);
if(tmcIsFalse(reg[7])) goto label_3; // goto to the end of the clause if the expression is false
//CALL function
tmcReallocRegister(reg[8]);
tmceps(1,0, reg[8],NULL);
tmcScalar(reg[9],5.000000000000000e+000);
tmcMul(reg[10],reg[8],reg[9]);

tmcAssign(ep1,reg[10]);
//statement here,line 7

// % Lines 8--8:
//end

goto label_2; //branch to end IF
label_3: ; //end IF clause
label_2: ; //end IF
//statement here,line 8

// % Lines 9--10:
//

//y1 = myeq( a);


//CALL function
tmcReallocRegister(reg[13]);
tmcmyeq(1,1, reg[13], a);

tmcAssign(y1,reg[13]);
//statement here,line 10

// % Lines 11--11:
//y2 = myeq( b);


//CALL function
tmcReallocRegister(reg[16]);
tmcmyeq(1,1, reg[16], b);

tmcAssign(y2,reg[16]);
//statement here,line 11

// % Lines 12--13:
//if sign(y1) == sign(y2)

//    S=[];


//CALL function
tmcReallocRegister(reg[19]);
tmcsign(1,1, reg[19], y1);

//CALL function
tmcReallocRegister(reg[21]);
tmcsign(1,1, reg[21], y2);
tmcEq(reg[22],reg[19],reg[21]);
if(tmcIsFalse(reg[22])) goto label_5; // goto to the end of the clause if the expression is false
tmcCreateMatrixEmpty(reg[23]);

tmcAssign(S,reg[23]);
//statement here,line 13

// % Lines 14--14:
//    return;

goto label_1; //branch to FUNCTION exit
//statement here,line 14

// % Lines 15--15:
//end

goto label_4; //branch to end IF
label_5: ; //end IF clause
label_4: ; //end IF
//statement here,line 15

// % Lines 16--17:
//

//x1=a;



tmcAssign(x1,a);
//statement here,line 17

// % Lines 18--18:
//x2=b;



tmcAssign(x2,b);
//statement here,line 18

// % Lines 19--21:
//

//while abs(x1-x2)  > ep1

//    x0 = 0.5*(x1+x2);

label_6: ; //WHILE expression


tmcSub(reg[31],x1,x2);
//CALL function
tmcReallocRegister(reg[32]);
tmcabs(1,1, reg[32], reg[31]);

tmcGt(reg[34],reg[32],ep1);
if(tmcIsFalse(reg[34])) goto label_8; // goto to the exit of the while if the expression is false
tmcScalar(reg[35],5.000000000000000e-001);


tmcAdd(reg[38],x1,x2);
tmcMul(reg[39],reg[35],reg[38]);

tmcAssign(x0,reg[39]);
//statement here,line 21

// % Lines 22--22:
//    y0 = myeq( x0  );


//CALL function
tmcReallocRegister(reg[42]);
tmcmyeq(1,1, reg[42], x0);

tmcAssign(y0,reg[42]);
//statement here,line 22

// % Lines 23--24:
//    if  abs(y0) <= eps 

//            break;


//CALL function
tmcReallocRegister(reg[45]);
tmcabs(1,1, reg[45], y0);
//CALL function
tmcReallocRegister(reg[46]);
tmceps(1,0, reg[46],NULL);
tmcLe(reg[47],reg[45],reg[46]);
if(tmcIsFalse(reg[47])) goto label_10; // goto to the end of the clause if the expression is false
goto label_8; //break to WHILE exit
//statement here,line 24

// % Lines 25--25:
//    end

goto label_9; //branch to end IF
label_10: ; //end IF clause
label_9: ; //end IF
//statement here,line 25

// % Lines 26--27:
//    if sign(y0) ~= sign(x0)

//        x2 = x0;


//CALL function
tmcReallocRegister(reg[49]);
tmcsign(1,1, reg[49], y0);

//CALL function
tmcReallocRegister(reg[51]);
tmcsign(1,1, reg[51], x0);
tmcNe(reg[52],reg[49],reg[51]);
if(tmcIsFalse(reg[52])) goto label_12; // goto to the end of the clause if the expression is false


tmcAssign(x2,x0);
//statement here,line 27

// % Lines 28--29:
//    else

//        x1 = x0;

goto label_11; //branch to end IF
label_12: ; //end IF clause


tmcAssign(x1,x0);
//statement here,line 29

// % Lines 30--30:
//    end

label_13: ; //end IF clause
label_11: ; //end IF
//statement here,line 30

// % Lines 31--31:
//end

label_7: ; //end WHILE
goto label_6; //branch to test WHILE expression
label_8: ; //exit WHILE
//statement here,line 31

// % Lines 32--33:
//

//S.x0 = x0;



tmcGetRefByFieldHcode(pRefHelper,S,0x0eb80000);/* x0 */
tmcAssign(pRefHelper,x0);
//statement here,line 33

// % Lines 34--34:
//S.y0 = y0;



tmcGetRefByFieldHcode(pRefHelper,S,0x0ed70000);/* y0 */
tmcAssign(pRefHelper,y0);
//statement here,line 34

// % Lines 35--36:
//

//xx=[1,3,4,5,6,10000];

tmcScalar(reg[63],1.000000000000000e+000);
tmcScalar(reg[64],3.000000000000000e+000);
tmcScalar(reg[65],4.000000000000000e+000);
tmcScalar(reg[66],5.000000000000000e+000);
tmcScalar(reg[67],6.000000000000000e+000);
tmcScalar(reg[68],1.000000000000000e+004);
tmcCollectColumns(reg[69],6,reg[63],reg[64],reg[65],reg[66],reg[67],reg[68]);
tmcCollectRows(reg[70],1,reg[69]);

tmcAssign(xx,reg[70]);
//statement here,line 36

// % Lines 37--37:
//rr=roots(xx);


//CALL function
tmcReallocRegister(reg[73]);
tmcroots(1,1, reg[73], xx);

tmcAssign(rr,reg[73]);
//statement here,line 37

// % Lines 38--38:
//disp(rr);


//CALL function
tmcReallocRegister(reg[76]);
tmcdisp(0,1, reg[76], rr);
//statement here,line 38

// % Lines 39--39:
//yy=polyval(xx,rr);



//CALL function
tmcReallocRegister(reg[79]);
tmcpolyval(1,2, reg[79], xx, rr);

tmcAssign(yy,reg[79]);
//statement here,line 39

// % Lines 40--40:
//disp(yy);


//CALL function
tmcReallocRegister(reg[82]);
tmcdisp(0,1, reg[82], yy);
//statement here,line 40

// % Lines 41--42:
//

//S.rr=rr;



tmcGetRefByFieldHcode(pRefHelper,S,0x0e400000);/* rr */
tmcAssign(pRefHelper,rr);
//statement here,line 42

// % Lines 43--43:
//S.yy=yy;



tmcGetRefByFieldHcode(pRefHelper,S,0x0f200000);/* yy */
tmcAssign(pRefHelper,yy);
//statement here,line 43

// % Lines 44--51:
//

//% Open this comment to check if SEH is supported

//% try 

//%     disp(S.oo);

//% catch

//%     S.oo='SEH supported';

//% end

//disp(S)


//CALL function
tmcReallocRegister(reg[90]);
tmcdisp(0,1, reg[90], S);
//statement here,line 51

// % Lines 52--53:
//

//function y=myeq(x)

label_1: ; //end Function
FINALLY
tmcFreeLocalVar(yy);
tmcFreeLocalVar(rr);
tmcFreeLocalVar(xx);
tmcFreeLocalVar(y0);
tmcFreeLocalVar(x0);
tmcFreeLocalVar(x2);
tmcFreeLocalVar(x1);
tmcFreeLocalVar(y2);
tmcFreeLocalVar(y1);
tmcFreeLocalVar(ep1);
tmcFreeRegFrame(reg);

TMC_DBG_POP_STACK_VAR(14);

ENDFINALLY
}

//FUNCTION DEFINITION ENDED
//statement here,line 53

// % Lines 54--54:
//global ite

//y = x.^2 .* sin (x) - x.^3 .* cos(x) + x;

//

//y = ExMex1(y , y);

//ite=ite+1;

//

//endfunction % for demonstration of OCTAVE syntax support

//

//

//

static void tmcmyeq(int nargout, int nargin,tmsMatrix *y
,tmsMatrix *x) {
tmsMatrix **reg=tmcCreateRegFrame(25);

TRY
TMC_DBG_PUSH_STACK_VAR("myeq",2,
x,"x",
y,"y");

//statement here,line 55


tmcScalar(reg[2],2.000000000000000e+000);
tmcPowerScalar(reg[3],x,reg[2]);

//CALL function
tmcReallocRegister(reg[5]);
tmcsin(1,1, reg[5], x);
tmcMulScalar(reg[6],reg[3],reg[5]);

tmcScalar(reg[8],3.000000000000000e+000);
tmcPowerScalar(reg[9],x,reg[8]);

//CALL function
tmcReallocRegister(reg[11]);
tmccos(1,1, reg[11], x);
tmcMulScalar(reg[12],reg[9],reg[11]);
tmcSub(reg[13],reg[6],reg[12]);

tmcAdd(reg[15],reg[13],x);

tmcAssign(y,reg[15]);
//statement here,line 55



//CALL function
tmcReallocRegister(reg[19]);
tmcExMex1(1,2, reg[19], y, y);

tmcAssign(y,reg[19]);
//statement here,line 57


tmcScalar(reg[22],1.000000000000000e+000);
tmcAdd(reg[23],ite,reg[22]);

tmcAssign(ite,reg[23]);
//statement here,line 58

label_1: ; //end Function
FINALLY
tmcFreeRegFrame(reg);

TMC_DBG_POP_STACK_VAR(2);

ENDFINALLY
}

//FUNCTION DEFINITION ENDED
//statement here,line 60

