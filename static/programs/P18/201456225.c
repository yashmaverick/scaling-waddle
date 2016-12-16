#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int dfs1(int j,int  *vis,int **a)
{
	int q=0,i;
	for(i=1;i<=n;i++)
	{
		if(a[j][i]==1 && vis[i]!=1)
		{
			vis[i]=1;
			q+=dfs1(i,vis,a);
		}
	}
	return (q+1);
}
int dfs2(int j,int  *vis,int **a)
{
	int q=0,i;
	for(i=1;i<=n;i++)
	{
		if(a[i][j]==1 && vis[i]!=1)
		{
			vis[i]=1;
			q+=dfs2(i,vis,a);
		}
	}
	return (q+1);
}
int main()
{
	int t,j,s,q,m,i,w;
	int visited[1005];
	int **a;
	a=(int **)malloc(sizeof(int *)*1005);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			{
			a[i]=(int *)malloc(sizeof(int )*1005);
			}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&s);
				a[s][i]=1;
			}
		}
		int w=0;
		for(i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			visited[i]=1;
			w=dfs1(i,visited,a);
			if(w==n)
			break;
		}
	q=0;
	if(w==n)
	{
		memset(visited,0,sizeof(visited));
		visited[i]=1;
		q=dfs2(i,visited,a);
	}
	printf("%d\n",q);
}
	return 0;
}
