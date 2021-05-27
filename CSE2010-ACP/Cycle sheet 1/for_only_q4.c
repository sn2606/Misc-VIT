#include <stdio.h>
#include <stdlib.h>
#define N 10

// Write a C program to print the following series
// 1
// 2    3
// 4    5   6
// 7    8   9   10

int main()
{
    int n = 1;

    for(int j = 0; n <= N; j++)
    {
        for(int k = 0; k < j; k++)
        {
            printf("%d", n);
            printf("\t");
            n++;
        }
        printf("\n");
    }

    return 0;
}