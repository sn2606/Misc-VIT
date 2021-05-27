clc
clear all
syms x y 
f = input('Enter the function f(x,y): ');
p = diff(f,x); q = diff(f,y);
[ax,ay] = solve(p,q);
ax = double(ax); ay = double(ay);
r=diff(p,x); s=diff(p,y); t=diff(q,y); D=r*t-s^2;
figure
ezsurf(f);
legstr={'Function Plot'}; % for Legend
for i=1:size(ax)
    T1=subs(D,{x,y},{ax(i),ay(i)});
    T2=subs(r,{x,y},{ax(i),ay(i)});
    T3=subs(f,{x,y},{ax(i),ay(i)});
    if (double(T1) == 0)
        sprintf('At (%f,%f) further investigation is required', ax(i), ay(i))
        legstr = [legstr,{Case of Further investigation'}];
        mkr = 'ko';
    elseif (double(T1) < 0)
        sprintf('The point (%f,%f) is a saddle point',ax(i), ay(i))
        legstr = [legstr,{'Saddle Point'}]; % updating Legend
        mkr = 'bv'; % marker
    else
        if (double(T2)<0)
            sprintf('The maximum value of the function is f(%f,%f)=%f',ax(i),ay(i),double(T3))
            legstr=[legstr,{'Saddle Point'}]; % updating Legend
            mkr = 'g+'; % marker
        else
            sprintf('The minimum value of the function is f(%f,%f)=%f', ax(i), ay(i), double(T3))
            legstr=[legstr,{'Minimum value of the function'}];% updating Legend
            mkr='r*'; % marker
        end
    end
    hold on
    plot3(ax(i),ay(i),T3,mkr,'Linewidth',4);
end
legend(legstr,'Location','Best');


            
            
    

