#include <stdio.h>
typedef long long int ll;
ll answ;//global

/*int modex(int a,int p,int m)
  {
  int ans=1;
  while(p>0)
  {
  if(p%2==1)
  ans=(ans*p)%m;
  p/=2;
  a=(a*a)%m;
  }
  return ans;
  }*/
ll modex(ll a,ll b,ll m)
{
	ll ans=1;
	while(b>0)
	{    
		if(b&1==1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b/=2;}
	return ans; 
}


	ll func(ll x,ll u,ll n)
{   if(u>=x)
	return (u-x)/n+1;
	else
		return 0;
}

void execute(ll x,ll y,ll z,ll u,ll n)
{
	answ=(answ+((func(x,u,n)*func(y,u,n))%1000000007*func(z,u,n)%1000000007))%1000000007;
}

int main()
{
	answ=0;

	ll t,u,d,m,n,a[1000007];

	ll i,j,k;

	scanf("%lld",&t);

	while(t--)
	{
		answ=0;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
		for(i=1;i<n;i++)
			a[i]=modex(i,d,n);
		if(d==0)
			a[0]=1;
		else
			a[0]=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(((a[i]+a[j])%n+a[k]%n)%n==m)
						execute(i,j,k,u,n);
		printf("%lld\n",answ);

	}

	return 0;
}
