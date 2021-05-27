// Implementation of Preemptive shortest job first algorithm
# include <stdio.h>
# include <stdlib.h>
# define N 10

int * burst_ordered(int *arr, int n, int *arr_reo);
int * process_exec(int *bt, int *arr_reo, int *pro, int n);
int * wait_time(int *bt, int *wt, int n);
int * turn_time(int *wt, int *bt, int *tat, int n);
void SJF(int *pro, int *wt, int *tat, int n);

int main()
{
    int burst_time[N], *waiting_time, *turnaround_time;
    int *burst_reo, *process;
    int n, status, i;

    waiting_time = (int *)malloc(N*sizeof(int));
    turnaround_time = (int *)malloc(N*sizeof(int));
    burst_reo = (int *)malloc(N*sizeof(int)); 
    process = (int *)malloc(N*sizeof(int));

    printf("\n----- SHORTEST JOB FIRST PREEMPTIVE SCHEDULING -----\n\n");
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

    burst_reo = burst_ordered(burst_time, n, burst_reo);

    process = process_exec(burst_time, burst_reo, process, n);

    waiting_time = wait_time(burst_reo, waiting_time, n);

    turnaround_time = turn_time(waiting_time, burst_reo, turnaround_time, n);

    SJF(process, waiting_time, turnaround_time, n);

    printf("\nProcess   Burst Time  Wait time   Turnaround time\n");

    for (i = 1; i <= n; i++)
    {
        printf("\n  P%d         %dms          %dms          %dms", process[i], burst_reo[i], waiting_time[i], turnaround_time[i]);
    }
    

    return 0;
}

int * burst_ordered(int *bt, int n, int *arr_reo)
{
    int i, j, temp;
    for(i = 0; i <= n; i++)
        arr_reo[i] = bt[i];

    arr_reo[0] = 0;


    for(i = 1; i <= n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            if(arr_reo[j] < arr_reo[i])
            {
                temp = arr_reo[j];
                arr_reo[j] = arr_reo[i];
                arr_reo[i] = temp;
                break;
            }
        }
    }

    return arr_reo;
}

int * process_exec(int *bt, int *arr_reo, int *pro, int n)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(bt[i] == arr_reo[j])
            {
                pro[j] = i;
                break;
            }
        }
    }

    return pro;
}

int * wait_time(int *bt, int *wt, int n)
{
    int i;

    wt[0] = 0;

    for(i = 1; i <= n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    return wt;

}

int * turn_time(int *wt, int *bt, int *tat, int n)
{
    int i;
    
    tat[0] = 0;

    for(i = 1; i <= n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    return tat;
}

void SJF(int *pro, int *wt, int *tat, int n)
{
    int t_at = 0, w_t_ = 0, i;

    for(i = 1; i <= n; i++)
    {
        printf("\n... Process %d executed.", pro[i]);
        t_at += tat[i];
        w_t_ += wt[i];
    }

    printf("\nAverage Waiting time = %f", ((float)w_t_)/((float)n));
    printf("\nAverage Turnaround time = %f\n", ((float)t_at)/((float)n));  
}