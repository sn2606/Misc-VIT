#include <stdio.h>
#include <stdlib.h>

// C program to swap two variables with and without the third variable

int main()
{
    float a, b, temp, n1, n2;
    int status;

    printf("Enter the first number a: ");
    fflush(stdin);
    status = scanf("%f", &a);

     // input validation of number
    while(status == 0)
    {
        printf("Please enter a number: ");
        fflush(stdin);
        status = scanf("%f", &a);
    }
    n1 = a;

    printf("Enter the second number b: ");
    fflush(stdin);
    status = scanf("%f", &b);

     // input validation of number
    while(status == 0)
    {
        printf("Please enter a number: ");
        fflush(stdin);
        status = scanf("%f", &b);
    }
    n2 = b;

    // With using third variable
    printf("\nSWITCHING WITH THIRD VARIABLE.\n");

    temp = a;
    a = b;
    b = temp;

    printf("The value of a is %f.\n", a);
    printf("The value of b is %f.\n", b);

    // Without using third variable
    printf("\nSWITCHING WITHOUT THIRD VARIABLE.\n");

    n1 = n1 - n2;
    n2 = n2 + n1; // n2 = n2 + n1 - n2 = n1
    n1 = n2 - n1; // n1 = n2 - n1 = n1 - n1 + n2 = n2

    printf("The value of a is %f.\n", n1);
    printf("The value of b is %f.\n", n2);

    return 0;
}
