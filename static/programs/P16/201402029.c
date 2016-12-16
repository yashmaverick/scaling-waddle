#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,i,x,y,value,total;
	scanf("%lld",&x);
	while(x--)
	{
		scanf("%lld",&n);
		long long int c=0;
		y=n;
		if(y==0 || y==1)
		{
			printf("0\n");
			continue;
		}
		while(y!=1)
		{
			y=y/2;
			c=c+1;
		}
		long long int p,q;
		if(n>pow(2,c)+pow(2,c-1)-1)
		{
			value=2*(c);
			printf("%lld\n",value);
		}
		else
		{
			value=2*(c)-1;
			printf("%lld\n",value);
		}
	}
	return 0;
}
