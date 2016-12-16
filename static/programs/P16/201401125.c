#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int t,n,temp,r;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		if(n==2)
			{
				printf("1\n");
				//break;
			}
		else if(n==3)
			{
				printf("2\n");
				//break;
			}
		else if(n==1)
			{
				printf("0\n");
				//break;
			}
		else
		{
			temp= log2(n);
			r= n-pow(2,temp);
			if(r<=(pow(2,temp-1)-1))
				{
					temp= (2*temp)-1;
					printf("%d\n",temp);
				}
			else
				{
					temp= (2*temp);
					printf("%d\n",temp);
				}
		}
	}
		return 0;
}