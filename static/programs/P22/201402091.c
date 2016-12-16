#include<stdio.h>
#define mod 1000000007
long long int size_min,size_max;
void swap(long long int* a,long long int* b)
{
    long long int temp=*b;
    *b=*a;
    *a=temp;
}
void insert_min(long long int heap[],long long int val)
{   long long int i,p;
    heap[++size_min]=val;
    i=size_min;
    while(i>1)
    {
        p=i/2;
        if(heap[p]>heap[i])
            swap(&heap[p],&heap[i]);
        i=p;
    }
}
long long int delete_min(long long int heap[])
{
    long long int mini=heap[1];
    heap[1]=heap[size_min];
    long long int min,mindex,i=1;
    while(i<=(size_min-1)/2 && (heap[i]>heap[2*i] || heap[i]>heap[2*i+1]))
    {
        if(heap[2*i]<heap[2*i+1])
        {
            min=heap[2*i];
            mindex=2*i;
        }
        else
        {
            min=heap[2*i+1];
            mindex=2*i+1;
        }
        swap(&heap[i],&min);
        i=mindex;
        heap[mindex]=min;
    }
    size_min--;
    return mini;
}
void insert_max(long long int heap[],long long int val)
{   long long int i,p;
    heap[++size_max]=val;
    i=size_max;
    while(i>1)
    {   
        p=i/2;
        if(heap[p]<heap[i])
            swap(&heap[p],&heap[i]);
        i=p;
    }   
}
long long int delete_max(long long int heap[])
{
    long long int maxi=heap[1];
    heap[1]=heap[size_max];
    long long int max,mindex,i=1;
    while(i<=(size_max-1)/2 && (heap[i]<heap[2*i] || heap[i]<heap[2*i+1]))
    {   
        if(heap[2*i]>heap[2*i+1])
        {
            max=heap[2*i];
            mindex=2*i;
        }
        else
        {
            max=heap[2*i+1];
            mindex=2*i+1;
        }
        swap(&heap[i],&max);
        i=mindex;
        heap[mindex]=max;
    }
    size_max--;
    return maxi;
}

int main()
{
    long long int t,a,b,c,n,i,x;
    scanf("%lld",&t);
    while(t--)
    {   
        long long int s=0;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
        long long int F[200005];
        long long int heap_min[200005];
        long long int heap_max[200005];
        size_min=size_max=0;
        F[1]=1;
        insert_max(heap_max,1);
        F[2]=(a+(b*2)+c)%mod;
        insert_max(heap_max,F[2]);
        insert_min(heap_min,delete_max(heap_max));
        if(n==1)
            printf("%lld\n",F[1]);
        else if(n==2)
            printf("%lld\n",F[1]+F[2]);
        else
        {   
            s=F[1]+F[2];
            for(i=3;i<=n;i++)
            {   
                if(size_max>=size_min)
                    x=heap_max[1];
                else
                    x=heap_min[1];
                F[i]=((x*a) + (b*i) + c)%mod;
                s=(s+F[i]);
                insert_max(heap_max,F[i]);
                if(heap_max[1] > heap_min[1])
                    insert_min(heap_min,delete_max(heap_max));
                if(size_max-size_min>1)
                    insert_min(heap_min,delete_max(heap_max));
                if(size_min-size_max>1)
                    insert_max(heap_max,delete_min(heap_min));
            }
            printf("%lld\n",s);
        }
    }
    return 0;
}
