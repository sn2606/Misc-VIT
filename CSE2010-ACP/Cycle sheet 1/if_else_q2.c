#include <stdio.h>
#include <stdlib.h>

//Richter scale characterization

int main()
{
    float y;

    printf("Enter the Richter number: ");
    scanf("%f", &y);


    if(y < 0 || y >10)
    {
        printf("Invalid input.");
    }
    else if(y < 5.0)
    {
        printf("Little or no damage.\n");
    }
    else if(y >= 5.0 && y < 5.5)
    {
        printf("Some damage.\n");
    }
    else if(y >= 5.5 && y < 6.5)
    {
        printf("Serious damage.\n");
    }
    else if(y >= 6.5 && y < 7.5)
    {
        printf("Disaster.\n");
    }
    else if(y >= 7.5)
    {
        printf("Higher Catastrophe.\n");
    }

    return 0;
}
