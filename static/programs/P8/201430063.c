#include<stdio.h>
#define ll long long int
#define MOD 1000000007
int val[45];
int modExp(int a,int b,int c)
{
	if(b==0)return 1;
	if(a==0)return 0;
	if(b==1)return a;
	int z=modExp(a,b/2,c);
	if(b%2==0)return (z*z)%c;
	return (z*z*a)%c;
}
int main()
{
	int t,upper,d,m,n,mod,i,j,k;
	ll repeat,repeat2,repeat3,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&upper,&d,&m,&n);
		mod=upper%n;
		repeat=upper/n;
		repeat2=(repeat*repeat)%MOD;
		repeat3=(repeat2*repeat)%MOD;
		for(i=0;i<n;i++)
			val[i]=modExp(i,d,n);
		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((val[i]+val[j]+val[k])%n==m)
					{
						ans+=repeat3;
						ans%=MOD;
					}
		for(i=0;i<=mod;i++)
			for(j=0;j<=mod;j++)
				for(k=0;k<=mod;k++)
					if((val[i]+val[j]+val[k])%n==m)
					{
						ans++;
						ans%=MOD;
					}
		for(i=0;i<=mod;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((val[i]+val[j]+val[k])%n==m)
					{
						ans+=(3*repeat2);
						ans%=MOD;
					}
		for(i=0;i<=mod;i++)
			for(j=0;j<=mod;j++)
				for(k=0;k<n;k++)
					if((val[i]+val[j]+val[k])%n==m)
					{
						ans+=(3*repeat);
						ans%=MOD;
					}
		printf("%lld\n",ans);
	}
	return 0;
}
