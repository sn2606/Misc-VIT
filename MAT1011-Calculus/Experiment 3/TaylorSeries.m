% Taylor Series for a two variable function
clc
clearvars
close all
syms x y
f = input('Enter the function f(x,y): ');
I = input('Enter the point [a,b] at which Taylor Series is sought: ');
a = I(1); b = I(2);
n = input('Enter the order of series: ');
tayser = taylor(f, [x,y], [a,b], 'order', n);
disp(tayser)
subplot(1,2,1);
ezsurf(f);
subplot(1,2,2);
ezsurf(tayser);