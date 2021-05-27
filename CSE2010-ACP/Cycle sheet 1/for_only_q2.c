#include <stdio.h>
#include <stdlib.h>
#define N 100

// Write a C program to read the age of 100 persons and count the number of persons
// in the age group 50 to 60. Use for and continue statement

int main()
{
    int n[N];
    int c = 0;

    for(int i = 0; i < N; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &n[i]);
        continue;
    }

    for(int i = 0; i < N; i++)
    {
        if(n[i] >= 50 && n[i] <= 60)
        {
            c++;
            continue;
        }
    }

    printf("There are %d people among given %d between ages 50 and 60.", c, N);

    return 0;
}
