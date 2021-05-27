#include <stdio.h>
#include <stdlib.h>

// C program to print all permutations of given digits. (repetitions not allowed)

void print_arr(int arr[], int size);
void exchange(int *a, int *b);
void permute(int *arr, int start, int end);

int main()
{
    //taking input to the array
    int size, i, arr[10];
    printf("Enter the size of array: ");
    scanf("%d",&size);

    for(i=0;i<size;i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d",&arr[i]);
    }

	//calling permutation function
    permute(arr, 0, size-1);

    return 0;
}

//function to print the array
void print_arr(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

//function to swap the variables
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Permutation function
void permute(int *arr, int start, int end)
{
    int i;

	if(start==end)
    {
        print_arr(arr, end+1);
        return;
    }

    for(i=start; i<=end; i++)
    {
        //swapping numbers
        exchange((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permute(arr, start+1, end);
        exchange((arr+i), (arr+start)); // Restore in the end for next round
    }
}
