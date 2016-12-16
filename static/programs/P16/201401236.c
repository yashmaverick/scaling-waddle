#include<stdio.h>
#include<math.h>
int main()
{
	long long int test,dpt,f,n;

	scanf("%lld",&test);
	while(test--)
	{

		
		scanf("%lld",&n);
	if(n==1)
		printf("0\n");
	else
	{		
	dpt=log2(n);
	if(n>=pow(2,dpt)&&n<(pow(2,dpt)+pow(2,dpt)/2))
		printf("%lld\n",2*dpt-1);
	else
		printf("%lld\n",2*dpt);

	}
	}	
return 0;
}
