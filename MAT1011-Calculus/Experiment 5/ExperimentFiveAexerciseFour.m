x = -4:4;
y = x;
z = x;
[X, Y, Z] = meshgrid(x,y,z);
[Cx, Cy, Cz] = curl(X,Y,Z,Y.*Z,3.*X.*Z,Z);
figure
quiver3(X,Y,Z,Cx,Cy,Cz,0);
title('3D visulization of curl');
%printing the curl  in terms of u,v,w because x,y,z are already used
%differently before
syms u v w
U = [u, v, w];
V = [v.*w, 3.*u.*w, w];
curl(V,U)