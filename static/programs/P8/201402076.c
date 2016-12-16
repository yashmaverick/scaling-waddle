#include<stdio.h>
#define MOD 1000000007 
long long n;
long long expo(long long x,long long y)
{
	if(y==0)
		return 1;
	else if(y==1)
		return x%n;
	else 
	{
		long long temp=expo(x,y/2);
		if(y%2==0)
			return (temp*temp)%n;
		else
			return (temp*temp*x)%n;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int ul,i,d,m,a[45]={0},b[45]={0};
		scanf("%lld %lld %lld %lld",&ul,&d,&m,&n);
		for(i=0;i<n;i++)
		{
			b[i]=expo(i,d);
		}
		for(i=0;i<n;i++)
		{
			a[i]=ul/n;
			if(i<=ul%n)
				a[i]++;
			//printf("%lld ",a[i]);
		}
		long long int j,k,ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((b[i]+b[j]+b[k])%n==m)
					{
						long long temp=a[i]*a[j];
						temp=temp%MOD;
						temp=temp*a[k];
						temp%=MOD;
						ans+=temp;
						ans%=MOD;
					}
		printf("%lld\n",ans);
	}
	return 0;
}


