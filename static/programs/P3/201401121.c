#include<stdio.h>
int main()
{
	int t;
	long long int a[100005];
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i=0;
		for(;i<n;i++)
			scanf("%lld",&a[i]);
		long long int min=0,max=0,prof=0;
		i=1;
		while(i<n)
		{
			if(a[i]>=a[min])
			{
				prof=a[i]-a[min];
				if(max<prof)
				{
					max=prof;
				}
			}
			else
				min=i;
			i++;
		}
		printf("%lld\n",max);
	}
	return 0;
}

				

	
