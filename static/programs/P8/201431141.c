#include<stdio.h>
#include<math.h>
long long int N;
long long int power(long long int a, long long int x)
{
	long long int ans=1;
	while(x!=0)
	{
		if(x&1)
			ans=(ans*a)%N;
		x>>=1;
		a=(a*a)%N;
	}
	return(ans%N);
}
int main()
{
	long long int t,p,a,b,c,i,j,k,u,d,m,v=0;
	scanf("%lld",&t);
	for(p=0;p<t;p++)
	{
		v=0;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&N);
		for(a=0;a<N;a++)
		{
			for(b=0;b<N;b++)
			{
				for(c=0;c<N;c++)
				{
					i=power(c,d);
					j=power(b,d);
					k=power(a,d);
					if((i+j+k)%N==m)
					{
						if(a<=u && b<=u && c<=u)
						{
							i=(((u-a)/N)+1)%1000000007;
							j=(((u-b)/N)+1)%1000000007;
							k=(((u-c)/N)+1)%1000000007;
							v=(v+(((i*j)%1000000007)*k)%1000000007)%1000000007;
						}
					}
				}
			}
		}	
		printf("%lld\n",v);
	}
	return 0;
}
