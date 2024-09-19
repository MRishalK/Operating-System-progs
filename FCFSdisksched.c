/*disk scheduling algorithm using FCFS*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial;
    printf("\n******FCFS DISK SCHEDULING******\n");
    printf("Enter the number of requests:");
    scanf("%d",&n);
    printf("\nEnter the request sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }
    printf("\nEnter the initial head position:");
    scanf("%d",&initial);

    for(i=0;i<n;i++)
    {
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("\nTOTAL HEAD MOVEMENT = %d\n",TotalHeadMoment);
    return 0;
}