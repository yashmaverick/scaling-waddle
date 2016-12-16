#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef struct node
{
	int src , dest;
	struct node* next;
}node;

typedef struct graph
{
	int v;
	node** l;
}graph;

node* newnode(int u , int v)
{
	node* c = (node*) malloc(sizeof(node));
	c -> src = u;
	c -> dest = v;
	return c;
}

int vis[100011] , vert[100011] , start;

void top(graph* g , int n)
{
	if(vis[n]) return;
	vis[n] = 1;
	node* c = g -> l[n];
	while(c)
	{
		int v = c -> dest;
		if(!vis[v])
			top(g,v);
		c = c -> next;
	}
	vert[start++] = n;
	return;
}

int main()
{
	int n,m,i; node* c;
	scanf("%d%d",&n,&m);
	graph* g = (graph*) malloc(sizeof(graph));
	g -> l = (node**) malloc(n * sizeof(node*));
	for(i = 0 ; i < n ; i++) g -> l[i] = NULL;
	while(m--)
	{
		int u , v;
		scanf("%d%d",&u,&v);
		u--; v--;
		c = newnode(u,v);
		c -> next = g -> l[u];
		g -> l[u] = c;
	}
	start = 0;
	for(i = n-1 ; i >=0 ; i--)
		if(!vis[i])
			top(g,i);
	for(i = start - 1; i >= 1 ; i--)
		printf("%d ", vert[i] + 1);
	printf("%d\n", vert[0] + 1);
	free(g);
	return 0;
}
