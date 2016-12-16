#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int dest,src;
	struct node* next;
}node;

typedef struct graph
{
	int v;
	node** l;
	node** r;
}graph;

node* newnode(int u ,int v)
{
	node* c = (node*) malloc(sizeof(node));
	c -> dest = v;
	c -> src = u;
	return c;
}

int vis[10011] , ans = 0;

void dfsr(graph* g , int n)
{
	if(vis[n]) return;
	ans++;
	vis[n] = 1;
	node* c = g -> l[n];
	while(c)
	{
		if(!vis[c -> dest])
			dfsr(g , c -> dest);
		c = c -> next;
	}
	return;
}

void dfs(graph* g , int n)
{
	if(vis[n]) return;
	vis[n] = 1;
	node* c = g -> r[n];
	while(c)
	{
		if(!vis[c -> dest])
			dfs(g , c -> dest);
		c = c -> next;
	}
	return;
}

int main()
{
	int i,m,n,t;
	scanf("%d",&t);
	while(t--)
	{
		graph* g = (graph*) malloc(sizeof(graph));
		scanf("%d",&n); node* c;
		g -> v = n;
		g -> l = (node**) malloc(n * sizeof(node*));
		g -> r = (node**) malloc(n * sizeof(node*));
		for(i =0 ; i  < n ; i++)
			g -> r[i] = g -> l[i] = NULL;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				int v;
				scanf("%d",&v); v--;
				c = newnode(i,v);
				c -> next = g -> l[i];
				g -> l[i] = c;
				c = newnode(v,i);
				c -> next = g -> r[v];
				g -> r[v] = c;
			}
		}
		for(i = 0 ; i < n ;i++) 
		{
			dfs(g,i);
			int j; for(j = 0 ; j < n && vis[j] ; j++);
			memset(vis,0,4*n);
			if(j == n)
			{
				dfsr(g,i);
				break;
			}
		}
		printf("%d\n",ans);
		memset(vis,0,4*n);
		ans = 0;
		free(g);
	}
	return 0;
}
