#include <stdio.h>
#include <stdlib.h>

// Write a C Program to read student’s grade from keyboard from 1 to 5) and prints its description.
// 1.Fail 2.Bad 3.Good 4.VeryGood 5.Excellent ,default: false grade

int main()
{
    int grade;

    printf("Enter your grade: ");
    scanf("%d", &grade); // Reading the grade given by student

    switch(grade)
    {               // Beginning switch statement
    case 1:
        printf("Fail.\n");
        break;
    case 2:
        printf("Bad.\n");
        break;
    case 3:
        printf("Good.\n");
        break;
    case 4:
        printf("Very Good.\n");
        break;
    case 5:
        printf("Excellent\n");
        break;
    default:
        printf("False Grade!");
        break;
    }                  // End of switch statement

    return 0;
}
