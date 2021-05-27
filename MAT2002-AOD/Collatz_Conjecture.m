clc
clear all
close all
syms n m i
n = input("Enter the number: ");
m = n;
i = 0;
while m>1
    if mod(m,2) == 0
        m = n/2;
        n = m;
    else
        m = 3*n + 1;
        n = m;
    end
    i = i + 1;
end
disp('No. of steps are: ')
disp(i)
