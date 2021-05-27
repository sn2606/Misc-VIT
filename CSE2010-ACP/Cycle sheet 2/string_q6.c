#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101

// C program to remove all characters in a string except the alphabets and display the resulting string

int main()
{
    char s[N], ed[N];
    int i,j;

    printf("Enter the string: ");
    fgets(s, 250, stdin);

    for(i = 0, j = 0; s[i] != '\0'; i++)
    {
        if(isalpha(s[i]))
        {
            ed[j] = s[i]; // adding alpha to another array
            j++;    // Increasing count when assigned
        }
    }

    ed[j] = '\0';

    printf("\nThe resulting string after removing all non-alphabet characters from %s is: \n", s);
    printf("%s", ed);

    return 0;
}