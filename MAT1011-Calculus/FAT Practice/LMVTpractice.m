clear all;
clc;
syms x c;
f = input('Enter the function: ');
I = input('Enter the interval [a,b]: ');
a = I(1); b = I(2);
fa = subs(f,x,a); fb = subs(f,x,b);
df = diff(f,x); dfc = subs(df,x,c);
LM = dfc - (fb - fa)/(b - a);
c = solve(LM);
count = 0;
for i = 1:length(c)
    count = count + 1;
    tx(count) = c(i);
end
fprintf('The values of c between %d and %d which satisfy LMVT are x = ',a,b);
disp(double(tx));
xval = linspace(a,b,100);
yval = subs(f,x,xval);
m = subs(df,x,tx);
ty = subs(f,x,tx);
plot(xval,yval);
hold on;
secant_slope = (fb -fa)/(b - a);
secant = fb + secant_slope*(x - b);
sxval = xval;
syval = subs(secant,x,sxval);
plot(sxval,syval,'-r');
hold on;
for i = 1:length(tx)
    tangent = ty(i) + m(i)*(x - tx(i));
    txval = linspace(tx(i)-1,tx(i)+1,20);
    tyval = subs(tangent,x,txval);
    plot(txval,tyval,':k');
    hold on;
    plot(tx(i),ty(i),'^m');
end
hold off;
grid on;
legend('Function','Secant','Tangent');
title('DEMONSTRATION OF LAGRANGES MEAN VALUE THEOREM');