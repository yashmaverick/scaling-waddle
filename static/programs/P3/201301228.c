#include<stdio.h>
int main()
{
	long long int i,n,prof=0,min=1000000000,t;
	scanf(" %lld",&t);
	while(t--)
	{
		prof=0;min=1000000000;
		scanf("%lld",&n);
		while(n--)
		{
			scanf("%lld",&i);
			if(min>i)
				min=i;
			if(i-min>prof) prof=i-min;
		}
		printf("%lld\n",prof);
	}
	return 0;
}
