#include<stdio.h>
#include<limits.h>
int main()
{
    int t,n,k,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int min_index;
        scanf("%d%d",&n,&k);
        int rear=k,front=1;
        int a[n+1];
        int min=INT_MAX;
        int ans[n-k+1];
        for(i=front;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i<=k)
            {
                if(a[i]<=min)
                {
                    min=a[i];
                    min_index=i;
                }
            }
        }
        int c=0;
        while(c!=n-k+1)
        {
            ans[c]=min;
            if(min_index==front)
            {
                rear++;
                front++;
                min=a[front];
                for(j=front;j<=rear;j++)
                {
                    if(a[j]<=min)
                    {
                        min=a[j];
                        min_index=j;
                    }
                }
           //     printf("front1: %d\trear1: %d\n",front,rear);
            }
            else
            {  
                front++;
                rear++;
                if(a[rear]<min)
                {
                    min=a[rear];
                    min_index=rear;
                }
             //   printf("front2 %d\trear2: %d\n",front,rear);
            }
            c++;
        }
        for(i=0;i<c-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[c-1]);
    }
    return 0;
}













