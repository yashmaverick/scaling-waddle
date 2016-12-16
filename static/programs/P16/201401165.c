#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int count,r,n,dia;
		scanf("%d",&n);
                if(n==1)
		{
			r=0;
		}
		if(n==2)
		{
			r=1;
		}
		if(n==3)
		{
			r=0;
		}
		count=0;
		while(n>1)
		{
			n=n/2;
			count++;
			if(n==2)
			{
				r=1;
			}
			if(n==3)
			{
				r=0;
			}
		}
		dia=(2*count)-r;
		printf("%d\n",dia);
		test--;	
	}

	return 0;
}
