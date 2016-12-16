#include<stdio.h>
#define MAX 45
#define M 1000000007
long long int ex(long long int a,long long int b,long long int n)
{
	long long int temp,ans=1;
	if(b==0)
		return 1;
	else
	{
		temp=ex(a,b/2,n)%n;
		if(b%2==0)
			ans=(ans*(temp*temp)%n)%n;
		else
			ans=(((ans*(a*(temp*temp)%n)%n)%n))%n;
	}
	return ans;
}
int main()
{
	long long int tc,i,j,k,A[MAX],B[MAX],up,d,n,m,cnt,x,y,z,temp,dum;
	scanf("%lld",&tc);
	while(tc--)
	{
		cnt=0;
		scanf("%lld%lld%lld%lld",&up,&d,&m,&n);
		for(i=0;i<n;i++)
			A[i]=i;
		for(i=0;i<n;i++)
		{
			B[i]=ex(i,d,n)%n;
//			printf("%lld ",B[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					temp=(B[i]+B[j]+B[k])%n;
					if(temp==m && i<=up && j<=up && k<=up)
					{
						x=(up-i)/n+1,y=(up-j)/n+1,z=(up-k)/n+1;
						cnt=(cnt+(((x*y)%M)*z)%M)%M;
					}
				}
			}
		}
		printf("%lld\n",cnt);

	}
	return 0;
}
