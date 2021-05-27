#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// C program to find sum of series 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) + ...

int main()
{
    int n, s1;
    int s = 0;

    printf("Program to find sum of series 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) + ...\n");
    printf("Enter value of n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        s1 = 0;

        for(int j = 1; j <= i; j++)
        {
            s1 += j;
        }
        s += s1;
    }

    printf("\nThe sum of given series of first %d natural numbers is %d.\n", n, s);

    return 0;
}
