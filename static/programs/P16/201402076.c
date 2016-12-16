#include<stdio.h>
int ans;
void solve()
{
	long long int q;
	scanf("%lld",&q);
	if(q==1)
		ans=0;
	else if(q==2)
		ans=1;
	else if(q==3)
		ans=2;
	else
	{
		int b=q;
		int c=0;
		while(b>0)
		{
			c++;
			b/=2;
		}
		int d=c-3;
		c--;
		long long int e=5;
		while(d--)
		{
			e=e*2;
			e++;
		}
		if(q<=e)
			ans=(2*c)-1;
		else
			ans=2*c;
	}
}
void output()
{
	printf("%d\n",ans);
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		solve();
		output();
	}
	return 0;
}
	
