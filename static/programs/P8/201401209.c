#include<stdio.h>
#define modulo 1000000007
typedef unsigned long long int ulld;
ulld power(ulld base , ulld exp,ulld n)
{
	ulld t=1;
	ulld temp=base%n;
	while(exp>0)
	{
		if(exp%2!=0)
		{
			t=(t*(temp%n))%n;
		}
		exp=exp/2;
		temp=((temp%n)*(temp%n))%n;
	}
	return t;
}
int main()
{
	unsigned long long int ans=0;
	unsigned long long int u,pow,m,n,d,soli,solj,solk,i,j,k;
	unsigned long long int cases;
	scanf("%llu",&cases);
	while(cases--)
	{	ans=0;
		scanf("%llu %llu %llu %llu",&u,&pow,&m,&n);
		ulld a[n];
		for(i=0;i<n;i++) a[i]=power(i,pow,n);
		//for(i=0;i<n;i++) printf("%lld ",a[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if((a[i]+a[j]+a[k])%n==m)
					{
						//printf("%lld %lld %lld \n",i,j,k);
						if( i<=u%n) soli=(u/n)%modulo+1;
						else soli=(u/n)%modulo;
						if( j<=u%n) solj=(u/n)%modulo+1;
						else solj=(u/n)%modulo;
						if( k<=u%n) solk=(u/n)%modulo+1;
						else solk=(u/n)%modulo;
						ans+=(((soli*solj)%modulo)*((solk)))%modulo;					
					}
				}
			}
		}
		printf("%llu\n",ans%modulo);
	}
	return 0;
}
