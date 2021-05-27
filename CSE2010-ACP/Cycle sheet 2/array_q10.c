#include <stdio.h>
#include <stdlib.h>
#define N 50

// C program to multiply two matrices

int main()
{

    float a[N][N], b[N][N], c[N][N] = {{0}};// c[N][N];
    int i, j, m, n, status, flag, k = 0;

    printf("Enter number of rows in the matrix (A): ");
    scanf("%d", &m);
    fflush(stdin);

    printf("Enter number of columns in the matrix (A): ");
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

    printf("\n\nThe second matrix has to be %d x %d, otherwise we can't multiply the matrices.\n", n, m);

    printf("\n\n------- MATRIX B (n x m) -------\n");

    // Taking input for matrix B + validation
    do {

    for(i = 0; i < n; i++)
    {
        printf("Enter row %d: ", i+1);
        flag = 1;

        for(j = 0; j < m; j++)
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


    // Multiplying the matrices
    for(i = 0; i < m; i++)
    {
        for(k = 0; k < m; k++)
        {
            for(j = 0; j < n; j++)
            {
                c[i][k] += a[i][j]*b[j][k];
            }
        }
    }

    // Printing the matrix C
    printf("\n\n------- MATRIX A * MATRIX B -------\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf(" %0.2f,", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}