#include <stdio.h>
#include <stdlib.h>

// C program to check whether a given number is Armstrong number or not
// Armstrong number is an integer whose
// sum of cubes of digits is the number itself

int main()
{
    int n, m, r;

    printf("Enter the number: ");
    scanf("%d", &n);

    int s = 0;
    m = n;

    while(m != 0)
    {
        r = m % 10;
        s = s*10 + r;
        m /= 10;
    }

    if(s == n)
    {
        printf("The number is a palindrome.\n");
    }
    else
    {
        printf("The number is not a palindrome.\n");
    }

    return 0;
}
