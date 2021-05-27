clear all
clc
A = input('Enter the transitional matrix that represents the web page: ');
[V,D] = eig(A);
for i = 1:length(A)
    if round(D(i,i),10) == 1
        X = V(:,i)
        break;
    end
end
[Y,I] = sort(X,'descend')
pn = ('a':'f');
pn = (pn(I))
