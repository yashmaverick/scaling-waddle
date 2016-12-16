#include<stdio.h>
int main()
{
	int i,t;
	long long int na,j,k,maxprofit;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		maxprofit=0;
		scanf("%lld",&na);
		long long int a[na];
		for(j=0;j<na;j++)
		{
			scanf("%lld",&a[j]);
		}
		k=a[0];
		for(j=0;j<na;j++)
		{
			if(k > a[j])
			{
				k=a[j];
			}
			if((a[j]-k)>maxprofit)
			{
				maxprofit=a[j]-k;
			}
		}
		printf("%lld\n",maxprofit);
	}
	return 0;
}
