clc
clear all
A = randi(10,10,10)
x = randi(10,10,1)
v = zeros(10,1);
for i = 1:10 
    for j = 1:10
        v(i) = v(i) + A(i,j)*x(j);
    end
end
disp(v)
v1 = sum(A*x)
v2 = A*x
v3 = x'*A

B = A + 1

V = randi(7,7,7)
V1 = V.^2
V2 = V^2
V3 = V/4


v = randi(10,7,1)
w = randi(10,7,1)
z = 0;
for i = 1:7
  z = z + v(i) * w(i);
end
disp(z)
z1 = sum(v.*w)
z2 = v'*w
z3 = v*w'
z4 = v.*w