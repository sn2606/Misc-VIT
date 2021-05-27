#include <stdio.h>
#include <stdlib.h>

// C program to count number of times a substring has appeared in a string

int length(char str[101]);

int main()
{
    char s[] = "Best brains of the nation may be found in the last benches of the classroom.";
    char check[] = "the";
    int count = 0, i, s_len, check_len, j, flag;

    s_len = length(s);
    check_len = length(check);

    printf("%s\n", s);

    for(i = 0; i < s_len - check_len; i++)
    {
        flag = 1;
        // flag inside doesn't work
        for(j = 0; j < check_len; j++)
        {
            if(s[i + j] != check[j])
                flag = 0;
            // Other way around doesn't work because
            // it counts char matching too
        }

        if(flag == 1)
            count++;
    }

    printf("\n\'%s\' appears in the string %d times.\n", check, count);

    return 0;
}

// Function to get length of a string
int length(char str[101])
{
    int i;

    for(i = 0; str[i] != '\0'; i++);

    return i;
}