#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000


typedef struct linked_list
{
	int v;
	struct linked_list * next;
}node;

node *adj[MAX];
int vis[MAX], max_depth, max_depth_node;

insert(int n, node **t)
{
	if( (*t) == NULL )
	{
		(*t) = (node*) malloc(sizeof(node));
		(*t)->v = n;
		(*t)->next = NULL;

		return ;
	}

	insert( n, &((*t)->next) );
	return ;
}

void dfs(int src, int depth)
{
	if(depth > max_depth)
	{
		max_depth = depth;
		max_depth_node = src;
	}

	vis[src] = 1;	 
	node *a = adj[src];

	while( a!= NULL )
	{	
		if( !vis[a->v] ) //Not visited a->v
		{
//			printf("%d calling %d\n", src, a->v);
			dfs(a->v,depth+1);
		}

		a = a->next ;	
	}

	return ; 
}

int main()
{
	int T, i, n, u, v;
	scanf("%d",&T);

	while(T--)
	{
				
		
		memset(adj, 0, sizeof(adj));

		scanf("%d",&n);

		for(i=0; i<n-1; i++)
		{
			scanf("%d%d",&u,&v);
			insert(u, &adj[v]);
			insert(v, &adj[u]);
		}
		
		memset(vis,0,sizeof(vis));
		max_depth = 0, max_depth_node = u;
		dfs(u,0);
//		printf("%d@%d\n",max_depth_node,max_depth);
		
		
		memset(vis,0,sizeof(vis));
		max_depth = 0;
		dfs(max_depth_node,0);
		printf("%d\n", max_depth+1);
	}
	
	return 0;
}
