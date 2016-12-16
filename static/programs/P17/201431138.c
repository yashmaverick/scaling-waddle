#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,pre[10000],in[10000],i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&in[j]);
	}
	scanf("%d",&t);
	while(t--)
	{
		int fi,li,a,b,strt,end,ans;
		scanf("%d %d",&fi,&li);
		for(i=0;i<n;i++)
		{
			if(in[i]==fi)
			{
				a=i;
			}
			if(in[i]==li)
			{
				b=i;
			}
		}
		if(a>b)
		{
			strt=b;
			end=a;
		}
		else
		{
			strt=a;
			end=b;
		}
		int flag=0;
		for(i=0;i<n;i++)
		{
			for(j=strt;j<=end;j++)
			{
				if(pre[i]==in[j])
				{
					ans=in[j];
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

