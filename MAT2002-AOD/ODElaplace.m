clear
close all
clc
syms s t 
assume ( s , 'positive' )
n= input ('Enter the order of linear equation: ');
b= input (['Enter the coefficients in 1 X ' ,num2str(n + 1),' matrix: ']) ;
c = input (['Enter the initial condition in 1 X ' ,num2str(n), ' matrix : ']) ;
N= 0 ; D = 0 ;
for i = 1 : n
    for j = 1 : n-i+1
        N=N+ s^( n-j)*b(i)*c(j);
    end
    D = D+b(i)*s^(n-i+1);
end
D=D+b(n+1);
f(t) = input('Enter the RHS f(t) = ');
F(s) = laplace(f) ;
Ys = (N+F )/D ;
y= simplify(ilaplace(Ys));
disp(['q(t) = ' ,char(y)])

%current in the circuit
it = diff(y,t);
disp('i(t) = ')
disp(it)



