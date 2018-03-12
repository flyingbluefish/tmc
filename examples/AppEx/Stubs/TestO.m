function y=TestO(x) 
%addpath('D:\Data_D\HSKOST\TMC\TMC_forLibre\examples\AppSIMO\MexSRC\MexDLLS')
%addpath('D:\Data_D\HSKOST\TMC\TMC_forLibre\examples\AppSIMO\MatSRC')
global ite;
A=[1,2;3,4];
B=[1;3];
C =A*B;
disp(C\B);
return;

x=[1:100];
summa = sum(x);
disp(summa);


x = [1:100];
S=cell(2,1);
S{1}.r=x;
S{2}.r=x*2;
S{end} = 44;
disp(['R=',num2str(S{end-1}.r(end-1))]);
disp(S);
K=struct;
K.y=[1:100];
disp(K(end).y(end-3));



a = -5;
b =  50;
Len =x;
e = logspace( -5, -2,Len);
e = fliplr(e);
y = zeros(1,Len);
x=y;
z=y;
for k=1:length(e)
    ep1  = e(k);
    S=solvemyeq(a,b,ep1);
    if ~isempty(S)
        y(k) = S.y0; x(k) = S.x0;
        z(k) = ite;
    end
end
save('res.mat','y','x','z');
%fp=fopen('res.txt');
%fprintf(fp,'done Ok');
%fclose(fp);
return;

figure(10);
subplot(3,1,1);
plot(e,y,'b');grid on;
subplot(3,1,2);
plot(e,x,'r');grid on;
subplot(3,1,3);
plot(e,z,'g');grid on;

disp('done');

