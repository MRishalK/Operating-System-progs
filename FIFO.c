/*PAGE REPLACEMENT ALGORITHM USING FIFO*/

#include<stdio.h>
int main()
{
    int i,j,n,a[50],frame[10],nf,k,avail,count=0;
    printf("Enter the number of pages:\n");
    scanf("%d",&n);
    printf("\nEnter the reference string:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the number of frames:\n");
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
    {
        frame[i]=-1;
        j=0;
    }
    printf("ref string\t page frames\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<nf;k++)
        if(frame[k]==a[i])
        avail=1;
        
        if(avail==0)
        {
            frame[j]=a[i];
            j=(j+1)%nf;
            count++;
            for(k=0;k<nf;k++)
            printf("%d\t",frame[k]);
        }
        printf("\n");
    }
    printf("page fault is %d",count);
    return 0;
}