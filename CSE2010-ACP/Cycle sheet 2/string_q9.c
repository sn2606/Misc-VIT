#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101

// C program to heck whether two given strings are anagrams of each other
// Not case sensitive

int letters(char str[N]);
int char_in_str(char str1[N], char str2[N]);

int main()
{
    char s1[N], s2[N];

    printf("Enter the first string: ");
    fgets(s1, N-1, stdin);

    printf("Enter the second string: ");
    fgets(s2, N-1, stdin);

    // Printing anagram or not anagram
    if(letters(s1) == letters(s2) && char_in_str(s1, s2))
        printf("\nThe strings are anagrams of each other!\n");
    else
        printf("\nThe strings are not anagrams of each other!\n");

    return 0;
}   // Main function ends here

// Function to count number of non-whitespace characters
int letters(char str[N])
{
    int i = 0, let = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 33)
            let++;
        i++;
    }

    return let;
}

// Program to check whether char in str1 occur in str2 too
int char_in_str(char str1[N], char str2[N])
{
    int i, j, val;

    for(i = 0; str1[i] != '\0'; i++)
    {
        for(j = 0; str2[j] != '\0'; j++)
        {
            if(str1[i] >= 33 && str2[j] >= 33)
            {
                val = 0;
                // If both char are alpha, convert to lowercase
                // so as to not be case sensitive
                if(isalpha(str1[i]) && isalpha(str2[j]))
                {
                    str1[i] = tolower(str1[i]);
                    str2[j] = tolower(str2[j]);
                }
                // If the char is present, val is changed to 1
                if(str1[i] == str2[j])
                {
                    val = 1;
                    break;
                }
            }
        }
    }

    return val;
}