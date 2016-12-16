#include<stdio.h>
long long int power(long long int x,long long int xx)
{
	long long int i,j,pow1=1,pow2=1;
	for(i=0;i<x;i++)
	{
		pow1=pow1*2;
	}
	for(j=0;j<xx;j++)
	{
		pow2=pow2*2;
	}
	return pow1+pow2-1;
}
int main()
{
	long long int T,N,n,i,xxx,count;
	scanf("%lld",&T);
	for(i=0;i<T;i++)
	{
		count=0;
		scanf("%lld",&n);
		if(n==1)
			printf("0\n");
		if(n>1)
		{
			count=0;
			N=n;
			while(N!=1)
			{
				N=N/2;
				count++;
			}
			xxx=power(count,count-1);

			if(n>xxx)
				printf("%lld\n",2*count);
			else
				printf("%lld\n",2*count-1);
		}
	}
	return 0;
}
