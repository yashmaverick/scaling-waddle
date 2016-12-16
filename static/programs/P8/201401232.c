#include<stdio.h>
typedef long long int lon;
lon n;
#define MOD 1000000007
void anombomb(lon hean[],lon n,lon up,lon exp);
int main()
{
	lon l,k;
	scanf("%lld",&k);
	while(k>0)
	{
		lon exp,up,m,l,po,ko,ans=0;
		scanf("%lld%lld%lld%lld",&up,&exp,&m,&n);
//		m=m%o;
	//	printf("%lld\n",m);
		lon hean[43];
		for(l=0;l<n;l++)
			hean[l]=0;
			m=m%n;
		anombomb(hean,n,up,exp);
		for(l=0;l<n;l++)
		{
			//printf("%lld  ",hean[l]);
		}
		for(l=0;l<n;l++)
		{
			for(po=0;po<n;po++)
			{
				for(ko=0;ko<n;ko++)

				{
					if(((po+ko+l)%n==m)&&(hean[po]*hean[l]*hean[ko])!=0)
					{
		//			printf("%lld %lld %lld\n",l,po,ko);
						ans=((ans%MOD)+((((hean[po]%MOD)*(hean[ko]%MOD))%MOD)*(hean[l]%MOD))%MOD)%MOD;
					}
				}
			}
		}
		printf("%lld\n",ans%MOD);
		k--;
	}
	return 0;
}
lon power(lon base,lon exp)
{
	lon aos=1;
	while(exp>0)
	{
		if(exp%2==0)
		{
			base=base%n;
		}
		else
		{
			aos=((aos%n)*(base%n))%n;
		}
		base=((base*base))%n;
		exp=exp/2;
	}
	return aos;
}
void anombomb(lon hean[],lon n,lon up,lon exp)
{
	lon l,sdk;
	sdk=exp;
	for(l=0;l<n&& l<=up;l++)
	{
	    sdk=exp;
		lon aos=1;
		aos=power(l,exp);	//	printf("%lld ",aos);
		hean[aos]++;
	//	printf("funcfor   ");
//		printf("%lld  ",hean[aos]);
		if(up>aos)
            hean[aos]+=(up-l)/n;//printf("%lld  ",hean[aos]);
//printf("%lld ",aos);
//printf("/n");	}
}
	return ;
}


