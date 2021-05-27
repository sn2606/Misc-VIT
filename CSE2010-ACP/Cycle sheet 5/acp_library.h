# ifndef __ACP_LIBRARY__
# define __ACP_LIBRARY__

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

// Main memory
typedef struct pf
{
    int *frames;
    int capacity;
    int flag;
    int page_fault;
}page_frames_fifo;

// Stucture of Queue
typedef struct qu
{
    int count;
    int front;
    int rear;
    int *Q;
}Queue;

// Main memory
typedef struct pf2
{
    int *frames;
    int *future;
    int *current;
    int capacity;
    int flag;
    int page_fault;
}page_frames_opt;

// Main memory
typedef struct pf3
{
    int *frames;
    int *past;
    int *current;
    int capacity;
    int flag;
    int page_fault;
}page_frames_lru;

extern memory *initial_memory(memory *m, int n);
extern process *initial_process(process *p, int m);
extern int find_first_fit(memory *m, int pb, int n, int pno);
extern void first_fit(memory *m, process *p, int n, int g);
extern int find_best_fit(memory *m, int pb, int n, int pno);
extern void best_fit(memory *m, process *p, int n, int g);
extern int find_worst_fit(memory *m, int pb, int n, int pno);
extern void worst_fit(memory *m, process *p, int n, int g);


extern page_frames_fifo *initial_pf(page_frames_fifo *p, int n);
extern void FIFO(page_frames_fifo *p, Queue *q, int *ps, int s, int frame);
extern Queue *initial_q(Queue *cq, int q);
extern int Is_empty(struct qu *a);
extern int Is_full(struct qu *a, int max);
extern void Enqueue(struct qu *a, int val, int frame);
extern int Dequeue(struct qu *a);
void Display(struct qu *a, int frame);

extern page_frames_opt *initial_pf2(page_frames_opt *p, int n);
extern void future_ref_opt(int *cur, int *fut, int *ps, int s, int frame);
extern int find_rep_opt(int *fut, int frame);
extern void OPT(page_frames_opt *p, int *ps, int s, int frame);

extern page_frames_lru *initial_pf3(page_frames_lru *p, int n);
extern void min_used_index(int *cur, int *past, int *ps, int s, int frame);
extern int find_rep_lru(int *past, int frame);
extern void LRU(page_frames_lru *p, int *ps, int s, int frame);


# endif