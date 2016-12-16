#include<stdio.h>
int main()
{
	long long int N,ll;
	scanf("%lld",&N);
	for(ll=1;ll<=N;ll++)
	{
		long long int a1,b1,c1;
		long long int a[100000],b[100000],c[100000];
		long long int i;
		scanf("%lld",&a1);
		for(i=0;i<a1;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&b1);
		for(i=0;i<b1;i++)
		{
			scanf("%lld",&b[i]);
		}
		scanf("%lld",&c1);
		for(i=0;i<c1;i++)
		{
			scanf("%lld",&c[i]);
		}long long int max=(c1>b1)?b1:c1;
		long long int lima=0,limc=0;
		long long int sum=0,j;
		for(i=0;i<max;i++)
		{if(lima==-1)lima=0;
			for(j=lima;j<=i;j++)
			{
				if(a[j]>b[i])
				{
					lima=j-1;
					if(j==0)
					lima=-1;
					break;
				}
			}
			if(j>i)
				lima=i;
			
			for(j=(limc>i)?limc:i;j<c1;j++)
			{
				if(c[j]>=b[i])
				{
					limc=j;
					break;
				}
			}
			if(j>=c1)
				limc=c1;
			sum=sum+(lima+1)*(c1-limc);
	//		printf("present sum is %lld\n",sum);
//			printf("%lld %lld %lld\n",i,j,sum);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
