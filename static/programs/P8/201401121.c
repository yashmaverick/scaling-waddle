#include<stdio.h>
//#include<iostream>
//using namespace std;

long long int  fastexp(long long int a,long long int b,long long int c)
{
	if(b==0)
		return 1;
	long long int x=fastexp(a,b/2,c);
	if(b&1)
		return (a%c*(x%c*x%c)%c)%c;
	else
		return ((x%c*x%c)%c);
}
long long int mod=1000000007;
int main()
{
//	cout<<fastexp(0,4,mod);
	int t;
	scanf("%d",&t);
	while(t--)
	{

		long long int u,d,m,n;
		scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
		long long int cnt=0;
		int i=0;
		for(;i<n;i++)
		{
			int j=0;
			for(;j<n;j++)
			{
				int k;
				for(k=0;k<n;k++)
				{
					if((fastexp(i,d,n)+fastexp(j,d,n)+fastexp(k,d,n))%n==m%n)
					{
						long long int ai,aj,ak;
						if(u%n<i%n)
							ai=u/n;
						else ai=u/n+1;

						if(u%n<j%n)
							aj=u/n;
						else aj=u/n+1;

						if(u%n<k%n)
							ak=u/n;
						else ak=u/n+1;
						cnt=(cnt+((ai*aj)%mod)*ak%mod)%mod;
					
					}
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}






		
