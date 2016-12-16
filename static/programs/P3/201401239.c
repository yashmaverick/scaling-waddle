#include<stdio.h>
typedef long long int ll;
int main()
{
	ll c,b;
	scanf("%lld",&b);
	for(c=0;c<b;c++)
	{
	ll n,a[100000],i,min,max;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{scanf("%lld",&a[i]);
		}
		min=a[0];
		max=0;
		for(i=0;i<n;i++)
		{
			if(a[i+1]-min<0)
				min=a[i+1];
			if(a[i+1]-min>max)
				max=a[i+1]-min;
		}
               printf("%lld\n",max);
	}
	return 0;
}
