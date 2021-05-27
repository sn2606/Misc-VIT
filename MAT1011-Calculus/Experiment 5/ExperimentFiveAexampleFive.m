x = -4:4;
y = x;
z = x;
[X, Y, Z] = meshgrid(x,y,z);
[Cx, Cy, Cz] = curl(X,Y,Z,-Y.*X.^2,X+Y.^3,zeros(size(X)));
% Note that as there are no z-values in our field, we supplied zeros for z
figure
quiver3(X,Y,zeros(size(X)),Cx,Cy,Cz,0);
hold on;
[X Y] = meshgrid(x,y);
quiver(X,Y,-Y.*X.^2,X+Y.^3);
figure 
[X Y] = meshgrid(-4:.3:4);
crl = curl(X,Y,-Y.*X.^2,X+Y.^3);
pcolor(X,Y,crl);
shading interp
hold on;
quiver(X,Y,-Y.*X.^2,X+Y.^3,'y');
hold off;
colormap copper
