#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101
#define L 20

// C program to print all the words in reverse

int main()
{

    char str[N];
    int index[L] = {0};
    char revw[N];
    int i,j,k,len, val1, val2;

    printf("Enter the given string: ");
    fgets(str, N-1, stdin);

    // Finding the length of the string
    len = length(str);

    // Space index array
    space(str, index);

    // Creating the reverse word array
    for(i = 1; index[i] != 0; i++)
    {
        val1 = index[i-1];
        val2 = index[i];

        for(j = val1+1, k = len - val2; k < len-val1-1 ; j++, k++)
        {
            revw[k] = str[j];
            //printf("%c\n", revw[k]);
        }
        revw[k] = ' ';
    }

    revw[len] = '\0';

    printf("\nThe words displayed in reverse are: \n\n");

    for(i = 0; revw[i] != '\0'; i++)
        printf("%c", revw[i]);
    printf("\n");

    return 0;
}

void space(char a[N], int b[L])
{
    int i, j;

    b[0] = -1;

    for(i = 0, j = 1; a[i] != '\0'; i++)
    {
        if(a[i] == ' ' || a[i] == '.' || a[i] == '\n')
        {
            b[j] = i;
            j++;
        }
    }

}

// Function to get length of a string
int length(char str[101])
{
    int i;

    for(i = 0; str[i] != '\n'; i++);

    return i;
}