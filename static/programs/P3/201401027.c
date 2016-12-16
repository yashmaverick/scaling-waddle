#include<stdio.h>
int main()
{
	long long int tc,i,ans,n,j,price[100010],Max,a;
	scanf("%lld",&tc);
	for(i=0;i<tc;i++)
	{
		ans=0;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&price[j]);
		Max=price[n-1];
		for(j=n-2;j>=0;j--)
		{
			Max=(Max>price[j])?Max:price[j];
			a=Max-price[j];
			ans=(ans>a)?ans:a;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
