#include<stdio.h>
#include<stdlib.h>
long long int func(long long int a,long long int n,long long int m)
{
    long long int c=1;
    while(n)
    {
	if(n&1)
	{
	    c=(c*a)%m;
	}
	n=n>>1;
	a=(a*a)%m;
    }
    return c%m;
}
int check(long long int a,long long int b,long long int c,long long int k,long long int m)
{
    if(((((((a%m)+(b%m))%m)%m)+c)%m)==k)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
long long int jugad(int UL,int i,int N)
{
    if((UL-i)<0)
    {
	return 0;
    }
    else
    {
	return (((UL-i)/N)+1);
    }
}
int main()
{
    int t;
    long long int UL,d,m,N,i,ans,j,k,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
	ans=0;
	scanf("%lld %lld %lld %lld",&UL,&d,&m,&N);
	for(i=0;i<N;i++)
	{
	    for(j=0;j<N;j++)
	    {

		for(k=0;k<N;k++)
		{
		    x=func(i,d,N)%N;
		    y=func(j,d,N)%N;
		    z=func(k,d,N)%N;
		    if(check(x,y,z,m,N))
		    {
//			printf("%lld %lld %lld\n",i,j,k);
			ans=ans+(((jugad(UL,i,N))*(jugad(UL,j,N)))%1000000007*(jugad(UL,k,N)))%1000000007;
		    }
		}
	    }
	}
	printf("%lld\n",ans%1000000007);
    }
    return 0;
}

