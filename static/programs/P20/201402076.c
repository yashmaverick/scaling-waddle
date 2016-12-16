#include<stdio.h>
#include<stdlib.h>
int* graph[1000005];
int arr[1000005],arr2[1000005],dist[1000005],n,vis[1000005];
int x[1000005],y[1000005];
void dfs(int u)
{
	vis[u]=1;
	int i;
	for(i=0;i<arr[u];i++)
	{
		int v=graph[u][i];
		if(vis[v]==0)
		{
			dist[v]=dist[u]+1;
			dfs(v);
		}
			
	}
}
void input()
{
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			arr[i]=0;
			arr2[i]=0;
			vis[i]=0;
		}

}
void precompute()
{
		int i;
		for(i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			u--;
			v--;
			x[i]=u;y[i]=v;
			arr[u]++;
			arr[v]++;
		}

}
void compute()
{
		int i;
		for(i=0;i<n-1;i++)
		{
			graph[x[i]][arr2[x[i]]]=y[i];
			graph[y[i]][arr2[y[i]]]=x[i];
			arr2[x[i]]++;
			arr2[y[i]]++;
		}

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		precompute();
		int i;

		for(i=0;i<n;i++)
			graph[i]=(int*)malloc(sizeof(int)*arr[i]);
		compute();
		dist[0]=0;
		dfs(0);	
		int max=dist[0],vmax=0;
		vis[0]=0;
		for(i=1;i<n;i++)
		{
			vis[i]=0;
			if(max<dist[i])
			{
				max=dist[i];
				vmax=i;
			}
		}
		dist[vmax]=0;
		dfs(vmax);
		max=dist[0];vmax=0;
		for(i=1;i<n;i++)
		{
			if(max<dist[i])
			{
				max=dist[i];
				vmax=i;
			}
		}
		max++;
		printf("%d\n",max);
	}
	return 0;
}
