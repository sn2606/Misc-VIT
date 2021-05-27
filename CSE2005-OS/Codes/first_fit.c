// C program to simulate first fit algorithm

# include <stdio.h>
# include <stdlib.h>
# define MAX 10

// Structure of memory
typedef struct mem
{
    int *mem_blocks;
    int *occupied;
    int *wastage;
}memory;

// Structure of process
typedef struct proc
{
    int *proc_blocks;
    int *allocated;
}process;

memory *initial_memory(memory *m, int n);
process *initial_process(process *p, int m);
int find_first_fit(memory *m, int pb, int n, int pno);
void first_fit(memory *m, process *p, int n, int g);

// MAIN FUNCTION
int main()
{
    process *procb;
    memory  *memb;
    int i, n, m, status;

    printf("------------------- FIRST FIT MEMORY ALLOCATION SCHEME -------------------\n");

    // Taking input for memory blocks
    printf("Enter no. of memory blocks: ");
    status = scanf("%d", &n);
    fflush(stdin);

    while (status == 0 || n <= 0 || n > MAX)
    {
        printf("\nInvalid Input!\n");
        printf("Enter no. of memory blocks: ");
        status = scanf("%d", &n);
        fflush(stdin);
    }

    memb = initial_memory(memb, n);

    for(i = 0; i < n; i++)
    {
        printf("Enter size of memory block %d: ", i + 1);
        status = scanf("%d", (memb->mem_blocks) + i);
        fflush(stdin);

        while (status == 0 || memb->mem_blocks[i] <= 0)
        {
            printf("\nInvalid Input!");
            printf("\nEnter size of memory block %d: ", i + 1);
            status = scanf("%d", (memb->mem_blocks) + i);
            fflush(stdin);
        }
    }

    // Taking Input for process blocks
    printf("\nEnter no. of processes: ");
    status = scanf("%d", &m);
    fflush(stdin);

    while (status == 0 || m < 0 || m > MAX)
    {
        printf("\nInvalid Input!\n");
        printf("Enter no. of processes: ");
        status = scanf("%d", &m);
        fflush(stdin);
    }

    procb = initial_process(procb, m);

    for(i = 0; i < m; i++)
    {
        printf("Enter size of process block %d: ", i + 1);
        status = scanf("%d", (procb->proc_blocks) + i);
        fflush(stdin);

        while (status == 0 || procb->proc_blocks[i] <= 0)
        {
            printf("\nInvalid Input!");
            printf("\nEnter size of process block %d: ", i + 1);
            status = scanf("%d", (procb->proc_blocks) + i);
            fflush(stdin);
        }
    }

    first_fit(memb, procb, n, m);

    return 0;    

}

// Function to initialize memory block information
memory *initial_memory(memory *m, int n)
{
    int i;

    m = (memory *)malloc(sizeof(memory));

    m->mem_blocks = (int *)malloc(n * sizeof(int));
    m->occupied   = (int *)malloc(n * sizeof(int));
    m->wastage    = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        *((m->mem_blocks) + i)  = 0;
        *((m->occupied) + i)    = -1;
        *((m->wastage) + i)     = -1;
    }

    return m;
}

// Function to initialize process block information
process *initial_process(process *p, int m)
{
    int i;

    p = (process *)malloc(sizeof(process));

    p->proc_blocks = (int *)malloc(m * sizeof(int));
    p->allocated   = (int *)malloc(m * sizeof(int));

    for(i = 0; i < m; i++)
    {
        *((p->proc_blocks) + i)  = 0;
        *((p->allocated) + i)    = -1;
    }

    return p;
}

// Function to find first fit for a memory block
int find_first_fit(memory *m, int pb, int n, int pno)
{
    int min = 0, i, flag = -1;

    for(i = 0; i < n; i++)
    {
        if(m->mem_blocks[i] >= pb && m->occupied[i] == -1)
        {
            flag = i;
            min  = m->mem_blocks[i] - pb;
            break;
        }
    }

    if (flag != -1)
    {
        m->occupied[flag] = pno;
        m->wastage[flag]  = min;
    }

    return (flag + 1);    
}

// Function to execute best fit algorithm for all processes
void first_fit(memory *m, process *p, int n, int g)
{
    int i, internal_frag = 0, external_frag = 0;

    for(i = 0; i < g; i++)
    {
        p->allocated[i] = find_first_fit(m, p->proc_blocks[i], n, i+1);
    }

    // Printing the final configuration for memory
    printf("\n\n------------------------------ MEMORY ------------------------------\n\n");
    printf("Block no.\t Block size\t Process no.\t Internal Fragmentation\n");
    printf("------------------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        if(m->occupied[i] != -1)
        {    
            printf(" \t%d\t %d kb\t\t Process %d\t %d kb\n", i + 1, m->mem_blocks[i], m->occupied[i], m->wastage[i]);
        }
        else
        {
            printf(" \t%d\t %d kb\t\t No Process\t Free\n", i + 1, m->mem_blocks[i]);
        }        
    }

    // Printing the final configuration for process
    printf("\n\n----------------  PROCESS ----------------\n\n");
    printf("Process no.\t Process size\t Block no.\n");
    printf("------------------------------------------\n");

    for(i = 0; i < g; i++)
    {
        if(p->allocated[i] != 0)
        {
            printf("  \t%d\t  %d kb\t  Block %d\n", i + 1, p->proc_blocks[i], p->allocated[i]);
        }
        else
        {
            printf("  \t%d\t  %d kb\t  Not Allocated\n", i + 1, p->proc_blocks[i]);
        }        

    }

    // Calculating total Internal and External Fragmentation
    
    for(i = 0; i < n; i++)
    {
        if(m->wastage[i] != -1)
        {
            internal_frag += m->wastage[i];
        }
        else
        {
            external_frag += m->mem_blocks[i];
        }        
    }

    printf("\nTotal Internal Fragmentation: %d KB", internal_frag);
    printf("\nTotal External Fragmentation: %d KB", external_frag);
    printf("\n\n");

}