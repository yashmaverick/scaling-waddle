#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		long long int d;
		scanf("%lld",&d);
		long long int a[100005];
		for(i=0;i<d;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int b[100005];
		for(i=d-1;i>0;i--)
		{
			b[i]=a[i]-a[i-1];
		}
		long long int sum=0,maxsum=0;
		for(i=d-1;i>0;i--)
		{
			sum=sum+b[i];
			if(sum<0)
			{
				sum=0;
			}
			if(sum>=maxsum)
				maxsum=sum;
		}
		printf("%lld\n",maxsum);
	}
	return 0;
}