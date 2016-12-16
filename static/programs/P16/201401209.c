#include<stdio.h>
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		long long int n,i;
		scanf("%lld",&n);
		long long int raj=n;
		long long int height=0;
		while(raj!=0)
		{
			raj=raj>>1;
			height++;
		}
		long long int x=1;
		for(i=1;i<=height-1;i++) x=x<<1;
//		printf("%lld %lld\n",height,x);
//		printf("%lld %lld\n",n,(x+(x/2)-1));
		if(n>(x+(x/2)-1)) printf("%lld\n",2*(height-1));
		else printf("%lld\n",2*(height-1)-1);
	}
	return 0;
}
