#include<stdio.h>
int main()
{
	long long int min=9999999,max=0,profit,price;
	int n,t,flag=0,x=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		max=0;
		profit=0;
		min=999999;
		for(x=0;x<n;x++)
		{
			scanf("%lld",&price);
			if (price<min)
			{
				min=price;
				max=0;
			}
			if(price>=max)
			{
				max=price;
				if(profit<=(max-min))
				{
					profit=max-min;
				}
			}
		}
		printf("%lld\n",profit);
	}
	return 0;
}	
