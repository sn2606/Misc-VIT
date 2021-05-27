clc
clear all
syms x y z
viewSolidone(z,0+0*x+0*y,sin(x)*cos(y),x,0+0*y,0.5*pi+0*y,y,0,0.5*pi)
int(int(sin(x)*cos(y),x,0,0.5*pi),y,0,0.5*pi)