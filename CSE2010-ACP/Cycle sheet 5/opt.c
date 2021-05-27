// C program to simulate optimal page replacement scheme
//  OS replaces the page that will not be used for the longest period of time in future

# include <stdio.h>
# include <stdlib.h>
# include "acp_library.h"
# define MAX 5


int main()
{
    int status, mm_frame, *page_stream, s, i;

    page_frames_opt *opt_pf2 = NULL;

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
    opt_pf2 = initial_pf2(opt_pf2, mm_frame);

    OPT(opt_pf2, page_stream, s, mm_frame);    
    
    return 0;
}