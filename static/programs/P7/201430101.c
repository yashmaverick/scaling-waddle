#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
int cmpfunc (const void * a, const void * b)
{
	return ( *(ll*)a - *(ll*)b );
}
ll arr[1000001];
int main()
{
	int test;
	ll n,i,count,cpairs;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld",&n);
		count=1;
		cpairs=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		qsort(arr, n, sizeof(ll), cmpfunc);
		for(i=0;i<n-1;i++)
		{
			if(arr[i]==arr[i+1])
			{
				count++;
			//	if(i==n-2)
			//	{
			//		cpairs=cpairs+((count*(count-1))/2);
			//	}
			}
			if(i==n-2 && arr[i]==arr[i+1])
			{
				cpairs=cpairs+((count*(count-1))/2);
			}
			else if(arr[i]!=arr[i+1])
			{
				cpairs=cpairs+((count*(count-1))/2);
				count=1;

			}

		}
		//	printf("%lld->",count);
		printf("%lld\n",cpairs);
	}
	return 0;
}

