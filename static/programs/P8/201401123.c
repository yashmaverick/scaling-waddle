#include<stdio.h>
#define s(n) scanf("%lld",&n)
typedef long long int LL;
#define M 1000000007

LL expo (LL a, LL b, LL mod);

void create_powers(LL power[], LL d, LL n)
{
	int i;
		for(i=0;i<n;i++)
			power[i]=expo(i,d,n);
}
LL expo (LL a, LL b, LL mod)
{
	LL prod=1;
	LL val=a;
	while(b)
	{
		if(b&1)
			prod=((prod * val)%mod);

		val=((val * val)%mod);
		//b=b>>1;
		b/=2;
	}
	//printf("%lld \n",prod); 
	return prod;
}

LL findnum(LL x,LL ub,LL n);
//declaration
int main()
{
	LL t,up,deg,m,n,i,j,d,power[50];
	LL k;
	s(t);
	while(t--){
		s(up);s(d);s(m);s(n);
		LL ans = 0;
		create_powers(power,d,n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((power[i]+power[j]+power[k])%n == m)
					{
						ans=(ans + (((findnum(i,up,n)*findnum(j,up,n))%M)*findnum(k,up,n)%M)%M)%M;
					}
		printf("%lld\n",ans);
//		putchar('\n');
	}
	return 0;
}

LL findnum(LL x, LL ub,LL n)
{
	if(ub>x)  //say ub is 20 and x is 30, it will return negative value
		return (ub-x)/n + 1;//we want to return all values less than ub that give the same modd
	else
		return 0;
}
