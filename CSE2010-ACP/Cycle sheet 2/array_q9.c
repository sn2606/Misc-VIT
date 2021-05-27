#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to find transpose of a matrix

int main()
{

    float a[N][N], b[N][N];// c[N][N];
    int i, j, m, n, status, flag;

    printf("Enter number of rows in the matrix (A): ");
    scanf("%d", &m);
    fflush(stdin);

    printf("Enter number of columns in the matrix (A): ");
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


    // Transposing the matrices
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    // Printing the matrix C
    printf("\n\n------- MATRIX A transpose -------\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf(" %0.4f,", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}