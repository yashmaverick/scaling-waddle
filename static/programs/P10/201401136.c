#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int N;
    scanf("%d",&N);
    char arr[N][110];
    char c;
    int front,rear;
    front=rear=-1;
    getchar();
    for(;;)
    {
        scanf("%c",&c);
        if(c=='A')
        {
            int i,n;
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                if(front==-1&&rear==-1)
                {
                    front=rear=0;
                    scanf("%s",arr[rear]);
                }
                else if(rear==N-1)
                {
                    rear=0;
                    if(front==0)
                        front++;
                    scanf("%s",arr[rear]);
                }
                else if(front-rear==1)
                {
                    if(front==N-1)
                        front=0;
                    else
                        front++;
                    rear++;
                    scanf("%s",arr[rear]);
                }
                else
                {
                    rear++;
                    scanf("%s",arr[rear]);
                }
            }
            getchar();
        }
        if(c=='R')
        {
            int i,n;
            scanf("%d",&n);
            getchar();
            for(i=0;i<n;i++)
            {
                if(front==rear&&front!=-1)
                    front=rear=-1;
                else if(front==N-1)
                    front=0;
                else
                    front++;
            }
        }
        if(c=='L')
        {
            if(front<=rear&&front!=-1)
            {
                int i;
                for(i=front;i<=rear;i++)
                    printf("%s\n",arr[i]);
            }
            if(front>rear)
            {
                int i;
                for(i=front;i<N;i++)
                    printf("%s\n",arr[i]);
                for(i=0;i<=rear;i++)
                    printf("%s\n",arr[i]);
            }
            scanf("\n");
        }
        if(c=='Q')
            break;
    }
    return 0;
}
