#include <stdio.h>
#include <stdlib.h>

// By a research study it is found that the intelligence of person can be calculated with
// the following formula, i = 2 + (y+0.5x). Write a C program to generate a table of
// values of i, y and x, where y varies from 1 to 6, and for each value of y, x varies
// from 5.5 to 12.5 in steps of 0.5

int main()
{
    float IP, x;
    int y;

    printf("X\t Y\t   I\t \n");
    printf("----------------------\n");

    for(y = 1; y <= 6; y++)
    {
        for(x = 5.5; x <= 12.5; x += 0.5)
        {
            printf("%0.3f\t %d\t %0.3f\t \n", x, y, IP = 2 + (y + 0.5*x));
        }
    }

    return 0;
}   // Main function ends

