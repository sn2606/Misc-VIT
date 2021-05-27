#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define P 3

// C program to  print a table of Scooter costs as per specifications

void print_arr(int arr[], int size);

int main()
{
    int base_price = 25000, mirror = 85, crash_gaurd = 225, side_box = 300;
    int req[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    int total[8][5] = {{0}};
    int i, j;

    printf("\nBase Price\t Mirror\t   Crash Guard\t   Side Box\t\tTotal\n");
    printf("---------------------------------------------------------------------\n");

    for(i= 0; i < 8; i++)
    {
        total[i][0] = base_price;
        total[i][1] = req[i][0];	// A
        total[i][2] = req[i][1];	// B
        total[i][3] = req[i][2];	// C
        total[i][4] = base_price + (mirror * req[i][0]) + (crash_gaurd * req[i][1]) + (side_box * req[i][2]);
		// As per the given formula total = bp + A*m + B*cg + C*sb
        print_arr(total[i], 5);
    }


    return 0;
}

//function to print the array
void print_arr(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d\t\t",arr[i]);
    }
    printf("\n");
}
