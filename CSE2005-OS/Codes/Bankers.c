#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int curr[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max_claim[5][3]= {{8,5,3},{3,2,2},{9,0,2},{6,2,2},{4,5,3}};
    int avl[3]= {3,3,2};
    int alloc[3] = {0, 0, 0};
    int max_res[3]= {10,5,7};
    int running[5];
 
    int i, j, exec, r=3, p=5;
    int count = 0;
    bool safe = false;
 

    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }
 

 
    printf("\nInstances: \n");
    for (i = 0; i < r; i++)
        printf("%d ", max_res[i]);
 
    printf("\n\nThe Allocation Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }
 
    printf("\nThe Maximum Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += curr[i][j];
    
 
    while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
 
                if (exec) {
                    printf("\n\n\nProcess[%d] is executing.\n", i);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avl[j] += curr[i][j];
                    break;
                }
            }
        }
 
        if (!safe) {
            printf("\nThe processes are in unsafe state.");
            break;
        }
 
        if (safe)
            printf("\nThe process is in safe state.");
 
        printf("\nAvailable:  ");
        for (i = 0; i < r; i++)
            printf("%d ", avl[i]);
    }
    printf("\n\n");
    return 0;
}