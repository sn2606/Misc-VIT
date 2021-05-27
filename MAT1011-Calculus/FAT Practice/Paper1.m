clear all
clc
syms x c
f = input('Enter the function: ');
I = input('Enter the interval [a,b]: ');
a = I(1); b = I(2);
fa = subs(f,x,a); fb = subs(f,x,b);
df = diff(f,x); dfc = subs(f,x,c);
if fa == fb
    c = solve(dfc);
count = 0;
for i = 1:length(c)
    if c(i)>a && c(i)<b
        count = count + 1;
        r(count) = c(i);
    end
end
values = sprintf('The values between %f and %f of the function which satisfy rolles theorem are: ',a,b);
disp(values)
disp(r)
else
    disp('The function does not satisfy conditions for rolles theorem for given range.')
end
tval = subs(f,x,r);
xval = linspace(a,b,100);
yval = subs(f,x,xval);
plot(xval,yval)
[p,q] = size(xval);'
for i = 1:length(tval)
    hold on;
    plot(xval,tval*ones(p,q),'r');
    hold on;
    plot(r(i),tval(i),'ok');
end
legend('Function','Tangent');
title('Demonstration of Rolles theore');