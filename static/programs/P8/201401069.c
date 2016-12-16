#include<stdio.h>
#define max 1000000007
int expo(long long int a,long long int b,long long int n)
{
	int result=1;
	while(b>0)
	{
		if(b%2==1)
		{
			result=(result*a)%n;
		}
		b/=2;
		a=(a*a)%n;
	}
	return result;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int upper,d,m,N,i,j,k;
		scanf("%lld%lld%lld%lld",&upper,&d,&m,&N);
		long long int store[N],count[N],tot=0;
		for(i=0;i<N;i++)
			store[i]=expo(i,d,N);
		for(i=0;i<N;i++)
			count[i]=(upper+N-i)/N;
		for(i=0;i<N;i++)
		{
			if(store[i]<0)
				continue;
			for(j=0;j<N;j++)
			{
				if(store[j]<0)
					continue;
				for(k=0;k<N;k++)
				{
					if(store[k]<0)
						continue;
					if((store[i]+store[j]+store[k])%N==m)
					{
						long long int x1=(count[i]*count[j])%max;
						tot=(tot+(x1*count[k])%max)%max;
					}
				}
			}
		}
		printf("%lld\n",tot%max);
	}
	return 0;
}
