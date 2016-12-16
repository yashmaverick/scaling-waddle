#include<stdio.h>
#define mn 1000000007
typedef long long int ll;
ll a[40];
ll powmod(ll a,ll b,ll m)
{
		ll ans=1;
		while(b>0)
		{
				if(b&1==1)//checking if b is odd
						ans=(ans*a)%m;
				a=(a*a)%m;
				b=b/2;
		}
		return ans;
}
int main()
{
		ll t,d,m,n,i,j,k,l,ul;
		scanf("%lld",&t);
		for(i=0;i<t;i++)
		{
				scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
				ll count=0;
				//if(n<ul)
				//		ul=n;
				ll ld,jd,kd,cj,ck,cl;
				for(j=0;j<n;j++)
				{
						jd=powmod(j%n,d,n);
						for(k=0;k<n;k++)
						{
								kd=powmod(k%n,d,n);
								for(l=0;l<n;l++)
								{
										ld=powmod(l%n,d,n);
										if(((jd%n+kd%n)%n+ld%n)%n==m)
										{
												cj=ck=cl=0;
												if(ul>=j)
														cj=(((ul-j)/n)+1);
												if(ul>=k)
														ck=(((ul-k)/n)+1);
												if(ul>=l)
														cl=(((ul-l)/n)+1);
												count=((count+(((cj*ck)%mn)*cl)%mn)%mn);

										}
								}
						}
				}
				printf("%lld\n",count%mn);
		}
		return 0;
}
