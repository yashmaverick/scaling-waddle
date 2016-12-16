#include<stdio.h>
long long int arr[40];
long long int powmod( long int a,long long int b,long long int c)
{
	 long long int ans=1;
	 a=a%c;
	while(b>0)
	{
		if(b&1==1)
		{
			ans=(ans*a)%c;
		}
		a=(a*a)%c;
		b>>=1;
	}
	return ans;
}
int main()
{
	 int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int up,d,m,n,cal,i,j,k,las,hit;
		long long int ans=0;
		scanf("%lld%lld%lld%lld",&up,&d,&m,&n);
		cal=m%n;
		for(i=0;i<n;i++)
		{
			arr[i]=0;
		}
		las=(up+1)/n;
		hit=(up+1)%n;
		for(i=0;i<n;i++)
		{
			k=(powmod(i,d,n))%n;
			arr[k]+=las;
		}
		for(i=0;i<hit;i++)
		{
			k=(powmod(i,d,n))%n;
			arr[k]++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(((i+j+k)%n)==cal)
						{
							ans=(ans+((((arr[i]%1000000007)*(arr[j]%1000000007))%1000000007)*arr[k]%1000000007)%1000000007)%1000000007;
						}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
