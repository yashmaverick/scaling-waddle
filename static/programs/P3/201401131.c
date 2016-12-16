#include<stdio.h>
int main()
{
long long int i,t;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		long long int n,j;
		scanf("%lld",&n);
		long long int a[n];
		long long int p,q,max,diff;
		j=0;
		while(j<n)
		{
			scanf("%lld",&a[j]);
			j++;
		}
		p=a[0];

		max=0;
		j=0;
		while(j<n)
		{
			if(a[j]-p > 0)
			{
				diff=a[j]-p;
				if(diff > max)
				{
					max=diff;
				}
				j++;	
			}
			else if(a[j] <= p)
			{
				p=a[j];
				q=j;
				j++;
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}
