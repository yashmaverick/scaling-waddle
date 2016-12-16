#include<stdio.h>
#include<stdlib.h>
int visited[1000000];
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
	struct list* out[1000000];
	struct list* in[1000000];
};
struct graph* cgraph(int v)
{
	struct graph* graph=malloc(sizeof(struct graph));
	graph->v=v;
	int i;
	for(i=1;i<=v;i++)
	{
		graph->in[i]=malloc(sizeof(struct list));
		graph->in[i]->head=NULL;
		graph->out[i]=malloc(sizeof(struct list));
		graph->out[i]->head=NULL;
	}
	return graph;
}
void addedge(struct graph* graph, int s, int d)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=graph->out[s]->head;
	graph->out[s]->head=newnode;
	struct node* newnodee=malloc(sizeof(struct node));
	newnodee->data=s;
	newnodee->next=graph->in[d]->head;
	graph->in[d]->head=newnodee;
}
void dfs(struct graph* graph, int s, int *count)
{
	visited[s]=1;
	(*count)++;
	struct node* current=graph->out[s]->head;
	while(current!=NULL)
	{
		if(!visited[current->data])
			dfs(graph,current->data,count);
		current=current->next;
	}
}
void reversedfs(struct graph* graph, int s)
{
	visited[s]=1;
	struct node* current=graph->in[s]->head;
	while(current!=NULL)
	{
		if(!visited[current->data])
			reversedfs(graph,current->data);
		current=current->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int d;
		int n;
		int p,q;
		scanf("%d",&n);
		int i,j,f=1;
		struct graph* graph=malloc(sizeof(struct graph));
		graph=cgraph(n);
		int count=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p);
			for(j=1;j<=p;j++)
			{
				scanf("%d",&d);
				addedge(graph,i,d);
			}
		}
		for(i=1;i<=n;i++)
		{
			f=1;
			for(j=1;j<=n;j++)
				visited[j]=0;
			reversedfs(graph,i);
			for(j=1;j<=n;j++)
			{
				if(visited[j]==0)
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				count++;
				break;
			}
		}
		int ans=0;
		for(j=1;j<=n;j++)
			visited[j]=0;
		if(count!=0)
			dfs(graph,i,&ans);
		printf("%d\n",ans);
	}
	return 0;
}
