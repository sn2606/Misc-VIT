syms t 
f = input('Enter the function: ');
F = laplace(f);
F = simplify(F);
disp(['L[f(t)] = ',char(F)])