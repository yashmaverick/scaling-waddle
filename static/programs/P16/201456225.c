#include<stdio.h>
#include<math.h>
int main()
{	long long int a,x,b,c,z,e,testcases;
    	scanf("%lld",&testcases);
	int i;
	for(i=0;i<testcases;i++)
	{	
	    	scanf("%lld",&a);
		x=log2(a);
		b=pow(2,x);
		c=pow(2,x-1);
		z=2*x;
		e=1;
		if(a>(b+c-e))
			printf("%lld\n",z);
		else
			printf("%lld\n",z-1);
	}
	return 0;
}

