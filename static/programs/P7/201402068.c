#include <stdio.h>
int main()
{
	int t;
	int a[1000001],x[1000001];
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);

		int min,max;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i==0)
			{
				min=a[0];
				max=a[0];
				continue;
			}
			if(min>a[i])
				min=a[i];
			if(max<a[i])
				max=a[i];
		}
		for(i=0;i<=max-min;i++)
			x[i]=0;
		for(i=0;i<n;i++)
			x[a[i]-min]++;
		long long int pairs=0,a2,b;
		for(i=0;i<=max-min;i++)
			if(x[i]>1)
			{
				a2=x[i];	
				b=x[i]-1;
				pairs+=(a2*b)/2;
			}
		printf("%lld\n",pairs);
	}
	return 0;
}
