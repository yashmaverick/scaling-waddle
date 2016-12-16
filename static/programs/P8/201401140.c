#include<stdio.h>
long long int modulo(long long int b,long long int m,long long int e)
{
	long long int r=1;
	b=b%m;
	while(e>0)
	{
		if(e%2==1)
			r=((r%m)*(b%m))%m;
		e=e >> 1;
		b=((b%m)*(b%m))%m;
	}
	return (r%m);
}
long long int mod(long long int i,long long int j,long long int k,long long int d,long long int N)
{
	long long int q=0;
	q=q+modulo(i,N,d)%N;
	q=q+modulo(j,N,d)%N;
	q=q+modulo(k,N,d)%N;
	q=q%N;
	return q;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		long long int ul,d,m,N,l,y;
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&N);
		long long int i,j,k,q,x,count=0,count1=0,count2=0,sum=0;
		x=((ul)%N);
		l=ul/N;
		if(ul<N)
			y=ul;
		else
			y=N-1;
		for(i=0;i<=y;i++)
			for(j=0;j<=y;j++)
				for(k=0;k<=y;k++)
				{
					q=mod(i,j,k,d,N);
					if(q==m)
					{
						count=((ul-i)/N+1)%1000000007;
						count1=((ul-j)/N+1)%1000000007;
						count2=((ul-k)/N+1)%1000000007;
						sum=(sum+((((count*count1)%1000000007)*count2)%1000000007)%1000000007);
					}
				}
		printf("%lld\n",(sum%1000000007));
	}
	return 0;
}
