// C Program to simulate LRU Page replacement scheme
// In Least Recently Used (LRU) algorithm is a Greedy algorithm 
// where the page to be replaced is least recently used
// Given memory capacity (as number of pages it can hold) and a string representing pages to be referred
// write a function to find number of page faults

# include <stdio.h>
# include <stdlib.h>
# include "acp_library.h"
# define M 5


int main()
{
    int status, mm_frame, *page_stream, s, i;

    page_frames_lru *lru_pf3 = NULL;

    FILE *fptr;
    fptr = fopen("page_stream.txt", "r");

    fscanf(fptr, "%d", &s);

    page_stream = (int *)malloc(s * sizeof(int));

    for(i = 0; i < s; i++)
    {
        fscanf(fptr, "%d", page_stream + i);
    }

    fclose(fptr);

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
    lru_pf3 = initial_pf3(lru_pf3, mm_frame);

    LRU(lru_pf3, page_stream, s, mm_frame);    
    
    return 0;
}