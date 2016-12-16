#include<stdio.h>
#define MOD 1000000007
void func1(int max,long long int a[])
{
	int j=0;
	while(a[j]!='\0')
	{
		if(max==a[j])
			break;
		j++;
	}
	printf("The value in place %d is the max\n",j);
}
int func(int b,int p,int m)
{
	int r=1;
	while(p>0)
	{
		if(p%2==1)
			r=(r*b)%m;
		p=p/2;
		b=(b*b)%m;
	}
	return r;
}
int main()
{
	int i,j,k,l,t;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{

		long long int ul,d;
		long long int n,m;
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
		long long int a[100000];
		long long int max=0;
		for(j=0;j<n;j++)
		{
			a[j]=func(j,d,n);
			if(a[j]>max)
				max=a[j];
		}
		long long int ans=0,x,y,z;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
				{
					if((a[i]+a[j]+a[k])%n==m)
					{
						x=(ul>=i)?(1+((ul-i)/n))%MOD:0;
						y=(ul>=j)?(1+((ul-j)/n))%MOD:0;
						z=(ul>=k)?(1+((ul-k)/n))%MOD:0;
						ans=(ans+((((x*y)%MOD)*z)%MOD))%MOD;
					}
				}
		printf("%lld\n",ans);
	}
	return 0;
}

