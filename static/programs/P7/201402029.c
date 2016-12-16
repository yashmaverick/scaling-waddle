#include<stdio.h>
#define MAX 1000009
int main()
{
	int x,i;
	long long int b[MAX];
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		long long int min=1000000000,pairs=0,flag=0,n,j,max=0;
		scanf("%lld",&n);
		long long int a[n];
		for(j=0;j<MAX;j++)
		{
			b[j]=0;
		}
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			if(a[j]<min)
			{
				min=a[j];
			}
		}
		for(j=0;j<n;j++)
		{
			a[j]=a[j]-min;
			b[a[j]]++;
			if(a[j]>max)
			{
				max=a[j];
			}
		}
		for(j=0;j<=max;j++)
		{
			if(b[j]>1)
			{
				pairs=pairs+((b[j])*(b[j]-1))/2;
			}
		}
		printf("%lld\n",pairs);
	}
	return 0;
}
