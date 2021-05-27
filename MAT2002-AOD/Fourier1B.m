clear all
clc
syms t

x = input('Enter the equally spaced values of x: ');
y = input('Enter the values of y = f(x): ');
m = input('Enter the number of harmonics required: ');

n = length(x);
a = x(1); b = x(n);
h = x(2) - x(1);
L = (b-a+h)/2;
theta = pi*x/L;
a0 = (2/n)*sum(y);
Fx = a0/2;
x1 = linspace(a,b,100);

for i = 1:m
    an = (2/n)*sum(y.*cos(i*theta));
    bn = (2/n)*sum(y.*sin(i*theta));
    cn = sqrt(an^2 + bn^2);
    disp(cn)
    Fx = Fx + an*cos(i*pi*t/L) + bn*sin(i*pi*t/L);
    Fx = vpa(Fx,4);
    Fx1 = subs(Fx,t,x1);
end

Fx1 = subs(Fx,t,x1);
plot(x1,Fx1)
hold on
plot(x,y)
hold off
title(['Fourier Series with ',num2str(m),' harmonics'])
legend('Fourier Series','Function PLot')

disp(strcat('Fourier Series with ', num2str(m),' harmonics is: ',char(Fx)))