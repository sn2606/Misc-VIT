#include <stdio.h>
#include <stdlib.h>
#define N 50

// C program to multiply two matrices

int main()
{

    float a[N][N], border = 0;// c[N][N];
    int i, j, m, n, status, flag;

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

    // Summing up border elements
   for(i = 0; i < m; i++)
   {
       for(j = 0; j < n; j++)
       {
           if(i == 0 || i == m-1 || j == 0 || j == n-1)
           {
               border += a[i][j];
           }
       }
   }

    // Printing the matrix A
    printf("\n\n------- MATRIX A -------\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("    %0.2f,", a[i][j]);
        }
        printf("\n");
    }

    printf("\nTHE SUM OF BORDER ELEMENTS IS: %f\n", border);

    return 0;
}
