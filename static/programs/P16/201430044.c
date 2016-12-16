#include<stdio.h>
int flag=0;
int m(int n)
{
	if(n==2)
	{
		flag=0;
		return 1;
	}
	if(n==3)
	{flag=1;
		return 1;}
	else
		return (1+m(n/2));
}
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		int d=m(n);
		if(flag==1)
			printf("%d\n",(2*d));
		else
			printf("%d\n",(2*d)-1);
	}
	return 0;
}
