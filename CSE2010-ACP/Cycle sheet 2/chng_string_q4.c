#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101

// C program to remove all non alphabet character from a string and display final value

int length(char str[N]);

int main()
{
    char S[N];
    char sub[N];
    int pos, i, S_len, sub_len, status;

    printf("Enter the string: ");
    fgets(S, N-1, stdin);

    printf("Enter the substring: ");
    fgets(sub, N-1, stdin);

    printf("Enter the position you want to insert: ");
    status = scanf("%d", &pos);

    S_len = length(S);
    sub_len = length(sub);
    
    // Input validation
    while(status == 0 || pos == 0 || pos>=S_len - 2)
    {
        printf("Please enter a valid position: ");
        fflush(stdin);
        scanf("%d", &pos);
    }
    
    // Making space for insertion
    // - 1 is because \n at end gets scanned too
    for(i = S_len; i >= pos; i--)
    {
        S[i+sub_len-1] = S[i];
    }
    
    // Inserting substring
    // - 1 because newline character gets scanned too
    // We don't want to print that
    for(i = pos; i < sub_len + pos - 1; i++)
    {
        S[i] = sub[i - pos];
    }

    printf("\n%s\n", S);

    return 0;
}

// Function to get length of a string
int length(char str[N])
{
    int i;

    for(i = 0; str[i] != '\0'; i++);

    return i;
}