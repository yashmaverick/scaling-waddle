#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MOD 1000000007
long long int a,b,c,n;
long long int minheapcount,maxheapcount;
long long int maxheap[1000000];
long long int minheap[1000000];
void inminheap(long long int value)
{
	minheapcount++;
	minheap[minheapcount] = value;
	long long int i = minheapcount;
	while(minheap[i/2]>value)
	{
		minheap[i]=minheap[i/2];
		i/=2;
	}
	minheap[i]=value;
}
void inmaxheap(long long int value)
{
	maxheapcount++;
	maxheap[maxheapcount] = value;
	long long int i = maxheapcount;
	while(maxheap[i/2]<value)
	{
		maxheap[i]=maxheap[i/2];
		i/=2;
	}
	maxheap[i]=value;
}
long long int minpop()
{
	long long int ans = minheap[1],temp;
    temp = minheap[minheapcount--];
    long long int i,j;
    for(i=1;2*i<=minheapcount;i=j)
    {
        j=2*i;
        if(j!=minheapcount && minheap[j+1] < minheap[j])
            j++;
        if(temp > minheap[j])
            minheap[i] = minheap[j];
        else
            break;
    }
    minheap[i] = temp;
    return ans;
}
long long int maxpop()
{
	long long int ans = maxheap[1],temp;
    temp = maxheap[maxheapcount--];
    long long int i,j;
    for(i=1;2*i<=maxheapcount;i=j)
    {
        j=2*i;
        if(j!=maxheapcount && maxheap[j+1] > maxheap[j])
            j++;
        if(temp < maxheap[j])
            maxheap[i] = maxheap[j];
        else
            break;
    }
    maxheap[i] = temp;
    return ans;
}
long long int func()
{
	long long int sum = 1,temp = 0,i;
	maxheapcount = 0;
	minheapcount = 0;
	maxheap[0] = LLONG_MAX;
	minheap[0] = LLONG_MIN;
	long long int curmedian = 1;
	inminheap(1);
	for(i=2;i<=n;i++)
	{
		long long int F = (a*curmedian + b*i + c)%MOD;
		sum += F;
		if(maxheapcount == minheapcount)
		{
			if(F<curmedian)
			{
				inmaxheap(F);
				curmedian = maxheap[1];
			}
			else
			{
				inminheap(F);
				curmedian = minheap[1];
			}
		}
		else if(maxheapcount > minheapcount)
		{
			if(F<curmedian)
			{
				temp = maxpop();
				inminheap(temp);
				inmaxheap(F);
			}
			else
			{
				inminheap(F);
			}
			curmedian = maxheap[1];
		}
		else
		{
			if(F<curmedian)
			{
				inmaxheap(F);
			}
			else
			{
				temp = minpop();
				inmaxheap(temp);
				inminheap(F);
			}
			curmedian = maxheap[1];
		}
	}
	return sum;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&a ,&b ,&c ,&n);
		//printf("HelloWorld\n");
		long long int ans = func();
		printf("%lld\n", ans);
	}
	return 0;
}