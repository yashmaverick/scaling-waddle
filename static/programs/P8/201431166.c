#include<stdio.h>
#define M 1000000007
long long int powmod(int i,int d,int N)
{
	long long int x;
	if(d==0)
		return 1;
	x=powmod(i,d/2,N);
	if((d%2)==0)
		return (x*x)%N;
	else
		return (i*((x*x)%N))%N;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int u,d,N,m;
		scanf("%lld %lld %lld %lld",&u,&d,&m,&N);
		long long int ans=m;
		long long int a[N],i,j,k,pairs;
		pairs=u/N;
		for(i=0;i<N;i++)
			a[i]=pairs;
		long long int extra;
		extra=u%N;
		for(i=0;i<=extra;i++)
			a[i]=a[i]+1;
		long long int count=0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				for(k=0;k<N;k++)
				{
					if((powmod(i,d,N)+powmod(j,d,N)+powmod(k,d,N))%N==ans)
						count=(count+(((a[i]*a[j])%M)*a[k])%M)%M;
				}
			}
	 	}
		printf("%lld\n",count);
	}
	return 0;
}



