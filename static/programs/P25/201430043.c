#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 2000000000

typedef struct Adjlist
{
	int vertex;
	int weight;
	struct Adjlist *next;
}list;

typedef struct heapnode
{
	int element;
	int vertex;
}node;

node heap[1000005];
int heapsize;
list* A[1000005];
int vis[1000005],dis[1000005];

void Initialize()
{
	heap[0].element= -INF;
	heap[0].vertex= 0;
	heapsize=0;
}

list* newnode(int node2 , int w)
{
// 	printf("ding\n");
	list* new =(list*)malloc(sizeof(list));
	new->vertex = node2;
	new->weight = w;
	new->next = NULL;
	return new;
}

void addEdge(int node , int node2 , int w)
{
// 	printf("ping\n");
	list* new = newnode(node2 , w);
	new->next = A[node];
	A[node] = new;
	list *new1 = newnode(node , w);
	new1->next = A[node2];
	A[node2]=new1;
}

void InsertH(int value,int vert)
{
// 	printf("ping\n");
	heapsize++;
	heap[heapsize].element=value;
	heap[heapsize].vertex=vert;
	int now=heapsize;
	while(heap[now/2].element > value)
	{
		heap[now].element = heap[now/2].element;
		heap[now].vertex = heap[now/2].vertex;
		now= now/2;
	}
	heap[now].element = value;
	heap[now].vertex = vert;
}

node DeleteMin()
{
	int child,now;
	node minelement,lastelement;
	minelement= heap[1]; 
	lastelement = heap[heapsize--];
	for(now = 1; now*2 <= heapsize ;now = child)
        {
                child = now*2;
                if(child != heapsize && heap[child+1].element < heap[child].element ) 
                {
                        child++;
                }
                if(lastelement.element > heap[child].element)
                {
                        heap[now] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[now] = lastelement;
        return minelement;
}

void MinSpan()
{
	dis[1] = 0;
	InsertH(0 , 1);
	while(heapsize > 0)
	{
		node v = DeleteMin();
		int u = v.vertex;
		if(vis[u] == 1)
			continue;
		vis[u] = 1;
		list* move = A[u];
		
		while(move != NULL)
		{
			int vertex = move->vertex;
			int new_dis = move->weight;
			
			if(dis[vertex] > new_dis && vis[vertex]!=1)
			{
				dis[vertex] = new_dis;
				InsertH(dis[vertex] , vertex);
			}
			move = move->next;
		}
	}
}

int main()
{
	int N,M,n1,n2,wt,i,j;
	long long int k;
	scanf("%d",&N);
	scanf("%d",&M);
	Initialize();
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&n1,&n2,&wt);
		addEdge(n1,n2,wt);
	}
	for(i=1;i<1000005;i++)
	{
		vis[i]=0;
		dis[i]=INF;
	}
	MinSpan();
	j=0;k=0;
	for(i=0;i<=N;i++)
	{
		if(dis[i]==INF)
		{
			j=1;
			printf("-1\n");
			break;
		}
		else
			k= k+dis[i];
	}
	if(j==0)
		printf("%lld\n",k);
	return 0;
}