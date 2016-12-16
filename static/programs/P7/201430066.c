#include<stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long int n,j;
		scanf("%ld",&n);
		long int a[n],b[1000000];
		for(j=0;j<1000000;j++)
		{
			b[j]=0;
			if(j<n)
			scanf("%ld",&a[j]);
		}
		long int k;
		for(j=0;j<n;j++)
		{
			k=(a[j]+10000000)%1000000;
			b[k]++;
		}
		long int sum=0;
		for(j=0;j<1000000;j++)
		{
			sum=sum+((b[j]*(b[j]-1))/2);
		}
		printf("%ld\n",sum);
	}
		return 0;
	}
