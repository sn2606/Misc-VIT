// C program to simulate critical section problem
// and provide solution using Lamport's Bakery Algorithm

# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# define N 10
# define TRUE 1
# define FALSE 0

int process_num[N] = {0}, choosing[N] = {FALSE};
int resource = 0;

int max_num(int *arr);
void lock(int num);
void unlock(int num);
void use_resource(int num);
void *bakery(int num);


int main()
{
    int process[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    for(i = 0; i < N; i++)
    {
        bakery(process[i]);
    }
    
    return 0;
}

// Function to get maximum number from an array
int max_num(int *arr)
{
    int max_ticket = 0, i;

    for(i = 0; i < N; i++)
    {
        if (arr[i] > max_ticket)
        {
            max_ticket = arr[i];
        }        
    }

    return max_ticket;
}

// Function to simulate lock
void lock(int num)
{
    int i;
    
    choosing[num] = TRUE;
    process_num[num] = max_num(process_num) + 1;
    choosing[num] = FALSE;

    // Entry section
    for(i = 0; i < N; i++)
    {
        while(choosing[i]);
        while(process_num[i] != 0 && ((process_num[i] < process_num[num]) || (process_num[i] == process_num[num] && i < num)));
    }
}

// Function to simulate unlock
void unlock(int num)
{
    process_num[num] = 0;
}

// Function to use resource
void use_resource(int num)
{
    if(resource != 0)
    {
        printf("Resource is already being used by P%d\n", resource);
    }

    resource = num;

    printf("P%d is using the resource...\n", resource);

    Sleep(5);
    resource = 0;
}

// Function to implement bakery algorithm
void *bakery(int num)
{
    printf("P%d is requesting for resource...\n", num);
    lock(num);
    printf("Resource acquired by P%d, other processes cannot use it.\n", num);
    use_resource(num);
    printf("P%d is releasing resource...\n", num);
    unlock(num);
    printf("Resource unlocked.\n\n");

    return NULL;
}