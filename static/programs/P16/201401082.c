#include<stdio.h>
int main()
{
	long long int t,n,count;
	scanf("%lld",&t);
	while(t--)
	{
		count=0;
		scanf("%lld",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
			
		}

		while(n!=2 && n!=3)
		{
			n=n/2;
			count++;
			//printf("%d\n",count);
		}
		count++;
		//printf("%d\n",count)
		if(n==2)
			n=2*count-1;
		else if(n==3)
			n=2*count;
		printf("%lld\n",n);
	}
	return 0;
}
