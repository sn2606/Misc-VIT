#include <stdio.h>
#include <stdlib.h>
#define N 50

// C program to print all quadruples (i,j,k,l) such that,
// i + j + k = l
// 1 <= i < j < k < l <= 50

int main()
{
    int i, j, k, l, count;
    count = 0;

    for(i = 1; i < 16; i++)
    {
        for(j = i + 1; (j < 25) && (j > i); j++)
        {
            for(k = j + 1; (k < 47) && (i + j + k <= 50) && (k > j); k++)
            {
                l = i + j + k;
                printf("%d + %d + %d = %d\n", i, j, k, l);
                count ++;
            }
        }
    }

    printf("\n\n There are total %d combinations.\n", count);
}