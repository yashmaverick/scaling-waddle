#include<stdio.h>
int main()
{
	long long int t,i=0,j,k,l;
	long long int x,m;
	scanf("%lld",&t);
	while(i<t)
	{
		scanf("%lld",&x);
		if(x!=1)
		{
			m=x;
			j=0;
			while(m!=0)
			{
				j=j+1;
				m=m/2;
			}
			k=1;
			m=x;
			l=j;
			while(m>3)
			{
				m=m/2;	
			}
			if(m==2)
				printf("%lld\n",(2*l-3));
			else
				printf("%lld\n",(2*l-2));
		}
		else
			printf("0\n");
		i++;
	}
	return 0;
}
