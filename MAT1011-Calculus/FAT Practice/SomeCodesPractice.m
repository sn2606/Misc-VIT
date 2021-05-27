clc
close all
clear vars
syms x y z
int(int(16-x^2-2*y^2,x,0,2),y,0,2)
viewSolidone(z,0+0*x+0*y,16-x^2-2*y^2,x,0+0*y,2+0*y,y,0,2)