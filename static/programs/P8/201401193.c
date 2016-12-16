#include<stdio.h>
long long int power(int n,long long int k,int m)
{
	if(k==0)
		return 1;
	else if(k==1)
		return n%m;
	long long int ans;
	ans=power(n,k/2,m);
	ans=(ans*ans)%m;
	if(k%2==1)
		ans=(ans*n)%m;
	return ans%m;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int d,ul,ni,nj,nk,ans=0,i,j,k;
		int n,m;
		scanf("%lld %lld %d %d",&ul,&d,&m,&n);
		long long int a[n],mod=1000000007;
		for(i=0;i<n;i++)
		{
			a[i]=power(i,d,n)%n;
//			printf("%lld ",a[i]);
		}
//		printf("\n");
		for(i=0;i<n && i<=ul;i++)
			for(j=0;j<n && j<=ul;j++)
				for(k=0;k<n && k<=ul ;k++)
					if((a[i]+a[j]+a[k])%n==m)
					{
						ni=((ul-i)/n)+1;
						if(ni<0)
							ni=0;
						nj=((ul-j)/n)+1;
						if(nj<0)
							nj=0;
						nk=((ul-k)/n)+1;
						if(nk<0)
							nk=0;
//				printf("%lld %lld %lld %d %d %d ",ni,nj,nk,i,j,k);
						ans+=(ni*((nj*nk)%mod)%mod);
//						printf("%lld\n",ans);
					}
		printf("%lld\n",ans%mod);
	}
	return 0;
}
