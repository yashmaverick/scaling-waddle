#include<stdio.h>
#include<math.h>

int main()
{
	long long int t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n == 1)
		{
			printf("0\n");
		}
		else
		{
			double d1,x;
			long long int d2,l;
			l=n+1;
			x=log(2);
			d1=log(l);
			d1=d1/x;
			d2=d1;
			if(d1 > d2)
			{
				l=pow(2,d2-1);
				if(n > (3*l)-1)
				{
					printf("%lld\n",2*(d2));
				}
				else
				{
					printf("%lld\n",2*(d2)-1);
				}

			}
			else		
			{
				l=pow(2,d2-2);
				if(n > (3*l)-1)
				{
					printf("%lld\n",2*(d2-1));
				}
				else
				{
					printf("%lld\n",2*(d2-1)-1);
				}
			}
		}
	}
	return 0;
}



