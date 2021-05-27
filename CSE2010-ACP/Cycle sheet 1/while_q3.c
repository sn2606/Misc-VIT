#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// C program to convert binary number to decimal number

int main()
{
    unsigned long int n;
    int r;

    printf("Enter the number: ");
    scanf("%lu", &n);

    unsigned long int m = n;
    int s = 0;
    int i = 0;

    while(n != 0)
    {
        r = n % 10;
        s += r*pow(2, i);
        n /= 10;
        i++;
    }

    printf("The decimal form of %lu is %d.", m, s);

    return 0;
}
