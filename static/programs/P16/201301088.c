#include<stdio.h>
typedef long long ll;
ll f(ll n)
{
	ll i=0;
	while(n/2)
	{
		n/=2;
		i++;
	}
	return i;
}
int main()
{
	ll n,t,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n); i=f(n); i = 1 << i;
		if( (n-i+1) <= i/2 ) printf("%lld\n",2*f(n)-1);
		else printf("%lld\n",2*f(n));
	}
	return 0;
}
