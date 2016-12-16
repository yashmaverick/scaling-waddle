#include<stdio.h>
long long int powr(long long int p)
{
	if(p==0)
		return 1;
	return 2*powr(p-1);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int n,ans,h;
		scanf("%lld",&n);
		ans=n;
		h=0;
		while(ans>powr(h))
		{
			ans = ans - powr(h);
			h++;
		}
		if(ans<=powr(h)/2)
			printf("%lld\n",h*2-1);
		else
			printf("%lld\n",2*h);
	}
	return 0;
}
