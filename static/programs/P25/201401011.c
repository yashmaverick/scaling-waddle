#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000
#define INF 2147483647
#define MIN(x,y) ((x) < (y) ? (x) : (y))

int vis[MAX], dist[MAX], heap[MAX], in_heap[MAX];
int end, top;

typedef struct node
{
	int v;
	int w;
	struct node *next;
}node;

node *adj[MAX];

void insert( int v, node **list, int w)
{
	if( (*list) == NULL )
	{
		(*list) = (node*) malloc(sizeof(node));
		(*list)->v = v;
		(*list)->w = w;
		(*list)->next = NULL;

		return ;
	}

	insert( v, &((*list)->next), w );
	return ;
}

void printlist(int n)
{
	int i;
	node *c;
	for(i=1;i<=n;i++)
	{
		printf("list of %d :",i);
		c = adj[i];
		while(c)
		{
			printf("%d:%d ",c->v,c->w);
			c = c->next;
		}
		printf("\n");
	}
	return ;
}

void printheap()
{
	int  i;
	for(i=top;i<end;i++)
		printf("%d.%d@%d ",in_heap[heap[i]],heap[i],dist[heap[i]]);
	printf("\n");

	return ;
}

void push(int N)
{
//	printf("pushing %d into heap..\n",N);
	int a=dist[N], idx, t, i; 
	heap[end]=N;
	idx=end;

	while(idx)
	{	
		in_heap[N] = idx;
		if(dist[heap[idx/2]] > a)
		{
			t = heap[idx];
			heap[idx] = heap[idx/2];
			heap[idx/2] = t;
			in_heap[heap[idx]]=idx;
			in_heap[heap[idx/2]]=idx/2;	
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
//	printf("popoing %d from heap..\n",heap[top]);
	int t,n,r,i;
	r = heap[1];
	heap[1] = heap[end-1];
	end--;
	
	n=1;
	while( (2*n)+1 <= end )
	{
		i = dist[heap[2*n]] < dist[heap[(2*n)+1]] ? 2*n : (2*n)+1 ;
		
		if(dist[heap[n]] > dist[heap[i]])
		{
			t = heap[n];
			heap[n] = heap[i];
			in_heap[heap[n]] = n;
			heap[i] = t;
			in_heap[heap[i]] = i;
		}
		else
			break;

		n=i;
	}
	if((2*n) == end-1)
	{
		if( dist[heap[2*n]] < dist[heap[n]] )
		{	
			t = heap[n];
			heap[n] = heap[2*n];
			in_heap[heap[n]] = n;
			heap[2*n] = t;
			in_heap[heap[2*n]] = 2*n;
		}
	}
//	printheap();
	return r;	
}

void update(int N)
{
//	printf("updating dist of %d to %d\n",N,dist[N]);
	int a, t, idx;
	a = dist[N];
	idx = in_heap[N];
	while(idx)
	{
		
		if( a < dist[heap[idx/2]] )
		{
			t = heap[idx];
			heap[idx] = heap[idx/2];
			heap[idx/2] = t; 

			in_heap[heap[idx]] = idx;
			in_heap[t] = idx/2 ;
		}
		else
			break;

		idx = idx/2;
	}
//	printheap();
}

int main()
{
	int i, n, k, u, v, w, count=0, b;
	long long int tot=0;
	node *a;
	heap[0]=0;

	end = top = 1;

	memset(vis,0,sizeof(vis));
	memset(adj,0,sizeof(adj));
	memset(in_heap,0,sizeof(heap));
	dist[0]=-1;

	scanf("%d%d",&n,&k);
	
	for(i=1;i<=n;i++)
		dist[i]=INF;
		
	for(i=1; i<=k; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		insert(v, &adj[u], w);
		insert(u, &adj[v], w);
	}
//	printlist(n);
	dist[1] = 0;
	push(1);

	while( top!=end )
	{
		vis[heap[top]] = 1;
		count++;
		tot+=dist[heap[top]];
		a = adj[pop()];
		while(a)
		{
			if(vis[a->v])
			{	
				a = a->next;
				continue;
			}

			b =  MIN ( a->w , dist[a->v] );
			if( b != dist[a->v])
			{
				dist[a->v] = b;

				if(in_heap[a->v])
					update(a->v);
				else
					push(a->v);	
			}
			a = a->next;
		}
	} 
	
	if(count<n)
		printf("-1\n");
	else	
		printf("%lld\n",tot);
	return 0;
}
