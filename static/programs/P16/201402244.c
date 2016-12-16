#include<stdio.h>
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--)
	{
	long long int n,j=1,i;
	scanf("%lld",&n);
	for(i=1;i<=30;i++)
	{
		j=j*2;
		if(n<j)
		break;
	}
	if(n<=((j+(j/2))/2)-1)
	{
	printf("%lld\n",2*(i-1)-1);
	}
	else
	{
	printf("%lld\n",(2*(i-1)));
	}
	}
return 0;
}
