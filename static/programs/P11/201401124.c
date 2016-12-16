#include<stdio.h>
int main()
{
	long long n=1,popped,i,a[100000],stac[100000],sp=0;
	while(n)
	{
		sp=-1;
		long long ans=0,max;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		i=0;
		while(i<n)
		{
			//scanf("%lld",&a[i]);
			if((sp==-1)||(a[i]>=a[stac[sp]]))
			{
				sp++;
				stac[sp]=i;
				i++;
			}
			else
			{
				popped=stac[sp];
				sp--;
				if(sp!=-1)
					max=a[popped]*(i-1-stac[sp]);
				else
					max=i*a[popped];
				if(max>ans)
					ans=max;
			
			}
		}
		while(sp!=-1)
		{
			popped=stac[sp];
			sp--;
			if(sp!=-1)
				max=a[popped]*(i-1-stac[sp]);
			else
				max=i*a[popped];
			if(max>ans)
				ans=max;
		}
		if(n!=0)
		printf("%lld\n",ans);


	}
	return 0;
}
