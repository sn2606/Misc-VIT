clc
clear all
close all
syms x a0 
syms a1 a2 a3
a = [a0 a1 a2 a3];
y = sum(a.*(x).^[0:3]);

c = input('Enter the coefficients in an array: ');
dy = diff(y);
d2y = diff(dy);
f = c(1)*d2y + c(2)*dy + c(3)*y;
gde = collect(f,x);
cof = coeffs(gde,x);

A2 = solve(cof(1),a2);
A3 = solve(cof(2),a3);

y = subs(y,a2,A2);
y = subs(y,a3,A3);
y = coeffs(y,[a1 a0]);
disp('Solution is: ')
disp(['y = A(',char(y(1)),'+...)+B(',char(y(2)),'+...)'])