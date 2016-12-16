#include<stdio.h>
int in[100000],pre[100000],dex[100000],root=0;
void function(int x,int y)
{
	if((dex[pre[root]]>dex[x] && dex[pre[root]]<dex[y]) || (dex[pre[root]]<dex[x] && dex[pre[root]]>dex[y]))
	{
		printf("%d\n",pre[root]);
		return ;
	}
	else if(dex[pre[root]]==dex[x])
	{
		printf("%d\n",pre[root]);
		return ;
	}
	else if(dex[pre[root]]==dex[y])
	{
		printf("%d\n",pre[root]);
		return ;
	}
	else
	{
		root++;
		function(x,y);
	}
}




int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		dex[in[i]]=i;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		root=0;
		scanf("%d%d",&x,&y);
		function(x,y);
	}
}

