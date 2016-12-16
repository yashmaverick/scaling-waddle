#include<stdio.h>
long long int mod=1000000007;
int expon(int a,long long int pow,long long int mod)
{
	long long int base;
	if(pow==0)
		return 1;
	base=expon(a,pow/2,mod);
	if(pow%2==0)
		base=(base%mod*base%mod)%mod;
	else
		base=((base%mod*base%mod)%mod*a%mod)%mod;
	return base;
}

int main()
{
	long long int ul,d,c;
	int m,n,i,j,k,t,a[41];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%d%d",&ul,&d,&m,&n);
		if(d==0)
			a[0]=1;
		else 
			a[0]=0;
		for(i=1;i<n;i++)
		{
			a[i]=expon(i,d,n)%n;
		}
		c=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(i<=ul&&j<=ul&&k<=ul&&m==(a[i]+a[j]+a[k])%n)
						c=c%mod+((((ul-i)/n+1)%mod*(((ul-j)/n)+1)%mod)%mod*((ul-k)/n+1)%mod)%mod;
		printf("%lld\n",c%mod);
	}
	return 0;
}
