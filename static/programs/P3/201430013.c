#include<stdio.h>
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n;
		scanf("%d",&n);
		long long int i,max,min,current;
		max=current=0;
		long long int a[100000];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		min=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]>max)
				max=a[i];
			if(a[i]<min)
			{
				min=a[i];
				max=0;
			}
			if(max-min>=current)
			{
				current=max-min;
				max=0;
			}
		}
		printf("%lld\n",current);
	}
	return 0;
}

