#include<stdio.h>
int main()
{
	long long int t,n;
	scanf("%lld",&t);
	while(t>0)
	{
		scanf("%lld",&n);
		long long int a[n],b,c,result=0,d,min,max;
		for(b=0;b<n;b++)
		{
			scanf("%lld",&a[b]);
		}
		min=a[0];
		max=a[0];
		for(b=1;b<n;b++)
		{
			if(a[b]<min)
			{
				min=a[b];
			}
			if(a[b]>max)
			{
				max=a[b];
			}
		}
		if(max-min==0)
		{
			printf("%lld\n",(n*(n-1))/2);
		}
		else
		{
		long long int e[max-min+1];
		for(b=0;b<=max-min;b++)
		{
			e[b]=0;
		}
		for(b=0;b<n;b++)
		{
			a[b]=a[b]-min;
		}
		for(b=0;b<n;b++)	
		{
			c=a[b];
			e[c]++;
		}
		for(b=0;b<=max-min;b++)	
		{
			c=e[b];
			result=result+(c*(c-1))/2;
		}
		printf("%lld\n",result);
		}
		t--;
	}
	return 0;
}
