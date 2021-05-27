clear all
clc
syms t
f = input('Enter the function of t: ');
F = laplace(f);
F = simplify(F);
disp(['L{',char(f),'}=',char(F)]);