#include<stdio.h>
typedef long long LL;
int main()
{
	LL t,n,i,j,c;
	scanf("%lld",&t);
	while(t--)
	{
		LL min=10000000, max=-10000000;
		scanf("%lld",&n);
		LL a[n],sum=0;
		LL b[1000000]={0};
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		for(j=0;j<n;j++)
		{
			c=a[j]-min;
			b[c]++;
		}
		for(j=0;j<=max-min;j++)
		{
			sum+=(b[j]*(b[j]-1))/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
