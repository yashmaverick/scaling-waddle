#include<stdio.h>
int main()
{
	long long int n,t,a[1000005],min,max,i;
	scanf("%lld",&t);
	while(t--)
	{
		min=100000000000;
		max=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
			{
				min=a[i];
			}
			if((a[i]-min)>max)
			{
				max=a[i]-min;
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}
