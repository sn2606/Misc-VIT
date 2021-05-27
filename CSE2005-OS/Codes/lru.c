// C Program to simulate LRU Page replacement scheme
// In Least Recently Used (LRU) algorithm is a Greedy algorithm 
// where the page to be replaced is least recently used
// Given memory capacity (as number of pages it can hold) and a string representing pages to be referred
// write a function to find number of page faults

# include <stdio.h>
# include <stdlib.h>
# define M 5

// Main memory
typedef struct pf
{
    int *frames;
    int *past;
    int *current;
    int capacity;
    int flag;
    int page_fault;
}page_frames;

page_frames *initial_pf(page_frames *p, int n);
void min_used_index(int *cur, int *past, int *ps, int s, int frame);
int find_rep(int *past, int frame);
void LRU(page_frames *p, int *ps, int s, int frame);

int main()
{
    int status, mm_frame;
    int page_stream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int s = 20;

    // int page_stream[]  = {1, 3, 0, 3, 5, 6, 3};
    // int s = 7;

    page_frames *lru_pf = NULL;

    printf("Enter the number of frames in main memory: ");
    status = scanf("%d", &mm_frame);

    // Input validation
    while (status == 0 || mm_frame <= 0 || mm_frame > M)
    {
        printf("Invalid Input!\n");
        printf("Enter the number of frames in main memory: ");
        status = scanf("%d", &mm_frame);
        fflush(stdin);
    }

    // Initializing the data structures
    lru_pf = initial_pf(lru_pf, mm_frame);

    LRU(lru_pf, page_stream, s, mm_frame);    
    
    return 0;
}

// Function to initialize page frames data structure
// n is the number of page frame in the main memory
page_frames *initial_pf(page_frames *p, int n)
{
    int i;
    
    p = (page_frames *)malloc(sizeof(page_frames));

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
int find_rep(int *past, int frame)
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
void LRU(page_frames *p, int *ps, int s, int frame)
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

                repl = find_rep(p->past, frame);

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