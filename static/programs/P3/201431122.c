

#include<stdio.h>

int main()
{
	long long int t,n,nc,nl,max,min;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		max=0;
		min=999999;
		while(n--)
		{
			scanf("%lld",&nc);
			if(nc<min)
				min=nc;
			else if(nc>=min)
			{
				if(max<(nc-min))
					max=nc-min;
			}	
		}
		printf("%lld\n",max);
	}
	return 0;
}
