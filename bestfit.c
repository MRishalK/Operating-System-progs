/*memory allocation using bestfit*/
#include<stdio.h>
#define MAX 20

int main()
{
    int bsize[MAX],fsize[MAX],nb,nf;
    int temp,low=10000;
    static int bflag[MAX],fflag[MAX];
    int i,j;

    printf("\nEnter the number of block:");
    scanf("%d",&nb);
    for(i=0;i<nb;i++)
    {
        printf("Enter the size of block %d:",i+1);
        scanf("%d",&bsize[i]);
    }

    printf("\nEnter the number of files:");
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
    {
        printf("Enter the size of files:",i+1);
        scanf("%d",&fsize[i]);
    }

    for(i=0;i<nf;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(bflag[j]!=1)
            {
                temp=bsize[j]-fsize[i];
                if(temp>=0)
                {
                    if(low>temp)
                    {
                        fflag[i]=j;
                        low=temp;
                    }
                }
            }
        }
        bflag[fflag[i]]=1;
        low=10000;
    }
    printf("\nFile no\tFile size\tBlock no\tBlock size\n");
    for(i=0;i<nf;i++)
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,fsize[i],fflag[i]+1,bsize[fflag[i]]);
    return 0;
}