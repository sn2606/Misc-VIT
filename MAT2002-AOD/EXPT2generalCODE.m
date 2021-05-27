clear all
clc
syms x
A = input('Enter a square matrix: ');
s = length(A);
eq1 = det(A-x*eye(s));
eigenvalues = solve(eq1,x);
for i = 1:s
    null(A-eigenvalues(i)*eye(s))
end

%Verification of Cayley-Hamilton theorem

cf = poly(A);
n = length(cf);
CHT = cf(1)*A^(n-1);

for i=2:n
    CHT = CHT + cf(i)*A^(n-1);
end

disp('RHS of the CHT: ')
disp(round(CHT))