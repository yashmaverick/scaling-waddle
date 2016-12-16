#include<stdio.h>
#include<string.h>
#define maxN 10005

int stc[maxN],arr[maxN],front,end,n,k;

void smartpush(int i)
{
    while(arr[stc[end-1]]>arr[i] && (end)>front)
    {
        end--;
    }
    stc[end]=i;
    end++;
    while((stc[front]+k)<=i)
    {
        front++;
    }
}

int display()
{
    int i;
    printf("front:%d end:%d ",front,end);
    for(i=front;i<end;i++)
    {
        printf("(%d->%d) ",i,arr[stc[i]]);
    }
    printf("\n");
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        front=0;
        end=1;
        scanf("%d %d",&n,&k);
        memset(stc,0,sizeof(stc));
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        stc[front]=0;
        if(0>=(k-1) && n!=1)
        {
            printf("%d ",arr[stc[front]]);
        }
        if(n==1 && 0>=(k-1))
        {
            printf("%d",arr[stc[front]]);
        }
        for(i=1;i<n;i++)
        {
            smartpush(i);
            //printf("%d: ",i);display();
            if(i>=(k-1) && i!=n-1)
            {
                printf("%d ",arr[stc[front]]);
            }
            if(i==n-1)
               printf("%d",arr[stc[front]]);
        }
        printf("\n");
    }
    return 0;
}
