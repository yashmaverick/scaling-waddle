#include<stdio.h>
int main()
{
	int node,test,j,w,h,g,temp,l,p;
	scanf("%d",&node);
	int pre[node];
	int in[node];
	int i;
	for(i=0;i<node;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<node;i++)
	{
		scanf("%d",&in[i]);
	}
	scanf("%d",&test);
	for(p=0;p<test;p++)
	{
		scanf("%d %d",&j,&w);
int flag=0;
		for(i=0;i<node;i++)
		{
			if(in[i]==j)
			{
				h=i;
			}
			if(in[i]==w)
			{
				g=i;
			}
		}
//printf("%d %d",h,g);
		if(h>g)
		{
			temp=h;
			h=g;
			g=temp;
		}
		for(i=0;i<node;i++)
		{
			for(l=h;l<=g;l++)
			{
				if(in[l]==pre[i])
				{
					printf("%d\n",pre[i]);
	                                flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
	}
return 0;
}
