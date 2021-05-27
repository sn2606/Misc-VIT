#include <stdio.h>
#include <stdlib.h>
#define N 100

// C program to extract odd, even and prime numbers in an array to 3 different arrays and display this array

int parity(int a);
int primality(int a);

int main()
{

    int num[N], odd[N], even[N], prime[N];
    int i, jo = 0, je = 0, jp = 0, n, status, flag;

    printf("Enter number of integers in the array: ");
    scanf("%d", &n);
    fflush(stdin);

    // Taking input + validation
    do {printf("Enter the array: ");

    flag = 1;

    for(i = 0; i < n; i++)
    {
        status = scanf("%d", &num[i]);

        if(status == 0 || num[i] < 0)
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

    // Defining the arrays
    for(i = 0; i < n; i++)
    {
        if(parity(num[i]) == 0)
        {
            even[je] = num[i];
            je++;
        }
        if(parity(num[i]) == 1)
        {
            odd[jo] = num[i];
            jo++;
        }
        if(primality(num[i]) == 1)
        {
            prime[jp] = num[i];
            jp++;
        }
    }

    // Printing the arrays
    printf("\n--- EVEN NUMBER ARRAY ---\n");
    printf("{");
    for(i = 0; i < je-1; i++)
        printf(" %d,", even[i]);
    printf(" %d}\n", even[je-1]);

    printf("\n--- ODD NUMBER ARRAY ---\n");
    printf("{");
    for(i = 0; i < jo-1; i++)
        printf(" %d,", odd[i]);
    printf(" %d}\n", odd[jo-1]);

    printf("\n--- PRIME NUMBER ARRAY ---\n");
    printf("{");
    for(i = 0; i < jp-1; i++)
        printf(" %d,", prime[i]);
    printf(" %d}\n", prime[jp-1]);

    return 0;
}

// Function to check odd or even
int parity(int a)
{
    if(a % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Function to check prime or not
int primality(int a)
{
    int i;

    if(a <= 1)
    {
        return 0;
    }

    for(i = 2; i < a; i++)
    {
        if(a%i == 0)
        {
            return 0;
        }
    }

    return 1;
}