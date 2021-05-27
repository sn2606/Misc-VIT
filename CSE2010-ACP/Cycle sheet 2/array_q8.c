#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to find sum of two matrices

int main()
{

    float a[N][N], b[N][N], c[N][N];
    int i, j, m, n, status, flag;

    printf("Enter number of rows in the matrices (A, B): ");
    scanf("%d", &m);
    fflush(stdin);

    printf("Enter number of columns in the matrices (A, B): ");
    scanf("%d", &n);
    fflush(stdin);

    printf("\n\n------- MATRIX A -------\n");

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

    printf("\n\n\n------- MATRIX B -------\n");

    // Taking input for matrix B + validation
    do {

    for(i = 0; i < m; i++)
    {
        printf("Enter row %d: ", i+1);
        flag = 1;
        for(j = 0; j < n; j++)
        {
            status = scanf("%f", &b[i][j]);
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


    // Adding the matrices
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // Printing the matrix C
    printf("\n\n------- MATRIX C -------\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf(" %0.4f,", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}