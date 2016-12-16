#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,count=0,ans;
		scanf("%lld",&n);
		long long int m;
		m=n;
		while(m!=0)
		{
			m=m/2;
			count++;
		}
		count=count-1;
		long long int x;
		x=pow(2,count-1);
		if(n-(x*2)+1 > x)
			ans=(2*count);
		else
			ans=(2*count)-1;
		printf("%lld\n",ans);
	}
	return 0;
}
