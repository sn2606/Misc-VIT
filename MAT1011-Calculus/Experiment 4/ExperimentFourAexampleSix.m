clc
clear all
syms x y z
viewSolidone(z,0+0*x+0*y,x^2+y^2,x,y/2,sqrt(y),y,0,4)
int(int(x^2+y^2,x,y/2,sqrt(y)),y,0,4)
