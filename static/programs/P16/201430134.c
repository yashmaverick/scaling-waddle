#include<stdio.h>
int main()
{
	int n;int num;int height,ans;
	scanf("%d",&n);
	while(n>0)
	{
		height=0;
		scanf("%d",&num);

		while(1)
		{
			if(num==1)
			{
				ans=0;
				break;
			}
			else if(num==2)
			{
				ans=(height+1)*2-(1);
				break;
			}
			else if(num==3)
			{
				ans=(height+1)*2;
				break;
			}
			num=num/2;
			height++;
		}
		printf("%d\n",ans);
		n--;
	}
	return 0;
}



