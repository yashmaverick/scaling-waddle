#include<stdio.h>
#include<math.h>
int main()
{
	long long int k,l,i,c,x,y;
	scanf("%lld",&k);
	i=2;
	c=0;
	while(k--)
	{
		scanf("%lld",&l);
		i=l;
		c=0;
		while(l>=2)
		{
			l=l/2;
			c++;
		}
		y=pow(2,c);
	//	printf("*%lld*\n",y);
	//	printf("**%lld\n",c);
		if((i-y)>=(y/2))
		{
			printf("%lld\n",(2*(c)));
		}
		else
		{
			printf("%lld\n",((2*(c))-1));
		}
	}
	return 0;
}
