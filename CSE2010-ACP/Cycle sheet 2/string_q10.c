#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define L 20

// C program to heck whether two given strings are anagrams of each other
// Not case sensitive


int main()
{
    char name[L][L];
    char s[L];
    int num, i, j;

    printf("Enter number of friends: ");
    scanf("%d", &num);

    printf("Enter the first names of your friends separated by a space: ");

    for(i = 0; i<num; i++)
        scanf("%s", name[i]);

    // Sorting the names
    for(i = 0; i<num; i++)
    {
        for(j = 0; j<i; j++)
        {
            if(string_cmp(name[i], name[j], 0) == 0)
            {
                // Swapping the strings
                string_cp(name[i], s);
                string_cp(name[j], name[i]);
                string_cp(s, name[j]);
            }
        }
    }

    for(i = 0; i < num; i++)
    {
        printf("%s\n", name[i]);
    }


}   // Main function ends here

// Function to check which string comes second in dictionary
int string_cmp(char str1[L], char str2[L], int ind)
{
    int val = 0;

    // ind checks chars at that position
    if(str1[ind] != '\0' || str2[ind] != '\0')
    {
        if(str1[ind] > str2[ind])
        {
            return val = 1;
        }
        else if(str1[ind] < str2[ind])
        {
            return val = 0;
        }
        else
        {
            // Recursive
            ind++;
            string_cmp(str1, str2, ind);
        }
    }
}

// Function to copy contents of one string to other
void string_cp(char str1[L], char str2[L])
{
    int i = 0;

    for(i = 0; str1[i] != '\0'; ++i)
    {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
}