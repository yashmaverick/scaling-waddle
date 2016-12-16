#include <stdio.h>
#define sd(t) scanf("%d",&t)
#define sl(t) scanf("%lld ",&t)
#define mod 1000000007
#define ll long long
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define p(t) printf("%lld\n",t)
#define ret(a) return a
#define elif else if
int powerless(int,int,int);
int main(void)
{
	int valmod,i,j,k,t;
	ll int d,up,m,n,c;
	sd(t);
	w(t)
	{
		c=0;
		sl(up);sl(d);sl(m);sl(n);
		ll int a[n];
		f(i,n) a[i]=0;
		if(up>=n) f(i,n)
			if(d!=0)
			{
				valmod=powerless(i,d,n);
				a[valmod]+=((up-i)/n) +1;
			}
			elif(n!=1) a[1]+=(up-i)/n +1;
			else a[0]+=(up-i)/n +1;
		else f(i,up+1)
			if(d)
			{
				valmod=powerless(i,d,n);
				a[valmod]++;
			}
			elif(n!=1) a[1]++;
			else a[0]++;
		f(i,n) f(j,n) f(k,n) if((i+j+k)%n==m) c=(c+((a[i]*a[j])%mod*a[k])%mod)%mod;
		p(c);
	}
	ret(0);
}

int powerless(int n,int d,int mo)
{
	ll int i,j=1,k;
	if(d==1)
		ret(n%mo);
	elif(!d) ret(1%mo);
	elif(n<=1) ret(n%mo);
	elif(d&1) j=n;
	k=powerless(n,d/2,mo);
	ret((((k*k)%mo)*j)%mo);
}