#include<stdio.h>
int main()
{
	int n,i,j,pre[1000001],in[1000001],t,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);

	scanf("%d",&t);

	int xi,yi,ans,temp;

	while(t>0)
	{
		xi=yi=ans=-1;
		scanf("%d%d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(in[i]==x)
				xi=i;
			if(in[i]==y)
				yi=i;
			if(yi>=0 && xi>=0)
				break;
		}
		if(xi>yi)
		{
			temp=xi;
			xi=yi;
			yi=temp;
		}
		for(i=0;i<n;i++)
		{
			for(j=xi;j<=yi;j++)
			{
				if(in[j]==pre[i])
				{
					ans=pre[i];
					break;
				}
			}
			if(ans!=-1)
				break;
		}
		printf("%d\n",ans);
		t--;
	}
	return 0;
}
