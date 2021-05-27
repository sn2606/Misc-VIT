#include<stdio.h>

struct process
{
    int process_no;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
    int RT;
    int BT_remaining;
    int init_scheduling;
}p[15],temp;

void main()
{
    int n,i,k,current_time,TQ,counter,sum_TAT=0,sum_WT=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the value for time quantum: ");
    scanf("%d",&TQ);
    for(i=0;i<n;i++)//Read the values of AT and BT for all n processes
    {
        p[i].process_no=i+1;
        printf("\n\nEnter the arrival time for process%d: ",p[i].process_no);
        scanf("%d",&p[i].AT);
        printf("\nEnter the burst time for process%d :",p[i].process_no);
        scanf("%d",&p[i].BT);
        p[i].BT_remaining=p[i].BT;
        p[i].init_scheduling=-1;
    }
    current_time=0;
    counter=0;//Count the number of processes that have finished execution
    printf("\n\nGantt chart: ");
    while(counter<n)
    {
        if(p[counter].init_scheduling==-1)
        {
            p[counter].init_scheduling=current_time;
            p[counter].RT=current_time-p[counter].AT;
        }
        if(p[counter].BT_remaining>TQ)
        {
            printf("\n%d-%d: P%d",current_time,current_time+TQ,p[counter].process_no);
            current_time+=TQ;
            p[counter].BT_remaining-=TQ;
            k=counter;//Position to be inserted (after all arrived processes)
            for(i=counter+1;i<n;i++)
            {
                if(p[i].AT<=current_time)
                k++;//Number of newly arrived processes
            }
            temp=p[counter];
            for(i=counter;i<k;i++)
            {
                p[i]=p[i+1];
            }
            p[k]=temp;
        }
        else
        {
            printf("\n%d-%d: P%d",current_time,current_time+p[counter].BT_remaining,p[counter].process_no);
            current_time+=p[counter].BT_remaining;
            p[counter].CT=current_time;
            p[counter].BT_remaining=0;
            p[counter].TAT=p[counter].CT-p[counter].AT;
            p[counter].WT=p[counter].TAT-p[counter].BT;
            sum_TAT+=p[counter].TAT;
            sum_WT+=p[counter].WT;
            counter++;
        }
    }
    printf("\n\n\tAverage TAT is %.2f",(float)sum_TAT/n);
    printf("\n\tAverage WT is %.2f",(float)sum_WT/n);
}