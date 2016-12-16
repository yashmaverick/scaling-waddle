#include<stdio.h>
long long int N;
long long int limit=0;
long long int up;
long long int squa(long long int a,long long int b)
{
	if(b==0)
		return 1;
	long long int x=squa(a,b/2);
	long long int y=((x%N)*(x%N))%N;
	if(b%2)return ((a%N)*(y%N))%N;
	return y%N;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int i,j,k,d,c;
		long long int l,m;
		scanf("%lld%lld%Ld%Ld",&up,&d,&m,&N);
		//	printf("the value of c is %d\n",c);
		limit=up%N;
		long long int count=0;
		l=(up>N)?N:up;
		for(i=0;i<=N-1;i++)
		{
			for(j=0;j<=N-1;j++)
			{
				for(k=0;k<=N-1;k++)
				{
					if((squa(i,d)+squa(j,d)+squa(k,d))%N==m)
					{	
						count=count+(((up-i)/N+1)%1000000007*((up-j)/N+1)%1000000007*((up-k)/N+1)%1000000007);
					}
				}
			}
		}
		printf("%lld\n",count%1000000007);
	}
	return 0;
}
