#include <stdio.h>
#include <stdlib.h>


struct Processes
{
    int burstTime, priority, arrivalTime, flag, remainingTime;
    int completionTime, turnaroundTime, waitingTime, cpu, rt, id, cot;
};

void main()
{
    struct Processes process[10],tmp;
    int a, totalNumber, totalTime = 0, highest;
    printf("Enter the number of process for the scheduler:\t");
    scanf("%d", &totalNumber);

    while (totalNumber > 8 && totalNumber < 1)
    {
        printf("Invalid! Enter the number of process for the scheduler:\t");
        scanf("%d", &totalNumber);
    }
    
    for (a = 0; a < totalNumber; a++)
    {
        printf("\nEnter the details for the process P%d\n", a + 1);
        printf("Arrival time: ");
        scanf("%d", &process[a].arrivalTime);
        printf("Burst time: ");
        scanf("%d", &process[a].burstTime);
        process[a].remainingTime = process[a].burstTime;
        printf("Priority: ");
        scanf("%d", &process[a].priority);
        totalTime += process[a].burstTime;
        totalTime += process[a].arrivalTime;
        process[a].flag = -1;
        process[a].id = a + 1;
        process[a].cot = 0;
    }

    int b;
    for (a = 0; a < totalNumber; a++)
    {
        for (b = a + 1; b < totalNumber; b++)
        {
            if (process[a].arrivalTime > process[b].arrivalTime)
            {
                tmp = process[a];
                process[a] = process[b];
                process[b] = tmp;
            }
        }
    }

    process[9].priority = 999;
    process[9].remainingTime = 9999;
    process[9].flag = -1;
    int previousId, first = 1;
    int last = 0;
    system("CLS");
    printf("GANTT CHART\n\n");
    int currentTime = process[0].arrivalTime;
    printf("\n|");
    while (currentTime < 100)
    {
        highest = 9;

        for (a = 0; a < totalNumber; a++)
        {
            if (currentTime - process[a].cot >= 2)
            {
                if (process[a].flag == -2)
                {
                    process[a].priority -= 2;
                }
            }
        }

        for (a = 0; a < totalNumber; a++)
        {
            if (process[a].remainingTime > 0)
            {
                if (process[a].priority < process[highest].priority)
                {
                    if (process[a].arrivalTime <= currentTime)
                    {
                        highest = a;
                    }
                }
            }
        }

        printf("\nSelected P%d\n", process[highest].id);

        if (process[highest].flag == -2)
        {
            process[highest].flag = -1;
        }

        if (process[highest].id != process[previousId].id)
        {
            process[previousId].flag = -2;
            process[previousId].cot = currentTime;
            if (process[highest].id != 0)
                printf("%d - |", currentTime);
            currentTime += 2;
        }

        if (process[highest].flag == -1)
        {
            process[highest].flag = 0;
            process[highest].cpu = currentTime;
        }

        if (process[highest].id != 0)
            printf("%d P%d |", currentTime, process[highest].id);

        previousId = highest;
        process[highest].remainingTime--;
        currentTime++;

        printf("Current time %d\n", currentTime);

        if (process[highest].remainingTime == 0 && process[highest].id != 0)
        {
            process[highest].flag = 1;
            process[highest].completionTime = currentTime;
            process[highest].turnaroundTime = process[highest].completionTime - process[highest].arrivalTime;
            process[highest].waitingTime = process[highest].turnaroundTime - process[highest].burstTime;
            process[highest].rt = process[highest].cpu - process[highest].arrivalTime;
            last = highest;
            continue;
        }
    }
    printf("%d", process[last].completionTime);
    printf("\n\n\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time \tWait Time \t\n");
    for (a = 0; a < totalNumber; a++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", a + 1, process[a].arrivalTime, process[a].burstTime, process[a].completionTime, process[a].turnaroundTime, process[a].waitingTime, process[a].rt);
    }
}