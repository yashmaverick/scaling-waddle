#include<stdio.h>
#include<stdlib.h>
long long int count=0;
long long int count1 = 0;
long long int func(long long int n)
{
	int m=n;
	count=0;
	while(1)
	{
		m = m/2;
		count++;
	//	printf("%d\n",m);
		if(m<2)
			break;
	}
	return count;
}
int main()
{
	long long int t,n,m,dia,c1;
	scanf("%lld",&t);
	while(t--)
	{
		count1 =0;
		c1 = 0;
		scanf("%lld",&n);
		if(n == 1 || n == 0)
			printf("0\n");
		else if(n == 2)
			printf("1\n");
		else
		{
			m=n;
			c1=func(m);
			count1=func(2*m/3);
			dia = c1 + count1;
			printf("%lld\n",dia);
		}
	}
	return 0;
}




