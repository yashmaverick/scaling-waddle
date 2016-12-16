#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define fo(i,m,n) for(i=m;i<n;i++)
#define rep(i,n) fo(i,0,n)
#define s(n) scanf("%lld",&n)//fastRead_int(&n)
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
/*
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
*/
ll bs1(ll a[],ll n,ll f,ll l)
{
	if(f<=l)
	{
		ll m=(f+l)/2;
		if(a[m]==n)
		{
			if(a[m-1]==n) return bs1(a,n,f,m-1);
		}
		else if(a[m]>n)
			return bs1(a,n,f,m-1);
		else
			return bs1(a,n,m+1,l);
	}
	return f;
}

ll bs2(ll a[],ll n,ll f,ll l)
{
	if(f<=l)
	{
		ll m=(f+l)/2;
		if(a[m]==n)
		{
			if(a[m+1]==n && m<l) return bs2(a,n,m+1,l);
			else return m;
		}
		else if(a[m]>n)
			return bs2(a,n,f,m-1);
		else
			return bs2(a,n,m+1,l);
	}
	return f;
}

int main()
{
	ll t; s(t);
	while(t--)
	{
		ll i,j,l,m,n,c2,c3,ans=0;
		s(l); ll p[l]; rep(i,l) s(p[i]);
		s(m); ll q[m],a[m],b[m]; rep(i,m) s(q[i]);
		s(n); ll r[n]; rep(i,n) s(r[i]);
		rep(j,m)
		{
			c3=j<n?bs1(r,q[j],j,n-1):n;
			b[j]=n-c3;
//			printf("%lld\n",c3);
		}
//		rep(j,m) printf("%lld ",b[j]); puts("");
		rep(j,m)
		{
			c3=bs2(p,q[j],0,min(j,l-1));
			if(p[c3]==q[j]) a[j]=c3+1;
			else a[j]=c3;
		}
//		rep(j,m) printf("%lld ",a[j]); puts("");
		for(i=0;i<m;i++)
			ans+=a[i]*b[i];
		p(ans);
	}
	return 0;
}
