#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define maxm(a,b) ((a) > (b) ? (a) : (b))
#define minm(a,b) ((a) < (b) ? (a) : (b))
#define mod 1000000007

typedef long long ll;

ll min[200011],max[200011];
ll min_size , max_size;

void swap(ll* a, ll* b)
{
	ll tmp = *a;
	*a = *b;
	*b = tmp; return;
}

void min_insert(int n)
{
	int i;
	min[++min_size] = n;
	for(i = min_size ; i && min[i] < min[i/2] ; i/=2)
		swap(min + i , min + i / 2);
	return;
}

void max_insert(int n)
{
	int i;
	max[++max_size] = n;
	for(i = max_size ; i && max[i] > max[i/2] ; i/=2)
		swap(max + i , max + i / 2);
	return;
}

//int min_del()
//{
//	int n = min[1] , i = 1;
//	min[i] = min[min_size--];
//	i = min_size;
//	while(i > 2)
//	{
//		if(min[i] < min[i/2])
//			swap(min + i , min + i/2);
//		i--;
//	}
//	return n;
//}
//
//int max_del()
//{
//	int n = max[1] , i = 1;
//	max[i] = max[max_size--];
//	i = max_size;
//	while(i > 2)
//	{
//		if(min[i] > min[i/2])
//			swap(min + i , min + i/2);
//		i--;
//	}
//	return n;
//}
int min_del()
{
	int minElement,lastElement,child,now;
	minElement = min[1];
	lastElement = min[min_size--];
	for(now = 1; now*2 <= min_size ;now = child)
	{
		child = now*2;
		if(child != min_size && min[child+1] < min[child] ) 
			child++;
		if(lastElement > min[child])
			min[now] = min[child];
		else
			break;
	}
	min[now] = lastElement;
	return minElement;
}

int max_del()
{
	int maxElement,lastElement,child,now;
	maxElement = max[1];
	lastElement = max[max_size--];
	for(now = 1; now*2 <= max_size ;now = child)
	{
		child = now*2;
		if(child != max_size && max[child+1] > max[child] ) 
			child++;
		if(lastElement < max[child])
			max[now] = max[child];
		else
			break;
	}
	max[now] = lastElement;
	return maxElement;
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		min[0] = INT_MIN; min_size = 0;
		max[0] = INT_MAX; max_size = 0;
		ll a,b,c,n,i,tmp;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		max_insert(1);
		ll f = 1,sl = 1,sr = 0,sum = 1;
		for(i = 2 ; i <= n ; i++)
		{
			tmp = max[1];
			f = (((a%mod) * (tmp%mod))%mod + ((b%mod) * (i%mod))%mod + c%mod)%mod;
			sum += f;
			if(sl > sr)
			{
				if(f < tmp)
				{
					max_del();
					min_insert(tmp);
					max_insert(f);
				}
				else min_insert(f);
				sr++;
			}
			else
			{
				tmp = min[1];
				if(f > tmp)
				{
					min_del();
					max_insert(tmp);
					min_insert(f);
				}
				else max_insert(f);
				sl++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
