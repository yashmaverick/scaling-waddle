#include<stdio.h>
#include<stdlib.h>

#define fo(i,m,n) for(i=m;i<n;i++)
#define rep(i,n) fo(i,0,n)
#define s(n) fastRead_int(&n)
#define ss(s) scanf("%s",s)
#define sc(c) scanf("%c",&c)
#define ps(s) printf("%s",s)
#define p(n) printf("%lld\n",n)
#define pf(n) printf("%.9lf\n",n)
#define swp(i,a,b) {i=a^b; a^=i; b^=i;}
#define mod(a) ((a)<0?-1*(a):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long int ll;

int cmpfunc (const void * a, const void * b)
{
	return ( *(ll*)a - *(ll*)b );
}

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

ll bs1(ll a[],ll n,ll f,ll l)
{
	if(f<=l)
	{
		ll m=(f+l)/2;
		if(a[m]==n)
		{
			if(a[m-1]==n)
				return bs1(a,n,f,m-1);
			return m;
		}
		else if(a[m]>=n)
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
			if(a[m+1]==n)
				return bs2(a,n,m+1,l);
			return m;
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
		ll i,n,l,h,ans=0;
		s(n); ll a[n];
		rep(i,n) s(a[i]);
		qsort(a,n,sizeof(ll),cmpfunc);
//		rep(i,n) printf("%lld ",a[i]); puts("");
		rep(i,n)
		{
//			p(i);
			l=bs1(a,a[i],i,n-1);
			h=bs2(a,a[i],i,n-1);
			i=h;
//			printf("%lld %lld\n",l,h);
		//	p(i);
			h-=l; h++; h*=h-1; h/=2;
			ans+=h;
		}
		p(ans);
	}
	return 0;
}
