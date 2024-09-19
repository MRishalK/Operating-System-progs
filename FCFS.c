#include<stdio.h>

void main()
{
    int nPro,i;
    float resWT=0,avgWT,resTT=0,avgTT;

    printf("Enter the number of process:");
    scanf("%d",&nPro);

    int bt[nPro],p[nPro],wt[nPro],tt[nPro];

    for(i=0;i<nPro;i++)
    {
        printf("Enter the burst time of %dth process:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
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
    
    printf("\nPROCESS\tBT\tWT\tTT");
    for(i=0;i<nPro;i++)
    {
        if(i>0)
        {
            wt[i]=wt[i-1]+bt[i-1];
        }
        tt[i]=wt[i]+bt[i];
    
        printf("\n%d\t%d\t%d\t%d\t",p[i],bt[i],wt[i],tt[i]);
    }
printf("\nAverage waiting time=%f",avgWT);
printf("\nAverage Turnaround time=%f",avgTT);

}
