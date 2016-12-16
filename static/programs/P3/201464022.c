#include<stdio.h>
int main()
{
	int t,i,n,max,min,ans,a;
	scanf("%d",&t);
	while(t--)
	{
		min=0;
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(i==0)
				min=a;
			if(a<min)
				min=a;
			if((a-min)>ans)
				ans=a-min;
		}
		printf("%d\n",ans);
	}
	return 0;
}

