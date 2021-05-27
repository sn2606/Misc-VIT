clc
clear

A = input('Enter the matrix: ');

%Inverse of matrix A
B = inv(A);
disp('Inverse of matrix A:')
disp(B)

%Eigen values of A
EV1 = eig(A);
disp('Eigen values of A:')
disp(EV1)

%Eigen values of B
EV2 = eig(B);
disp('Eigen values of B:')
disp(EV2)

%One by Lambda
n = length(EV1);
L = zeros(n,1);
for i = 1:n
    L(i) = 1/EV1(i);
end
disp('One by Lambda')
disp(L)


