/*#include<stdio.h>
void main()
{
int n,i,j,temp,BT[10],p[10],WT[10],CT[10],TAT[10],AT[0],pri[50];
float sumw,sumt;
printf("ENter the number of process\n");
scanf("%d",&n);
//BURST TIME
printf("\n-------Burst Time-------\n:");
for(i=0;i<n;i++)
{
p[i]=i+1;
printf("Enter the Burst Time of process %d ",p[i]);
scanf("%d",&BT[i]);
printf("Enter the Priority of process %d ",p[i]);
scanf("%d",&pri[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(pri[j]>pri[j+1])
{
temp=pri[j];
pri[j]=pri[j+1];
pri[j+1]=temp;
temp=BT[j];
BT[j]=BT[j+1];
BT[j+1]=temp;
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
printf("\nThe burst time are\n");
for(i=0;i<n;i++)
{
printf("BURST Time of process %d = %d\n",p[i],BT[i]);
printf("priority of process %d = %d\n",p[i],pri[i]);
}
//WAITING TIME
WT[0]=0;
printf("\n-------WAITING Time-------\n:");
printf("\nThe waiting time of %d process is %d \n",p[0],WT[0]);
for(i=1;i<n;i++)
{
WT[i]=WT[i-1]+BT[i-1];
printf("The waiting time of %d process is %d \n",p[i],WT[i]);
}
for(i=0;i<n;i++)
{
sumw=sumw+WT[i];
}
//TAT
printf("\n-------TURN AROUND TIME-------\n");
for(i=0;i<n;i++)
{
TAT[i]=WT[i]+BT[i];
printf("The Turn around time of %d process is %d \n",p[i],TAT[i]);
}
for(i=0;i<n;i++)
{
sumt=TAT[i]+sumt;
}
//print
printf(" P\tpri\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\n",p[i],pri[i],BT[i],WT[i],TAT[i]);
}
printf("THE AVERAGE WAITING TIME IS %f\n",sumw/n);
printf("THE AVERAGE TURN AROUND TIME IS %f\n",sumt/n);
}
*/
#include<stdio.h>

void main()
{
    int nPro,i,j,tempB,tempP,tempPR;
    float resWT=0,avgWT,resTT=0,avgTT;

    printf("Enter the number of process:");
    scanf("%d",&nPro);

    int bt[nPro],p[nPro],wt[nPro],tt[nPro],pr[nPro];

    for(i=0;i<nPro;i++)
    {
        printf("Enter the burst time of %dth process:",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the corresponding priority of the process:");
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    for(i=0;i<nPro-1;i++)
    {
        for(j=0;j<nPro-i-1;j++)
        {
            if(pr[j]>pr[j+1])
            {
                tempPR=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=tempPR;

                tempB=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=tempB;

                tempP=p[j];
                p[j]=p[j+1];
                p[j+1]=tempP;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<nPro;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        resWT=wt[i]+resWT;
    }
    avgWT=resWT/nPro;

    for(i=0;i<nPro;i++)
    {
        tt[i]=wt[i]+bt[i];
        resTT=tt[i]+resTT;
    }
    avgTT=resTT/nPro;
    
    printf("\nPROCESS\tBT\tPR\tWT\tTT");
    for(i=0;i<nPro;i++)
    {
        if(i>0)
        {
            wt[i]=wt[i-1]+bt[i-1];
        }
        tt[i]=wt[i]+bt[i];
    
        printf("\n%d\t%d\t%d\t%d\t%d\t",p[i],bt[i],pr[i],wt[i],tt[i]);
    }
printf("\nAverage waiting time=%f",avgWT);
printf("\nAverage Turnaround time=%f",avgTT);

}