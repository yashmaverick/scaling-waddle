#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int dfs(int j,int  *v,int **a)
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
	int **adj,**adj2;
	adj=malloc(sizeof(int*)*1005);
	adj2=malloc(sizeof(int*)*1005);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			{
				adj[i]=malloc(sizeof(int)*1005);
				adj2[i]=malloc(sizeof(int)*1005);
				for(j=0;j<=n;j++)
				{
						adj[i][j]=0;
						adj2[i][j]=0;
				}
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
				for(j=0;j<=n;j++)
				{
						visit[j]=0;
				}
			visit[i]=1;
			w=dfs(i,visit,adj);
			if(w==n)
			break;
		}
	q=0;
	if(w==n)
	{
			for(j=0;j<=n;j++)
				{
						visit[j]=0;
				}
		visit[i]=1;
		q=dfs(i,visit,adj2);
	}
	printf("%d\n",q);
}
	return 0;
}
