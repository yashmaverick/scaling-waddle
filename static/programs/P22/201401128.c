#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size_min,size_max;
int heap_min[200005],heap_max[200005];

void insert_min(long long int x)
{
    int i=++size_min;
    for(;i>1 && heap_min[i/2]>x;i/=2)
    {
        heap_min[i]=heap_min[i/2];
    }
    heap_min[i]=x;
}

int delete_min()
{
    if(size_min==0)
        return -1;
    int min=heap_min[1];
    int last=heap_min[size_min--];
    int i,min_child;
    for(i=1;i<=size_min/2;i=min_child)
    {
        min_child=2*i;
        if(2*i!=size_min && heap_min[2*i+1]<heap_min[2*i])
            min_child=2*i+1;
        if(last<heap_min[min_child])
            break;
        else
            heap_min[i]=heap_min[min_child];
    }
    heap_min[i]=last;
    return min;
}

void insert_max(long long int x)
{
    int i=++size_max;
    for(;i>1 && heap_max[i/2]<x;i/=2)
    {
        heap_max[i]=heap_max[i/2];
    }
    heap_max[i]=x;
}

int delete_max()
{
    if(size_max==0)
        return -1;
    int max=heap_max[1];
    int last=heap_max[size_max--];
    int i,max_child;
    for(i=1;i<=size_max/2;i=max_child)
    {
        max_child=2*i;
        if(2*i!=size_max && heap_max[2*i+1]>heap_max[2*i])
            max_child=2*i+1;
        if(last>heap_max[max_child])
            break;
        else
            heap_max[i]=heap_max[max_child];
    }
    heap_max[i]=last;
    return max;
}

int main()
{
    int t,n,i;
    long long a,b,c,ans,cur;
    scanf("%d",&t);
    while(t--)
    {
        size_max=size_min=0;
        scanf("%lld%lld%lld%d",&a,&b,&c,&n);
        ans=1;
        insert_max(1);
        for(i=2;i<=n;i++)
        {
            if(size_min==size_max)
            {
               cur=(a*heap_max[1]+b*i+c)%1000000007;
               ans+=cur;
               if(cur>heap_max[1])
                   insert_min(cur);
               else
                   insert_max(cur);
            }
            else if(size_max==size_min+1)
            {
               cur=(a*heap_max[1]+b*i+c)%1000000007;
               ans+=cur;
               if(cur>heap_max[1])
                    insert_min(cur);
               else
               {
                    insert_min(delete_max());
                    insert_max(cur);     
               }
            }
            else if(size_min==size_max+1)
            {
               cur=(a*heap_min[1]+b*i+c)%1000000007;
               ans+=cur;
               if(cur<heap_min[1])
                   insert_max(cur);
               else
               {
                   insert_max(delete_min());
                   insert_min(cur);
               }
            }
//            printf("for %d cur is %lld\n",i,cur);

        }
        printf("%lld\n",ans);
 //       memset(heap_min,0,sizeof(heap_min));
 //       memset(heap_max,0,sizeof(heap_max));
    }
return 0;
}
