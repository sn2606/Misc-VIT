// C program to simulate FIFO page replacement scheme

# include <stdio.h>
# include <stdlib.h>
# include "acp_library.h"
# define MAX 5

// Main Driver Function
int main()
{
    int status, mm_frame, *page_stream, s, i;

    page_frames_fifo *fifo_pf = NULL;
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

    FILE *fptr;
    fptr = fopen("page_stream.txt", "r");

    fscanf(fptr, "%d", &s);

    page_stream = (int *)malloc(s * sizeof(int));

    for(i = 0; i < s; i++)
    {
        fscanf(fptr, "%d", page_stream + i);
    }

    fclose(fptr);

    // Initializing the data structures
    fifo_pf = initial_pf(fifo_pf, mm_frame);
    queue   = initial_q(queue, mm_frame);

    // FIFO page replacement simulation
    FIFO(fifo_pf, queue, page_stream, s, mm_frame);
    
    return 0;
}