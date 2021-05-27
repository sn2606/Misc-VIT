clc
clear all
syms x y z
syms x1 y1 z1
syms theta

A1=input('Enter coefficients in order x^2,y^2,z^2,yz,xz,xy: ');
a = A1(1); b = A1(2); c = A1(3);
f = 0.5*A1(4); g = 0.5*A1(5); h = 0.5*A1(6);

A = [a h g;h b f;g f c];

%n = input('Enter the power of A required: ');

[P D]=eig(A);
disp('Given Matrix (A) : ')
disp(A)
disp('Orthogonal Modal Matrix (P): ')
disp(P)
disp('Inverse of P : ')
PI=inv(P);
disp(PI)
disp('Diagonal Matrix:')
DM=round(inv(P)*A*P, 2);
disp(DM)
diA = diag(DM);
disp('The eigen values of the matrix are: ')
disp(diA)
disp(strcat('The eigen vector corresponding to l1 = ',num2str(diA(1))))
e1 = P(:,1) 
disp(strcat('The eigen vector corresponding to l2 = ',num2str(diA(2))))
e2 = P(:,2)
disp(strcat('The eigen vector corresponding to l3 = ',num2str(diA(3))))
e3 = P(:,3)

%Canonical form
CF = (diA(1))*(x1^2) + (diA(2))*(y1^2) + (diA(3))*(z1^2);
disp('Canonical form of equation is: ')
disp(CF)

%Orthogonal Transformation
disp('Matrix of transformation is (P): ')
disp(P)
disp('The transformation can be represented by: ')
disp('<x1,y1,z1> = P<x,y,z>')
disp('Where <x1,y1,z1> represents the new coordinate system and <x,y,z> represents the old coordinate system.')

%Angle of rotation
Trace = trace(P)
% R = 1 + 2*cos(theta);
% eqn = Trace == R;
% S = solve(eqn,theta);

theta = acos((Trace-1)/2);
disp('The angle of rotation is: ')
disp(strcat(num2str(theta),' radians'))

% nth power
% Dn = diA^n;
% An = PI*Dn*P;
% disp(strcat('The ', num2str(n), ' th power of A is:'))
% disp(An)