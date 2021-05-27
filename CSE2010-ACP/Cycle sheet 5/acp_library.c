
/**********************************************************************************************************
 *                      LIBRARY OF MEMORY ALLOCATION AND PAGE REPLACEMENT ALGORITHMS                      * 
 * *******************************************************************************************************/


# include <stdio.h>
# include <stdlib.h>
# include "acp_library.h"
# define MAX 10
# define M 5

// // Structure of memory
// typedef struct mem
// {
//     int *mem_blocks;
//     int *occupied;
//     int *wastage;
// }memory;

// // Structure of process
// typedef struct proc
// {
//     int *proc_blocks;
//     int *allocated;
// }process;

// // Main memory
// typedef struct pf
// {
//     int *frames;
//     int capacity;
//     int flag;
//     int page_fault;
// }page_frames_fifo;

// // Stucture of Queue
// typedef struct qu
// {
//     int count;
//     int front;
//     int rear;
//     int *Q;
// }Queue;

// // Main memory
// typedef struct pf2
// {
//     int *frames;
//     int *future;
//     int *current;
//     int capacity;
//     int flag;
//     int page_fault;
// }page_frames_opt;

// // Main memory
// typedef struct pf3
// {
//     int *frames;
//     int *past;
//     int *current;
//     int capacity;
//     int flag;
//     int page_fault;
// }page_frames_lru;


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

/***********************************************************************************
 *                                FIRST FIT ALGORITHM                              * 
 **********************************************************************************/


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


/***********************************************************************************
 *                                BEST FIT ALGORITHM                               * 
 **********************************************************************************/


