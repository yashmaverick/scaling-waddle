#include<stdio.h>
long long int maxheap[200001],maxsize;
long long int minheap[200001],minsize;
long long int sum;
void maxswap(long long int *maxheap,long long int i)
{
    long long int t=maxheap[i];
    maxheap[i]=maxheap[i/2];
    maxheap[i/2]=t;
}
void maxinsert(long long int x)
{
    maxheap[++maxsize]=x;
    long long int i=maxsize;
    while(maxheap[i]>maxheap[i/2] && i>1)
    {
	maxswap(maxheap,i);
	i/=2;
    }
}
void deletemax()
{
    if(maxsize==0)
    {
	return;
    }
    maxheap[1]=maxheap[maxsize];
    maxsize--;
    long long int i=1;
    long long int mc;
    while((i*2)+1<=maxsize||i*2<=maxsize)
    {
	if(i*2!=maxsize && maxheap[i*2]<maxheap[(i*2)+1])
	    mc=(i*2)+1;
	else
	    mc=i*2;
	if(maxheap[mc]<maxheap[i])
	    break;
	else
	    maxswap(maxheap,mc);
	i=mc;
    }
}
void minswap(long long int *minheap,long long int i)
{
    long long int t=minheap[i];
    minheap[i]=minheap[i/2];
    minheap[i/2]=t;
}
void mininsert(long long int x)
{
    minheap[++minsize]=x;
    long long int i=minsize;
    while(minheap[i]<minheap[i/2] && i>1)
    {
	minswap(minheap,i);
	i/=2;
    }
}
void deletemin()
{
    if(minsize==0)
    {
	return;
    }
    minheap[1]=minheap[minsize];
    minsize--;
    long long int i=1;
    long long int mc;
    while((i*2)+1<=minsize||i*2<=minsize)
    {
	if(i*2!=minsize && minheap[i*2]>minheap[(i*2)+1])
	    mc=(i*2)+1;
	else
	    mc=i*2;
	if(minheap[mc]>minheap[i])
	    break;
	else
	    minswap(minheap,mc);
	i=mc;
    }
}
int main()
{
    long long int a,b,c;
    long long int n,i,j;
    long long int mi,fi,temp,test;
    scanf("%lld",&test);
    while(test--)
    {
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	maxsize=0;
	minsize=0;
	maxinsert(1);
	sum=1;
	for(i=2;i<=n;i++)
	{
	    mi=maxheap[1];
	    fi=((a*mi)%1000000007 + (b*i)%1000000007 + c)%1000000007;
	    sum+=fi;
	    if(maxsize==minsize)
	    {
		if(fi<=maxheap[1])
		{
		    maxinsert(fi);
		}
		else
		{
		    mininsert(fi);
		    temp=minheap[1];
		    deletemin();
		    maxinsert(temp);
		}
	    }
	    else
	    {
		if(fi<=maxheap[1])
		{
		    maxinsert(fi);
		    temp=maxheap[1];
		    deletemax();
		    mininsert(temp);
		}
		else
		{
		    mininsert(fi);
		}
	    }
	}
	printf("%lld\n",sum);
    }
    return 0;
}
