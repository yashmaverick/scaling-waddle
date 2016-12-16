#include<stdio.h>
int main()
{
	long long int t,n,i,min,mkp[1000000];
	long long int s;
	scanf("%lld",&t);
	while(t--)
	{
		s=0;
		long long int flag[1000000]={0};
		min=10000000;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&mkp[i]);
			if(mkp[i]<=min)
				min=mkp[i];
		}
		for(i=0;i<n;i++)
			flag[(mkp[i]-min)]++;
		for(i=0;i<1000000;i++)
			s=s+((flag[i]*(flag[i]-1))/2);
		printf("%lld\n",s);
	}
	return 0;
}
