clear all
close all
clc
X = -4:4;
Y = X;
Z = X;
[x,y,z] = meshgrid(X,Y,Z);
[cx,cy,cz] = curl(x,y,z,-y,x,zeros(size(x)));
figure;
subplot(1,2,1);
quiver3(x,y,zeros(size(x)),cx,cy,cz,0);
title('3-d view of curl');
subplot(1,2,2);
quiver(x,y,-y,x);
title('2-d view of curl');