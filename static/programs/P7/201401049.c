#include <stdio.h>
#include <limits.h>
#define MIN(X,Y) (((X)<(Y))?(X):(Y))
#define s(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define MAX 1000006
#define ll long long
#define w(t) while(t--)
#define f(i,j,n) for(i=j;i<n;i++)
#define p(t) printf("%lld\n",t)
#define ret(a) return a
#define c(t) t*(t-1)/2
ll int a[MAX],b[MAX];
int main(void)
{
	int t,n;
	ll int i,freq,res,min;
	s(t);
	w(t)
	{
		s(n);
		sl(a[0]);
		min=a[0];
		f(i,1,n)
		{
			sl(a[i]);
			min=MIN(a[i],min);
		}
		f(i,0,n)
		{
			a[i]-=min;
			b[a[i]]++;
		}
		res=0;
		f(i,0,1000001)
		{
			if(b[i]>1)
				res+=c(b[i]);
			b[i]=0;
		}
		p(res);
	}
	ret(0);
}