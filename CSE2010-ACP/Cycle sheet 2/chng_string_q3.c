#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101

// C program to remove all non alphabet character from a string and display final value

int main()
{
    char S[N];
    int i = 0, j;

    printf("Enter the string: ");
    fgets(S, N-1, stdin);


    while(S[i] != '\0')
    {
        // If character is not an alphabet, delete it
        if(isalpha(S[i]) == 0)
        {
            for(j = i; S[j] != '\0'; j++)
            {
                S[j] = S[j+1];
            }
        }
        // Else check the next character
        else
            i++;
    }

    printf("Removing all characters from a string except the alphabets: \n");
    printf("[WITHOUT USING A SECOND ARRAY]\n\n");
    printf("%s", S);

    return 0;
}