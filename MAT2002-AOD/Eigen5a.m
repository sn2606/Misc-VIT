clc
clear

A = input('Enter the Matrix: ');

cf = poly(A);
n = length(cf);

%To find the inverse
INV = cf(1)*A^(n-2);
for i=2:n-1
    INV = INV + cf(i)*A^(n-i-1);
end
INV = INV/(-cf(n));
disp('Inverse of A: ')
disp(INV)