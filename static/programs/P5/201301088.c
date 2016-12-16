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
#define mod(a) ((a)<0?-1*(a):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

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

int cmpfunc (const void * a, const void * b)
{
	return ( *(ll*)a - *(ll*)b );
}

ll i,j;

ll bs(ll a[],ll n,ll f,ll l)
{
	if(f<=l)
	{
		ll m=(f+l)/2;
		if(a[m]==n && m!=i && m!=j)
			return 1;
		else if(a[m]>n && m!=i && m!=j)
			return bs(a,n,f,m-1);
		else if(a[m]<n && m!=i && m!=j)
			return bs(a,n,m+1,l);
	}
	return 0;
}

int main()
{
	ll n,k,f,t;
	s(t);
	while(t--)
	{
		s(n);s(k); ll a[n];
		rep(i,n)
		{
			scanf("%*s");
			s(a[i]);
		}
		qsort(a,n,sizeof(ll),cmpfunc);
		rep(i,n) { fo(j,i+1,n) if((f=bs(a,k-a[i]-a[j],0,n-1))) break; if(f) break;}
		if(f) ps("YES\n");
		else ps("NO\n");
	}
	return 0;
}
