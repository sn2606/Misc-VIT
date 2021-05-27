#include <stdio.h>
#include <stdlib.h>
#define N 50

// C program to find minimum element in a given row
// and maximum element in a given column

int main()
{

    float a[N][N], min, max;// c[N][N];
    int i, j, m, n, status, flag, pmin, pmax;

    printf("\nEnter number of rows in the matrix (A): ");
    scanf("%d", &m);
    fflush(stdin);

    printf("\nEnter number of columns in the matrix (A): ");
    scanf("%d", &n);
    fflush(stdin);

    printf("\n\n------- MATRIX A (m x n) -------\n");

    // Taking input for matrix A + validation
    do {

    for(i = 0; i < m; i++)
    {
        printf("Enter row %d: ", i+1);
        flag = 1;

        for(j = 0; j < n; j++)
        {
            status = scanf("%f", &a[i][j]);
            if(status == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
        {
            printf("Invalid entry!\n");
            fflush(stdin);
            break;
        }
    }

    }while(flag == 0);

    // Input for row number
    fflush(stdin);
    printf("\nEnter the row number whose min element you want: ");
    status = scanf("%d", &pmin);
    // Input validation
    while(status == 0 || pmin <= 0 || pmin > m)
    {
        printf("Invalid row number! Please enter a valid row number: ");
        fflush(stdin);
        scanf("%d", &pmin);
    }

    // Input for column number
    fflush(stdin);
    printf("\nEnter the column number whose max element you want: ");
    status = scanf("%d", &pmax);
    // Input validation
    while(status == 0 || pmax <= 0 || pmax > n)
    {
        printf("Invalid column number! Please enter a valid column number: ");
        fflush(stdin);
        scanf("%d", &pmax);
    }

    // Initial value declaration
    min = a[pmin - 1][0];
    max = a[0][pmax - 1];

    // Finding the min element in the given row
    for(i = 1; i < m; i++)
    {
        if(a[pmin - 1][i] <= min)
            min = a[pmin - 1][i];
    }

    // Finding the max element in the given column
    for(i = 1; i < n; i++)
    {
        if(a[i][pmax - 1] >= max)
            max = a[i][pmax - 1];
    }

    // Printing the matrix A
    printf("\n\n----------- MATRIX A -----------\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("    %0.2f,", a[i][j]);
        }
        printf("\n");
    }

    // Printing the min and max elements
    printf("\n\n The minimum element in row %d is: %f", pmin, min);
    printf("\n\n The maximum element in column %d is: %f\n", pmax, max);

    return 0;
}
