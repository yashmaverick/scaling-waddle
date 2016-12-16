#include<stdio.h>
typedef long long int LL;
LL MAX(LL a,LL b)
{
	return a>b?a:b;
}
int main()
{
	LL i,n,x,y,max,temp,min,t;
	scanf("%lld",&t);
	while(t--)
	{
	scanf("%lld%lld%lld",&n,&x,&y);
	max = MAX(0,y-x);
	min = y>x?x:y;
	for(i=0;i<n-2;i++)
	{
		scanf("%lld",&temp);
		max = MAX(max,temp-min);
		min = min>temp?temp:min;
	}
	printf("%lld\n",max);
	}
	return 0;
}

