#include <stdio.h>
#define MOD 1000000007
long long int fexp(long long int a, long long int b)
{
	if (b == 0)
		return 1;
	if (a == 0)
		return 0;
	if (b == 1)
		return a;
	if (b == 2)
		return a*a;
	if (b%2 == 0)
		return fexp(fexp(a,b/2),2);
	else
		return a*fexp(fexp(a,(b-1)/2),2);
}
long long int mmod(long long int a, long long int b, long long int n)
{
	long long int ans = 1;
	a = a%n;
	while (b > 0)
	{
		if (b&1 == 1)
		{
			ans = (ans*a)%n;
		}
		a = (a*a)%n;
		b>>=1;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a[1000000] = {0};
		long long int u,d,m,n;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
		long long int val = m%n;
		long long int t,t1,t2,t3;
		long long int i,j,k;
		long long int ans = 0;
		long long int count = 0;
		long long int x;
		for (i = 0; i < n; i++)
		{
			x = mmod(i,d,n);
			if (i <= u) a[x] += (u-i)/n + 1;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if ((i+j+k)%n == val)
					{
						ans += ((a[i]*((a[j]*a[k])%MOD))%MOD);
						ans = ans%MOD;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
