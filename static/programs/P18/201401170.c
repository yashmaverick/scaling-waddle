#include<stdio.h>
int count,a[1003][1003],visited[1003]={0},n,ans;
void rdfs(int v)
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[i][v]==1&& !visited[i])
		{
			count++;
			rdfs(i);
		}
	}
}
void dfs(int v)
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]==1&& !visited[i])
		{
			count++;
			dfs(i);
		}
	}
}
int main()
{
	int t,m,x,y,i,j;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				a[x][i]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			count=0;
			for(j=1;j<=n;j++)
			{
				visited[j]=0;
			}
			dfs(i);
			if(count==n-1)
			{
				ans++;
				break;
			}
		}
		count=0;
		for(j=1;j<=n;j++)
			visited[j]=0;
		rdfs(i);
		printf("%d\n",ans+count);
	}
	return 0;
}
