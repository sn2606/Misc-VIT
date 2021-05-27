#include <stdio.h>
#include <stdlib.h>
#define N 100

// Write a C program to print all integers that are not divisible by 2 or 3 and lie
// between 1 and 100. Program should also account /the number of such integers and
// print the result

int factorial(int a);

int main()
{
    int i, count;

    printf("The numbers are:\n");

    for(i = 1; (i <= N); i++)
    {
        if((i%2 != 0) && (i%3 != 0))
        {
            printf("%d\n", i);
            count++;
        }

    }

    printf("\nThere are %d numbers between 1 and 100 that are not divisible by 2 or 3.", count);

    return 0;
}
