#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 251

// C program to concatenate three given strings

int length(char str[N]);

int main()
{
    char s1[] = "If you fail, never give up because FAIL means \"First Attempt at learning\".\n\t";
    char s2[] = "All of us do not have equal talent. But, all of us have an equal opportunity to develop our talents.\n\t";
    char s3[] = "Excellence is a continuous process & not an accident.";
    char quote[N];
    int l1, l2, l3, i, freq = 0;

    // Determining lengths of strings.
    l1 = length(s1);
    l2 = length(s2);
    l3 = length(s3);

    for(i = 0; s1[i] != '\0'; i++)
    {
        quote[i] = s1[i];
    }
    quote[l1] = ' '; // Space after period for good representation

    for(i = 0; s2[i] != '\0'; i++)
    {
        quote[l1 + 1 + i] = s2[i]; // Concatenating first string to second
    }
    quote[l1 + l2 + 1] = ' '; // Space after period

    for(i = 0; s3[i] != '\0'; i++)
    {
        quote[l1 + l2 + 2 + i] = s3[i]; // Concatenating third string to first and second
    }
    quote[l1 + l2 + l3 + 2] = '\0'; // Defining the EOF character

    // Printing out the quote
    printf("Dr. APJ Abdul Kalam quotes that\n\t\"%s\"\n", quote);

    // COUNTING OCCURANCE OF SPECIAL CHARACTERS

    for(i = 0; quote[i] != '\0'; i++)
    {
        if(quote[i] >= 33 && isalnum(quote[i])==0)
            freq++;
    }

    printf("\nThere are %d special characters in the given quote.\n", freq);

    return 0;
}

// Function to find length of the string
int length(char str[N])
{
    int len = 0, i = 0;
    while(str[i] != '\0')
    {
        len++;
        i++;
    }

    return len;
}
