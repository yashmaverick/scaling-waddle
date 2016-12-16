#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int src,dest;
	struct node* next;
}node;

typedef struct graph
{
	int v;
	node* l[1000011];
}graph;

node* newnode(int u , int v)
{
	node* c = (node*) malloc(sizeof(node));
	c -> src = u;
	c -> dest = v;
	return c;
}

int vis[1000011],maxpath = -1,maxdist_node = -1;

void dfs(graph* g , int n , int path)
{
	if(!vis[n])
	{
		path++;
//		printf("%d %d\n",n+1,path);
		vis[n] = 1;
		node* c = g -> l[n];
		while(c)
		{
			if(!vis[c -> dest])
				dfs(g , c -> dest , path);
			c = c -> next;
		}
		if(maxpath < path)
		{
			maxpath = path;
			maxdist_node = n;
		}
	}
	return;
}

int main()
{
	int i,e,n,t,path;
	scanf("%d",&t);
	while(t--)
	{
		maxpath = maxdist_node = -1;
		path = 0;
		scanf("%d",&n);
		node* c;
		graph* g = (graph*) malloc(sizeof(graph));
		g -> v = n;
		for(i = 0 ; i < n ; i++)
			g -> l[i] = NULL;
		e = n-1;
		while(e-- > 0)
		{
			int u , v;
			scanf("%d%d", &u, &v); u--; v--;
			c = newnode(u,v);
			c -> next = g -> l[u];
			g -> l[u] = c;
			c = newnode(v,u);
			c -> next = g -> l[v];
			g -> l[v] = c;
		}
		dfs(g,0,path);
		maxpath = -1; path = 0;
		memset(vis,0,4*n);
		dfs(g,maxdist_node,path);
		printf("%d\n",maxpath);
		memset(vis,0,4*n);
		maxpath = maxdist_node =  -1;
		free(g);
	}
	return 0;
}
