#include <stdio.h>
#include <stdlib.h>

// The equation x2+y2 = r2 represents a circle with center at origin and radius r.
// Write a C program that reads r from the keyboard and prints the number of
// points with integer coordinated that lie within the circle

int main()
{
    int x, y, points, val, status;
    float r;

    points = 0;

    printf("Enter the radius: ");
    status = scanf("%f", &r);

    while(status == 0 || r < 0)
    {
        printf("Invalid! Please enter a valid radius value: ");
        fflush(stdin);
        status = scanf("%f", &r);
    }

    val = r/1;

    for(x = val; x >= -val; x--)
    {
        for(y = val; y >= -val; y--)
        {
            if(x*x + y*y < r*r)
            {
                points++;
            }
        }
    }

    printf("\nThere are %d integer coordinates that lie within the circle.\n", points);

    return 0;
}
