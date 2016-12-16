#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[100001],i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int buy,sell,profit,maxprofit=0;
		profit=0;
		buy=a[0];
		sell=0;
		//for(i=0;i<n;i++)
		//	printf("%d ",a[i]);
	//	printf("buy=%d ",buy);
		for(i=1;i<n;i++)
		{
			if(a[i]<buy)
				buy=a[i];
			else if(a[i]>buy)
				sell=a[i];
			if(sell>buy)
				profit=sell-buy;
	//		printf("buy=%d , sell=%d , profit=%d ",buy,sell,profit);
			if(profit>maxprofit)
				maxprofit=profit;
		}
		printf("%d\n",maxprofit);
		maxprofit=0;
	}
	return 0;
}

