#include <stdio.h>
#include <stdlib.h>

// Read three numbers from the user and find the biggest of three using simple (multiple) if statements.

int main()
{
    float a, b, c;
    printf("Enter number 1: ");
    scanf("%f", &a);
    printf("Enter number 2: ");
    scanf("%f", &b);
    printf("Enter number 3: ");
    scanf("%f", &c);

    float g = a;

    if(b >= g)
        g = b;

    if(c >= g)
        g = c;

    printf("The biggest of three numbers is %f", g);

    return 0;
}
