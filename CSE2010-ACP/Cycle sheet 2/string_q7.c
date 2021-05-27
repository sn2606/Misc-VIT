#include <stdio.h>
#include <stdlib.h>

// C program to replace space with a special character in a string

int main()
{
    char s[] = "ARISE, AWAKE, and STOP NOT UNTIL THE GOAL is ACHIEVED";
    int i;

    // Replacing space with tilde
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ')
        {
            s[i] = '~';
        }
    }

    printf("\n%s\n", s);

    return 0;
}