#include<stdio.h>
#include<math.h>


	
int main()

{
	int test,n,ans,i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		if(n==0 || n==1)
			printf("0\n");
		else
		{
			for(i=1;i<n;i++)
			{
				int power=pow(2,i+1);
				if(n==(power)-1)//power
				{
					ans=2*i;
					break;
				}
				else if(n>(power/2-1)+power/4 && n<=power-1)//power/2 power/4 power
				{
					ans=(2*i);
					break;
				}
				else if(n>(power/2-1) && n<=(power/2-1)+power/4)//power/2 power/2 power/4
				{
					ans=(2*i)-1;
					break;
				}
			}
		printf("%d\n",ans);
		}
	}
	return 0;
}

