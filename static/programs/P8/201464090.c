#include<stdio.h>
#include<math.h>
long long int powmod(long long int div, long long int powe,long long int mod);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int u,d,m,i,j,k,count=0,q,w,e,p,l,b,n;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
		for(i=0;i<fmin(u+1,n);i++)
		{
			for(j=0;j<fmin(u+1,n);j++)
			{
				for(k=0;k<fmin(n,u+1);k++)
				{
					q=powmod(i,d,n);
					w=powmod(j,d,n);
					e=powmod(k,d,n);
					if((q+w+e)%n== m)
					{
						p=((u-i)/n+1)%1000000007;
						l=((u-j)/n+1)%1000000007;
						b=((u-k)/n+1)%1000000007;
						count=count+((((p*l)%1000000007)*b)%1000000007);
					}
				}
			}
			count=count%1000000007;
		}
		printf("%lld\n",count);
	}
	return 0;
}
long long int powmod (long long int div, long long int powe,long long int mod)
{
	long long int result = 1;
	div=div%mod;
	while (powe>0)
	{
		if (powe & 1)
			result = (result*div)%mod;
		powe >>= 1;
		div = (div*div)%mod;
	}
	return result;
}
