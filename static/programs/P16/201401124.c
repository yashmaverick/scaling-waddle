#include<stdio.h>
int main()
{
	long long int pow[100],i,q,sub,ans,n;
	pow[0]=1;
	for(i=1;i<=60;i++)
	{
		pow[i]=pow[i-1]*2;
	}
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&q);
		if(q==1)
		{
			printf("0\n");
			continue;
		}
		i=0;
		while(q>=pow[i])
		{
			i++;
		}
		i--;
		sub=(pow[i+1]-1)-pow[i];
		sub=sub/2;
		if(q-pow[i]<=sub)
		{
			ans=2*i-1;
		}
		else
			ans=2*i;
		printf("%lld\n",ans);
		//n--;
	}
	return 0;
}
