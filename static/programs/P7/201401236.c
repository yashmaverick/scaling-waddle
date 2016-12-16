#include<stdio.h>
long long int a[1000000];
long long int perm(long long int n)
{
	long long int t=n*(n-1)/2;
	return t;
}
int main()
{
	long long int sum=0,r,i,n,min,g,k,max,test;
	scanf("%lld",&test);
	while(test--)
	{


		min=99999999;
		max=-99999999;
		sum=0;         
		long long int b[1000000]={0};
		scanf("%lld",&n);
		g=n;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		k=0;
		while(n--)
		{
			if(a[k]<min)
				min=a[k];
			if(a[k]>max)
				max=a[k];
			k++;
		}

		for(i=0;i<g;i++)
		{
			k=a[i];
			b[k-min]++;
		}
		for(i=0;i<=max-min;i++)
		{
			r=perm(b[i]);
			sum=sum+r;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
