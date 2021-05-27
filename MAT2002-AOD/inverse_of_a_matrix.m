clear all
clc
P = [1 1 1;0 -1 2;-1 1 1];
Q = inv(P);
disp(Q)
A = [1 1 3;1 5 1;3 1 1];
S = Q*A*P;
disp(S)
X = P*(S^4)*Q;
disp(X)
C = A^4;
disp(C)