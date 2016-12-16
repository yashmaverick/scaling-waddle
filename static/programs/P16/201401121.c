#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==1)
		{
			printf("0\n");
			continue;

		}
		long long int i=1,m=0;
		while(i<=n)
	{
			i=i*2;
			m++;
		}
		i=i/2;
		m--;
	//	printf("%lld",i);
		if(n>(i+2*i-1)/2)
			printf("%lld\n",2*m);
		else
			printf("%lld\n",2*m-1);
	}
	return 0;
}



		
