/*memory allocation using WORSTFIT*/

#include<stdio.h>
#define MAX 25
void main()
{
    int frag[MAX],bsize[MAX],fsize[MAX],i,j,nb,nf,temp,highest=0;
    static int bf[MAX],ff[MAX];

    printf("\nEnter the number of block:");
    scanf("%d",&nb);
    for(i=1;i<=nb;i++)
    {
        printf("Enter the size of block %d:",i);
        scanf("%d",&bsize[i]);
    }

    printf("\nEnter the number of files:");
    scanf("%d",&nf);
    for(i=1;i<=nf;i++)
    {
        printf("Enter the size of files:",i);
        scanf("%d",&fsize[i]);
    }

    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
            temp=bsize[j]-fsize[i];
            if(temp>=0)
            {
                if(highest<temp)
                {
                    ff[i]=j;
                    highest=temp;
                }
            }
            }
        }
        frag[i]=highest;
        bf[ff[i]]=1;
        highest=0;
    }
    printf("\nFileno\t\tFilesize\tBlockno\tBlocksize\tFragment");
    for(i=1;i<=nf;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,fsize[i],ff[i],bsize[ff[i]],frag[i]);
        printf("\n");
    
}