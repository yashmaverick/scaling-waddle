#include<stdio.h>
long long int per(long long int t,long long int d,int N)
{
	if(d==0)
	{
		return 1;
	}
	else if(d%2==0)
	{
		return per(((t%N)*(t%N)),d/2,N)%N;
	}
	else
	{
		return ((per((t%N)*(t%N),d/2,N))*(t%N))%N;
	}
}
long long int nos(long long int p,long long int N,long long int ul)
{
	if(p<=ul%N)
	{
		return (ul/N)+1;
	}
	else
	{
		return (ul/N);
	}
}
int main()
{
	long long int ul,d,N,m;
	int t,v;
	long long int a[41];
	long long int p,q,r;
	long long int ans;
	scanf("%d",&t);
	while(t>0)
	{
		ans=0;
		scanf("%lld %lld %lld %lld",&ul,&d,&m,&N);
		for(v=0;v<N;v++)
		{
			a[v]=per(v,d,N);
		}
		for(p=0;p<N;p++)
		{
			for(q=0;q<N;q++)
			{
				for(r=0;r<N;r++)
				{
					if((a[p]+a[q]+a[r])%N==m)
					{
						ans=(ans+(((nos(p,N,ul)*nos(q,N,ul))%1000000007)*nos(r,N,ul))%1000000007)%1000000007;
					}
				}
			}
		}
		printf("%lld\n",ans);
		t--;
	}
	return 0;
}
