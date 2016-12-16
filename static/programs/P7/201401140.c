#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int a[n],i,min,max;
		scanf("%lld",&a[0]);
		min=a[0];
		max=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(min>a[i])
				min=a[i];
			if(max<a[i])
				max=a[i];
		}
		long long int b[max-min+1];
		for(i=0;i<max-min+1;i++)
			b[i]=0;
		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;
			b[a[i]]++;
		}
		long long int sum;
		sum=0;
	//	for(i=0;i<max-min+1;i++)
	//		printf("%lld ",b[i]);
	//	printf("\n");
		for(i=0;i<max-min+1;i++)
			if(b[i]>1)
				sum=sum+((b[i]*(b[i]-1))/2);
		printf("%lld\n",sum);
	}
	return 0;
}
