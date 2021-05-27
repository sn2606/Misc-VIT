#include <stdio.h>
#include <stdlib.h>
#define N 101

// C program to carry out left to right rotation of an array n times.

void print_array(char a[N], int l);

int main()
{
    char arr[N], temp;
    int i, j, n, flag, status;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    // Taking input + validation
    do {printf("Enter the array(no spaces unless it's an element): ");

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

    // Right rotating the array and printing it

    for(i = 0; i < n; i++)
    {
        temp = arr[0];
        for(j = n-1; j > 0; j--)
        {
            arr[(j+1)%n] = arr[j];
        }
        arr[1] = temp;

        printf("\nRotation %d: ", i+1);
        print_array(arr, n);
    }


    return 0;
}

void print_array(char a[N], int l)
{
    int i;

    printf("{");
    for(i = 0; i < l-1; i++)
        printf(" %c,", a[i]);
    printf(" %c}\n", a[l-1]);
}
