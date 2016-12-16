#include<stdio.h>
int main()
{
	int t,k,l,d;
	long long int n;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			printf("%d\n",0);
			continue;
		}
		if(n==2)
		{
			printf("%d\n",1);
			continue;
		}
		if(n==3)
		{
			printf("%d\n",2);
			continue;
		}
		l=0;
		while(n>=4)
		{
			l++;
			n=n/2;
		}
		d=l+1;
		if(n==2)
		{
			printf("%d\n",(2*d-1));
		}
		if(n==3)
		{
			printf("%d\n",2*d);
		}
		

	}
	return 0;
}
