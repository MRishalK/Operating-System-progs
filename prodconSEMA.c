/*producer consumer problem using semaphore*/

#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int s)
{
    return(--s);
}
int signal(int s)
{
    return(++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;

    printf("\nPRODUCER PRODUCES THE ITEM %d\n",x);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nCONSUMER CONSUMES THE ITEM %d\n",x);
    x--;
    mutex=signal(mutex);
}

int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    while(1)
    {
        printf("\nEnter your choice:\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                    if((mutex==1)&&(empty!=0))
                    {
                        producer();
                    }
                    else
                    {
                        printf("BUFFER IS FULL");
                    }
                    break;
            case 2:
                    if((mutex==1)&&(full!=0))
                    {
                        consumer();
                    }
                    else
                    {
                        printf("BUFFER IS EMPTY");
                    }
                    break;
            case 3:
                    printf("EXITING FROM PROGRAM.......");
                    exit(0);
                    break;
        }
    }
}