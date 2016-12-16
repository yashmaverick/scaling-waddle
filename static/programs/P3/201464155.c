#include<stdio.h>
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int REALLY_BIG_NO=1000000000000;
		long long int bottom=REALLY_BIG_NO; // arbirtrary large number
		long long int currBestBuy=0,top=0,currBestSell=0,profit=0,n;
		scanf("%lld",&n);
		long long int prices[n],i;
		for(i=0;i<n;i++)
			scanf("%lld",&prices[i]);
		for (i=0;i<n;++i)
		{
			if(prices[i]<bottom)
			{
				bottom=prices[i];
				top=-1;
			}
			else if(prices[i]>top)
			{
				top=prices[i];
				long long int potentialProfit=(top-bottom);
				if (potentialProfit>profit &&
						bottom!=REALLY_BIG_NO)
				{
					profit=potentialProfit;
				}
			}
		}
		printf("%lld\n",profit);
	}
	return 0;
}
