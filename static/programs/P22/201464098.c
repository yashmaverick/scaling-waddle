#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
typedef long long int ll;
typedef struct heapnode{
	long long int value;
}heapnode;
heapnode max_heap[500005];
heapnode min_heap[500005];
ll min_heapsize=0;
ll max_heapsize=0;
void min_insert(heapnode num)
{
	min_heap[0].value=-222;
	min_heapsize++;
	min_heap[min_heapsize]=num;
	ll present = min_heapsize;
	while(min_heap[present/2].value > num.value)
	{
		min_heap[present]=min_heap[present/2];
		present/=2;
	}
	min_heap[present]=num;
}
heapnode min_delete()
{
	heapnode min,last;
	last=min_heap[min_heapsize--];
	min=min_heap[1];
	ll present,child;
	for(present=1;present*2 <= min_heapsize;present=child)
	{
		child=present*2;
		if(child != min_heapsize && min_heap[child+1].value < min_heap[child].value)
		{
			child++;
		}
		if(last.value > min_heap[child].value)
		{
			min_heap[present]=min_heap[child];
		}
		else
			break;
	}
	min_heap[present]=last;
	return min;
}
void max_insert(heapnode num)
{
	max_heap[0].value=9999999999;
	max_heapsize++;
	max_heap[max_heapsize]=num;
	ll present = max_heapsize;
	while(max_heap[present/2].value < num.value)
	{
		max_heap[present]=max_heap[present/2];
		present/=2;
	}
	max_heap[present]=num;
}
heapnode max_delete()
{
	heapnode max=max_heap[1];
	heapnode last=max_heap[max_heapsize--];
	ll present ,child;
	for(present=1;present*2 <= max_heapsize;present=child)
	{
		child = present*2;
		if(child != max_heapsize && max_heap[child+1].value > max_heap[child].value)
		{
			child++;
		}
		if(last.value < max_heap[child].value)
		{
			max_heap[present]=max_heap[child];
		}
		else
			break;
	}
	max_heap[present]=last;
	return max;
}
int main()
{
	long long int  test,a,b,c,i,j,k,g,n;
	scanf("%lld",&test);
	for(g=0;g<test;g++)
	{
		max_heapsize=0;
		min_heapsize=0;
		//printf("hello");
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		//printf("adshgfhewjhgfwjkf\n");
		//printf("%lld %lld %lld %lld",a,b,c,n);
		//ll f[n+1];
		//ll xx;
		//printf("getlost\n");
		long long int  f[n+1];
		long long int  xx;
		heapnode rounak;
		//printf("miss u mom\n");
		//rounak.value = 1;
		//printf("jfdashffdewfjkskdw");
		//return 0;
		rounak.value=1;
		max_insert(rounak);
		f[1]=1;
		heapnode temp;
		for(i=2;i<=n;i++)
		{
			//printf("dfhja\n");
			if(max_heapsize==min_heapsize)
			{
				temp=max_heap[1];
				xx=temp.value;
			}
			else if((max_heapsize - min_heapsize)==1)
			{
				temp=max_heap[1];
				xx=temp.value;
			}
			else
			{
				temp=min_heap[1];
				xx=temp.value;
			}
			f[i]=((a*xx)%mod + (b*i)%mod +c)%mod;
			ll joke=f[i];
			temp=max_heap[1];
			ll pk=temp.value;
			heapnode hello;
			if( joke < pk)
			{
				hello.value=joke;
				max_insert(hello);
			}
			else
			{
				hello.value=joke;
				min_insert(hello);
			}
			if((max_heapsize - min_heapsize)==2)
			{
				temp=max_delete();
				min_insert(temp);
			}
			else if((min_heapsize - max_heapsize)==2)
			{
				temp=min_delete();
				max_insert(temp);
			}
		}
		//printf("welcome\n");
		ll sum=0;
		for(i=1;i<=n;i++)
			sum+=f[i];
		printf("%lld\n",sum);
	}
	return 0; 
}
