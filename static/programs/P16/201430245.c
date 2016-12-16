#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b,count=0,ans,i,j;
		scanf("%d",&n);
		a=n;
		if(n==1)
		{
			printf("0\n");
		}
		else if(n==2)
		{
			printf("1\n");
		}
		else if(n>=3)
		{
			while(a/2!=1)
			{
				a=a/2;
				count++;
			}
			if(a==2)
			{
				printf("%d\n",2*count+1);
			}
			else if(a==3)
			{
				printf("%d\n",2*count+2);
			}
		}
	}
return 0;
}
