#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define mod 1000000007
//MINHEAP
long long int minheap[200004],mins=0;

void minswap(long long int *i,long long int *j)
{
    long long int temp=*i;
    *i=*j;
    *j=temp;
}

void minpush(long long int a)
{
    mins++;
    minheap[mins]=a;
    long long int temp=mins;
    while(a<minheap[temp/2]&&temp/2>0)
    {
        minswap(&minheap[temp],&minheap[temp/2]);
        temp=temp/2;
    }
}
/*long long int findmin(long long int key)
{
    long long int l=key<<1;
    if(minheap[l]==-1)
        return (l+1);
    if(minheap[l+1]==-1)
        return l;
    if(minheap[l]<minheap[l+1])
        return l;
    else
        return l+1;
}
void minpop()
{
    long long int key=1,min;
    minheap[key]=minheap[mins];
    min=findmin(key);
    while((key<<1) <= mins && minheap[key] > minheap[min])
    {
        minswap(&minheap[key],&minheap[min]);
        key=min;
        min=findmin(key);
    }
    minheap[mins--]=-1;
}
*/
long long int minpop()
{
    minswap(&minheap[1],&minheap[mins]);
    mins--;
    long long int ind=1;
    while(ind*2<=mins)
    {
        long long int child=ind*2;
        if(child+1<=mins)
        {
            if(minheap[child+1]<minheap[child])
                child++;

        }
        if(minheap[ind]>minheap[child])
        {
            minswap(&minheap[ind],&minheap[child]);
            ind=child;
        }
        else {
            break;
        }

    }
    return minheap[mins+1];
}

void minprint ()
{
    long long int i;
    for(i=1;i<=mins;i++)
    {
        printf("%d ",minheap[i]);
    }
    printf("\n");
}

//MAXHEAP

long long int maxheap[200004],maxs=0;

void swap(long long int *i,long long int *j)
{
    long long int temp=*i;
    *i=*j;
    *j=temp;
}

void push(long long int a)
{
    maxs++;
    maxheap[maxs]=a;
    long long int temp=maxs;
    while(a>maxheap[temp/2]&&temp/2>0)
    {
        swap(&maxheap[temp],&maxheap[temp/2]);
        temp=temp/2;
    }
}

long long int pop()
{
    swap(&maxheap[1],&maxheap[maxs]);
    maxs--;
    long long int ind=1;
    while(ind*2<=maxs)
    {
        long long int child=ind*2;
        if(child+1<=maxs)
        {
            if(maxheap[child+1]>maxheap[child])
                child++;

        }
        if(maxheap[ind]<maxheap[child])
        {
            swap(&maxheap[ind],&maxheap[child]);
            ind=child;
        }
        else {
            break;
        }

    }
    return maxheap[maxs+1];
}

void maxprint ()
{
    long long int i;
    for(i=1;i<=maxs;i++)
    {
        printf("%d ",maxheap[i]);
    }
    printf("\n");
}

//MAIN PROGRAM
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        maxs=0;
        mins=0;
        memset(minheap,-1,sizeof(minheap));
        memset(maxheap,0,sizeof(maxheap));
        long long int a,b,c,n;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
        long long int med=1,f=1;
        unsigned long long int sum=1;
        long long int i;
        push(1);
        for(i=2;i<=n;i++)
        {
            f=(((a*maxheap[1])%mod+(b*(i))%mod)%mod+c)%mod;
            sum=sum+f;
           // printf("sum is %lld\n",sum);
        /*    printf("minheap\n");
            minprint();
            printf("maxheap\n");
            maxprint();
            printf("f=%lld and sum =%llu\n",f,sum);
        */    if(f>maxheap[1])
            {
                minpush(f);
                if(mins>maxs)
                {
                    push(minheap[1]);
                    minpop();
                }
            }
            else {
                push(f);
                if(maxs> (mins+1))
                {
                    minpush(pop());
                }
            }
        }
        printf("%llu\n",sum);
    }
}
