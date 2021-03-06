//File: gcdroot.c 
//Generated by TMC Converter(C)2009-2016
#include "tmc.h"
#include "stdtmc.h"

#include "TestO.globals.h"

// User provided C-code header (must be included in include path):
#include "External_func.h"

// % Lines 1--33:
//

//function [z, bkerr] = gcdroot( p, tol)

//%  

//%  GCDROOT calculates the multiplicity structure and initial root 

//%  approximation of a real polynomial p,

//% 

//%        p(x) = a_1 x^n + a_2 x^n-1 + ... + a_n x + a_n+1,

//%

//%  given by an (n+1)-row vector p = (a_1, ..., a_n+1) 

//%

//%  METHOD : for details, contact the author 

//%

//%             Zhonggang Zeng

//%             Department of Mathematics

//%             Northeastern Illinois University

//%             Chicago, IL 60625

//%          

//%             email: zzeng@neiu.edu

//%

//%  INPUT :  p = polynomial coefficients. 

//%           tol = zero remainder threshold; 

//%                 default = 10^{-10}, set internally

//%                 if no value is specified.

//%

//%  OUTPUT : z = roots of polynomial p and multiplicities:

//%                  z(:,1) = all distinct roots

//%                  z(:,2) = corresponding multiplicities

//%           bkerr = backward error

//%

//%  CALL :   It is best to call pzero with only one argument as   

//%               >> z = gcdroot(p). 

//%

//   if nargin == 1, tol = 1.e-10; end;

