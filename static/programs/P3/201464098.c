#include<stdio.h>
int main()
{
	long long int t,g;
	scanf("%lld",&t);
	for(g=0;g<t;g++)
	{
		long long int n,i,r=0;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long int left[n],right[n];
		left[0]=a[0];
		right[n-1]=a[n-1];
		long long int max=0;
		for(i=1;i<n;i++)
		{
			if(left[i-1]>=a[i])
				left[i]=a[i];
			else
				left[i]=left[i-1];
		}
		for(i=n-2;i>=0;i--)
		{
			if(right[i+1] <= a[i])
			{
				right[i]=a[i];
			}
			else
				right[i]=right[i+1];
		}
		for(i=0;i<n;i++)
		{	
			if(right[i]-left[i]>=max)
				max=right[i]-left[i];
		}
		if(max<=0)
			printf("0\n");
		else
			printf("%lld\n",max);
	}
	return 0;
}
