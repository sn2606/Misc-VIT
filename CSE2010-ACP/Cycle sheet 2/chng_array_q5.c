#include <stdio.h>
#include <stdlib.h>
#define N 101

// C program to print out 0(2+)0

int main()
{
    int arr[N], n;
    int i, j, k, flag, status, exists = 0;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    // Taking input + validation
    do {printf("Enter the array(allowed integers are 0,2): ");

    flag = 1;

    for(i = 0; i < n; i++)
    {
        status = scanf("%d", &arr[i]);

        if(status == 0 || arr[i] == '\n' || (arr[i] != 0 && arr[i] != 2))
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

    // Printing out the sequence
    for(i = 0; i < n - 1; i++)
    {
        // Proceed only if the arr[i] is zero
        if(arr[i] == 0)
        {
            for(j = i + 1; j < n; j++)
            {
                if(arr[j] == 0)
                {
                    // Checking if all elements in between is 2
                    for(k = i + 1; k < j; k++)
                    {
                       // exists is a flag variable
                       // if 2 is not present then it will immediately
                       // break out of the loop
                       exists = 1;
                       if(arr[k] != 2)
                       {
                           exists = 0;
                           break;
                       }

                    }// third for loop ends

                    if(j == i+1 && (arr[j] == 0 && arr[i] == 0))
                    {
                        exists = 0;
                        break;
                    }
                    // If such a sequence exists then
                    // break out of loop and go to printing
                    // j value will be preserved
                    if(exists == 1)
                        break;
                }//if statement ends
            }// Second for loop ends

            // Printing the sequence if it exists
            if(exists == 1)
            {
                for(k = i; k <= j; k++)
                {
                   printf("%d", arr[k]);
                }
                printf("\n");
            }
        } // If statement ends

    }// First for loop ends

    return 0;
}