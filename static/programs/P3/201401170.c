#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int a[n],i,max,x1,x2;
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int b[n];
		max=a[n-1];
		for(i=n-1;i>=0;i--)
		{
			if(a[i]>max)
			{
				b[i]=a[i];
				max=a[i];
			}
			else
			{
				b[i]=max;
			}
		}
		max=0;
		for(i=0;i<n;i++)
		{
			if(b[i]-a[i]>max)
				max=b[i]-a[i];
		}
		printf("%lld\n",max);
	}
	return 0;
}
