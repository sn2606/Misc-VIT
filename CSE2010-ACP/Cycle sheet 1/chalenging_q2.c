#include <stdio.h>
#include <stdlib.h>
#define N 20

// c program to approximate e

int factorial(int a);

int main()
{
    double sum;
    int i;

    printf("\nThis program approximates value of Euler's number, e, using the infinte series sum\n");
    printf("e = 1/1! + 1/2! + 1/3! + ... \n\n");
    printf("Which is case: x = 1 for McLaurin expansion of e^x.\n\n");

    for(i = 0; i < N; i++)
    {
        sum += ((double)1)/((double)factorial(i));
    }

    printf("Using first %d terms of the series, e = %lf\n", N, sum);

    return 0;
}

int factorial(int a)
{
    if(a == 1 || a == 0)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
}
