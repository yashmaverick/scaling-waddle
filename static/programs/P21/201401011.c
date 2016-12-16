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
//		printf("Showing adj list of %d :\n",i);
		c = adj[i];
		while(c)
		{
//			printf("v:%d,w:%d\n",c->v,c->w);
			c = c->next;
		}
	}
	return ;
}

void push(int N)
{
	int a=dist[N], idx, t, i; 
//	printf("pushing %d at dist %d into heap\n",N,a);
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
		}
		else
			break;

		idx = idx/2 ;
	}
	
	end++;
	return ;
}

void pop()
{
//	printf("poping  %d at dist %d from heap\n", heap[top], dist[heap[top]]);
	int t,n;
	t = heap[end-1];
	end--;
	
	n=1;
	while( (2*n)+1 <= end )
	{
//		printf("dist are %d and %d \n", dist[heap[2*n]], dist[heap[(2*n)+1]]);
		heap[n] = dist[heap[2*n]] < dist[heap[(2*n)+1]] ? heap[2*n] : heap[(2*n) + 1];
		n = dist[heap[2*n]] < dist[heap[(2*n)+1]] ? 2*n : (2*n) + 1;
		in_heap[heap[n]] = n/2 ;
	}
	heap[n] = t;
	in_heap[t] = n;
	return ;	
}

void update(int N)
{
	int a, t, idx;
//	printf("updating %d to new dist %d\n",N, dist[N]);
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
}

int main()
{
	int t, i, n, k, u, v, w, src, dest, b;
	node *a;
	heap[0]=0;
	
//	scanf("%d",&t);
//	while(t--)
//	{
//		printf("Test cast %d\n",t+1);
		end = top =1;
		
		memset(vis,0,sizeof(vis));
		memset(adj,0,sizeof(adj));
		memset(in_heap,0,sizeof(heap));
		dist[0]=-1;
		for(i=1;i<MAX;i++)
		{
			dist[i]=INF;
		}		

		scanf("%d%d",&n,&k);
		
//		printf("no of edges = %d , number of vertices = %d\n",k,n);
		
		for(i=1; i<=k; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			insert(v, &adj[u], w);
			
		}
//		printlist(n);

//		printf("back to main\n");
		scanf("%d%d",&src,&dest);
//		printf("%d->%d\n",src,dest);
	
		dist[src] = 0;
		push(src);
		while( !vis[dest] && top!=end )
		{
			vis[heap[top]] = 1;

			a = adj[heap[top]];
			while(a)
			{
				if(vis[a->v])
				{	
					a = a->next;
					continue;
				}

				b =  MIN ( dist[heap[top]] + a->w , dist[a->v] );
				if( b != dist[a->v])
				{
					dist[a->v] = b;
					
					if(in_heap[a->v])
						update(a->v);
					else
						push(a->v);	
				}

//				printf("ATM the min dist of %d from %d is %d \n",a->v,src,dist[a->v]);	
				a = a->next;
			}
//			for(i=top;i<end;i++)
//				printf("%d ",heap[i]);
//			printf("\n");
			pop();
//			for(i=top;i<end;i++)
//				printf("%d ",heap[i]);
//			printf("\n");
		} 

		if(dist[dest] == INF)
			printf("NO\n");
		else
			printf("%d\n",dist[dest]);
//	}

	return 0;
}
