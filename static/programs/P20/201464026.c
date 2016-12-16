#include <stdio.h>
#include <stdlib.h>
int maxdepth,maxnode;
typedef struct ll
{
	int node;
	struct ll *next;
}ll;
ll* insert(ll *g, int value)
{
	ll *h = (ll *)malloc(sizeof(ll));
	h->node = value;
	h->next = g;
	return h;
}
void dfs(ll **g, int start, int n, int *visited,int depth)
{
	if(depth>maxdepth)
	{
		maxdepth = depth;
		maxnode = start;
	}
	visited[start]=1;
	ll* i;
	for(i=g[start];i!=NULL;i=i->next)
	{
		if(visited[i->node])
			continue;
		else
			dfs(g,i->node,n,visited,depth+1);
	}
}
/*int dfscall(ll **g,int start,int n)
{
	int i,count=0;
	int *visited = (int *)malloc(sizeof(int)*(n+1));
	for(i=1;i<=n;i++)
		visited[i]=0;
	dfs(g,start,n,visited);
	for(i=1;i<=n;i++)
		if(visited[i])
			count++;
	free(visited);
	return count;
}*/
void printgraph(ll **g,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        ll* temphead;
        temphead = g[i];;
        while(temphead!=NULL)
        {
            printf("Node: %d ,Link: %d\n",temphead->node,i);
            temphead = temphead->next;
        }
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,*visited;
		maxdepth=0;
		maxnode=1;
		ll **g;
		scanf("%d",&n);
		g = (ll **)malloc(sizeof(ll *)*(n+1));
		visited = (int *)malloc(sizeof(int)*(n+1));
		for(i=1;i<=n;i++)
		{
			g[i] = NULL;
			visited[i]=0;
		}
		for(i=1;i<n;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			g[u] = insert(g[u],v);
			g[v] = insert(g[v],u);
		}
		dfs(g,1,n,visited,0);
		for(i=1;i<=n;i++)
			visited[i]=0;
		dfs(g,maxnode,n,visited,0);
		printf("%d\n",maxdepth+1);
		free(g);
		free(visited);
	}
	return 0;
}