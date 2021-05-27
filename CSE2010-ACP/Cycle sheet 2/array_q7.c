#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to find and replace an element in an array

void insert(char a[N], char e, int p, int l);

int main()
{

    char arr[N], repeating[N], non_repeating[N];
    int i, j, k, n, r = 0, nr = 0, status, flag, repeats;// temp;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    // Taking input + validation
    do {
    printf("Enter the array(no spaces unless it's an element): ");
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

    //Starting from last element and moving down is a good idea
    // Deleting repeated elem is easy and it won't be revisited
    for(i = n-1; i >= 0; i--)
    {
        // Set default value as 0 each time a new element is evaluated
        repeats = 0;

        // Evaluating is the element has ever appeared before
        for(j = 0; j < i; j++)
        {
            if(arr[j] == arr[i])
            {
                // Change flag var to 1
                // To signal that element is repeating
                repeats = 1;
                // Remove the repeating element from array
                // To avoid repetition in repeating array
                for(k = j+1; k <= i; k++)
                {
                    arr[k-1] = arr[k];
                }
                // Everything is shifter 1 elem back
                // So ith position is new too
                i--;
            }
        }

        // If repeats is 0 then add element to non repeating array
        // If repeats is 1 then add element to repeating array
        if(repeats == 0)
        {
            non_repeating[nr] = arr[i];
            nr++;
        }
        else
        {
            repeating[r] = arr[i];
            r++;
        }
    }


    // Printing the repeating array
    printf("\n\n--- REPEATING ARRAY ---\n");
    printf("{");
    for(i = 0; i < r-1; i++)
        printf(" %c,", repeating[i]);
    printf(" %c}\n", repeating[r-1]);


    // Printing the non-repeating array
    printf("\n\n--- NON REPEATING ARRAY ---\n");
    printf("{");
    for(i = 0; i < nr-1; i++)
        printf(" %c,", non_repeating[i]);
    printf(" %c}\n", non_repeating[nr-1]);

    return 0;
}