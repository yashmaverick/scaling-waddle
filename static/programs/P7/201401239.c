#include<stdio.h>
int main()
{
	long long int c,d;
	scanf("%lld",&d);
	for(c=0;c<d;c++)
	{
		long long int i,n;
		scanf("%lld",&n);
		long long int a[n];
		//for(i=0;i<n;i++)
		long long int min=0,max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		long long int b[max-min+1];
		for(i=0;i<(max-min+1);i++)
			b[i]=0;
		for(i=0;i<n;i++)
		{b[a[i]-min]++;
		}
		long long int x=0,s=0;
		for(i=0;i<(max-min+1);i++)
		{
			x=x+(b[i]*(b[i]-1))/2;
		}
		printf("%lld\n",x);
	}
	return 0;	
}
