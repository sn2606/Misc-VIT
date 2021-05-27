#include <stdio.h>
#include <stdlib.h>

// Given a set of 10 two-digit integer containing both positive and negative values,
// write a program using for loop to compute the sum of all positive values and print
// the sum and the number of values added. The C program should use scanf to read
// the values and terminate when the sum exceeds 985. Do not use goto statement

int main()
{
    int n, sum, count_sum, count_input, status;
    count_input = 0;
    count_sum = 0;
    sum = 0;

    printf("This program needs 10 two digit integer values.\n");
    printf("If the sum of positive integer exceeds 985, the program will terminate.\n\n");

    do
    {
        printf("Enter a number: ");
        status = scanf("%d", &n);

        while(status == 0 || n < -99 || n > 99 || (n > -10 && n < 10) )
        {
            printf("Invalid! Please enter a two digit number: ");
            fflush(stdin);
            status = scanf("%d", &n);
        }

        count_input ++;

        if(n > 0)
        {
            sum += n;
            count_sum++;
        }

        if(sum > 985)
        {
            printf("As the sum exceeds 985, %d will not be considered as additional input.\n", n);
            printf("Exit from input.\n\n");
        }

    }while(sum < 985 && count_input < 10);

    if(sum > 985)
    {
        sum -= n;
        count_sum--;
    }

    printf("The sum of positive integers in above provided inputs is %d.\n", sum);
    printf("The number of positive integers in above provided inputs is %d.\n", count_sum);

    return 0;
}
