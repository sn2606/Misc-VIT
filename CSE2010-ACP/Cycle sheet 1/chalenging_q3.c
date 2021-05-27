#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define P 3.141592
#define N 19

// C program value of sin(x) by McLaurin series

int factorial(int a);

int main()
{
    float sinx = 0, x, val = 0;
    int i, j, status;

    printf("Enter value of x: ");
    status = scanf("%f", &x);

    // N = 19 (We will be considering first 10 terms)
    // int part will be between -2,147,483,648 to 2,147,483,647 (2^31)
    // log21(2^31) = 7.297676314365785
    // function pow will be executed before division
    // so if we don't want buffer overflow, we have to constraint values.
    // anyway, 7 > 2*pi, so we can subtract 2*pi from it and calculate.
    while((status == 0) || (x >= 7.2976) || (x < -7.2976))
    {
        printf("Please enter a valid input (number between -7.2976 and 7.2976): ");
        fflush(stdin);
        status = scanf("%f", &x);
    }
    
    // properties of sin
    
    if(x > 2*P)
        x -= 2*P;
    else if(x < -2*P)
        x += 2*P;
    else if(x > P)
        x = -(x - P);
    else if(x < -P)
        x = -(x + P);

    for(i = 1, j = 0; i <= N; i += 2, j++) // j for number of terms
    {
        val = ((float)pow(x,i))/((float)factorial(i)); // terms of McLaurin series
        sinx += ((float)pow(-1,j))*val; // alternate positive and negative terms
    }

    printf("\nsin(%f) = %0.5f\n", x, sinx);

    return 0;
}

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

