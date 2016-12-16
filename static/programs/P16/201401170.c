#include<stdio.h>
int main()
{
	int t,x,y,ans,i;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
			printf("0\n");
		else
		{
			x=1;
			i=0;
			while(x<=n)
			{
				i++;
				x=1<<i;
			}
			y=x/2-1;
			ans=2*(i-1);
			if(n>((x+y)/2))
				printf("%d\n",ans);
			else
				printf("%d\n",ans-1);
		}
	}
	return 0;
}
