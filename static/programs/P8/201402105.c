#include<stdio.h>
#define mod 1000000007
int exp(int b,int e,int m)
{
	if(e==0)return 1;
	if(e==1)return b;
	if(e&1)return (b*exp(b,e-1,m))%m;
	int k=exp(b,e/2,m);
	return (k*k)%m;
}
int main()
{
	int t,n,m,d,u,i,j,k,t1,t2,t3;
	int a[40];
	long long int ans,t4,t5,t6;
	scanf("%d",&t);
	while(t)
	{
		t--;
		scanf("%d %d %d %d",&u,&d,&m,&n);
		m=m%n;
		if(u>=n)
		{
			t1=u/n;
			t2=n;
			t3=u%n;
		}
		else
		{
			t1=0;
			t3=u;
			t2=u+1;
		}
		for(i=0;i<t2;i++)
		{
			a[i]=exp(i,d,n);
		}
		ans=0;
		for(i=0;i<t2;i++)
		{
			for(j=0;j<t2;j++)
			{
				for(k=0;k<t2;k++)
				{
					if((a[i]+a[j]+a[k])%n==m)
					{
						if(i<=t3)t4=t1+1;
						else t4=t1;
						if(j<=t3)t5=t1+1;
						else t5=t1;
						if(k<=t3)t6=t1+1;
						else t6=t1;
						t4=(t4*t5)%mod;
						t4=(t4*t6)%mod;
						ans=(ans+t4)%mod;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
