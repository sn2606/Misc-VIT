#include <stdio.h>
#include <stdlib.h>
#define N 101

int length(char str[N]);
void reverse_string(char str[N], int len);

int main()
{
    char s[N];
    int l;

    printf("Enter the string you want to reverse: ");
    fgets(s, N-1, stdin);

    l = length(s);

    printf("The reversed string is:\n");

    reverse_string(s, l);

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

// Function to reverse the string and print it
void reverse_string(char str[N], int len)
{
    int i;
    char rev_str[N];

    // While printing we need EOF character
    rev_str[len] = '\0';

    for(i = 0; str[i] != '\0'; i++)
    {
        rev_str[len-1-i] = str[i];
    }

    // Printing the reversed string
    printf("%s\n", rev_str);
}
