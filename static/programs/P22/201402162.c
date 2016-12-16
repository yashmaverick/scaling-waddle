#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007;
#define MAX 1000000007;
#define MIN 0;
long long int f[1000000];
long long int minheap[1000000];
long long int maxheap[1000000];
long long int mincount;
long long int maxcount;
void insertmin(long long int value)
{
	mincount++;
	minheap[mincount]=value;
	long long int a,temp;
	a=mincount;
	while(minheap[a]<minheap[a/2] && a>1)
	{
		temp=minheap[a];
		minheap[a]=minheap[a/2];
		minheap[a/2]=temp;
		a=a/2;
	}
}
void delmin()
{
	minheap[1]=minheap[mincount];
	minheap[mincount]=MAX;
	mincount--;
	long long int a,temp;
	a=1;
	while((minheap[a]>minheap[(2*a)]  || minheap[a]>minheap[(2*a)+1]) && (2*a<=mincount))
	{
		if(minheap[(2*a)]<minheap[(2*a)+1])
		{
			temp=minheap[a];
			minheap[a]=minheap[(2*a)];
			minheap[(2*a)]=temp;
			a=2*a;
		}
		else
		{
			temp=minheap[a];
			minheap[a]=minheap[(2*a)+1];
			minheap[(2*a)+1]=temp;
			a=(2*a)+1;
		}
	}
}
void insertmax(long long int value)
{
	maxcount++;
	maxheap[maxcount]=value;
	long long int a,temp;
	a=maxcount;
	while(maxheap[a]>maxheap[a/2] && a>1)
	{
		temp=maxheap[a];
		maxheap[a]=maxheap[a/2];
		maxheap[a/2]=temp;
		a=a/2;
	}
}
void delmax()
{
	maxheap[1]=maxheap[maxcount];
	maxheap[maxcount]=MIN;
	maxcount--;
	long long int a,temp;
	a=1;
	while((maxheap[a]<maxheap[(2*a)]  || maxheap[a]<maxheap[(2*a)+1]) && (2*a<=maxcount))
	{
		if(maxheap[(2*a)]>maxheap[(2*a)+1])
		{
			temp=maxheap[a];
			maxheap[a]=maxheap[(2*a)];
			maxheap[(2*a)]=temp;
			a=2*a;
		}
		else
		{
			temp=maxheap[a];
			maxheap[a]=maxheap[(2*a)+1];
			maxheap[(2*a)+1]=temp;
			a=(2*a)+1;
		}
	}
}
int main()
{
	long long int i,t,a,b,c,n;
	long long int sum;
	scanf("%lld",&t);
	long long int median;
	while(t--)
	{
		f[1]=1;
		median=1;
		mincount=0;
		maxcount=0;
		sum=f[1];
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		for(i=2;i<=n;i++)
		{
			f[i]=((a*median)+(b*i)+c)%MOD;
			if(i%2==1)
			{
				if(f[i]<=median)
					insertmax(f[i]);
				else
				{
					insertmin(f[i]);
					insertmax(median);
					median=minheap[1];
					delmin();
				}
			}
			else
			{
				if(f[i]>=median)
					insertmin(f[i]);
				else
				{
					insertmax(f[i]);
					insertmin(median);
					median=maxheap[1];
					delmax();
				}
			}
			sum=sum+f[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
