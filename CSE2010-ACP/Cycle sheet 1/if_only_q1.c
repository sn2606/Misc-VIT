#include <stdio.h>
#include <stdlib.h>

// Get a number from user. If the number is less than or equal to 10. Print the message “good”.

int main()
{
    float a;
    printf("Enter a number: ");
    scanf("%f", &a);

    if(a <= 10)
    {
        printf("Good");
    }

    return 0;
}