#include <stdio.h>

long long a,b,c,d;
#define MOD 1000000007
void fib(long long n,long long ans[])
{
	if(n==0)
	{
		ans[0] = 0;
		ans[1] = 1;
		return;
	}
	fib((n/2),ans);
	a = ans[0];
	b = ans[1];
	c = 2*b - a;
	if(c < 0)
		c += MOD;
	c = (a * c) % MOD;
	d = (a*a + b*b) % MOD;
	if(n%2 == 0)
	{
		ans[0] = c;
		ans[1] = d;
	}
	else
	{
		ans[0] = d;
		ans[1] = c+d;
	}
}

int main()
{long long int n,q,z;
	scanf("%lld%lld",&n,&q);
	long long sum=0;
	long long int arr[n];
	long long int ans[2]={0};
	for(z=0;z<n;z++)
	{
		scanf("%lld",&arr[z]);
		ans[0]=0;ans[1]=0;
		fib((arr[z]+1),ans);
		sum=sum+ans[0];}


	for(z=0;z<q;z++)
	{long long int x,y;
		scanf("%lld%lld",&x,&y);
		
		ans[0]=0;ans[1]=0;
		fib((arr[x-1]+1),ans);
		sum-=ans[0];
		arr[x-1]+=y;
		
		ans[0]=0;ans[1]=0;
		fib((arr[x-1]+1),ans);
		sum=sum+ans[0];
		
		printf("%lld\n",sum%MOD);}

	return 0;
}
