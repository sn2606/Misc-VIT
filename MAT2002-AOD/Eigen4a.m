clc
clear

A = input('Enter the Matrix: ');

%Sum of diagonal elements is trace of the matrix
B = trace(A);
disp('Trace of matrix A:')
disp(B)

%Eigenvalues 
EV = eig(A);
disp('Eigenvalues')
disp(EV)

%Sum of Eigen Values
S = sum(EV);
disp('Sum of Eigenvalues:')
disp(S)

if B == int8(S)
    disp('The sum of eigenvalues of a matrix is equal to the trace of the matrix')
else
    disp('Error')
end

