#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Write a menu driven c program with the following options
// 1. odd or even 2. Prime or not 3. Factorial of a number 4. Exit

void parity(int a);
int primality(int a);
void prime(int a);
int factorial(int a);

int main()
{
    int n, option, status;

    printf("Enter the number: ");
    fflush(stdin);
    status = scanf("%d", &n);

     // input validation of number
    while(status == 0)
    {
        printf("Please enter a number: ");
        fflush(stdin);
        status = scanf("%d", &n);
    }

    // Printing the menu
    printf("\nPlease select one of the following options:\n1. Odd or Even\n2. Prime or composite\n3. Factorial\n4. Exit.\n\n");

    // Taking options
    do
    {
        printf("Enter the option number: ");
        fflush(stdin);
        status = scanf("%d", &option);

        // Input validation of option
        while(status == 0)
        {
            printf("Please enter a valid option: ");
            fflush(stdin);
            status = scanf("%d", &option);
        }

        switch(option)
        {
        case 1:
            parity(n);
            break;
        case 2:
            prime(n);
            break;
        case 3:
            printf("The factorial of %d is %d.\n", n, factorial(n));
            break;
        case 4:
            break;
        default:
            printf("\nInvalid option!\n");
        } // switch loop ends here

    }while(option != 4); // do while loop ends

    return 0;
}   // Main function ends

// Function to check odd or even
void parity(int a)
{
    if(a % 2 == 0)
    {
        printf("The number %d is even.\n", a);
    }
    else
    {
        printf("The number %d is odd.\n", a);
    }
}

// Function to check prime or not
int primality(int a)
{
    int i, p;

    if(i <= 1)
    {
        return 0;
    }

    for(i = 2; i < a; i++)
    {
        if(a%i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Function to print prime or not
void prime(int a)
{
    if(primality(a) == 1)
    {
        printf("The number %d is prime.\n", a);
    }
    else if(a == 1)
    {
        printf("1 is a unique number! Neither prime nor composite!\n");
    }
    else
    {
        printf("The number %d is composite.\n", a);
    }
}

// Function to get factorial of a number
int factorial(int a)
{
    if(a == 1 || a == 0)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
}