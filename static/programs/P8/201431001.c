#include<stdio.h>

#define MOD 1000000007

long long int powerex(long long a,long long b,long long m)
{
	long long int x;
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	else
	{
		x = powerex(a,b/2,m);
		if(b%2==0)
			return (x*x)%m;
		else
			return (((a*x)%m)*x)%m;
	}
}
/*long long int powerex(long long int a, long long int b,long long int m)
{
	long long int result = 1;
	while (b){
    	if (b&1){
    		result *= a;
    		result %= m;
    	}

    	b >>= 1;
    	b %= m;
    	a *= a;
    	a %= m;
    }

  return result%m;
}*/

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long ul,d,N,m;
		scanf("%lld %lld %lld %lld",&ul,&d,&m,&N);

		long long count[N];
		long long temp1=(ul%N),i,j,k;
		
		for (i = 0; i < N; i++)
			count[i]=ul/N;
		for (i = 0; i <= temp1; i++)
			count[i]++;
		
		/*for (i = 0; i < N; ++i)
		{
			printf("%lld ", count[i]);
		}
		printf("\n");
		*/
		long long finalcount=0;
		for (i=0;i<N;i++)
			for(j=0;j<N;j++)
				for(k=0;k<N;k++)
				{
					if(((powerex(i,d,N)+powerex(j,d,N)+powerex(k,d,N))%N)==m)
					{
						finalcount+=((((count[i]*count[j])%MOD)*count[k])%MOD);
						//printf("%lld ",finalcount);
					}
				}
				printf("%lld\n",finalcount%MOD);
	}
	return 0;
}