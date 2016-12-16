#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,i=0,j;
		scanf("%lld",&n);
		long long int m=n;
		while(m!=1)
		{
			m=m/2;
			i++;
		}
		j= pow(2,i-1)+ pow(2,i) -1;
		if(n<=j)
			printf("%lld\n",(2*i)-1);
		else
			printf("%lld\n",2*i);
	}
	return 0;
}
