#include<stdio.h>
#define mod 1000000007
typedef long long LL;
LL a[1001], b[1001];

LL fastexp(LL a, LL b, LL n)
{
	if(b == 0)
		return 1;
	LL x = fastexp(a, b/2, n);
	LL y = (x*x)%n;
	if(b%2)
		return (a*y)%n;
	return y;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL ul, d, m, n, i, j, k, quo, rem, count=0;
		scanf("%lld%lld%lld%lld", &ul, &d, &m, &n);
		for(i=0; i<n; i++)
			a[i] = fastexp(i,d,n);
		quo = ul/n;
		rem = ul%n;
		for(i=0; i<n; i++)
		{
			if(i <= rem)
				b[i] = quo+1;
			else
				b[i] = quo;
		}
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				for(k=0; k<n; k++)
					if((a[i]+a[j]+a[k])%n == m%n)
						count = (count +(((b[i]*b[j])%mod)*b[k])%mod)%mod;
		printf("%lld\n", count);
	}

	return 0;
}
