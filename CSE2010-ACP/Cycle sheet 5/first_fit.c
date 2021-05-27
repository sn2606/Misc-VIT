// C program to simulate first fit algorithm

# include <stdio.h>
# include <stdlib.h>
# include "acp_library.h"
# define MAX 10


// MAIN FUNCTION
int main()
{
    process *procb;
    memory  *memb;
    int i, n, m, status;

    printf("------------------- FIRST FIT MEMORY ALLOCATION SCHEME -------------------\n");
    
    FILE *fptr;
    fptr = fopen("proc_mem_blocks.txt", "r");

    fscanf(fptr, "%d", &n);
    memb = initial_memory(memb, n);

    for(i = 0; i < n; i++)
    {
        fscanf(fptr, "%d", (memb->mem_blocks) + i);
    }

    fscanf(fptr, "%d", &m);
    procb = initial_process(procb, m);

    for(i = 0; i < m; i++)
    {
        fscanf(fptr, "%d", (procb->proc_blocks) + i);
    }

    first_fit(memb, procb, n, m);

    return 0;    

}