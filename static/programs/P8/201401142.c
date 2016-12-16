#include<stdio.h>
#define MOD 1000000007
typedef long long int LL;
LL expo(LL number,LL power);
void fillvalues();
LL t,d,N,m,upperlimit,power[40],values[40],result;
int main()
{
	int i,j,k;
	scanf("%lld",&t);
	while(t--)
	{
		result = 0;
		scanf("%lld%lld%lld%lld",&upperlimit,&d,&m,&N);
		m = m%N;
		if(d==0)
			power[0] = 1;
		else
			power[0] = 0;
		power[1] = 1;
		for(i=2;i<N;i++)
			power[i] = expo(i,d);
		fillvalues();
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				for(k=0;k<N;k++)
					if((power[i]+power[j]+power[k])%N == m)
						result =(((values[i]*values[j])%MOD*values[k])+result)%MOD;
		printf("%lld\n",result);
	}
	return 0;
}
LL expo(LL number,LL power)
{
	if(power)
	{
		if(power&01)
			return (number*expo((number*number)%N,power/2))%N;
		else
			return (expo((number*number)%N,power/2))%N;
	}
	else
		return 1;
}
void fillvalues()
{
	LL i;
	if (upperlimit<N)
	{	
		for(i=0;i<=upperlimit;i++)
			values[i] = 1;
	}
	else 
	{
		for(i=0;i<N;i++)
			values[i] = ((upperlimit - i)/N) + 1;
	}
	return ;
}
