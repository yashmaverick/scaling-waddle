#include<stdio.h>
int main()
{
	long long int i,j,k,n,a[1000000],test,t,max,min,diff;
	scanf("%lld", &test);
	for(t=0;t<test;t++)
	{
		scanf("%lld", &n);
		for(i=0;i<n;i++)
		{
			scanf("%lld", &a[i]);
		}
		min=a[0];max=0;
		for(i=1;i<n;i++)
		{
			if(a[i]-min<0)
			{
				min=a[i];
			}
			else
			{
				diff=a[i]-min;
				if(diff>max)
				{
					max=diff;
				}
			}
		}
		printf("%lld\n", max);
	}
	return 0;
}
