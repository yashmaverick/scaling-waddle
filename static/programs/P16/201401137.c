#include<stdio.h>

int main()
{
	long long int t,h;
	scanf("%lld",&t);
	for(h=0;h<t;h++)
	{
		long long int n,k,level=1;
		scanf("%lld",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		k=2;
		while(1)
		{
			if(k<=n && n<=(k*2)-1)
			{
				int q=(3*k)/2;
				if(n>=q)
				{
					printf("%lld\n",level*2);
				}
				else
				{
					printf("%lld\n",(level*2)-1);
				}
				break;
			}
			else
			{
				k=k*2;
				level++;
			}
		}
	}
	return 0;
}



