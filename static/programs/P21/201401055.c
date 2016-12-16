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

void dijkstra(int source)
{
	dis[source] = 0;
// 	vis[source] = 1;
	
	InsertH(0 , source);
// 	printf("%d %d\n" , heap[1].element , heap[1].vertex);
	while(heapsize > 0)
	{
// 		printf("ping\n");
		node v = DeleteMin();
		int u = v.vertex;
		if(vis[u] == 1)
			continue;
		vis[u] = 1;
		list* move = A[u];
		
		while(move != NULL)
		{
			int vertex = move->vertex;
			int new_dis = dis[u] + move->weight;
			
			if(dis[vertex] > new_dis)
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
	int N,M,n1,n2,wt,i,s,t;
	scanf("%d",&N);
	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&n1,&n2,&wt);
		addEdge(n1,n2,wt);
	}
	for(i=1;i<100005;i++)
	{
		vis[i]=0;
		dis[i]=INF;
	}
	Initialize();
	/*list* crawl = A[3];
	while(crawl != NULL)
	{
		printf("%d " , (crawl->vertex));
		printf("%d " , (crawl->weight));
		printf("done\n");
		crawl = crawl->next;
	}
	*/
// 	printf("%d \n" , heap[0].vertex);
	scanf("%d" , &s);
	scanf("%d" , &t);
	dijkstra(s);
	if(dis[t] == INF)
		printf("NO\n");
	else
		printf("%d\n" , dis[t]);
	return 0;
}
