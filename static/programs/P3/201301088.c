#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define fo(i,m,n) for(i=m;i<n;i++)
#define rep(i,n) fo(i,0,n)
#define s(n) fastRead_int(&n)
#define ss(s) scanf("%s",s)
#define sc(c) scanf("%c",&c)
#define ps(s) printf("%s",s)
#define p(n) printf("%lld\n",n)
#define pf(n) printf("%.9lf\n",n)
#define swp(i,a,b) {i=a^b; a^=i; b^=i;}
#define mod(a) (a<0?-1*a:a)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

typedef long long int ll;

inline void fastRead_int(ll *a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*a=0;
	while (c>33)
	{
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}

int main()
{
	ll i,t,test,n,max,min; s(test);
	while(test--)
	{
		s(n); ll a[n]; max=0; min=1e9;
		rep(i,n)
		{
			s(t);
			if(t<min)
				min=t;
			if(t-min>0) a[i]=t-min;
			else a[i]=0;
			max=max<a[i]?a[i]:max;
		}
		p(max);
	}
	return 0;
}
