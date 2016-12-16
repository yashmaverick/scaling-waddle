#include<stdio.h>
int main()
{
	int t,n,i,prft,buy,flag,mprft;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int stock[n];
		buy=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&stock[i]);
			if(stock[i]>=buy)
				buy=stock[i];
		}
		prft=0;
		mprft=0;
		flag=0;
		for(i=0;i<n-1;i++)
		{
			if(stock[i]<stock[i+1])
			{
				if(stock[i]<=buy)
				{
					buy=stock[i];
					flag=1;
				}
			}
			if(flag==1)
			{
				prft=stock[i+1]-buy;
				if(prft>=mprft)
					mprft=prft;
			}
		}
		printf("%d\n",mprft);
	}
	return 0;
}
