x = -4:0.5:4;
y = x;
[X Y] = meshgrid(x,y);
Div = divergence(X,Y,X.*Y.^2, X.^2);
figure
pcolor(X,Y,Div);
shading interp
hold on;
quiver(X,Y, X.*Y.^2, X.^2, 'Y');
hold off;
colormap copper
title('Vector field of F(x,y) = [xy^2, x^2]');