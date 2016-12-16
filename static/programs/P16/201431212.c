#include<stdio.h>
int power(int base,int exp)
{
	if(exp==0)
		return 1;
	else if(exp%2==0)
	{
		int p=power(base,exp/2);
		return (p*p);
	}
	else
		return base*power(base,exp-1);
}
int main()
{
	int t,m,j,n;
	long long int x;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		scanf("%lld",&x);
		n=0;
		while(1)
		{
			if(x>=power(2,n) && x<=power(2,n+1)-1)
			{
				j=n;
				break;
			}
			else
				n++;
		}
		if(x<(power(2,n)+(power(2,n)/2)))
			printf("%d\n",(2*n)-1);
		else
			printf("%d\n",2*n);
	}
	return 0;
}
