// C program to simulate FIFO page replacement scheme

# include <stdio.h>
# include <stdlib.h>
# define MAX 5

// Main memory
typedef struct pf
{
    int *frames;
    int capacity;
    int flag;
    int page_fault;
}page_frames;

// Stucture of Queue
typedef struct qu
{
    int count;
    int front;
    int rear;
    int *Q;
}Queue;

// Prototyping functions

page_frames *initial_pf(page_frames *p, int n);
void FIFO(page_frames *p, Queue *q, int *ps, int s, int frame);
Queue *initial_q(Queue *cq, int q);
int Is_empty(struct qu *a);
int Is_full(struct qu *a, int max);
void Enqueue(struct qu *a, int val, int frame);
int Dequeue(struct qu *a);
void Display(struct qu *a, int frame);

// Main Driver Function
int main()
{
    int status, mm_frame;
    int page_stream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int s = 20;

    // int page_stream[]  = {1, 3, 0, 3, 5, 6, 3};
    // int s = 7;

    page_frames *fifo_pf = NULL;
    Queue *queue = NULL;

    printf("Enter the number of frames in main memory: ");
    status = scanf("%d", &mm_frame);

    // Input validation
    while (status == 0 || mm_frame <= 0 || mm_frame > MAX)
    {
        printf("Invalid Input!\n");
        printf("Enter the number of frames in main memory: ");
        status = scanf("%d", &mm_frame);
        fflush(stdin);
    }

    // Initializing the data structures
    fifo_pf = initial_pf(fifo_pf, mm_frame);
    queue   = initial_q(queue, mm_frame);

    // FIFO page replacement simulation
    FIFO(fifo_pf, queue, page_stream, s, mm_frame);
    
    return 0;
}

// Function to initialize page frames data structure
// n is the number of page frame in the main memory
page_frames *initial_pf(page_frames *p, int n)
{
    p = (page_frames *)malloc(sizeof(page_frames));

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
void FIFO(page_frames *p, Queue *q, int *ps, int s, int frame)
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
            printf("| \t\t%d \n", p->flag);
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

// Function to diaplay the queue
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