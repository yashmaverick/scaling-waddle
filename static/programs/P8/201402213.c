#include<stdio.h>
long long int u,m,n;
long long int min(long long int a,long long int b)
{
	if(a<b)
		return a;
	else
		return b;
}

long long int p(long long int x,long long int d)
{
	if(d==0)
		return 1;
	if(d==1)
		return x%n;
	if((d&1)==0)
	{
		long long int k=p(x,d/2);
		return (k*k)%n;
	}
	else
	{
		long long int k=p(x,d/2);
		return (k*k*x)%n;
	}
}
int f(long long int a,long long int b,long long int c,long long int d)
{
	//printf("%d-%d %d-%d %d-%d \n",a,p(a,d),b,p(b,d),c,p(c,d));
	if((p(a,d)+p(b,d)+p(c,d))%n==m)
		return 1;
	else
		return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	long long int ans=0;
	while(t--)
	{
		ans=0;
		long long int d;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
		long long int i,j,k;
		for(i=0;i<=min(n-1,u);i++)
			for(j=0;j<=min(n-1,u);j++)
				for(k=0;k<=min(n-1,u);k++)				
					if(f(i,j,k,d)==1)
					{
						long long a=(((u-i)/n)+1)%1000000007;
						long long b=(((u-j)/n)+1)%1000000007;
						long long c=(((u-k)/n)+1)%1000000007;
						ans=(ans+(((a*b)%1000000007)*c)%1000000007)%1000000007;
					}
		printf("%lld\n",ans);
	}
	return 0;
}
