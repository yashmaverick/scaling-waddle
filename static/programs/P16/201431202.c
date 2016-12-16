#include<stdio.h>
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int r=n,p=n;
		long long int count=0;
		while(r!=1)
		{
			r=r/2;
			count++;
		}
		while(1 && p>1)
		{
			if(p==2 || p==3)break;
			p=p/2;
		}
		if(p==2)printf("%lld\n",2*count-1);
		else printf("%lld\n",2*count);
	}
	return 0;
}
