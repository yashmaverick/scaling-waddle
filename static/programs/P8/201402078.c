#include<stdio.h>
#define mod 1000000007
long long int calculate(long long int k,long long int d,long long int n)
{
	int result = 1;
	while (d)
	{
		if(d&1)
			result=(result*k)%n;
		d>>=1;
		k=(k*k)%n;
	}
	return result%n;
}
int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		long long int ul,d,m,n;
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
		long long int i,a[40],j,k;
		for(i=0;i<n;i++)
			a[i]=calculate(i,d,n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((a[i]+a[j]+a[k])%n== m && i<=ul && j<=ul && k<=ul) 
					{
						ans=(ans+((((((ul-i)/n)+1)%mod)*(((ul-j)/n)+1)%mod)%mod)*((((ul-k)/n)+1)%mod)%mod)%mod;
					}
		printf("%lld\n",ans);
	}
	return 0;
}
