#include <stdio.h>
#include <stdlib.h>
#define N 101

// C program to print every word in a new line

int main()
{
    char s[N];
    int i;

    printf("Enter a string: ");
    fgets(s, N-1, stdin);

    // Replacing space with newline character
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ')
        {
            s[i] = '\n';
        }
    }

    printf("\n%s\n", s);

    return 0;
}