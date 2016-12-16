#include<stdio.h>
#define ll long long int
#define mod 1000000007
ll mpow(ll a,ll b,ll c)
{
	ll x=1,y=a; 
	y=y%c;
	while(b > 0){ 
		if(b%2 == 1){
			x=(x*y)%c;
		}
		y = (y*y)%c; 
		b /= 2;
	}
	return x%c;
}
int main()
{
	ll t,c,u,d,m,N,i,j,k,s,x,y,a[50],r;
	scanf("%lld",&t);
	while(t--)
	{
		c=0;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&N);
		a[0]=0;
		for(i=1;i<=40;i++)
			a[i]=mpow(i,d,N);
		x=m;
		r=N;
		for(i=0;i<r;i++)
		{
			for(j=0;j<r;j++)
			{
				for(k=0;k<r;k++)
				{
					s=a[i]+a[j]+a[k];
					if(s%N==x && i<=u&& j<=u && k<=u)
					{
					c=(c+((((((u-i)/N)+1)%mod)*((((u-j)/N)+1)%mod)%mod)*((((u-k)/N)+1)%mod))%mod)%mod;
					}
				}
			}
		}
		printf("%lld\n",c);
	}
	return 0;
}

