// Simulating Bounded Buffer problem 
// Solution using semaphore

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# define N 5

// Node of a buffer
typedef struct bounded_buffer_node
{
    int val;
    struct bounded_buffer_node *next;
}node;

// The bounded buffer
typedef struct bounded_buffer
{
    node *front;
    node *rear;
    int empty_buffer;
    int full_buffer;
}bounded_buffer;

// The semaphore that provides mutual exclusion
typedef struct semaphore
{
    int bin_semaphore;
    bounded_buffer *list;
}semaphore;

int data = 0;

node *create_node(int num);
bounded_buffer *initial_buffer(bounded_buffer *b);
semaphore *initial_semaphore(semaphore *s);
int is_empty(bounded_buffer *b);
int is_full(bounded_buffer *b);
void add_data(bounded_buffer *b, int num);
int remove_data(bounded_buffer *b);
void wait(semaphore *s, int process_no);
void signal(semaphore *s);
void producer(semaphore *s, bounded_buffer *b);
void consumer(semaphore *s, bounded_buffer *b);

int main()
{
    int process[2] = {0, 1};
    // P0 is producer process
    // P1 is consumer process

    bounded_buffer *buffer = initial_buffer(buffer);
    semaphore *sema = initial_semaphore(sema);

    consumer(sema, buffer);
    producer(sema, buffer);
    producer(sema, buffer);
    consumer(sema, buffer);
    producer(sema, buffer);
    producer(sema, buffer);
    consumer(sema, buffer);
    producer(sema, buffer);
    producer(sema, buffer);
    producer(sema, buffer);
    producer(sema, buffer);
    consumer(sema, buffer);
    consumer(sema, buffer);
    consumer(sema, buffer);
    consumer(sema, buffer);
    
    
    return 0;
}

// Function to create a new node
node *create_node(int num)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->val  = num;
    new_node->next = NULL;
    
    return new_node;
}

// Function to initialize the shared buffer
bounded_buffer *initial_buffer(bounded_buffer *b)
{
    b = (bounded_buffer *)malloc(sizeof(b));

    b->front = NULL;
    b->rear  = NULL;
    b->empty_buffer = N;
    b->full_buffer  = 0;

    return b;
}

// Function to initialize the mutual exclusion semaphore
semaphore *initial_semaphore(semaphore *s)
{
    s = (semaphore *)malloc(sizeof(s));

    s->bin_semaphore = 1;
    // List of processes (producer or consumer) waiting on the semaphore
    s->list  = initial_buffer(s->list);

    return s;
}

// Function to check if the buffer is empty
int is_empty(bounded_buffer *b)
{
    if(b->empty_buffer == N)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

// Function to check if the buffer is full
int is_full(bounded_buffer *b)
{
    if(b->full_buffer == N)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

// Function to add the data that producer generates to the buffer
void add_data(bounded_buffer *b, int num)
{
    if(is_full(b))
    {
        errno = 1;
        perror("Buffer is Full");
        return;
    }

    node *new_node = create_node(num);

    if(is_empty(b))
    {
        b->front = new_node;
        b->rear  = new_node;
    }
    else
    {
        b->rear->next = new_node;
        b->rear       = new_node;
    }
    
    (b->empty_buffer)--;
    (b->full_buffer)++;
}

// Function to consume the data by producer
int remove_data(bounded_buffer *b)
{
    if(is_empty(b))
    {
        errno = 1;
        perror("Buffer is Empty");
        return -99;
    }

    node *temp = (node *)malloc(sizeof(node));

    temp = b->front;
    b->front = b->front->next;

    (b->empty_buffer)++;
    (b->full_buffer)--;

    return(temp->val);
}

// Function to wait on accessing the buffer
void wait(semaphore *s, int process_no)
{
    while (s->bin_semaphore <= 0);    
    (s->bin_semaphore)--;
    if(s->bin_semaphore <= 0)
    {
        node *process_wait = create_node(process_no);
        if(is_empty(s->list))
        {
            s->list->front = process_wait;
            s->list->rear  = process_wait;
        }
        else
        {
            s->list->rear->next = process_wait;
            s->list->rear  = process_wait;
        }

    }
}

// Function to signal buffer can be accessed
void signal(semaphore *s)
{
    (s->bin_semaphore)++;
    if (s->bin_semaphore > 0)
    {
        node *temp = (node *)malloc(sizeof(node));

        temp = s->list->front;
        s->list->front = s->list->front->next;
    }
}

// Producer process
void producer(semaphore *s, bounded_buffer *b)
{
    wait(s, 1);

    if(!is_full(b))
    {
        data++;
        add_data(b, data);
        printf("%d (data generated) was added to shared buffer.\n", data);
    }
    else
    {
        printf("Producer will sleep till consumer singals a wakeup.\n");
    }
    

    signal(s);
}

// Consumer process
void consumer(semaphore *s, bounded_buffer *b)
{
    wait(s, 0);

    if(!is_empty(b))
    {
        int consume = remove_data(b);
        printf("%d was consumed.\n", consume);
    }
    else
    {
        printf("Consumer will sleep till producer singals a wakeup.\n");
    }

    signal(s);
}