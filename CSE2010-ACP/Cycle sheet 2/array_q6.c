#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to find and replace an element in an array

void insert(char a[N], char e, int p, int l);

int main()
{

    char arr[N], find, replace;
    int i, n, status, flag;

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

    // The element to be found:
    printf("Enter the element you want to find: ");
    fflush(stdin);
    scanf("%c", &find);

    // The element you want to replace it with
    printf("Enter the character you want to replace the element with: ");
    fflush(stdin);
    scanf("%c", &replace);

    // Finding and replacing the element
    for(i = 0; i < n; i++)
    {
        if(arr[i] == find)
        {
            arr[i] = replace;
        }
    }

    // Printing the resulting array
    printf("\n\n--- RESULTANT ARRAY ---\n");
    printf("{");
    for(i = 0; i < n-1; i++)
        printf(" %c,", arr[i]);
    printf(" %c}\n", arr[n-1]);

    return 0;
}