clc
clear all
syms x y z
viewSolidone(z,0+0*x+0*y,16-x^2-2*y^2,x,0+0*y,2+0*y,y,0,2)
int(int(16-x^2-2*y^2,x,0,2),y,0,2)
