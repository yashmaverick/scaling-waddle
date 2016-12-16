#include<stdio.h>

long long int p(long long int a,long long int b,long long int m)
{
        long long int x;
        if(b==0)
                return 1;
        x=(p(a,b/2,m))%m;
        if(b%2==0)
                return ((x%m)*(x%m))%m;
        else
                return ((a%m)*(((x%m)*(x%m))%m))%m;
}


int main()
{
	long long int x,y,z,count,val,t,ul,d,N,m,i,j,k,temp;
	scanf("%lld",&t);
	while(t--)
	{
		count=0;
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&N);
		val=m;
		for(i=0;i<N;i++)
		{
			x=p(i,d,N)%N;
			for(j=0;j<N;j++)
			{
				y=p(j,d,N)%N;
				for(k=0;k<N;k++)
				{
					if(i<=ul && j<=ul && k<=ul)
					{
						z=p(k,d,N)%N;
						temp=(x+y+z)%N;
						if(temp==val)
							count=(count+((((((ul-i)/N)+1)%1000000007)*((((ul-j)/N)+1)%1000000007)%1000000007)*((((ul-k)/N)+1)%1000000007))%1000000007)%1000000007;
					}
				}
			}

		}
		printf("%lld\n",count);
	}
	return 0;
}
