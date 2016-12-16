#include<stdio.h>

unsigned long long int powmod(unsigned long long int a,unsigned long long int b,unsigned long long int n)
{
	unsigned long long int ans=1;
	while(b>0)
	{
		if((b%2)==1) ans=(ans*a)%n;

		a=(a*a)%n;
		b=b/2;
	}
	return ans;
}

int main()
{
	int t,z;
	scanf("%d",&t);

	for(z=0;z<t;z++)
	{
		unsigned long long int u,d,n,m;
		scanf("%llu %llu %llu %llu",&u,&d,&m,&n);

		unsigned long long int temp[n],i;

		for(i=0;i<n;i++)
		{
			temp[i]=powmod(i,d,n);
//			printf("%llu ",temp[i]);
		}
//		printf("\n");

		unsigned long long int j,k,ans=0;

		unsigned long long int check=u%n,count=u/n;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(m==((temp[i]+temp[j]+temp[k])%n))
					{
						unsigned long long int numx=count,numy=count,numz=count;

						if(i<=check) numx++;

						if(j<=check) numy++;

						if(k<=check) numz++;


						ans=((ans+((((numx*numy)%1000000007)*numz)%1000000007))%1000000007);
					}
				}
			}
		}

		printf("%llu\n",ans%1000000007);
	}
	return 0;
}