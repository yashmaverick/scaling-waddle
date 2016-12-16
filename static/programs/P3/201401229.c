#include<stdio.h>
int main()
{
	int test;
	long long int n, ar[100000], i,min, max_profit;
	scanf("%d",&test);
	while(test--)
	{
		min=1000000000;
		max_profit=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&ar[i]);
			if(ar[i]<min)
				min=ar[i];
			if(ar[i]-min>max_profit)
				max_profit=ar[i]-min;
		}
		printf("%lld\n",max_profit);
	}
	return 0;
}

