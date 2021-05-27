#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// C program to find sum of squares of first n natural numbers

int main()
{
    int n;
    int s2 = 0;

    printf("Program to find sum of squares of first n natural numbers.\n");
    printf("Enter value of n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        s2 += pow(i,2);
    }

    printf("\nThe sum of squares of first %d natural numbers is %d.\n", n, s2);

    return 0;
}
