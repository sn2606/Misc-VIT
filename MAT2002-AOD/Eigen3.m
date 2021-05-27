clc
clear

A = input('Enter the Matrix: ');

%Verification of Cayley-Hamilton theorem
cf = poly(A);
n = length(cf);
CHT = cf(1)*A^(n-1);
for i=2:n
    CHT = CHT + cf(i)*A^(n-i);
end
disp('RHS of C-H Theorem: ')
disp(round(CHT))

%To find the inverse
INV = cf(1)*A^(n-2);
for i=2:n-1
    INV = INV + cf(i)*A^(n-i-1);
end
INV = INV/(-cf(n));
disp('Inverse of A: ')
disp(INV)
