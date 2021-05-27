#include <stdio.h>
#include <stdlib.h>
#define S 50

// C program to count the number of vowels in a string using switch-case control structure


int main()
{
    char str[S];
    int count = 0, i = 0;

    printf("Enter the string: ");
    scanf("%[^\n]", str);

    for(i = 0; i < S && str[i] != 0; i++)
    {
        printf("%c \n", str[i]);
        switch(str[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            count ++;
            printf("%d \n\n", count);
            break;

        default:
            count += 0;
            printf("%d \n\n", count);
            break;
        }
    }

    printf("The number of vowels in the given string is: %d", count);

    return 0;
}