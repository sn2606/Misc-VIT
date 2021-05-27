#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to insert element into an array at chosen position

void insert(char a[N], char e, int p, int l);

int main()
{

    char arr[N], elem;
    int i, n, status, flag, begin = 0, end, middle, option;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    end = n-1;
    middle = (begin + end)/2;

    // Taking input + validation
    do {printf("Enter the array (no spaces): ");

    flag = 1;

    for(i = 0; i < n; i++)
    {
        status = scanf("%c", &arr[i]);

        if(status == 0 || arr[i] == '\n')
        {
            flag = 0;
        }
    }

    if(flag == 0)
    {
        printf("Invalid array!\n");
        fflush(stdin);
    }

    }while(flag == 0);

    // ELEMENT TO BE ENTERED - USER INPUT
    printf("Please enter element you want to enter: ");
    fflush(stdin);
    scanf("%c", &elem);

    // Choose where you want to enter:
    printf("\nPLEASE CHOOSE WHERE YOU WANT TO INSERT THE ELEMENT FROM THE GIVEN OPTIONS:\n");
    printf("1. Beginning\n2. Middle\n3. End\n\n");

    do
    {
        printf("Enter the option number: ");
        fflush(stdin);
        status = scanf("%d", &option);
        flag = 1;

        if(status == 0)
        {
            printf("Invalid input!\n");
            flag = 0;
            option = 0;
        }

        switch(option)
        {
        case 1:
            insert(arr, elem, begin, n);
            break;
        case 2:
            insert(arr, elem, middle, n);
            break;
        case 3:
            insert(arr, elem, end, n);
            break;
        default:
            flag = 0;
            break;
        }
    }while(flag == 0);


    // Printing the resulting array
    printf("\n\n--- RESULTANT ARRAY ---\n");
    printf("{");
    for(i = 0; i < n; i++)
        printf(" %c,", arr[i]);
    printf(" %c}\n", arr[n]);

    return 0;
}

// Function to insert an element e in array a of length l at position p
void insert(char a[N], char e, int p, int l)
{
    int i;

    for(i = l; i > p; i--)
    {
        a[i] = a[i-1];
    }

    a[p] = e;
}