#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to swap adjacent elements an array at chosen position

void insert(char a[N], char e, int p, int l);

int main()
{

    int num[N], temp;
    int i, j, n, status, flag;

    printf("Enter number of integers in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    // Taking input + validation
    do {printf("Enter the array: ");

    flag = 1;
    
    for(i = 0; i < n; i++)
    {
        status = scanf("%d", &num[i]);

        if(status == 0)
        {
            flag = 0;
			break;
        }
    }

    if(flag == 0)
    {
        printf("Invalid array!\n");
        fflush(stdin);
    }

    }while(flag == 0);
    
    // Sorting the array
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(num[j] > num[i])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    // Printing the resulting array
    printf("\n\n--- RESULTANT ARRAY ---\n");
    printf("{");
    for(i = 0; i < n-1; i++)
        printf(" %d,", num[i]);
    printf(" %d}\n", num[n-1]);

    return 0;
}