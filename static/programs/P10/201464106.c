#include<stdio.h>
int front=-1,rear=-1,N;
char a[1004][105];
void del(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        if(front==N-1)
            front=0;
        else
            front=(front+1)%N;
    }
}

void append()
{
    if(rear==-1)
    {
        rear=0;
        front=0;
    }
    else if(front==0 && rear==N-1)
    {
        front++;rear=(rear+1)%N;
    }
    else if((front-rear)==1)
    {
        front=(front+1)%N;
        rear=(rear+1)%N;
    }
    else
    {
        rear=(rear+1)%N;
    }
        scanf("%s",a[rear]);
        //        printf("inside rear: ");
        //        printf("%s\n",a[rear]);
 }

int main()
{
    int i,n,j;
    scanf("%d",&N);
    char command,enter;
    scanf("%c%c",&enter,&command);
    while(command!='Q')
    {
        //        printf("inside while\n");
        if(command=='L')
        {
            if(front==-1 || rear==-1)
            {
                }
            else if(front<=rear)
            {
                for(i=front;i<=rear;i++)
                {
                    {
                        //                    printf("inside L\n");
                        printf("%s\n",a[i]);
                    }
                }
            }
            else
            {
                for(j=front;j<N;j++)
                    printf("%s\n",a[j]);
                for(i=0;i<=rear;i++)
                    printf("%s\n",a[i]);
            }


        }
        else if(command=='R')
        {
            scanf("%d",&n);
            //            printf("inside R\n");
            del(n);
        }
        else if(command=='A')
        {
            scanf("%d",&n);
            //            printf("inside A\n");
            for(i=0;i<n;i++)
                append();
        }
     //   printf("front: %d rear: %d\n",front,rear);
        scanf("%c%c",&enter,&command);
    }
    return 0;
}




