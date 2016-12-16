#include<stdio.h>
#define f(i,n) for(i=0;i<n;i++)
#define LL long long int
LL a[40];
LL read_long(LL *address)
{
	scanf("%lld",address);
}
LL hem(LL *pointer)
{
	printf("%lld\n",*pointer);
}
LL ipow(LL a,LL b,LL mod)
{
	if(a==0)
		return 0;
	LL result=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			result=((result%mod)*a)%mod;
		a=(a%mod*a%mod)%mod;
		b>>=1;
	}
	return result;
}
int main()
{
LL t;
	read_long(&t);
	while(t--)
	{
		LL i,a1,a2,a3,d,n,u,count=0,m;
		read_long(&u);
			read_long(&d);
			read_long(&m);
			read_long(&n);
			a[0]=0;
		f(i,n) a[i]=ipow(i,d,n);
		f(a1,n)
			f(a2,n)
				f(a3,n)
					if((a[a1]+a[a2]+a[a3])%n==m) if(a1<=u && a2<=u && a3<=u) count=(count+((((((u-a1)/n)+1)%1000000007*(((u-a3)/n)+1)%1000000007)%1000000007)*(((u-a2)/n)+1))%1000000007)%1000000007;
		hem(&count);
	}
	return 0;
}
