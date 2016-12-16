#include<stdio.h>
long long int emod(long long int a,long long int e,long long int N)
{
	long long int res=1;
	while(1)
	{
		if(e<=0)
		{
			break;
		}
		if((e&1)==1)
		{
			res=(res*a)%N;
		}
		e=e>>1;
		a=(a*a)%N;
	}
	return res%N;
}

int main()
{
	long long int test;
	long long int a,b,count,x;
	long long int A1,A2,A3,u,d,m,N,x1,x2,x3;
	scanf("%lld",&test);
	while(test)
	{
		test--;
		scanf("%lld %lld %lld %lld",&u,&d,&m,&N);
		count=0;
		for(A1=0;((A1<N)&&(A1<=u));A1++)
		{
			for(A2=0;((A2<N)&&(A2<=u));A2++)
			{
				for(A3=0;((A3<N)&&(A3<=u));A3++)
				{
					x=emod(A1,d,N)+emod(A2,d,N)+emod(A3,d,N);
					if((x%N)==m)
					{
						x1=((u-A1)/N)+1;
						x2=((u-A2)/N)+1;
						x3=((u-A3)/N)+1;
						x1=x1%1000000007;
						x2=x2%1000000007;
						x3=x3%1000000007;
						count+=(((x1*x2)%1000000007)*x3)%1000000007;
						count=count%1000000007;
					}
				}
			}
		}
		count=count%1000000007;
		printf("%lld\n",count);
	}
	return 0;
}

