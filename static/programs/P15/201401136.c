#include<stdio.h>
int a[10002],b[10002];
int rear,front;
int indx,min;
void push(int num)
{
    rear++;
    if(rear==1)
    {
        b[rear]=num;
        front=1;
    }
    else
        b[rear]=num;
}
void pop()
{
    front++;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        min=1000000003;
        front=rear=0;
        int j,n,k;
        scanf("%d%d",&n,&k);
        for(j=1;j<=n;j++)
            scanf("%d",&a[j]);
        for(j=1;j<=k;j++)
        {
            push(a[j]);
            if(j==1)
            {
                min=a[j];
                indx=rear;
            }
            else
            {
                if(a[j]<=min)
                {
                    min=a[j];
                    indx=rear;
                }
            }
        }
        if(k==n)
            printf("%d\n",min);
        else
            printf("%d ",min);
        for(j=k+1;j<=n;j++)
        {
            if(indx==front)
            {
                pop();
                min=1000000003;
                push(a[j]);
                int c;
                for(c=front;c<=rear;c++)
                {
                    if(b[c]<=min)
                    {
                        min=b[c];
                        indx=c;
                    }
                }
            }
            else
            {
                pop();
                if(a[j]<=min)
                {
                    min=a[j];
                    indx=j;
                }
                push(a[j]);
            }
            if(j==n)
                printf("%d\n",min);
            else
                printf("%d ",min);
        }
    }
    return 0;
}
