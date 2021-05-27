clc
clear

A = input('Enter the matrix: ');
m = input('Enter the positive integer m: ');

%Matrix A to the power m
B = A^m;
disp('Matrix A^m:')
disp(B)

%Eigen values of A
EV1 = eig(A);
disp('Eigen values of A:')
disp(EV1)

%Eigen values of B
EV2 = eig(B);
disp('Eigen values of A^m:')
disp(EV2)

%Lambda to the power m
n = length(EV1);
L = zeros(n,1);
for i = 1:n
    L(i) = EV1(i)^m;
end
disp('Lambda to the power m:')
disp(L)