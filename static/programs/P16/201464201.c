#include<stdio.h>
#include<math.h>
int main()
{
	long long int i,j,a[1000005],test,t,count,n,rem,m;
	scanf("%lld", &test);
	for(t=0;t<test;t++)
	{
		rem=0;
		count=0;
		scanf("%lld", &n);
		if(n==0)
		{
			printf("0\n");
			break;
		}
		m=n;
		while(n!=0)
		{
			rem=rem+n%2;
			n=n/2;
			count++;
		}
	//	printf("%lld\n", count);
		n=m-(pow(2,count-1)-1);
	//	printf("n=%lld\n", n);
		if(n>(pow(2,count-2)))
		{
			printf("%lld\n", (count-1)*2);
		}
		else
		{
			printf("%lld\n", (count-1)*2-1);
		}
	}
	return 0;
}
