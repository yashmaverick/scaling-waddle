#include<stdio.h>
#define mod 1000000007
long long int f[200010];
long long int m[200010];
long long int maxheap[200010];
long long int minheap[200010];
long long int mincount=0;
long int maxcount=0;
long long int sum;
void insertmin(long long int num)
{
    mincount++;
    minheap[mincount]=num;
    long long int i=mincount;
    while(i!=1)
    {
        long long int parent=i/2;
        if(minheap[parent]>minheap[i])
        {
            long long int temp=minheap[parent];
            minheap[parent]=minheap[i];
            minheap[i]=temp;
            i=parent;
        }
        else
            break;
    }
}
void insertmax(long long int num)
{
    maxcount++;
    maxheap[maxcount]=num;
    long long int i=maxcount;
    while(i!=1)
    {
        long long int parent=i/2;
        if(maxheap[parent]<maxheap[i])
        {
           long long int temp=maxheap[parent];
            maxheap[parent]=maxheap[i];
            maxheap[i]=temp;
            i=parent;
        }
        else
            break;
    }
}
void delmin()
{
    minheap[1]=minheap[mincount];
    mincount=mincount-1;
    long long int i=1;
    while(i<=mincount/2)
    {
        if(minheap[2*i]<minheap[i] || minheap[2*i+1]<minheap[i])
        {
            if(minheap[2*i]<=minheap[2*i+1])
            {
               long long int temp=minheap[i];
                minheap[i]=minheap[2*i];
                minheap[2*i]=temp;
                i=2*i;
            }
            else
            {
                long long int temp=minheap[i];
                minheap[i]=minheap[2*i+1];
                minheap[2*i+1]=temp;
                i=2*i+1;
            }
        }
        else
            break;
    }
}
void delmax()
{
    maxheap[1]=maxheap[maxcount];
    maxcount=maxcount-1;
    long long int i=1;
    while(i<=maxcount/2)
    {
        if(maxheap[2*i]>maxheap[i] || maxheap[2*i+1]>maxheap[i])
        {
            if(maxheap[2*i]>=maxheap[2*i+1])
            {
                long long int temp=maxheap[i];
                maxheap[i]=maxheap[2*i];
                maxheap[2*i]=temp;
                i=2*i;
            }
            else
            {
                long long int temp=maxheap[i];
                maxheap[i]=maxheap[2*i+1];
                maxheap[2*i+1]=temp;
                i=2*i+1;
            }
        }
        else
            break;
    }
}
long long int median(long long int j)
{
    if(j==2)
        return f[1];
    else if(j==3)
    {
        if(f[1]<=f[2])
        {
            insertmax(f[1]);
            insertmin(f[2]);
            return f[1];
        }
        else
        {
            insertmax(f[2]);
            insertmin(f[1]);
            return f[2];
        }
    }
    else
    {
        if(f[j-1]>m[j-1])
            insertmin(f[j-1]);
        else if(f[j-1]<=m[j-1])
            insertmax(f[j-1]);
        long long int diff=mincount-maxcount;
        if(diff==0)
            return maxheap[1];
        else if(diff==1)
            return minheap[1];
        else if(diff==-1)
            return maxheap[1];
        else if(diff>0)
        {
            long long int temp=minheap[1];
            delmin();
            insertmax(temp);
            return maxheap[1];
        }
        else
        {
            long long int temp=maxheap[1];
            delmax();
            insertmin(temp);
            return maxheap[1];
        }
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        long long int a,b,c,n;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
        int j;
        sum=0;
        mincount=maxcount=0;
        for(j=1;j<=n;j++)
        {
            if(j==1)
            {
                f[1]=1;
                m[1]=1;
                sum=f[1];
            }
            else
            {
                m[j]=median(j);
                f[j]=(a*m[j]+(b*j)+c)%mod;
                sum=sum+f[j];
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
