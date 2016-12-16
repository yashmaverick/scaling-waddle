#include<stdio.h>
int a[100000];
int main()
{
	int i,j,n,t;
	long long int max,min,d;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(i>0)
			{
				if(min>a[i-1])
					min=a[i-1];
				if(a[i]>min)
				{
					d=a[i]-min;
					if(d>max)
						max=d;
				}
			}
			else if(i==0)
				min=a[0];
		}
		printf("%lld\n",max);
	}
	return 0;
}