void tmcgcdroot(int nargout, int nargin,tmsMatrix *z,tmsMatrix *bkerr
,tmsMatrix *p__input__tmc,tmsMatrix *tol__input__tmc) {
tmsMatrix **reg=tmcCreateRegFrame(393);
tmsMatrix *p=tmcNewMatrix();
tmsMatrix *tol=tmcNewMatrix();
tmsMatrix *gamma=tmcNewMatrix();
tmsMatrix *thresh=tmcNewMatrix();
tmsMatrix *drop=tmcNewMatrix();
tmsMatrix *n=tmcNewMatrix();
tmsMatrix *q=tmcNewMatrix();
tmsMatrix *ff=tmcNewMatrix();
tmsMatrix *gg=tmcNewMatrix();
tmsMatrix *nf=tmcNewMatrix();
tmsMatrix *mx=tmcNewMatrix();
tmsMatrix *wtol=tmcNewMatrix();
tmsMatrix *s0=tmcNewMatrix();
tmsMatrix *s=tmcNewMatrix();
tmsMatrix *wthrh=tmcNewMatrix();
tmsMatrix *k=tmcNewMatrix();
tmsMatrix *h=tmcNewMatrix();
tmsMatrix *u=tmcNewMatrix();
tmsMatrix *f=tmcNewMatrix();
tmsMatrix *v=tmcNewMatrix();
tmsMatrix *m=tmcNewMatrix();
tmsMatrix *A=tmcNewMatrix();
tmsMatrix *x=tmcNewMatrix();
tmsMatrix *u0=tmcNewMatrix();
tmsMatrix *v0=tmcNewMatrix();
tmsMatrix *B=tmcNewMatrix();
tmsMatrix *g0=tmcNewMatrix();
tmsMatrix *uuu=tmcNewMatrix();
tmsMatrix *vvv=tmcNewMatrix();
tmsMatrix *rec=tmcNewMatrix();
tmsMatrix *l=tmcNewMatrix();
tmsMatrix *t=tmcNewMatrix();
tmsMatrix *j_=tmcNewMatrix();
tmsMatrix *jj=tmcNewMatrix();
tmsMatrix *g=tmcNewMatrix();
tmsMatrix *ll=tmcNewMatrix();
tmsMatrix *mm=tmcNewMatrix();
tmsMatrix *yy=tmcNewMatrix();
tmsMatrix *y=tmcNewMatrix();
tmsMatrix *kk=tmcNewMatrix();
tmsMatrix *id=tmcNewMatrix();
tmsMatrix *w=tmcNewMatrix();

tmcCopyMat(p,p__input__tmc);
tmcCopyMat(tol,tol__input__tmc);
TRY
TMC_DBG_PUSH_STACK_VAR("gcdroot",46,
p__input__tmc,"p__input__tmc",
tol__input__tmc,"tol__input__tmc",
z,"z",
bkerr,"bkerr",
p,"p",
tol,"tol",
gamma,"gamma",
thresh,"thresh",
drop,"drop",
n,"n",
q,"q",
ff,"ff",
gg,"gg",
nf,"nf",
mx,"mx",
wtol,"wtol",
s0,"s0",
s,"s",
wthrh,"wthrh",
k,"k",
h,"h",
u,"u",
f,"f",
v,"v",
m,"m",
A,"A",
x,"x",
u0,"u0",
v0,"v0",
B,"B",
g0,"g0",
uuu,"uuu",
vvv,"vvv",
rec,"rec",
l,"l",
t,"t",
j_,"j_",
jj,"jj",
g,"g",
ll,"ll",
mm,"mm",
yy,"yy",
y,"y",
kk,"kk",
id,"id",
w,"w");

//CALL function
tmcReallocRegister(reg[1]);
tmcnargin(1,0, reg[1]);
tmcScalar(reg[2],1.000000000000000e+000);
tmcEq(reg[3],reg[1],reg[2]);
if(tmcIsFalse(reg[3])) goto label_3; // goto to the end of the clause if the expression is false
tmcScalar(reg[4],1.000000000000000e-010);

tmcAssign(tol,reg[4]);
//statement here,line 33

goto label_2; //branch to end IF
label_3: ; //end IF clause
label_2: ; //end IF
//statement here,line 33

// % Lines 34--34:
//   gamma = 100;       % residual growth factor, default = 100

tmcScalar(reg[6],1.000000000000000e+002);

tmcAssign(gamma,reg[6]);
//statement here,line 34

// % Lines 35--35:
//   thresh = tol*100;  % zero singular threshold, default = 100*tol


tmcScalar(reg[9],1.000000000000000e+002);
tmcMul(reg[10],tol,reg[9]);

tmcAssign(thresh,reg[10]);
//statement here,line 35

// % Lines 36--36:
//   drop = 5.0d-5;

tmcScalar(reg[12],5.000000000000000e-005);

tmcAssign(drop,reg[12]);
//statement here,line 36

// % Lines 37--39:
//   

//  % make the polynomial monic

//   if p(1) == 0, p = p(min(find(p)):n+1); n = length(p)-1; end;


tmcScalar(reg[15],1.000000000000000e+000);
tmcGetByIndex(reg[16],p,1,reg[15]);
tmcScalar(reg[17],0.000000000000000e+000);
tmcEq(reg[18],reg[16],reg[17]);
if(tmcIsFalse(reg[18])) goto label_5; // goto to the end of the clause if the expression is false


//CALL function
tmcReallocRegister(reg[21]);
tmcReallocRegister(reg[22]);
tmcReallocRegister(reg[23]);
tmcfind(1,1, reg[21], reg[22], reg[23], p,NULL,NULL);
//CALL function
tmcReallocRegister(reg[24]);
tmcReallocRegister(reg[25]);
tmcmin(1,1, reg[24], reg[25], reg[21],NULL,NULL);

tmcScalar(reg[27],1.000000000000000e+000);
tmcAdd(reg[28],n,reg[27]);
tmcCreateColonBaseLimit(reg[29],reg[24],reg[28]);
tmcGetByIndex(reg[30],p,1,reg[29]);

tmcAssign(p,reg[30]);
//statement here,line 39


//CALL function
tmcReallocRegister(reg[33]);
tmclength(1,1, reg[33], p);
tmcScalar(reg[34],1.000000000000000e+000);
tmcSub(reg[35],reg[33],reg[34]);

tmcAssign(n,reg[35]);
//statement here,line 39

goto label_4; //branch to end IF
label_5: ; //end IF clause
label_4: ; //end IF
//statement here,line 39

// % Lines 40--40:
//   if p(1) ~= 1, p = p/(p(1)); end; 


tmcScalar(reg[38],1.000000000000000e+000);
tmcGetByIndex(reg[39],p,1,reg[38]);
tmcScalar(reg[40],1.000000000000000e+000);
tmcNe(reg[41],reg[39],reg[40]);
if(tmcIsFalse(reg[41])) goto label_7; // goto to the end of the clause if the expression is false


tmcScalar(reg[44],1.000000000000000e+000);
tmcGetByIndex(reg[45],p,1,reg[44]);
tmcDiv(reg[46],p,reg[45]);

tmcAssign(p,reg[46]);
//statement here,line 40

goto label_6; //branch to end IF
label_7: ; //end IF clause
label_6: ; //end IF
//statement here,line 40

// % Lines 41--42:
//   

//   n = length(p)-1;    % get polynomial degree 


//CALL function
tmcReallocRegister(reg[49]);
tmclength(1,1, reg[49], p);
tmcScalar(reg[50],1.000000000000000e+000);
tmcSub(reg[51],reg[49],reg[50]);

tmcAssign(n,reg[51]);
//statement here,line 42

// % Lines 43--43:
//   q = polyder(p)/n;   % the derevative


//CALL function
tmcReallocRegister(reg[54]);
tmcReallocRegister(reg[55]);
tmcpolyder(1,1, reg[54], reg[55], p,NULL);

tmcDiv(reg[57],reg[54],n);

tmcAssign(q,reg[57]);
//statement here,line 43

// % Lines 44--45:
//   

//   ff = p; gg = q;   % back up the polynomial 



tmcAssign(ff,p);
//statement here,line 45



tmcAssign(gg,q);
//statement here,line 45

// % Lines 46--46:
//   nf = norm(ff,inf);  % the largest coefficient


//CALL function
tmcReallocRegister(reg[64]);
tmcinf(1,0, reg[64]);
//CALL function
tmcReallocRegister(reg[65]);
tmcnorm(1,2, reg[65], ff, reg[64]);

tmcAssign(nf,reg[65]);
//statement here,line 46

// % Lines 47--48:
//   

//   mx = n; wtol = tol; s0 = 0; s = 0; wthrh = thresh;



tmcAssign(mx,n);
//statement here,line 48



tmcAssign(wtol,tol);
//statement here,line 48

tmcScalar(reg[71],0.000000000000000e+000);

tmcAssign(s0,reg[71]);
//statement here,line 48

tmcScalar(reg[73],0.000000000000000e+000);

tmcAssign(s,reg[73]);
//statement here,line 48



tmcAssign(wthrh,thresh);
//statement here,line 48

// % Lines 49--50:
//   

//   k = n;            % the degree of working polynomial



tmcAssign(k,n);
//statement here,line 50

// % Lines 51--53:
//   while k >= 1 

//       if k == 1   % the polynomial is linear, GCD = 1

//           h = 1; u = f; v = 1; m = 1;

label_8: ; //WHILE expression

tmcScalar(reg[80],1.000000000000000e+000);
tmcGe(reg[81],k,reg[80]);
if(tmcIsFalse(reg[81])) goto label_10; // goto to the exit of the while if the expression is false

tmcScalar(reg[83],1.000000000000000e+000);
tmcEq(reg[84],k,reg[83]);
if(tmcIsFalse(reg[84])) goto label_12; // goto to the end of the clause if the expression is false
tmcScalar(reg[85],1.000000000000000e+000);

tmcAssign(h,reg[85]);
//statement here,line 53



tmcAssign(u,f);
//statement here,line 53

tmcScalar(reg[89],1.000000000000000e+000);

tmcAssign(v,reg[89]);
//statement here,line 53

tmcScalar(reg[91],1.000000000000000e+000);

tmcAssign(m,reg[91]);
//statement here,line 53

// % Lines 54--56:
//       else

//          for m = 1:k

//             A = sylves(ff,gg,m);

goto label_11; //branch to end IF
label_12: ; //end IF clause
tmcScalar(reg[93],1.000000000000000e+000);

tmcCreateColonBaseLimit(reg[95],reg[93],k);
tmcForIterInit(reg[96],reg[95],m);
label_16: ; //FOR begin
if(tmcForIterNext(reg[96],reg[95])) goto label_15; // exit for



//CALL function
tmcReallocRegister(reg[100]);
tmcsylves(1,3, reg[100], ff, gg, m);

tmcAssign(A,reg[100]);
//statement here,line 56

// % Lines 57--57:
//             s0 = s;



tmcAssign(s0,s);
//statement here,line 57

// % Lines 58--59:
//            

//             [s,x] = zminsv(A,tol);



//CALL function
tmcReallocRegister(reg[106]);
tmcReallocRegister(reg[107]);
tmczminsv(2,2, reg[106], reg[107], A, tol);

tmcAssign(s,reg[106]);

tmcAssign(x,reg[107]);
//statement here,line 59

// % Lines 60--63:
//             

//             %fprintf('s. value %g,%g,%g\n',m,k,s);

//             if s < wthrh*nf | m == mx | s < drop*s0

//                 u0 = x(1:m+1)'/x(1); v0 = x(m+2:length(x))'/x(m+2);




tmcMul(reg[113],wthrh,nf);
tmcLt(reg[114],s,reg[113]);


tmcEq(reg[117],m,mx);
tmcOrScalar(reg[118],reg[114],reg[117]);



tmcMul(reg[122],drop,s0);
tmcLt(reg[123],s,reg[122]);
tmcOrScalar(reg[124],reg[118],reg[123]);
if(tmcIsFalse(reg[124])) goto label_18; // goto to the end of the clause if the expression is false

tmcScalar(reg[126],1.000000000000000e+000);

tmcScalar(reg[128],1.000000000000000e+000);
tmcAdd(reg[129],m,reg[128]);
tmcCreateColonBaseLimit(reg[130],reg[126],reg[129]);
tmcGetByIndex(reg[131],x,1,reg[130]);
tmcTranspose(reg[132],reg[131]);

tmcScalar(reg[134],1.000000000000000e+000);
tmcGetByIndex(reg[135],x,1,reg[134]);
tmcDiv(reg[136],reg[132],reg[135]);

tmcAssign(u0,reg[136]);
//statement here,line 63



tmcScalar(reg[140],2.000000000000000e+000);
tmcAdd(reg[141],m,reg[140]);

//CALL function
tmcReallocRegister(reg[143]);
tmclength(1,1, reg[143], x);
tmcCreateColonBaseLimit(reg[144],reg[141],reg[143]);
tmcGetByIndex(reg[145],x,1,reg[144]);
tmcTranspose(reg[146],reg[145]);


tmcScalar(reg[149],2.000000000000000e+000);
tmcAdd(reg[150],m,reg[149]);
tmcGetByIndex(reg[151],x,1,reg[150]);
tmcDiv(reg[152],reg[146],reg[151]);

tmcAssign(v0,reg[152]);
//statement here,line 63

// % Lines 64--64:
//                 B = cauchymt(u0,length(ff)-length(u0)+1);



//CALL function
tmcReallocRegister(reg[156]);
tmclength(1,1, reg[156], ff);

//CALL function
tmcReallocRegister(reg[158]);
tmclength(1,1, reg[158], u0);
tmcSub(reg[159],reg[156],reg[158]);
tmcScalar(reg[160],1.000000000000000e+000);
tmcAdd(reg[161],reg[159],reg[160]);
//CALL function
tmcReallocRegister(reg[162]);
tmccauchymt(1,2, reg[162], u0, reg[161]);

tmcAssign(B,reg[162]);
//statement here,line 64

// % Lines 65--65:
//                 g0 = scalsq(B,ff'); % scaled least squares solver



tmcTranspose(reg[166],ff);
//CALL function
tmcReallocRegister(reg[167]);
tmcscalsq(1,2, reg[167], B, reg[166],NULL);

tmcAssign(g0,reg[167]);
//statement here,line 65

// % Lines 66--66:
//                 g0 = g0'/g0(1);


tmcTranspose(reg[170],g0);

tmcScalar(reg[172],1.000000000000000e+000);
tmcGetByIndex(reg[173],g0,1,reg[172]);
tmcDiv(reg[174],reg[170],reg[173]);

tmcAssign(g0,reg[174]);
//statement here,line 66

// % Lines 67--67:
//                 uuu = conv(g0,u0)-ff; vvv = conv(g0,v0)-gg;



//CALL function
tmcReallocRegister(reg[178]);
tmcconv(1,2, reg[178], g0, u0);

tmcSub(reg[180],reg[178],ff);

tmcAssign(uuu,reg[180]);
//statement here,line 67



//CALL function
tmcReallocRegister(reg[184]);
tmcconv(1,2, reg[184], g0, v0);

tmcSub(reg[186],reg[184],gg);

tmcAssign(vvv,reg[186]);
//statement here,line 67

// % Lines 68--68:
//                 [h,u,v,rec] = gcdgn(ff, gg, g0, u0, v0);






//CALL function
tmcReallocRegister(reg[193]);
tmcReallocRegister(reg[194]);
tmcReallocRegister(reg[195]);
tmcReallocRegister(reg[196]);
tmcgcdgn(4,5, reg[193], reg[194], reg[195], reg[196], ff, gg, g0, u0, v0);

tmcAssign(h,reg[193]);

tmcAssign(u,reg[194]);

tmcAssign(v,reg[195]);

tmcAssign(rec,reg[196]);
//statement here,line 68

// % Lines 69--70:
//                 if rec < wtol | m == mx

//                     wtol = max([wtol,rec*gamma]); 



tmcLt(reg[203],rec,wtol);


tmcEq(reg[206],m,mx);
tmcOrScalar(reg[207],reg[203],reg[206]);
if(tmcIsFalse(reg[207])) goto label_20; // goto to the end of the clause if the expression is false



tmcMul(reg[211],rec,gamma);
tmcCollectColumns(reg[212],2,wtol,reg[211]);
tmcCollectRows(reg[213],1,reg[212]);
//CALL function
tmcReallocRegister(reg[214]);
tmcReallocRegister(reg[215]);
tmcmax(1,1, reg[214], reg[215], reg[213],NULL,NULL);

tmcAssign(wtol,reg[214]);
//statement here,line 70

// % Lines 71--71:
//                     wthrh = max([wthrh,(s/nf)*100]);




tmcDiv(reg[220],s,nf);
tmcScalar(reg[221],1.000000000000000e+002);
tmcMul(reg[222],reg[220],reg[221]);
tmcCollectColumns(reg[223],2,wthrh,reg[222]);
tmcCollectRows(reg[224],1,reg[223]);
//CALL function
tmcReallocRegister(reg[225]);
tmcReallocRegister(reg[226]);
tmcmax(1,1, reg[225], reg[226], reg[224],NULL,NULL);

tmcAssign(wthrh,reg[225]);
//statement here,line 71

// % Lines 72--72:
//                     break; 

goto label_15; //break to WHILE exit
//statement here,line 72

// % Lines 73--73:
//                 end;

goto label_19; //branch to end IF
label_20: ; //end IF clause
label_19: ; //end IF
//statement here,line 73

// % Lines 74--74:
//             end;

goto label_17; //branch to end IF
label_18: ; //end IF clause
label_17: ; //end IF
//statement here,line 74

// % Lines 75--75:
//          end;

label_14: ; //FOR end
goto label_16; //branch to FOR begin
label_15: ; //FOR exit
//statement here,line 75

// % Lines 76--76:
//       end;

label_13: ; //end IF clause
label_11: ; //end IF
//statement here,line 76

// % Lines 77--78:
//       if k == n

//           z = roots(u); l = ones(m,1); 



tmcEq(reg[230],k,n);
if(tmcIsFalse(reg[230])) goto label_22; // goto to the end of the clause if the expression is false

//CALL function
tmcReallocRegister(reg[232]);
tmcroots(1,1, reg[232], u);

tmcAssign(z,reg[232]);
//statement here,line 78


tmcScalar(reg[235],1.000000000000000e+000);
//CALL function
tmcReallocRegister(reg[236]);
tmcones(1,2, reg[236], m, reg[235]);

tmcAssign(l,reg[236]);
//statement here,line 78

// % Lines 79--79:
//           if m == 1, l = [n];  break; end;


tmcScalar(reg[239],1.000000000000000e+000);
tmcEq(reg[240],m,reg[239]);
if(tmcIsFalse(reg[240])) goto label_24; // goto to the end of the clause if the expression is false

tmcCollectColumns(reg[242],1,n);
tmcCollectRows(reg[243],1,reg[242]);

tmcAssign(l,reg[243]);
//statement here,line 79

goto label_10; //break to WHILE exit
//statement here,line 79

goto label_23; //branch to end IF
label_24: ; //end IF clause
label_23: ; //end IF
//statement here,line 79

// % Lines 80--81:
//       else

//           t = roots(u);

goto label_21; //branch to end IF
label_22: ; //end IF clause

//CALL function
tmcReallocRegister(reg[246]);
tmcroots(1,1, reg[246], u);

tmcAssign(t,reg[246]);
//statement here,line 81

// % Lines 82--83:
//           for j_ = 1:m

//               [s,jj] = min(abs(z-t(j_))); l(jj) = l(jj)+1;

tmcScalar(reg[248],1.000000000000000e+000);

tmcCreateColonBaseLimit(reg[250],reg[248],m);
tmcForIterInit(reg[251],reg[250],j_);
label_28: ; //FOR begin
if(tmcForIterNext(reg[251],reg[250])) goto label_27; // exit for



tmcGetByIndex(reg[255],t,1,j_);
tmcSub(reg[256],z,reg[255]);
//CALL function
tmcReallocRegister(reg[257]);
tmcabs(1,1, reg[257], reg[256]);
//CALL function
tmcReallocRegister(reg[258]);
tmcReallocRegister(reg[259]);
tmcmin(2,1, reg[258], reg[259], reg[257],NULL,NULL);

tmcAssign(s,reg[258]);

tmcAssign(jj,reg[259]);
//statement here,line 83



tmcGetByIndex(reg[264],l,1,jj);
tmcScalar(reg[265],1.000000000000000e+000);
tmcAdd(reg[266],reg[264],reg[265]);


tmcGetRefByIndex(pRefHelper,l,1,jj);
tmcAssign(pRefHelper,reg[266]);
//statement here,line 83

// % Lines 84--84:
//           end;

label_26: ; //FOR end
goto label_28; //branch to FOR begin
label_27: ; //FOR exit
//statement here,line 84

// % Lines 85--85:
//           if m == 1, l(jj) = l(jj) + k - 1; end;


tmcScalar(reg[270],1.000000000000000e+000);
tmcEq(reg[271],m,reg[270]);
if(tmcIsFalse(reg[271])) goto label_30; // goto to the end of the clause if the expression is false


tmcGetByIndex(reg[274],l,1,jj);

tmcAdd(reg[276],reg[274],k);
tmcScalar(reg[277],1.000000000000000e+000);
tmcSub(reg[278],reg[276],reg[277]);


tmcGetRefByIndex(pRefHelper,l,1,jj);
tmcAssign(pRefHelper,reg[278]);
//statement here,line 85

goto label_29; //branch to end IF
label_30: ; //end IF clause
label_29: ; //end IF
//statement here,line 85

// % Lines 86--86:
//       end;

label_25: ; //end IF clause
label_21: ; //end IF
//statement here,line 86

// % Lines 87--87:
//       if m > 1, k = k - m;  else, k = 0; break;  end;


tmcScalar(reg[282],1.000000000000000e+000);
tmcGt(reg[283],m,reg[282]);
if(tmcIsFalse(reg[283])) goto label_32; // goto to the end of the clause if the expression is false


tmcSub(reg[286],k,m);

tmcAssign(k,reg[286]);
//statement here,line 87

goto label_31; //branch to end IF
label_32: ; //end IF clause
tmcScalar(reg[288],0.000000000000000e+000);

tmcAssign(k,reg[288]);
//statement here,line 87

goto label_10; //break to WHILE exit
//statement here,line 87

label_33: ; //end IF clause
label_31: ; //end IF
//statement here,line 87

// % Lines 88--89:
//       if k > 0 

//          f = h; g = polyder(f)/k; 


tmcScalar(reg[291],0.000000000000000e+000);
tmcGt(reg[292],k,reg[291]);
if(tmcIsFalse(reg[292])) goto label_35; // goto to the end of the clause if the expression is false


tmcAssign(f,h);
//statement here,line 89


//CALL function
tmcReallocRegister(reg[296]);
tmcReallocRegister(reg[297]);
tmcpolyder(1,1, reg[296], reg[297], f,NULL);

tmcDiv(reg[299],reg[296],k);

tmcAssign(g,reg[299]);
//statement here,line 89

// % Lines 90--90:
//          ff = f; gg = g; nf = norm(ff);  mx = m;



tmcAssign(ff,f);
//statement here,line 90



tmcAssign(gg,g);
//statement here,line 90


//CALL function
tmcReallocRegister(reg[306]);
tmcnorm(1,1, reg[306], ff,NULL);

tmcAssign(nf,reg[306]);
//statement here,line 90



tmcAssign(mx,m);
//statement here,line 90

// % Lines 91--91:
//       end;

goto label_34; //branch to end IF
label_35: ; //end IF clause
label_34: ; //end IF
//statement here,line 91

// % Lines 92--92:
//   end;

label_9: ; //end WHILE
goto label_8; //branch to test WHILE expression
label_10: ; //exit WHILE
//statement here,line 92

// % Lines 93--94:
//   

//   ff = [1];  ll = l;    % form the base polynomial

tmcScalar(reg[310],1.000000000000000e+000);
tmcCollectColumns(reg[311],1,reg[310]);
tmcCollectRows(reg[312],1,reg[311]);

tmcAssign(ff,reg[312]);
//statement here,line 94



tmcAssign(ll,l);
//statement here,line 94

// % Lines 95--95:
//   mm = max(ll); 


//CALL function
tmcReallocRegister(reg[317]);
tmcReallocRegister(reg[318]);
tmcmax(1,1, reg[317], reg[318], ll,NULL,NULL);

tmcAssign(mm,reg[317]);
//statement here,line 95

// % Lines 96--96:
//   [yy,jj] = sort(abs(z));   y = z(jj); ll = l(jj);


//CALL function
tmcReallocRegister(reg[321]);
tmcabs(1,1, reg[321], z);
//CALL function
tmcReallocRegister(reg[322]);
tmcReallocRegister(reg[323]);
tmcsort(2,1, reg[322], reg[323], reg[321],NULL);

tmcAssign(yy,reg[322]);

tmcAssign(jj,reg[323]);
//statement here,line 96



tmcGetByIndex(reg[328],z,1,jj);

tmcAssign(y,reg[328]);
//statement here,line 96



tmcGetByIndex(reg[332],l,1,jj);

tmcAssign(ll,reg[332]);
//statement here,line 96

// % Lines 97--98:
//   for kk = 1:mm

//       id = find(ll>0);

tmcScalar(reg[334],1.000000000000000e+000);

tmcCreateColonBaseLimit(reg[336],reg[334],mm);
tmcForIterInit(reg[337],reg[336],kk);
label_38: ; //FOR begin
if(tmcForIterNext(reg[337],reg[336])) goto label_37; // exit for

tmcScalar(reg[339],0.000000000000000e+000);
tmcGt(reg[340],ll,reg[339]);
//CALL function
tmcReallocRegister(reg[341]);
tmcReallocRegister(reg[342]);
tmcReallocRegister(reg[343]);
tmcfind(1,1, reg[341], reg[342], reg[343], reg[340],NULL,NULL);

tmcAssign(id,reg[341]);
//statement here,line 98

// % Lines 99--99:
//       ff = conv(ff,polyr2p(y(id)));




tmcGetByIndex(reg[348],y,1,id);
//CALL function
tmcReallocRegister(reg[349]);
tmcpolyr2p(1,1, reg[349], reg[348]);
//CALL function
tmcReallocRegister(reg[350]);
tmcconv(1,2, reg[350], ff, reg[349]);

tmcAssign(ff,reg[350]);
//statement here,line 99

// % Lines 100--100:
//       ll = ll - 1;


tmcScalar(reg[353],1.000000000000000e+000);
tmcSub(reg[354],ll,reg[353]);

tmcAssign(ll,reg[354]);
//statement here,line 100

// % Lines 101--101:
//   end;

label_36: ; //FOR end
goto label_38; //branch to FOR begin
label_37: ; //FOR exit
//statement here,line 101

// % Lines 102--102:
//   z = [z, l];   % solution



tmcCollectColumns(reg[358],2,z,l);
tmcCollectRows(reg[359],1,reg[358]);

tmcAssign(z,reg[359]);
//statement here,line 102

// % Lines 103--104:
//

//   w = ones(1,length(p));

tmcScalar(reg[361],1.000000000000000e+000);

//CALL function
tmcReallocRegister(reg[363]);
tmclength(1,1, reg[363], p);
//CALL function
tmcReallocRegister(reg[364]);
tmcones(1,2, reg[364], reg[361], reg[363]);

tmcAssign(w,reg[364]);
//statement here,line 104

// % Lines 105--105:
//   for j_ = 1:length(p), if abs(p(j_))>1, w(j_)=1/abs(p(j_));end,end;

tmcScalar(reg[366],1.000000000000000e+000);

//CALL function
tmcReallocRegister(reg[368]);
tmclength(1,1, reg[368], p);
tmcCreateColonBaseLimit(reg[369],reg[366],reg[368]);
tmcForIterInit(reg[370],reg[369],j_);
label_41: ; //FOR begin
if(tmcForIterNext(reg[370],reg[369])) goto label_40; // exit for


tmcGetByIndex(reg[373],p,1,j_);
//CALL function
tmcReallocRegister(reg[374]);
tmcabs(1,1, reg[374], reg[373]);
tmcScalar(reg[375],1.000000000000000e+000);
tmcGt(reg[376],reg[374],reg[375]);
if(tmcIsFalse(reg[376])) goto label_43; // goto to the end of the clause if the expression is false
tmcScalar(reg[377],1.000000000000000e+000);


tmcGetByIndex(reg[380],p,1,j_);
//CALL function
tmcReallocRegister(reg[381]);
tmcabs(1,1, reg[381], reg[380]);
tmcDiv(reg[382],reg[377],reg[381]);


tmcGetRefByIndex(pRefHelper,w,1,j_);
tmcAssign(pRefHelper,reg[382]);
//statement here,line 105

goto label_42; //branch to end IF
label_43: ; //end IF clause
label_42: ; //end IF
//statement here,line 105

label_39: ; //FOR end
goto label_41; //branch to FOR begin
label_40: ; //FOR exit
//statement here,line 105

// % Lines 106--106:
//   bkerr = norm( (ff-p).*w , inf );



tmcSub(reg[387],ff,p);

tmcMulScalar(reg[389],reg[387],w);
//CALL function
tmcReallocRegister(reg[390]);
tmcinf(1,0, reg[390]);
//CALL function
tmcReallocRegister(reg[391]);
tmcnorm(1,2, reg[391], reg[389], reg[390]);

tmcAssign(bkerr,reg[391]);
//statement here,line 106

// % Lines 107--108:
//   

//   
label_1: ; //end Function
FINALLY
tmcFreeLocalVar(w);
tmcFreeLocalVar(id);
tmcFreeLocalVar(kk);
tmcFreeLocalVar(y);
tmcFreeLocalVar(yy);
tmcFreeLocalVar(mm);
tmcFreeLocalVar(ll);
tmcFreeLocalVar(g);
tmcFreeLocalVar(jj);
tmcFreeLocalVar(j_);
tmcFreeLocalVar(t);
tmcFreeLocalVar(l);
tmcFreeLocalVar(rec);
tmcFreeLocalVar(vvv);
tmcFreeLocalVar(uuu);
tmcFreeLocalVar(g0);
tmcFreeLocalVar(B);
tmcFreeLocalVar(v0);
tmcFreeLocalVar(u0);
tmcFreeLocalVar(x);
tmcFreeLocalVar(A);
tmcFreeLocalVar(m);
tmcFreeLocalVar(v);
tmcFreeLocalVar(f);
tmcFreeLocalVar(u);
tmcFreeLocalVar(h);
tmcFreeLocalVar(k);
tmcFreeLocalVar(wthrh);
tmcFreeLocalVar(s);
tmcFreeLocalVar(s0);
tmcFreeLocalVar(wtol);
tmcFreeLocalVar(mx);
tmcFreeLocalVar(nf);
tmcFreeLocalVar(gg);
tmcFreeLocalVar(ff);
tmcFreeLocalVar(q);
tmcFreeLocalVar(n);
tmcFreeLocalVar(drop);
tmcFreeLocalVar(thresh);
tmcFreeLocalVar(gamma);
tmcFreeLocalVar(tol);
tmcFreeLocalVar(p);
tmcFreeRegFrame(reg);

TMC_DBG_POP_STACK_VAR(46);

ENDFINALLY
}

//FUNCTION DEFINITION ENDED
//statement here,line 108

// % Lines 109--109:
