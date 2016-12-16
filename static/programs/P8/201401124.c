#include<stdio.h>
#define mod 1000000007
long long expo(long long i,long long d,long long N)
{
	long long ans=1;
	while(d!=0)
	{
		if(d%2!=0)
			ans=(ans*i)%N;
		i=(i*i)%N;
		d=d/2;
		if(ans<0)
			ans+=N;
	}
	return ans;
}
int main()
{
	int t;
	long long a[40],temp,u,sum,d,m,N,i,j,k,n;
	scanf("%d",&t);
	while(t)
	{
		sum=0;
		scanf("%lld %lld %lld %lld",&u,&d,&m,&N);
		for(i=0;i<40;i++)
			a[i]=0;
		n=u/N;
		if(u<(u%N))
			temp=u;
		else
			temp=u%N;
		for(i=0;i<=temp;i++)
			a[expo(i,d,N)]+=n+1;
		while(i<=u&&i<N)
		{
			a[expo(i,d,N)]+=n;
			i++;
		}
		for(i=0;i<40;i++)
			for(j=0;j<40;j++)
				for(k=0;k<40;k++)
					if(((i+j+k)%N)==m)
						sum=(sum+(((a[i]*a[j])%mod)*a[k])%mod)%mod;
					
			
		printf("%lld\n",sum);
		t--;
	}
	return 0;
} 
