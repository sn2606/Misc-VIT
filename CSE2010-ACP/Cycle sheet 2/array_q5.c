#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to swap adjacent elements an array at chosen position

void insert(char a[N], char e, int p, int l);

int main()
{

    char arr[N], temp;
    int i, n, status, flag, position, option;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    // Taking input + validation
    do {printf("Enter the array (no spaces): ");

    flag = 1;

    for(i = 0; i < n; i++)
    {
        status = scanf("%c", &arr[i]);

        if(status == 0 || arr[i] == '\n')
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

    // ELEMENT TO BE ENTERED - USER INPUT
    printf("Please enter position you want swap at: ");
    fflush(stdin);
    scanf("%d", &position);

    if(position > 0 && position < n-1)
    {
        printf("\nDo you want to swap with:-\n");
        printf("1. Element behind the position\n2. Element in front of the position\n\n");
        printf("Enter the option: ");
        scanf("%d", &option);
        while(option != 1 && option != 2)
        {
            printf("Invalid option!\n");
            printf("Please enter a valid option");
            fflush(stdin);
            scanf("%d", &option);
        }
    }

    // SWAPPING
    // Case 1: swap at first position
    if(position == 0)
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    else if(position > 0 && position < n-1)
    {
        temp = arr[position];
        if(option == 1)
        {
            arr[position] = arr[position - 1];
            arr[position - 1] = temp;
        }
        else if(option == 2)
        {
            arr[position] = arr[position + 1];
            arr[position + 1] = temp;
        }
    }
    else
    {
        temp = arr[position];
        arr[position] = arr[position - 1];
        arr[position - 1] = temp;
    }


    // Printing the resulting array
    printf("\n\n--- RESULTANT ARRAY ---\n");
    printf("{");
    for(i = 0; i < n-1; i++)
        printf(" %c,", arr[i]);
    printf(" %c}\n", arr[n-1]);

    return 0;
}
