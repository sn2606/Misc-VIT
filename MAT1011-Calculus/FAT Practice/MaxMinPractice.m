clear all
clc
syms x;
f = input('Enter the function: ');
I = input('Enter the interval [a,b]: ');
a=I(1);b=I(2);
df = diff(f,x);
ddf = diff(df,x);
f = inline(vectorize(f));
df = inline(vectorize(df));
ddf = inline(vectorize(ddf));
range = linspace(a,b,100);
plot(range,f(range),'-b','LineWidth',2);
legstr = {'Function Plot'};
hold on
guesses = linspace(a,b,5);
root = zeros(size(guesses));
for i = 1:numel(guesses)
    root(i) = fzero(df,guesses(i));
end
root = root(a<=root & root<=b);
root = unique(round(root,4));
plot(root,f(root),'or','MarkerSize',10);
legstr = [legstr,{'Critical points'}];
disp(['Critical points of f(x) are: ', num2str(root)])
maxp = root(ddf(root)<0);
if(numel(maxp)~=0)
    disp(['Local maximum of f(x) occurs at: ',num2str(maxp)])
end
minp = root(ddf(root)>0);
if(numel(minp)~=0)
    disp(['Local minimum of f(x) occurs at: ',num2str(minp)])
end
fval = f(root);
if(numel(maxp)~=0)
    gmax = root(fval == max(fval));
    disp(['Global maximum of f(x) occurs at: ',num2str(gmax),' and its value is: ',num2str(max(fval))]);
    plot(gmax,f(gmax),'m+','MarkerSize',10);
    legstr = [legstr,{'Global Maximum'}];
end
if(numel(minp)~=0)
    gmin = root(fval == min(fval));
    disp(['Global minimum of f(x) occurs at: ',num2str(gmin),' and its value is: ',num2str(min(fval))]);
    plot(gmin,f(gmin),'k^','MarkerSize',10);
    legstr = [legstr,{'Global Minimum'}];
end
legend(legstr,'Location','best')    