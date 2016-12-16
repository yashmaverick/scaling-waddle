#include<stdio.h>
#define MOD 1000000007
long long int power(long long int a,long long int b,long long int m)
{
	long long int t;
	if(b==0)
		return 1;
	if(b%2==0)
	{
		t=power(a,b/2,m)%m;
		return (t*t)%m;
	}
	else
	{
		t=power(a,b/2,m)%m;
		return (((t*t)%m)*a)%m;
	}

}
int main()
{
	long long int t,d,f,n,p,ans,m,u,i,j,k,a[50],c1,c2,c3,h;
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		c1=0;
		c2=0;
		c3=0;
		scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
		for(i=0;i<n;i++)
		{
			a[i]=power(i,d,n);
//			printf("%lld ",a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if((a[i]+a[j]+a[k])%n==m)
					{
						c1=((u-i)/n+1)%MOD;
						c2=((u-j)/n+1)%MOD;
						c3=((u-k)/n+1)%MOD;
						h=(c1*c2)%MOD;
						ans=(ans+(h*c3)%MOD)%MOD;						
//						printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",i,j,k,c1,c2,c3,h,ans);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
