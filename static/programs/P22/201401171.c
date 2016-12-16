#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxN  2345678
#define mod 1000000007

long long int heapmin[maxN],heapSizemin;
long long int heapmax[maxN],heapSizemax;

void insertmin(long long int num)
{
    if (heapSizemin==0)
    {
        heapSizemin=1;
        heapmin[1]=num;
        return;
    }
    long long int location=++heapSizemin;
    long long int parentnode;
    while(location>1)
    {
        parentnode = (location)/2;
        if(num>heapmin[parentnode])
        {
            heapmin[location]=num;
            return;
        }
        heapmin[location]=heapmin[parentnode];
        location=parentnode;
    }
    heapmin[1]=num;
}

long long int deletemin()
{
    long long int minElement,lastElement,child,now;
    minElement=heapmin[1];
    if (heapSizemin==1)
    {
        heapSizemin--;
        return heapmin[1];
    }
    lastElement= heapmin[heapSizemin--];
    for(now=1;now*2<=heapSizemin;now=child)
    {
        child=now*2;
        if (child!=heapSizemin && heapmin[child+1]<heapmin[child])
        {
            child++;
        }
        if (lastElement>heapmin[child])
            heapmin[now]=heapmin[child];
        else
            break;
    }        
    heapmin[now]=lastElement;
    return minElement;
}

void insertmax(long long int num)
{
    if (heapSizemax==0)
    {
        heapSizemax=1;
        heapmax[1]=num;
        return;
    }
    long long int location=++heapSizemax;
    long long int parentnode;
    while(location>1)
    {   
        parentnode = (location)/2;
        if(num<heapmax[parentnode])
        {   
            heapmax[location]=num;
            return;
        }   
        heapmax[location]=heapmax[parentnode];
        location=parentnode;
    }   
    heapmax[1]=num;
}

long long int deletemax()
{
    long long int maxElement,lastElement,child,now;
    maxElement=heapmax[1];
    if (heapSizemax==1)
    {   
        heapSizemax--;
        return heapmax[1];
    }   
    lastElement= heapmax[heapSizemax--];
    for(now=1;now*2<=heapSizemax;now=child)
    {   
        child=now*2;
        if (child!=heapSizemax && heapmax[child+1]>heapmax[child])
        {   
            child++;
        }   
        if (lastElement<heapmax[child])
            heapmax[now]=heapmax[child];
        else
            break;
    }            
    heapmax[now]=lastElement;
    return maxElement;
}

void printmin()
{
    long long int i=0;
    printf("min: ");
    for(i=1;i<=heapSizemin;i++)
    {
        printf("%lld ",heapmin[i]);
    }
    printf("\n");
}

void printmax()
{
    long long int i=0;
    printf("max: ");
    for(i=1;i<=heapSizemax;i++)
    {
        printf("%lld ",heapmax[i]);
    }
    printf("\n");

}

long long int min(long long int a,long long int b){if(b>a)return a;return b;}

long long int getMedian()
{
    long long int val;
    if(heapSizemin==heapSizemax)
        val= min(heapmin[1],heapmax[1]);
    else if (heapSizemin > heapSizemax)
        val= heapmin[1];
    else
        val= heapmax[1];
    //printf("median: %lld\n",val);
    return val;
}

void addHeap(long long int val)
{
    if (val>=getMedian())
    {
        insertmin(val);
        if(heapSizemin-heapSizemax>1)
        {
            insertmax(deletemin());
        }
    }
    else
    {
        insertmax(val);
        if(heapSizemax-heapSizemin>1)
            insertmin(deletemax());
    }
}

int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int ans=1,i,a,b,c,n;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        heapSizemin=0;
        heapSizemax=0;
        insertmin(1);   
        for(i=2;i<=n;i++)
        {
            long long int m = getMedian();
            addHeap((a*m+b*i+c)%mod);
            ans=ans+(a*m+b*i+c)%mod;
            //printmin();
            //printmax();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
