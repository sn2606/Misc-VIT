#include <stdio.h>
#include <stdlib.h>
#define N 50

// C program to find sum of zig-zag elements of a given matrix
// and replace the non zig-zag elements by 0

int main()
{

    float a[N][N], sum;// c[N][N];
    int i, j, n, status, flag;

    printf("\nEnter the dimension of the square matrix (A): ");
    scanf("%d", &n);
    fflush(stdin);

    printf("\n\n------- MATRIX A (m x n) -------\n");

    // Taking input for matrix A + validation
    do {

    for(i = 0; i < n; i++)
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

    // Zig-Zaging

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == 0 || i == 3 || j == n - i - 1)
            {
                sum += a[i][j];
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    // Printing the matrix A
    printf("\n\n----------- MATRIX A -----------\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("    %0.2f,", a[i][j]);
        }
        printf("\n");
    }

    // Printing the min and max elements
    printf("\n\n The sum of the zig-zag elements is: %f\n", sum);

    return 0;
}
