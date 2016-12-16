#include<stdio.h>
#include<stdlib.h>
int visited[1000000];
int max=0;
int vertex;
int min(int a,int b)
{
	return (a>b)?b:a;
}
struct node
{
	int data;
	struct node* next;
};
struct list
{
	struct node* head;
};
struct graph
{
	int v;
	struct list* array[1000000];
};
struct graph* cgraph(int v)
{
	struct graph* graph=malloc(sizeof(struct graph));
	graph->v=v;
	int i;
	for(i=1;i<=v;i++)
	{
		graph->array[i]=malloc(sizeof(struct list));
		graph->array[i]->head=NULL;
	}
	return graph;
}
void addedge(struct graph* graph,int s,int d)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=graph->array[s]->head;
	graph->array[s]->head=newnode;
	struct node* newnodee=malloc(sizeof(struct node));
	newnodee->data=s;
	newnodee->next=graph->array[d]->head;
	graph->array[d]->head=newnodee;
}
void dfs(struct graph* graph,int s,int v)
{
	visited[s]=v;
	if(v>max)
	{
		vertex=s;
		max=v;
	}
	struct node* current=graph->array[s]->head;
	while(current!=NULL)
	{
		if(!visited[current->data])
			dfs(graph,current->data,v+1);
		current=current->next;
	}
}
int main()
{
	int t1;
	scanf("%d",&t1);
	while(t1--)
	{
		int n;
		scanf("%d",&n);
		int i;
		int p,q;
		struct graph* graph=malloc(sizeof(struct graph));
		graph=cgraph(n);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&p,&q);
			addedge(graph,p,q);
		}
		for(i=0;i<=n;i++)
			visited[i]=0;
		max=0;
		dfs(graph,1,0);
		for(i=0;i<=n;i++)
			visited[i]=0;
		max=0;
		dfs(graph,vertex,0);
		printf("%d\n",max+1);
	}
	return 0;
}
