/*PAGE REPLACEMENT ALGORITHM USING LFU*/

#include<stdio.h>
int main()
{
    int q[50],k, cntr[20], min, c=0,i,j,n,p[50],f;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter the reference string : ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter no of frames : ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        cntr[i]=0;
        q[i]=-1;
    }
    printf("\nLeast Frequently Used");
    for(i=0;i<n;i++)
    {
        for(j=0;j<f;j++)
            if(p[i]==q[j])
            {
                cntr[j]++;
                break;
            }
        if(j==f)
        {
            min = 0;
            for(k=1;k<f;k++)
                if(cntr[k]<cntr[min])
                    min=k;
            q[min]=p[i];
            cntr[min]=1;
            c++;
        }
        printf("\n");
        for(j=0;j<f;j++)
        {
            if(q[j]==-1)
                printf("-\t");
            else
                printf("%d\t",q[j]);
        }
    }
    printf("page fault is %d\n",c);
    return 0;
}
