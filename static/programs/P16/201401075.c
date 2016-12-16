#include<stdio.h>
int main()
{
	int t;
	int q,ans,state;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&q);
		ans=0;
		while(q!=1)
		{
			if(q==2)
				state=2;
			else
				state=3;
			q=q/2;
			ans++;
		}
		if(state==2)
			ans=ans*2-1;
		else
			ans=ans*2;
		printf("%d\n",ans);
	}
	return 0;
}

