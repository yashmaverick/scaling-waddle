#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int dfs(int j,int  *v,int a[][1005])
{
	int q=0,i;
	for(i=1;i<=n;i++)
	{
		if(a[j][i]==1 && v[i]!=1)
		{
			v[i]=1;
			q+=dfs(i,v,a);
		}
	}
	return (q+1);
}
int main()
{
	int t,j,s,q,m,i,w;
	int visit[1005];
	int adj[1005][1005];
	int adj2[1005][1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			{
			 memset(adj[i],0,sizeof(adj[i]));
			 memset(adj2[i],0,sizeof(adj2[i]));
			}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&s);
				adj[s][i]=1;
				adj2[i][s]=1;
			}
		}
		int w=0;
		for(i=1;i<=n;i++)
		{
			memset(visit,0,sizeof(visit));
			visit[i]=1;
			w=dfs(i,visit,adj);
			if(w==n)
			break;
		}
	q=0;
	if(w==n)
	{
		memset(visit,0,sizeof(visit));
		visit[i]=1;
		q=dfs(i,visit,adj2);
	}
	printf("%d\n",q);
}
	return 0;
}
