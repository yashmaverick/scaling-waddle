#include<stdio.h>
unsigned int powerexp(unsigned int x)
{
	if(x==0)
		return 1;
	unsigned int y=powerexp(x/2);	
	if(x%2==0)
		return y*y;
	else 
		return 2*y*y;
}		
int main()
{
	unsigned int a,t,n,level,i;
	scanf("%u",&t);
	while(t--)
	{
		scanf("%u",&n);
		level=0;i=n;
		while((i|1)!=1)
		{
			i=i>>1;
			level++;
		}
		a=powerexp(level-1);//printf("n=%u level= %u , a=%u\n",n,level,a);
		if(n<(3*a))
			printf("%u\n",(2*level)-1);
		else
			printf("%u\n",2*level);
	}
	return 0;
}	
