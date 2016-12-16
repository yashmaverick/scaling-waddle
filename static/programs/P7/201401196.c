#include <stdio.h>
long long int a[1000000],b[1000000],min,sum;
int main()
{
	int t,i,j,k;
	long int n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld",&n);
		min=100000000;sum=0;
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			if(a[j]<min)
				min=a[j];
		}
		for(j=0;j<1000000;j++)
			b[j]=0;
		for(j=0;j<n;j++)
			a[j]-=min;
		for(j=0;j<n;j++)
			b[a[j]]++;
		for(j=0;j<1000000;j++)
			if(b[j]!=0)	sum+=(b[j]*(b[j]-1)/2);
		printf("%lld\n",sum);
	}
	return 0;
}
