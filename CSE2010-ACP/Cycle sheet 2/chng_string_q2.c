#include <stdio.h>
#include <stdlib.h>
#define N 101

// C program to remove duplicate characters from given string and print the resultant string

int main()
{
    char S[N];
    char RS[N];
    int i, j, k, flag;

    printf("Enter the string: ");
    fgets(S, N-1, stdin);


    RS[0] = S[0];

    for(i = 1, k = 1; S[i] != '\0'; i++)
    {
        for(j = 0; j < i; j++)
        {
            flag = 1;
            if(S[j] == S[i])
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
            RS[k] = S[i];
            k++;
        }
    }

    if(flag == 0)
        RS[k+1] = '\0'; // If last var has already appeared, k++ wont happen
    else
        RS[k] = '\0'; // If last var is unique, k++ will happen

    printf("\nAfter deleting duplicates from the string the resultant string is: ");
    printf("\n%s\n", RS);

    return 0;
}
