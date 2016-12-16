#include<stdio.h>
#include<stdlib.h>
int vertex;
int count = 0;
int max = 0;
int maxnode;
struct adjnode
{
	int value;
	struct adjnode *next;
};
struct adjlist
{
	struct adjnode *head;
};
struct Graph
{
	int v;
	struct adjlist *array;
};
struct Graph *creategraph(int v)
{
	int i;
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->array = (struct adjlist*)malloc((v+1) * sizeof(struct adjlist));
	for(i=0;i<=v;i++)
		graph->array[i].head = NULL;
	return graph;
}
struct adjnode* newnode(int v)
{
	struct adjnode *node;
	node = (struct adjnode*)malloc(sizeof(struct adjnode));
	node->next = NULL;
	node->value = v;
	return node;
}
void addedge(struct Graph *graph, int from, int to)
{
	struct adjnode *node;
	node = newnode(to);
	node->next = graph->array[from].head;
	graph->array[from].head = node;
	node = newnode(from);
	node->next = graph->array[to].head;
	graph->array[to].head = node;
}
void dfs(struct Graph *graph, int v, int visited[])
{
	int i;
	count++;
	if(count >= max)
	{
		max = count;
		maxnode = v;
	}
	visited[v] = 1;
	struct adjnode* pt;
	pt = graph->array[v].head;
//	printf("final count = %d, value = %d \n",count,v);
	//	printf("%d\n",v);
	while(pt)
	{
		if(visited[pt->value] == 0)
			dfs(graph,pt->value,visited);
		pt = pt->next;
		//		printf("count = %d\n",count);
	}
	count--;
}
void printgraph(struct Graph *graph)
{
	struct adjnode *pt;
	int i;
	for(i=0;i<(graph->v);i++)
	{
		pt = graph->array[i].head;
//		printf("%d",i);
		while(pt)
		{
//			printf(" --> %d",pt->value);
			pt = pt->next;
		}
//		printf("\n");
	}
}
int main()
{
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
	
		count=0;
		maxnode=0;
		int a,b;
		scanf("%d",&vertex);
		int visited[vertex+1];
		for(i=0;i<=vertex;i++)
			visited[i]=0;
//		for(i=0;i<=vertex;i++)
//			printf("%d ",visited[i]);
//		printf("\n");
		struct Graph *graph;
		graph = creategraph(vertex);
		for(i=0;i<vertex-1;i++)
		{
			scanf("%d %d",&a,&b);
			addedge(graph,a,b);
		}
		dfs(graph,a,visited);
		for(i=0;i<=vertex;i++)
			visited[i] = 0;
		count = 0;
		max = 0;
		dfs(graph,maxnode,visited);
		printf("%d\n",max);
		//	printf("-----------------\n");
//		printgraph(graph);
	//	free(graph);
	}
	return 0;
}
