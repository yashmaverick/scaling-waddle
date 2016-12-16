#include<stdio.h>
#define MOD 1000000007
long long int ul,d,m,n;
long long int ex(long long int a, long long int b, long long int m)
{
	if(b==0)
		return 1;
	if(b&1==1)
		return (a*ex((a*a)%m,b>>1,m))%m;
	else
		return ex((a*a)%m,b>>1,m)%m;
}
int main()
{
	long long int tc,i,j,k,l,t,a1,a2,a3,ans;
	scanf("%lld",&tc);
	for(i=0;i<tc;i++)
	{
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
		ans=0;
		t=n;
		for(j=0;j<t;j++)
			for(k=0;k<t;k++)
				for(l=0;l<t;l++)
					if(j<=ul && k<=ul && l<=ul && ((ex(j,d,n)+ex(k,d,n)+ex(l,d,n))%n==m))
					{
						a1=(((ul-l)/n)+1)%MOD;
						a2=(((ul-k)/n)+1)%MOD;
						a3=(((ul-j)/n)+1)%MOD;
						ans=(ans+((((a1*a2)%MOD)*a3)%MOD))%MOD;
					}
		printf("%lld\n",ans);
	}
	return 0;
}
