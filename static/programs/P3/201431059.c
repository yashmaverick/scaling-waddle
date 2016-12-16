#include<stdio.h>
typedef long long int ll;
ll max(ll x, ll y)
{ return (y > x)? y : x; }

ll maxSubArraySum(ll*a,ll size)
{
	ll max_so_far = a[0], i;
	ll curr_max = a[0];

	for (i = 1; i < size; i++)
	{
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

/* Driver program to test maxSubArraySum */
int main()
{
	int test;
	ll arr[100001];
	ll arr2[100001],i;
	scanf("%d",&test);
	while(test--)
	{
		ll n;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		arr2[0]=0;
		for(i=1;i<n;i++)
		{
			arr2[i]=arr[i]-arr[i-1];	
		}
	ll max_sum = maxSubArraySum(arr2, n);
	printf("%lld\n", max_sum);
	}
	return 0;
}
