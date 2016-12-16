#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100010

typedef struct linked_list
{
	int v;
	struct linked_list * next;
}node;

node *adj[MAX];
int in_degree[MAX], heap[MAX], end=1;

void insert(int n, node **t)
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

void push(int N)
{
//	printf("pushing %d into heap..\n",N);
	int a=N, idx, t, i; 
	heap[end]=N;
	idx=end;

	while(idx)
	{	
		//in_heap[N] = idx;
		if(heap[idx/2] > a)
		{
			t = heap[idx];
			heap[idx] = heap[idx/2];
			heap[idx/2] = t;
			//in_heap[heap[idx]]=idx;
			//in_heap[heap[idx/2]]=idx/2;	
		}
		else
			break;

		idx = idx/2 ;
	}

	end++;
//	printheap();
	return ;
}

int pop()
{
//	printf("poping %d from heap..\n",heap[top]);
	int t,n,r,i;
	r = heap[1];
	heap[1] = heap[end-1];
	end--;
	
	n=1;
	while( (2*n)+1 <= end )
	{
		i = heap[2*n] < heap[(2*n)+1] ? 2*n : (2*n)+1 ;
		
		if(heap[n] > heap[i])
		{
			t = heap[n];
			heap[n] = heap[i];
			//in_heap[heap[n]] = n;
			heap[i] = t;
			//in_heap[heap[i]] = i;
		}
		else
			break;

		n=i;
	}
	if((2*n) == end-1)
	{
		if( heap[2*n] < heap[n] )
		{	
			t = heap[n];
			heap[n] = heap[2*n];
			//in_heap[heap[n]] = n;
			heap[2*n] = t;
			//in_heap[heap[2*n]] = 2*n;
		}
	}
//	printheap();
	return r;	
}

void delete(int u)
{
	node *a = adj[u];
	while(a)
	{
		in_degree[a->v]-- ;
		if(!in_degree[a->v])
			push(a->v);
		a = a->next;
	}
	return ;
}

void sort()
{
	int i=1, k;
	printf("%d",heap[1]);
	k=pop();
	delete(k);
	for(i=1;i<end;)
	{
		printf(" %d",heap[1]);
		k = pop();
		delete(k);		
	}
	printf("\n");

	return ;
}

void create_graph(int N, int M)
{
	memset(in_degree,0,sizeof(in_degree));
	int u, v, i;
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&u,&v);
		in_degree[v]++;
		insert(v,&adj[u]);
	}
	return ;
}

int main()
{
	int V, E, i;
	scanf("%d%d",&V,&E);
	create_graph(V,E);
	
	for(i=1;i<=V;i++)
	{
		if(!in_degree[i])
			push(i);
	}
	
	sort();
	return 0;
}
