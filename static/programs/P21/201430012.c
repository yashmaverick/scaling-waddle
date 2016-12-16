#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000005
struct adj_node
{
	long long index;
	long long cost;
	struct adj_node *next;
};

struct heap_node
{
	long long index;
	long long cost;
};

long long dist[MAX],heap_pos[MAX];
struct adj_node *adj_list[MAX];
struct heap_node min_heap[MAX];
long long heapsize,heaplength;

void heap_decrease_cost(long long ,long long);
void init_adj_list(long long);
void add_edge(long long,long long,long long);
void build_min_heap(void);
void dijkstra(long long,long long);
void min_heapify(long long);
struct heap_node heap_extract_min(void);
void clear_adj_list(long long);

int main()
{
	long long i,n,m,u,v;
	long long w;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		u--;v--;
		add_edge(u,v,w);
	//	add_edge(v,u,w);	
	}
	scanf("%lld%lld",&u,&v);
	u--;v--;
	dijkstra(n,u);
	if(dist[v]!=LLONG_MAX)
		printf("%lld\n",dist[v]);
	else
		puts("NO");
	return 0;
}
void init_adj_list(long long n)
{
	long long i;
	for(i=0;i<n;i++)
		adj_list[i]=NULL;
}

void add_edge(long long node1,long long node2,long long cost)
{
	struct adj_node *nodeptr;
	nodeptr=(struct adj_node *)malloc(sizeof(struct adj_node));
	nodeptr->index=node2;
	nodeptr->cost=cost;
	nodeptr->next=adj_list[node1];
	adj_list[node1]=nodeptr;
}

void dijkstra(long long n,long long s)
{
	long long alt,i,u,v;
	struct adj_node *ptr;
	struct heap_node current_node;
	for(i=0;i<n;i++)
		dist[i]=LLONG_MAX;
	dist[s]=0;
	for(i=0;i<n;i++)
	{
		min_heap[i].index=i;
		min_heap[i].cost=dist[i];
		heap_pos[i]=i;
	}
	heaplength=n;
	build_min_heap();
	while(heapsize)
	{
		current_node=heap_extract_min();
		u=current_node.index;
		ptr=adj_list[u];
		while(ptr!=NULL)
		{
			v=ptr->index;
			alt=dist[u]+ptr->cost;
			if(alt<dist[v])
			{
				dist[v]=alt;
				heap_decrease_cost(heap_pos[v],dist[v]);
			}
			ptr=ptr->next;
		}
	}
}

void build_min_heap(void)
{
	long long i;
	heapsize=heaplength;
	for(i=heaplength/2-1;i>=0;i--)
		min_heapify(i);
}

void min_heapify(long long i)
{
	long long l,r,smallest;
	struct heap_node temp;
	l=2*i+1;
	r=l+1;
	if((l<heapsize) && (min_heap[l].cost<min_heap[i].cost))
		smallest=l;
	else
		smallest=i;
	if((r<heapsize) && (min_heap[r].cost<min_heap[smallest].cost))
		smallest=r;
	if(smallest!=i)
	{
		temp=min_heap[i];
		min_heap[i]=min_heap[smallest];
		min_heap[smallest]=temp;
		heap_pos[min_heap[smallest].index]=smallest;
		heap_pos[min_heap[i].index]=i;
		min_heapify(smallest);
	}
}

struct heap_node heap_extract_min(void)
{
	struct heap_node min;
	min=min_heap[0];
	min_heap[0]=min_heap[heapsize-1];
	heap_pos[min_heap[0].index]=0;
	heap_pos[min.index]=heapsize-1;
	heapsize--;
	min_heapify(0);
	return min;
}


void heap_decrease_cost(long long i,long long newcost)
{
	long long parent;
	struct heap_node temp;
	min_heap[i].cost=newcost;
	parent=(i-1)/2;
	while((i>0) && (min_heap[parent].cost>min_heap[i].cost))
	{
		temp=min_heap[parent];
		min_heap[parent]=min_heap[i];
		min_heap[i]=temp;
		heap_pos[min_heap[parent].index]=parent;
		heap_pos[min_heap[i].index]=i;
		i=parent;
		parent=(i-1)/2;
	}
}

void clear_adj_list(long long n)
{
	long long i;
	struct adj_node *ptr;
	for(i=0;i<n;i++)
	{
		while(adj_list[i]!=NULL)
		{
			ptr=adj_list[i];
			adj_list[i]=adj_list[i]->next;
			free(ptr);
		}
	}
}
