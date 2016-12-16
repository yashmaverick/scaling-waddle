#include<stdio.h>
unsigned long long int power(unsigned long long int a,unsigned long long int n,unsigned long long int N,unsigned long long int product)
{
	if(n==1)
	{
		return a;
	}
	else
	{
		product=power(a,n/2,N,product);
		if(n%2==0)
		{
			product=((product)%N*(product%N))%N;
		//	product=product%N;
		}
		else
		{
			product=(product%N)*(product%N)*a;
			product=product%N;
		}
//		printf("%llu %llu %llu\n",a,n,product);
		return product;

	}
}
int main()
{
	unsigned long long int a,n,ans,d,N,m,uplim,t,test,tot,count,i,j,k,sum,max,count1,totx,toty,totz,flag=0;
	scanf("%llu", &test);
	unsigned long long int b[50];
	for(t=0;t<test;t++)
	{
		flag=0;
		count=0;tot=0;count1=0;totx=toty=totz=0;
		scanf("%llu %llu %llu %llu", &uplim, &d, &m, &N);
		max=N-1;
		for(i=0;i<45;i++)
		{
			b[i]=power(i,d,N,i);
		}
		if(uplim<N)
		{
			max=uplim;
		}
		for(i=0;i<=max;i++)
		{
			for(j=0;j<=max;j++)
			{
				for(k=0;k<=max;k++)
				{
					sum=b[i]+b[k]+b[j];
					//		printf("%lld\n", sum);
					if(sum%N==m)
					{
						if(k<=uplim%N)
						{
							totz=(((uplim)/N))%1000000007+1;
						}
						else
						{
							totz=(((uplim)/N))%1000000007;
						}
						if(j<=uplim%N)
						{
							toty=(((uplim)/N))%1000000007+1;
						}
						else
						{
							toty=((uplim/N))%1000000007;
						}
						if(i<=uplim%N)
						{
							totx=(((uplim)/N))%1000000007+1;
						}
						else
						{
							totx=((uplim)/N);
						}
						tot=tot+(((totx*toty)%1000000007)*(totz%1000000007))%1000000007;
					}
				}
			}
		}
		printf("%llu\n", tot%1000000007);
	}
	return 0;
}


