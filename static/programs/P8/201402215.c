#include<stdio.h>
long long int n=1000000007;
long long int power(long long int i,long long int d,long long int N)
{	long long int ans;
	if(d==0)
		return 1;
	else
	{
		ans=power(i,d/2,N)%N;
	if(d%2==0)
	return (ans*ans)%N;
	else
		return (ans*ans)%N*i;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int upperlimit,d,m,N,ans=0;
	long long int i,j,k;	
		scanf("%lld %lld %lld %lld",&upperlimit,&d,&m,&N);
		long long int a[40]={0};
		for(i=0;i<N;i++)
		{
			
			a[i]=power(i,d,N)%n;
		}
//		for(i=0;i<N;i++)
//			printf("%lld ",a[i]);
//		printf("\n");
		long long int x,y,z;
		for(x=0;x<N;x++)
		{
			for(y=0;y<N;y++)
			{
				for(z=0;z<N;z++)
				{
					if((a[x]+a[y]+a[z])%N==m%N && x<=upperlimit && y<=upperlimit && z<=upperlimit)
					{	//printf("%lld %lld %lld\n",x,y,z);
						i=(upperlimit-x)/N+1;
						j=(upperlimit-y)/N+1;
						k=(upperlimit-z)/N+1;
					
					ans+=((i)%n*(j)%n*(k)%n)%n;
					}
				}
			}
		}
		printf("%lld\n",ans%n);
	}
	return 0;
}


