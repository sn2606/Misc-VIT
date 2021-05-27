clear all
clc
syms x y
f = input('Enter the given function in variable x: ');
x0 = input('Enter the x coordinate of point: ');
y0 = subs(f,x0);
fx = diff(f,x);
m = subs(fx,x,x0);
tangent = y0 + m*(x - x0);
t_line = y - tangent;
plotrange = [x0-3,x0+3];
ezplot(f,plotrange);
hold on
ezplot(tangent,plotrange);
title('Tangent line plot');
t = sprintf('The tangent to the curve y = %s at point (%d,%d) is y = %s',f,x0,y0,tangent);
disp(t)