// Implementation of First Come First Serve algorithm
# include <stdio.h>
# include <stdlib.h>
# define N 10

int * process_ordered(int *arr, int n, int *arr_reo);
int * wait_time(int *arr, int *bt, int *wt, int n);
int * turn_time(int *arr, int *wt, int *bt, int *tat, int n);

int main()
{
    int process[N], burst_time[N], *waiting_time, *turnaround_time;
    int *process_reo;
    int n, status, i;

    waiting_time = (int *)malloc(N*sizeof(int));
    turnaround_time = (int *)malloc(N*sizeof(int));
    process_reo = (int *)malloc(N*sizeof(int)); 

    printf("\n----- FIRST COME FIRST SERVE SCHEDULING -----\n\n");
    printf("Enter the number of processes: ");
    status = scanf("%d", &n);
    fflush(stdin);

    while (status == 0 || n > N || n <= 0)
    {
        printf("Invalid Input!\n");
        printf("Enter the number of processes: ");
        status = scanf("%d", &n);
        fflush(stdin);
    }    

    for(i = 1; i <= n; i++)
    {
        printf("Enter the order of arrival of process %d: ", i);
        status = scanf("%d", &process[i]);
        fflush(stdin);

        while (status == 0 || n > N || n <= 0)
        {
            printf("Invalid Input!\n");
            printf("Enter the order of arrival of process %d: ", i);
            status = scanf("%d", &process[i]);
            fflush(stdin);
        }
    }

    burst_time[0] = 0;

    for(i = 1; i <= n; i++)
    {
        printf("Enter the burst time of process %d: ", i);
        status = scanf("%d", &burst_time[i]);
        fflush(stdin);

        while (status == 0 || n > N || n <= 0)
        {
            printf("Invalid Input!\n");
            printf("Enter the burst time of process %d: ", i);
            status = scanf("%d", &burst_time[i]);
            fflush(stdin);
        }
    }

    process_reo = process_ordered(process, n, process_reo);

    waiting_time = wait_time(process, burst_time, waiting_time, n);

    turnaround_time = turn_time(process, waiting_time, burst_time, turnaround_time, n);

    printf("\nProcess   Burst Time  Wait time   Turnaround time\n");

    for (i = 1; i <= n; i++)
    {
        printf("\n  P%d         %d          %d          %d", process_reo[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    

    return 0;
}

int * process_ordered(int *arr, int n, int *arr_reo)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(arr[j] == i)
            {
                arr_reo[i] = j;
                break;
            }
        }
    }

    return arr_reo;
}

int * wait_time(int *arr, int *bt, int *wt, int n)
{
    int i, ind;

    wt[0] = 0;

    for(i = 1; i <= n; i++)
    {
        ind = arr[i];
        wt[ind] = wt[ind - 1] + bt[ind - 1];
    }

    return wt;

}

int * turn_time(int *arr, int *wt, int *bt, int *tat, int n)
{
    int i, ind;
    
    tat[0] = 0;

    for(i = 1; i <= n; i++)
    {
        ind = arr[i];
        tat[ind] = wt[ind] + bt[ind];
    }

    return tat;
}