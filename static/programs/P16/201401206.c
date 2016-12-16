#include<stdio.h>

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int count=0;
		float rem,x;
		x=n;
		if(x==1)
			printf("0\n");
		else
		{
			while(x>=2)
			{
				x=x/2;
				count++;
			}
			rem=x-1;
			//	printf("**%f %d**\n",rem,count);
			if(rem>=0.5)
				printf("%d\n",2*count);
			else
				printf("%d\n",(2*count)-1);
		}
	}
	return 0;
}
