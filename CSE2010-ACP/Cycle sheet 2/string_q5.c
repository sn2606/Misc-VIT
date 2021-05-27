#include <stdio.h>
#include <stdlib.h>
#define N 251

// C program to print the words, sentences in a given sting and the length of the string


int main()
{
    char s[N];
    int words = 0, sentences = 0, i;

    printf("Enter the paragraph: ");
    fgets(s, 250, stdin);

    printf("%s", s);

    for(i = 0; s[i] != '\n'; i++)
    {
        if(s[i] == ' ')
            words++;
        if(s[i] == '.' && (s[i+1] == ' ' || s[i+1] == '\n'))
            sentences++;
    }

    printf("\nIn the given paragraph,\n");
    printf("\tThere are %d words\n", words + 1); // Spaces are always 1 less than words
    printf("\tThere are %d sentences\n", sentences);
    printf("\tThe length of the string is %d\n", i);

    return 0;
}
