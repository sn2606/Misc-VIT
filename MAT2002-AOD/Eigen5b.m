clc
clear
syms b c x

A = input('Enter the 2 X 2 matrix: ');
n = input('Enter the power desired: ');

%Eigen values of A
EV = eig(A);
disp('Eigen values of A:')
disp(EV)

S = b*x + c == x^n ;
eq1 = subs(S,x,EV(1));
eq2 = subs(S,x,EV(2));

[K,B] = equationsToMatrix([eq1,eq2],[b,c]);
disp('K:')
disp(K)
disp('B:')
disp(B)

X = linsolve(K,B);
disp('X:')
disp(X)

H = X(1)*A + X(2)*eye(2);
disp('A^n:')
disp(H)





