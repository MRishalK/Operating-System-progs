#include<stdio.h>

int main()
{
    int n,i,allCompleted=0,timeint,time=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the time quantum:");
    scanf("%d",&timeint);

    struct process{
        int bursttime;
        int num;
        int turnaroundtime;
        int waitingtime;
        int isComplete;
    }
    p[n],queue[n];
    float avgBT=0,avgWT=0,avgTAT=0;

    for(i=0;i<n;i++)
    {
        p[i].num=i+1;
        printf("Enter burst time of process %d:",p[i].num);
        scanf("%d",&p[i].bursttime);
        p[i].isComplete=0;
        queue[i]=p[i];
    }
    i=0;
    while(1)
    {
        if(allCompleted==n)
        {
            break;
        }
        if(queue[i].isComplete==1)
        {
            i=(i+1)%n;
            continue;
        }
        if(queue[i].bursttime>=timeint)
        {
            time+=timeint;
            queue[i].bursttime-=timeint;
            if(queue[i].bursttime==0)
            {
                queue[i].isComplete=1;
                allCompleted++;
                p[i].turnaroundtime=time;
            }
        }
        else
        {
            time+=queue[i].bursttime;
            queue[i].bursttime=0;
            queue[i].isComplete=1;
            allCompleted++;
            p[i].turnaroundtime=time;
        }
        i=(i+1)%n;
    }
    for(i=0;i<n;i++)
    {
        p[i].waitingtime=p[i].turnaroundtime-p[i].bursttime;
        avgWT+=p[i].waitingtime;
        avgBT+=p[i].bursttime;
        avgTAT+=p[i].turnaroundtime;
    }
    avgBT/=n;
    avgWT/=n;
    avgTAT/=n;
    printf("\nSI.\tBT\tWT\tTAT\n");
    printf("No.\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i].num,p[i].bursttime,p[i].waitingtime,p[i].turnaroundtime);
    }
    printf("Avg:\t\t%f\t%f\n",avgWT,avgTAT);
    return 0;
}