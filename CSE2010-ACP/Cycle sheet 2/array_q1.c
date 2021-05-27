#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101

// C program to sort an array of alphabets (both upper and lower) in an array in ascending order

int main()
{

    char str[N], temp, c1, c2;
    int i, j, n;


    printf("----Program to sort an array of n alphabets----\n\n");
    printf("Enter n: ");
    scanf("%d", &n);

    fflush(stdin);

    printf("Enter the string: ");
    fgets(str, N-1, stdin);
    fflush(stdin);
    
    // Input validation
    for(i = 0; i<n; i++)
    {
        if(isalpha(str[i]) == 0 || str[i] == '\n' || str[i] == '\0')
        {
            printf("Invalid input!");
            printf("\nPlease enter all alphabets without separation: ");
            fgets(str, N-1, stdin);
        }
    }
    
    // Sorting when case sensitive
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(str[j] > str[i])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("[CASE SENSITIVE]\n");
    printf("{");
    for(i = 0; i< n-1; i++)
        printf(" %c,", str[i]);
    printf("%c}\n", str[n-1]);


    // NON CASE SENSITIVE SORTING
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            c1 = tolower(str[i]);
            c2 = tolower(str[j]);

            if(c2 > c1)
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("\n[NOT CASE SENSITIVE]\n");
    printf("{");
    for(i = 0; i< n-1; i++)
        printf(" %c,", str[i]);
    printf("%c}\n", str[n-1]);

    return 0;
}