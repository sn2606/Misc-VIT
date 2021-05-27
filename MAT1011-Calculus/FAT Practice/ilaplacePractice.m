clear all
clc
syms s 
F = input('Enter the function F(s): ');
f = ilaplace(F);
disp(['f(t) = ',char(f)])