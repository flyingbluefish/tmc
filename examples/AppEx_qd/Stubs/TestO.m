function y=TestO(x) 
% This example uses MultRoot by ZHONGGANG ZENG
% References:
% [1] ZHONGGANG ZENG, "COMPUTING MULTIPLE ROOTS OF INEXACT POLYNOMIALS",
% MATHEMATICS OF COMPUTATION,
% Volume 74, Number 250, Pages 869-903
% S 0025-5718(04)01692-8
% Article electronically published on July 22, 2004
% [2] ZHONGGANG ZENG, "MultRoot - A Matlab package computing polynomial roots and multiplicities"
% Journal ACM Transactions on Mathematical Software (TOMS), Volume 30 Issue 2, June 2004 , Pages 218-236



% www=load('D:\Data_D\HSKOST\TMC\qd_tmc\tmc_src-1.02\examples\AppEx_qd\testroot1.mat')
%figure(222);plot( real(www.xx),imag(www.xx),'r.',real(www.qxx),imag(www.qxx),'bo',real(roots(www.aa)),imag(roots(www.aa)),'gx');grid on;
% www=load('HH.mat');
% A=www.HH;
% B=www.B;
% disp(det(A));
% disp(det_qd(A));
% disp(eig(A));
% disp(eig_qd(A));
%disp(A\B);
%  disp(leftdivide_qd(A,B));
% return



ar = 0.00001;
ai  = 10;

x0 = ar + ai*j;
x1 = ar - ai*j;

va = [1, -2*ar,ar^2+ai^2];
vb = va;
vb = conv(vb,va);
vb = conv(vb,va);
vb = conv(vb,va);
 vb = conv(vb,va);
 vb = conv(vb,va);
 vb = conv(vb,va);
 vb = conv(vb,va);
 vb = conv(vb,va);
 
%   vb = conv(vb,va);
%  vb = conv(vb,va);
%  vb = conv(vb,va);

% aa=[1,909,367236,86545284,13111610526,1324272663126,...
%         89167692650484,3859687267585236,97457103506527209,1093685272684360901];



aa = vb;
xx =  roots( aa);
qxx =  roots_qd( aa);

disp('Roots=');
disp(xx);
for cnt=1:length(xx)
    yy(cnt) = polyval(aa,xx(cnt));    
end
disp('P(roots)=');
disp(yy);



disp('Quad Roots=');
disp(qxx);
for cnt=1:length(qxx)
    qyy(cnt) = polyval(aa,qxx(cnt));    
end


disp('***********************************************');
disp('Quad P(roots)=');
disp(qyy);
qerr = qxx - xx;
disp(qerr);

disp('Coeficcients: aa=');
disp(aa);

mqq = multroot(aa);
disp('multroots=');
disp(mqq);

save('testroot1.mat','aa','xx','qxx','yy','qyy','x0');



 