/*memory allocation using firstfit*/
#include<stdio.h>

struct process
{
    int ps;
    int flag;
} p[50];

struct sizes
{
    int size;
    int alloc;
} s[5];

int main()
{
    int i=0,np=0,n=0,j=0;

    printf("Enter the number of blocks: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the size of block %d:",i);
        scanf("%d",&s[i].size);
    }
    printf("Enter the number of process: ");
    scanf("%d",&np);
    for(i=0;i<np;i++)
    {
        printf("Enter the size of process %d:",i);
        scanf("%d",&p[i].ps);
    }

    printf("\nProcess\tProces size\tBlock\n");
    for(i=0;i<np;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i].flag!=1)
            {
                if(p[i].ps<=s[j].size)
                {
                    if(!s[j].alloc)
                    {
                        p[i].flag=1;
                        s[j].alloc=1;
                        printf("\n%d\t\t%d\t\t%d\t",i,p[i].ps,s[j].size);
                    }
                }
            }
        }
    }
    for(i=0;i<np;i++)
    {
        if(p[i].flag!=1)
            printf("\nThe process %d must wait as there is no sufficient memory",i);
    }
}
