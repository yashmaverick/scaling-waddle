#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m=0;
		scanf("%d",&n);
		if(n==1)
			printf("0");
		else
		{
			
			while(n!=2&&n!=3)
			{
				n=n/2;
				m++;
			}
			m++;
			if(n==2)
				printf("%d",2*m-1);
			else if(n==3)
				printf("%d",2*m);
		}
		printf("\n");
	}
	return 0;
}
