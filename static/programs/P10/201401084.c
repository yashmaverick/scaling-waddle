#include <stdio.h>


int main()
{
    int n,x,i;
    char c;
    scanf("%d",&n);
    char a[n][101];
    int front=-1;
    int rear=-1;
    int e=0;
    for(;;)
    {
        scanf("%c",&c);
        if(c=='A')
        {
            scanf("%d",&x);
            for(i=0;i<x;i++)
            {
                if(rear<front)
                {
                    if((front-rear)==1)
                    {
                        if(front==n-1)
                            front=0;
                        else
                            front++;
                    }
                    rear++;
                }
                else if(front<rear)
                {
                    if(front==-1)
                        front=0;
                    if(rear==n-1)
                    {
                        if(front==0)
                            front++;
                        rear=0;
                    }
                    else
                        rear++;
                }
                else if(front==rear)
                {
                    if(front==-1)
                        front++;
                    if(rear==n-1)
                        rear=0;
                    else
                        rear++;
                }
                scanf("%s",a[rear]);
            }
        }
        else if(c=='L')
        {
            if(front!=-1)
            {
                if(front==rear)
                    printf("%s\n",a[front]);
                else if(front<rear)
                {
                    for(i=front;i<=rear;i++)
                    {
                        printf("%s\n",a[i]);
                    }
                }
                else
                {
                    //i=front;
                    for(i=front;i<n;i++)
                    {
                        printf("%s\n",a[i]);
                    }
                    for(i=0;i<=rear;i++)
                    {
                        printf("%s\n",a[i]);
                    }
                }
            }
        }
        else if(c=='R')
        {
            scanf("%d",&x);
            for(i=0;i<x;i++)
            {
                if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }
                else if(front<rear)
                {
                    front++;
                }
                else if(rear<front)
                {
                    if(front==n-1)
                    {
                        front=0;
                    }
                    else
                    {
                        front++;
                    }
                }
            }
        }
        else if(c=='Q')
        {
            break;
        }
    }
    return 0;
}

