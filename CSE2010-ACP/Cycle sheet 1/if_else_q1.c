#include <stdio.h>
#include <stdlib.h>

// Write a c program to check given year is leap year or not.

int main()
{
    int y;

    printf("Enter the year: ");
    scanf("%d", &y);

    if(y%100 == 0)
    {
        if(y%400 == 0)
        {
            printf("Given year is a leap year.");
        }
        else
        {
            printf("Given year is not a leap year.");
        }
    }
    else if(y%4 == 0)
    {
        printf("Given year is a leap year.");
    }
    else
    {
        printf("Given year is not a leap year.");
    }

    return 0;
}
