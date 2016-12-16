#include<stdio.h>
int main()
{
	int i,t;
	long long int x,n,j,max,min,sum;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		long long int a[n];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		min=a[0];
		max=a[0];
		sum=0;
		for(j=0;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
			}
			if(max<a[j])
			{
				max=a[j];
			}
		}
		x=1000000;
		long long int y[(max-min)+6];
		for(j=0;j<(max-min)+6;j++)
		{
			y[j]=0;
		}
		for(j=0;j<n;j++)
		{
			y[(max-a[j]+5)%(x)]=y[(max-a[j]+5)%x]+1;
		}
		for(j=0;j<(max-min)+6;j++)
		{
			sum+=(y[j]*(y[j]-1))/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
