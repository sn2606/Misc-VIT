clear vars
close all
clc
syms x y
f = input('Enter the function: ');
I = input('Enter the interval [a,b] around which Taylor is sought: ');
a = I(1); b = I(2); 
n = input('Enter the order: ');
tayser = taylor(f,[x,y],[a,b],'order',n);
subplot(1,2,1);
ezsurf(f)
subplot(1,2,2);
ezsurf(tayser)