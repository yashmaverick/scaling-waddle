#include<stdio.h>
int n;
long long int power(long long int base,long long int exp)
{
	long long int p;
	if(base==0 && exp==0)
		return 1;
	if(exp==0)
		return 1;
	p=power(base,exp/2)%n;
	if(exp%2==0)
		return (p%n*p%n)%n;
	else
		return ((base%n*p%n)%n*p%n)%n;
}
int main()
{
	int g,t,m;
	long long int i,j,k,ul,d,count=0,count1=0,count2=0,count3=0;
	scanf("%d",&t);
	for(g=0;g<t;g++)
	{
		scanf("%lld%lld%d%d",&ul,&d,&m,&n);
		count=0;
		if(ul<=n)
		{
			for(i=0;i<=ul;i++)
			{
				for(j=0;j<=ul;j++)
				{
					for(k=0;k<=ul;k++)
					{
						if(((((power(i,d))%n)+((power(j,d))%n)+((power(k,d))%n))%n)==m)
							count++;
					}
				}
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					for(k=0;k<n;k++)
					{
						count1=(((ul-i)/n)+1)%1000000007;
						count2=(((ul-j)/n)+1)%1000000007;
						count3=(((ul-k)/n)+1)%1000000007;
						if(((((power(i,d))%n)+((power(j,d))%n)+((power(k,d))%n))%n)==m)
							count=((count%1000000007)+((((count1*count2)%1000000007)*count3)%1000000007)%1000000007);

					/*	count1=(((ul-i)/n)+1)%1000000007;
						count2=(((ul-j)/n)+1)%1000000007;
						count3=(((ul-k)/n)+1)%1000000007;
						count=((count%1000000007)+((((count1*count2)%1000000007)*count3)%1000000007)%1000000007);*/
					}
				}
			}
		}
		printf("%lld\n",count%1000000007);
	}
	return 0;
}
