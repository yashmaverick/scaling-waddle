#include<stdio.h>
int main()
{
	long long int test,n,k,i,j,sell,buy;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld",&n);
		long long int a[n],pro,maxpro;
		for(k=0;k<n;k++)
		{
			scanf("%lld",&a[k]);
		}
		buy=a[0];
		sell=a[0];
		maxpro=sell-buy;
		for(j=1;j<n;j++)
		{
			if(a[j]>sell)
			{
				sell=a[j];
				pro=sell-buy;
				if(pro>maxpro)
					maxpro=pro;
			}
			if(a[j]<buy)
			{
				buy=a[j];
				sell=a[j];
			}
		}
		printf("%lld\n",maxpro);
		
	}
	return 0;
}

