#include<stdio.h>
int main()
{
	int n;
	long long int a[100000],i,k,j,m,min,diff;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&m);
		i=0;
		while(i<m)
		{
			scanf("%lld",&a[i]);
			i++;
		}
		i=0;
		min=a[0];
		diff=0;
		while(i<m)
		{
			if(a[i]<min)
			{
				min=a[i];
			}
			if(diff<a[i]-min)
			{
				diff=a[i]-min;
			}
			i++;
		}
		printf("%lld\n",diff);



		
	}
	return 0;
}
