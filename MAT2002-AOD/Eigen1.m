clc
clear
A = input('Enter the matrix: ');

%Characteristic Equation
cf = poly(A);
disp('Characteristic Equations')
disp(cf)

%Eigenvalues
EV = eig(A);
disp('Eigenvalues')
disp(EV)

%Eigenvectors
[P D] = eig(A);
disp('Eigenvectors')
disp(P)
