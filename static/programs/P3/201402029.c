#include<stdio.h>
int main()
{
	long long int x,i;
	scanf("%lld",&x);
	for(i=0;i<x;i++)
	{
		long long int j,n,profit=0,prevprofit=0;
		scanf("%d",&n);
		long long int a[n];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		long long int max=a[n-1];
		for(j=n-2;j>=0;j--)
		{
			prevprofit=max-a[j];
			if(profit>prevprofit)
			{	
				prevprofit=profit;	
			}
			profit=prevprofit;
			if(a[j]>max)
			{
				max=a[j];
			}
		}
		printf("%lld\n",prevprofit);
	}
	return 0;
}
