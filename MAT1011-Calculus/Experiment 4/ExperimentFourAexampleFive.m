clc
clear all
syms x y z
viewSolidone(z,0+0*x+0*y,y*sin(x*y),x,1+0*y,2+0*y,y,0,pi)
int(int(y*sin(x*y),x,1,2),y,0,pi)
