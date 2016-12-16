#include<stdio.h>
#include<math.h>
int main()
{
	int i,t;
	long long int num,l,log=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		log=0;
		scanf("%lld",&num);
		l=num;
		while(l>1)
		{
			log++;
			l=l/2;
		}
		if(num==1)
		{
			printf("0\n");
		}
		else if(num<(3*pow(2,log-1)))
		{
			printf("%lld\n",(2*log)-1);
		}
		else
		{
			printf("%lld\n",(2*log));
		}
	}
	return 0;
}
