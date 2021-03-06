
function [z, bkerr] = gcdroot( p, tol)
%  
%  GCDROOT calculates the multiplicity structure and initial root 
%  approximation of a real polynomial p,
% 
%        p(x) = a_1 x^n + a_2 x^n-1 + ... + a_n x + a_n+1,
%
%  given by an (n+1)-row vector p = (a_1, ..., a_n+1) 
%
%  METHOD : for details, contact the author 
%
%             Zhonggang Zeng
%             Department of Mathematics
%             Northeastern Illinois University
%             Chicago, IL 60625
%          
%             email: zzeng@neiu.edu
%
%  INPUT :  p = polynomial coefficients. 
%           tol = zero remainder threshold; 
%                 default = 10^{-10}, set internally
%                 if no value is specified.
%
%  OUTPUT : z = roots of polynomial p and multiplicities:
%                  z(:,1) = all distinct roots
%                  z(:,2) = corresponding multiplicities
%           bkerr = backward error
%
%  CALL :   It is best to call pzero with only one argument as   
%               >> z = gcdroot(p). 
%
   if nargin == 1, tol = 1.e-10; end;
   gamma = 100;       % residual growth factor, default = 100
   thresh = tol*100;  % zero singular threshold, default = 100*tol
   drop = 5.0d-5;
   
  % make the polynomial monic
   if p(1) == 0, p = p(min(find(p)):n+1); n = length(p)-1; end;
   if p(1) ~= 1, p = p/(p(1)); end; 
   
   n = length(p)-1;    % get polynomial degree 
   q = polyder(p)/n;   % the derevative
   
   ff = p; gg = q;   % back up the polynomial 
   nf = norm(ff,inf);  % the largest coefficient
   
   mx = n; wtol = tol; s0 = 0; s = 0; wthrh = thresh;
   
   k = n;            % the degree of working polynomial
   while k >= 1 
       if k == 1   % the polynomial is linear, GCD = 1
           h = 1; u = f; v = 1; m = 1;
       else
          for m = 1:k
             A = sylves(ff,gg,m);
             s0 = s;
            
             [s,x] = zminsv(A,tol);
             
             %fprintf('s. value %g,%g,%g\n',m,k,s);
             if s < wthrh*nf | m == mx | s < drop*s0
                 u0 = x(1:m+1)'/x(1); v0 = x(m+2:length(x))'/x(m+2);
                 B = cauchymt(u0,length(ff)-length(u0)+1);
                 g0 = scalsq(B,ff'); % scaled least squares solver
                 g0 = g0'/g0(1);
                 uuu = conv(g0,u0)-ff; vvv = conv(g0,v0)-gg;
                 [h,u,v,rec] = gcdgn(ff, gg, g0, u0, v0);
                 if rec < wtol | m == mx
                     wtol = max([wtol,rec*gamma]); 
                     wthrh = max([wthrh,(s/nf)*100]);
                     break; 
                 end;
             end;
          end;
       end;
       if k == n
           z = roots(u); l = ones(m,1); 
           if m == 1, l = [n];  break; end;
       else
           t = roots(u);
           for j_ = 1:m
               [s,jj] = min(abs(z-t(j_))); l(jj) = l(jj)+1;
           end;
           if m == 1, l(jj) = l(jj) + k - 1; end;
       end;
       if m > 1, k = k - m;  else, k = 0; break;  end;
       if k > 0 
          f = h; g = polyder(f)/k; 
          ff = f; gg = g; nf = norm(ff);  mx = m;
       end;
   end;
   
   ff = [1];  ll = l;    % form the base polynomial
   mm = max(ll); 
   [yy,jj] = sort(abs(z));   y = z(jj); ll = l(jj);
   for kk = 1:mm
       id = find(ll>0);
       ff = conv(ff,polyr2p(y(id)));
       ll = ll - 1;
   end;
   z = [z, l];   % solution

   w = ones(1,length(p));
   for j_ = 1:length(p), if abs(p(j_))>1, w(j_)=1/abs(p(j_));end,end;
   bkerr = norm( (ff-p).*w , inf );
   
   