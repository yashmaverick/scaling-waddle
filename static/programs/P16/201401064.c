#include<stdio.h>
int main()
{
	int n,test;
	scanf("%d",&test);
	while(test--)
	{
		int state=0,k,b=1,i;
		scanf("%d",&n);
		for(i=0;;i++)
		{
		/*	if(n==1)
			{
				state=1;
				printf("0\n");
			}*/
			b=b*2;
			if(b>n)
			{
				k=i;
				break;
			}
		}
		if(n>=((b+(b/2))/2))
		{
			printf("%d\n",2*k);
		}

		if(n<((b+(b/2))/2))
		{
			printf("%d\n",((2*k)-1));
		}
	}
	return 0;

}

