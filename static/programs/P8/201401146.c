#include<stdio.h>
int PW(int a,long long int d,int N)
{
	if(d==0)
		return 1;
	if(d==1)
		return a%N;
	int t;
	t=PW(a,d/2,N);
	if(d%2==0)
		return ((t%N)*(t%N))%N;
	else
		return (((a%N)*(t%N))%N*(t%N))%N;
}
int main()
{
	int t,m,N,j,k,l,i,x,y,z;
	long long int ul,d,ans,F;
	scanf("%d",&t);
	while(t--)
	{
		F=1000000007;
		scanf("%lld%lld%d%d",&ul,&d,&m,&N);
		if(ul>=N-1)
			l=N-1;
		else
			l=ul;
		int pow[41];
		for(i=0;i<=N;i++)
			pow[i]=(PW(i,d,N));
		ans=0;
		for(i=0;i<=l;i++)
		{
			for(j=0;j<=l;j++)
			{
				for(k=0;k<=l;k++)
				{
					if((pow[i]+pow[j]+pow[k])%N==m)
					{
						x=(ul-i)/N+1;
						y=(ul-j)/N+1;
						z=(ul-k)/N+1;
						ans=ans+((((x%F)*(y%F))%F)*(z%F))%F;
					}
				}
			}
		}
		printf("%lld\n",ans%F);
	}
	return 0;
}
