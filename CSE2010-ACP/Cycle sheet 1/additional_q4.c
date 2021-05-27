#include <stdio.h>
#include <stdlib.h>

// Assume a given series 1!/2! + 2!/3! + 3!+4!...n!/(n+1)! ----
// Write a C program to calculate its sum

int factorial(int a);

int main()
{
    int n, status, i;
    float sum = 0;

    printf("This program will compute sum of series r!/(r+1)! till r = n.\n\n");

    printf("Enter the number n: ");
    fflush(stdin);
    status = scanf("%d", &n);

     // input validation of number
    while(status == 0)
    {
        printf("Please enter a number: ");
        fflush(stdin);
        status = scanf("%d", &n);
    }

    for(i = 1; i <= n; i++)
    {
        sum += ((float)factorial(i))/((float)factorial(i + 1));
    }

    printf("\nThe sum of the series is: %f", sum);

    return 0;
}   // Main function ends


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

