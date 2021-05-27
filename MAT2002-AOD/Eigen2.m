clc
clear

A = input('Enter the matrix: ');

%Determinant
detA = det(A);
disp('Determinant of A: ')
disp(detA)

%Eigenvalues
EV = eig(A);
disp('Eigenvalues: ')
disp(EV)

%Product of eigenvalues
prev = prod(EV);
disp('Product of Eigenvalues: ')
disp(prev)

if detA == int8(prev)
    disp('The product of eigenvalues of matrix A is equal to its determinant.')
else
    disp('There is an error')
end
