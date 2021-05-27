x = -1:.05:1;
y = -1:.05:1;
[x,y] = meshgrid(x,y);
z = x*(x.^2 + y.^2);
surf(x, y, z);
colormap cool
shading interp
