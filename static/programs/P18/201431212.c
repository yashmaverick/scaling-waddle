#include<stdio.h>
int a[1003][1003],b[1003];
int count=0,flag=0,depth=0;
void dfs(int n1,int v)
{
	int i,u;
	if(b[n1]==1)
		return ;
	if(b[n1]==0)
	{
		b[n1]=1;
		for(u=1;u<=v;u++)
		{
			if(a[n1][u]==1 && b[u]!=1)
			{
				depth++;
				dfs(u,v);
			}
		}
	}
}
void dfs1(int n1,int v)
{
	int j;
	if(b[n1]==1)
		return ;
	if(b[n1]==0)
	{
		b[n1]=1;
		for(j=1;j<=v;j++)
		{
			if(a[j][n1]==1 && b[j]!=1)
			{
				count++;
				dfs1(j,v);
			}
		}
	}
}
int main()
{
	int t,m,i,j,v,n1,n2,e;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		count=0,depth=0;
		for(i=0;i<1003;i++)
		{
			for(j=0;j<1003;j++)
				a[i][j]=0;
			b[i]=0;
		}
		scanf("%d",&v);
		for(n1=1;n1<=v;n1++)
		{
			scanf("%d",&e);
			for(i=1;i<=e;i++)
			{
				scanf("%d",&n2);
				a[n2][n1]=1;
			}
		}
		for(n1=1;n1<=v;n1++)
		{
			for(i=0;i<1003;i++)
				b[i]=0;
			depth=0;
			dfs(n1,v);
			if(depth==v-1)
			{
				count++;
				break;
			}
		}
		for(i=0;i<1003;i++)
			b[i]=0;
		dfs1(n1,v);
		printf("%d\n",count);
	}
	return 0;
}