// Function to find best fit for a memory block
int find_best_fit(memory *m, int pb, int n, int pno)
{
    int min = 0, i, flag = -1, j;

    for(i = 0; i < n; i++)
    {
        if(m->mem_blocks[i] >= pb && m->occupied[i] == -1)
        {
            flag = i;
            min  = m->mem_blocks[i] - pb;
            break;
        }
    }

    for(j = i + 1; j < n; j++)
    {
        if(m->mem_blocks[j] >= pb && m->occupied[j] == -1)
        {
            if(min > m->mem_blocks[j] - pb)
            {
               flag = j;
               min  = m->mem_blocks[j] - pb;
            }
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
void best_fit(memory *m, process *p, int n, int g)
{
    int i, internal_frag = 0, external_frag = 0;

    for(i = 0; i < g; i++)
    {
        p->allocated[i] = find_best_fit(m, p->proc_blocks[i], n, i+1);
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
        if(p->allocated[i] != -1)
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


/***********************************************************************************
 *                                WORST FIT ALGORITHM                              * 
 **********************************************************************************/

// Function to find worst fit for a memory block
int find_worst_fit(memory *m, int pb, int n, int pno)
{
    int max = 0, i, flag = -1, j;

    for(i = 0; i < n; i++)
    {
        if(m->mem_blocks[i] >= pb && m->occupied[i] == -1)
        {
            flag = i;
            max  = m->mem_blocks[i] - pb;
            break;
        }
    }

    for(j = i + 1; j < n; j++)
    {
        if(m->mem_blocks[j] >= pb && m->occupied[j] == -1)
        {
            if(max < m->mem_blocks[j] - pb)
            {
               flag = j;
               max  = m->mem_blocks[j] - pb;
            }
        }
    }

    if (flag != -1)
    {
        m->occupied[flag] = pno;
        m->wastage[flag]  = max;
    }

    return (flag + 1);    
}

// Function to execute worst fit algorithm for all processes
void worst_fit(memory *m, process *p, int n, int g)
{
    int i, internal_frag = 0, external_frag = 0;

    for(i = 0; i < g; i++)
    {
        p->allocated[i] = find_worst_fit(m, p->proc_blocks[i], n, i+1);
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


/***********************************************************************************
 *                        FIFO PAGE REPLACEMENT ALGORITHM                          * 
 **********************************************************************************/


// Function to initialize page frames data structure
// n is the number of page frame in the main memory
page_frames_fifo *initial_pf(page_frames_fifo *p, int n)
{
    p = (page_frames_fifo *)malloc(sizeof(page_frames_fifo));

    p->frames     = (int *)malloc(n * sizeof(int));
    p->capacity   = n;
    p->flag       = 0;
    p->page_fault = 0;

    return p;
}

// Function to perform FIFO Page Replacement
// p = Page Frame data structure
// q is queue for FIFO principle, keeps track of pages in FIFO order
// ps is the Page Stream to be checked
// s is the length of page stream
// frame is the number of page frames in main memory
void FIFO(page_frames_fifo *p, Queue *q, int *ps, int s, int frame)
{
    int i, j, repl;

    printf("\nPAGE FRAMES \t PAGE FAULT\n");
    printf("------------------------------\n");

    for(i = 0; i < s; i++)
    {
        if(p->capacity != 0)
        {
            p->flag = 0;
            //(p->page_fault)++;

            Enqueue(q, *(ps + i), frame);
            p->frames[frame - p->capacity] = ps[i];

            (p->capacity)--;

            for(j = 0; j < (frame - p->capacity); j++)
            {
                printf("| %d ", p->frames[j]);
            }
            printf("|");
            for(j = 0; j <= p->capacity; j++)
            {
                printf("    ");
            }
            printf("\t%d\n", p->flag);  
            
        }
        else
        {
            p->flag = 0;

            // Searching for the page
            for(j = 0; j < frame; j++)
            {
                if(p->frames[j] == *(ps + i))
                {
                    p->flag = 1;
                    break;
                }
            }

            // If there's a page fault, then we'll replace
            if(p->flag == 0)
            {
                repl = Dequeue(q);
                // Display(q, frame);
                // printf("repl = %d\n", repl);
                Enqueue(q, ps[i], frame);
                // Display(q, frame);
                for(j = 0; j < frame; j++)
                {
                    if(p->frames[j] == repl)
                    {
                        p->frames[j] = *(ps + i);
                    }
                }
            }

            for(j = 0; j < frame; j++)
            {
                printf("| %d ", p->frames[j]);
            }
            printf("| \t%d \n", p->flag);
        }

        if(p->flag == 0)
            (p->page_fault)++;

        //Display(q);

    }

    printf("\nTotal no. of page faults : %d\n", p->page_fault);
    printf("Total no. of hits: %d\n", s - p->page_fault);
    printf("Hit ratio : %0.2f\n\n", ((float)(s - p->page_fault))/((float)s));
}

// Function to initialize the queue data structure
Queue *initial_q(Queue *cq, int q)
{
    cq = (Queue *)malloc(sizeof(Queue));
    cq->count = 0;
    cq->front = -1;
    cq->rear = -1;
    cq->Q    = (int *)malloc(q * sizeof(int));

    return cq;
}

// Function to check if the queue is empty
int Is_empty(struct qu *a)
{
    if(a->count == 0)
        return 1;

    return 0;
}

// Function to check if the queue is full
int Is_full(struct qu *a, int max)
{
    if(a->count == max)
        return 1;
    return 0;
}

// Function to enqueue an element
void Enqueue(struct qu *a, int val, int frame)
{
    if(Is_full(a, frame))
    {
        printf("\nQueue Overflow!\n\n");
        return;
    }
    else
    {
        a->rear = (a->rear + 1) % frame;
        a->Q[a->rear] = val;

        if(a->front == -1)
        {
            a->front = a->front + 1;
        }
        a->count = a->count + 1;
    }
    
}

// Function to dequeue an element
int Dequeue(struct qu *a)
{
    int ret;

    if(Is_empty(a))
    {
        printf("\nQueue Underflow! No elements to dequeue.\n\n");
        return -1;
    }
    else
    {
        ret = a->Q[a->front];

        a->Q[a->front] = 28;
        if(a->front == a->rear)
        {
            a->front = -1;
            a->rear = -1;
        }
        else
        {
            a->front = a->front + 1;
        }
        a->count = a->count - 1;
    }

    return ret;    
}

// Function to display the queue
void Display(struct qu *a, int frame)
{
    int i, j;
    if(Is_empty(a))
    {
        printf("\nQueue Underflow! No elements to display.\n\n");
        return;
    }
    else
    {
        printf("\n------ QUEUE ------\n\n");
        printf("|");
        for(i = a->front, j = 0; j < a->count ; i = (i+1) % frame, j++)
        {
            printf(" %d |", a->Q[i]);
        }
        printf("\n\n");
    }    
}

/***********************************************************************************
 *                      OPTIMAL PAGE REPLACEMENT ALGORITHM                         * 
 **********************************************************************************/


// Function to initialize page frames data structure
// n is the number of page frame in the main memory
page_frames_opt *initial_pf2(page_frames_opt *p, int n)
{
    int i;
    
    p = (page_frames_opt *)malloc(sizeof(page_frames_opt));

    p->frames     = (int *)malloc(n * sizeof(int));
    p->future     = (int *)malloc(n * sizeof(int));
    p->current    = (int *)malloc(n * sizeof(int));
    p->capacity   = n;
    p->flag       = 0;
    p->page_fault = 0;

    for(i = 0; i < n; i++)
    {
        p->future[i]  = -1;
        p->current[i] = -1;
    }

    return p;
}

// Find future reference
// Fut is the array that will store future index; ps is the page stream
// cur is the array that will store current indices
// s is length of the page stream, frame is the no of frames in main memory
void future_ref_opt(int *cur, int *fut, int *ps, int s, int frame)
{
    int i, j, flag;

    for(i = 0; i < frame; i++)
    {
        flag = 0;
        for(j = cur[i] + 1; j < s; j++)
        {
            if(ps[j] == ps[cur[i]])
            {
                fut[i] = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            fut[i] = -1;
        }
    }
}

// Function to find index of page to replace
int find_rep_opt(int *fut, int frame)
{
    int ind, max;

    max = 0;

    for(ind = 0; ind < frame; ind++)
    {
        if(fut[ind] == -1)
            return ind;
        else if(fut[max] < fut[ind])
        {
            max = ind;
        }
    }

    return max;
}

// Function to simulate optimal page replacement algorithm
// p = Page Frame data structure
// ps is the Page Stream to be checked
// s is the length of page stream
// frame is the number of page frames in main memory
void OPT(page_frames_opt *p, int *ps, int s, int frame)
{
    int i, j, repl;

    printf("\nPAGE FRAMES \t PAGE FAULT\n");
    printf("------------------------------\n");

    for(i = 0; i < s; i++)
    {
        if(p->capacity != 0)
        {
            p->flag = 0;
            //(p->page_fault)++;

            p->frames[frame - p->capacity] = ps[i];
            p->current[frame - p->capacity] = i;

            (p->capacity)--;

            for(j = 0; j < (frame - p->capacity); j++)
            {
                printf("| %d ", p->frames[j]);
            }
            printf("|");
            for(j = 0; j <= p->capacity; j++)
            {
                printf("    ");
            }
            printf("\t%d\n", p->flag);  
            
        }
        else
        {
            p->flag = 0;

            // Searching for the page
            for(j = 0; j < frame; j++)
            {
                if(p->frames[j] == *(ps + i))
                {
                    p->flag = 1;
                    p->current[j] = i;
                    break;
                }
            }

            // If there's a page fault, then we'll replace
            if(p->flag == 0)
            {
                future_ref_opt(p->current, p->future, ps, s, frame);
                repl = find_rep_opt(p->future, frame);

                p->frames[repl]  = *(ps + i);
                p->current[repl] = i;
            }

            for(j = 0; j < frame; j++)
            {
                printf("| %d ", p->frames[j]);
            }
            printf("| \t%d \n", p->flag);
        }

        if(p->flag == 0)
            (p->page_fault)++;

    }

    printf("\nTotal no. of page faults : %d\n", p->page_fault);
    printf("Total no. of hits: %d\n", s - p->page_fault);
    printf("Hit ratio : %0.2f\n\n", ((float)(s - p->page_fault))/((float)s));
}


/***********************************************************************************
 *                         LRU PAGE REPLACEMENT ALGORITHM                          * 
 **********************************************************************************/


// Function to initialize page frames data structure
// n is the number of page frame in the main memory
page_frames_lru *initial_pf3(page_frames_lru *p, int n)
{
    int i;
    
    p = (page_frames_lru *)malloc(sizeof(page_frames_lru));

    p->frames     = (int *)malloc(n * sizeof(int));
    p->past       = (int *)malloc(n * sizeof(int));
    p->current    = (int *)malloc(n * sizeof(int));
    p->capacity   = n;
    p->flag       = 0;
    p->page_fault = 0;

    for(i = 0; i < n; i++)
    {
        p->past[i]  = -1;
        p->current[i] = -1;
    }

    return p;
}

// Find past reference
// past is the array that will store past index; ps is the page stream
// cur is the array that will store current indices
// s is length of the page stream, frame is the no of frames in main memory
void min_used_index(int *cur, int *past, int *ps, int s, int frame)
{
    int i, j, flag;

    for(i = 0; i < frame; i++)
    {
        flag = 0;
        for(j = cur[i]; j >= 0; j--)
        {
            if(ps[j] == ps[cur[i]])
            {
                past[i] = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            past[i] = -1;
        }
    }
}

// Function to find index of page to replace
int find_rep_lru(int *past, int frame)
{
    int ind, min;

    min = 0;

    for(ind = 0; ind < frame; ind++)
    {
        if(past[ind] == -1)
            return ind;
        else if(past[min] >= past[ind])
        {
            min = ind;
        }
    }

    return min;
}

// Function to simulate LRU page replacement algorithm
// p = Page Frame data structure
// ps is the Page Stream to be checked
// s is the length of page stream
// frame is the number of page frames in main memory
void LRU(page_frames_lru *p, int *ps, int s, int frame)
{
    int i, j, repl;

    printf("\nPAGE FRAMES \t PAGE FAULT\n");
    printf("------------------------------\n");

    for(i = 0; i < s; i++)
    {
        if(p->capacity != 0)
        {
            p->flag = 0;
            //(p->page_fault)++;

            p->frames[frame - p->capacity] = ps[i];
            p->current[frame - p->capacity] = i;

            (p->capacity)--;

            for(j = 0; j < (frame - p->capacity); j++)
            {
                printf("| %d ", p->frames[j]);
            }
            printf("|");
            for(j = 0; j <= p->capacity; j++)
            {
                printf("    ");
            }
            printf("\t%d\n", p->flag);  
            
        }
        else
        {
            p->flag = 0;

            // Searching for the page
            for(j = 0; j < frame; j++)
            {
                if(p->frames[j] == *(ps + i))
                {
                    p->flag = 1;
                    p->current[j] = i;
                    break;
                }
            }

            // If there's a page fault, then we'll replace
            if(p->flag == 0)
            {
                min_used_index(p->current, p->past, ps, s, frame);

                // for(int e = 0; e < frame; e++)
                //     printf("%d   ", p->past[e]);

                // printf("\n");

                repl = find_rep_lru(p->past, frame);

                p->frames[repl]  = *(ps + i);
                p->current[repl] = i;
            }

            for(j = 0; j < frame; j++)
            {
                printf("| %d ", p->frames[j]);
            }
            printf("| \t%d \n", p->flag);
        }

        if(p->flag == 0)
            (p->page_fault)++;

    }

    printf("\nTotal no. of page faults : %d\n", p->page_fault);
    printf("Total no. of hits: %d\n", s - p->page_fault);
    printf("Hit ratio : %0.2f\n\n", ((float)(s - p->page_fault))/((float)s));
}