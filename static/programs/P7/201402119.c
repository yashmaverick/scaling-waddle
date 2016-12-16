#include<stdio.h>

long long int b[10000001];
int main()
{
	long long int t,n,min,max,tmp,var,cnt;
	scanf("%lld",&t);
	while(t--)
	{
		min=10000000;
		max=-10000000;
		cnt=0;
		long long int i;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i] <= min)
				min=a[i];
			if(a[i] >= max)
				max=a[i];
		}
		tmp=1000001;
		for(i=0;i<tmp;i++)
		{
			b[i]=0;
		}
		for(i=0;i<n;i++)
		{
			var=a[i];
			b[var-min]++;
		}
		for(i=0;i<tmp;i++)
		{
			cnt=cnt+(b[i]*(b[i]-1))/2;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
