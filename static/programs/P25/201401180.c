#include<stdio.h>
#include<stdlib.h>
long long int min(long long int a, long long int b)
{
	return (a>b)?b:a;
}
struct node
{
	long long int data;
	long long int weight;
	struct node* next;
};
struct list
{
	struct node* head;
};
struct graph
{
	long long int v;
	struct list* array[1000000];
};
struct graph* cgraph(long long int v)
{
	struct graph* graph=malloc(sizeof(struct graph));
	graph->v=v;
	long long int i;
	for(i=1;i<=v;i++)
	{
		graph->array[i]=malloc(sizeof(struct list));
		graph->array[i]->head=NULL;
	}
	return graph;
}
void addedge(struct graph* graph, long long int s, long long int d, long long int w)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=d;
	newnode->weight=w;
	newnode->next=graph->array[s]->head;
	graph->array[s]->head=newnode;

}

struct heapnode
{
	long long int v;
	long long int d;
};
void minheap(struct heapnode* a[1000000],long long int n, long long int index[])
{
	if (n==1)
	{
		index[a[n]->v]=n;
		return;
	}
	else if (a[n]->d<a[n/2]->d)
	{
		struct heapnode* tmp=a[n/2];
		index[a[n]->v]=n/2;
		index[a[n/2]->v]=n;
		a[n/2]=a[n];
		a[n]=tmp;
		n/=2;
		minheap(a,n,index);
	}
	else
	{
		index[a[n]->v]=n;
		return;
	}
}
struct heapnode* deletemin(struct heapnode* a[1000000], long long int *n1, long long int index[])
{
	struct heapnode* ans=a[1];
	index[ans->v]=(*n1);
	struct heapnode* tt=a[*n1];
	(*n1)--;
	long long int n=(*n1);
	long long int i=1;
	long long int t=tt->d;
	long long int t1;
	while ((2*i) <= n)
	{
		long long int j=2*i;
		if (j!=n&&a[j]->d>=t&&a[j+1]->d>=t)
			break;
		else if (j==n&&a[j]->d>=t)
			break;
		else
		{
			t1=min(a[j]->d,a[j+1]->d);
			if (t1==a[j]->d)
			{
				index[a[j]->v]=i;
				a[i]=a[j];
				i=j;
			}	
			else
			{
				index[a[j+1]->v]=i;
				a[i]=a[j+1];
				i=j+1;
			}
		}
	}
	index[tt->v]=i;
	a[i]=tt;
	return ans;
}
void update(struct heapnode* a[1000000],long long int i,long long int index[])
{
	while(i>1&&a[i/2]->d>a[i]->d)
	{
		struct heapnode* tmp=malloc(sizeof(struct heapnode));
		index[a[i/2]->v]=i;
		index[a[i]->v]=i/2;
		tmp=a[i/2];
		a[i/2]=a[i];
		a[i]=tmp;
		i/=2;
	}
}
void print(long long int d[],long long int v)
{
	long long int i;
	long long int sum=0;
	for(i=1;i<=v;i++)
		sum+=d[i];
	printf("%lld\n",sum);
}
void prim(struct graph* graph)
{
	long long int v=graph->v;
	long long int i;
	long long int index[100000];
	long long int d[100000];
	long long int p[100000];
	struct heapnode* a[100000];
	long long int size=v;
	for(i=1;i<=v;i++)
	{
		if(i!=1)
		{
			a[i] = (struct heapnode*)malloc(sizeof(struct heapnode));
			d[i]=10e10;
			a[i]->v=i;
			a[i]->d=10e10;
			index[a[i]->v]=i;
			minheap(a,i,index);
			p[i]=-1;
		}
		else
		{
			a[i] = (struct heapnode*)malloc(sizeof(struct heapnode));
			d[i]=0;
			a[i]->v=i;
			a[i]->d=0;
			index[a[i]->v]=i;
			minheap(a,i,index);
			p[i]=-1;
		}
	}
	while(size!=0)
	{
		struct heapnode* tmp=deletemin(a,&size,index);
		struct node* current = malloc(sizeof(struct node));
		long long int t = tmp->v;
		current=graph->array[t]->head;
		while(current!=NULL)
		{
			if(index[current->data]<=size && current->weight < d[current->data])
			{
				d[current->data]=current->weight;
				p[current->data]=t;
				long long int ind=index[current->data];
				a[ind]->d=d[current->data];
				update(a,ind,index);
			}
			current = current->next;
		}
	}
	print(d,v);
}
void dfs(struct graph* graph, int s,int visited[])
{
	visited[s]=1;
	struct node* current=graph->array[s]->head;
	while(current!=NULL)
	{
		if(!visited[current->data])
			dfs(graph,current->data,visited);
		current=current->next;
	}
}
int main()
{
	long long int i,j,w,n,e,p,q;
	scanf("%lld",&n);
	struct graph* graph=malloc(sizeof(struct graph));
	graph=cgraph(n);
	scanf("%lld",&e);
	for(i=0;i<e;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&w);
		addedge(graph,p,q,w);
		addedge(graph,q,p,w);
	}
	int visited[100000];
	int f=1;
	for(i=1;i<=n;i++)
		visited[i]=0;
	dfs(graph,1,visited);
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			f=0;
			break;
		}
	}
	if(f==1)
		prim(graph);
	else
		printf("%d\n",-1);
	return 0;
}
