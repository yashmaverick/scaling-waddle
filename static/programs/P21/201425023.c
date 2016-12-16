#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct AdjListNode
{
	int dstn;
	int weight;
	struct AdjListNode* next;
}node;
typedef struct AdjList
{
	node* head;
}list;
typedef struct Graph
{
	int V;
	list * arr;
}graph;

node* createNode(int d, int w)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->dstn = d;
	temp->weight = w;
	temp->next = NULL;
	return temp;
}
graph* createGraph(int n)
{
	int i;
	graph* temp = (graph*)malloc(sizeof(graph));
	temp->V = n;
	temp->arr = (list*)malloc(sizeof(list)*n);
	for(i=0;i<n;i++)
	{
		temp->arr[i].head = NULL;
	}
	return temp;
} 
void addEdge(graph* g,int src, int dstn,int wt)
{
	//IMP -- directed graph
	node* temp = createNode(dstn,wt);
	temp->next = g->arr[src].head;
	g->arr[src].head = temp;
}

typedef struct heapNode
{
	int v;
	int dist;
}heapNode;

typedef struct minHeap
{
	int size;
	int capacity;
	int* posofnode;
	heapNode** harr;
}minHeap;

void swap(minHeap* mh,int a,int b)
{
	heapNode* ah = mh->harr[a];
	heapNode* bh = mh->harr[b];
	mh->posofnode[ah->v] = b;
	mh->posofnode[bh->v] = a;
	//heapNode* t= mh->harr[a];
	mh->harr[a]=bh;
	mh->harr[b] =ah;
}

heapNode* createHeapNode(int v,int dist)
{
	heapNode* temp =(heapNode*)malloc(sizeof(heapNode));
	temp->v=v;
	temp->dist = dist;
	return temp;
}
minHeap* createMinHeap(int cap)
{
	minHeap* temp = (minHeap*)malloc(sizeof(minHeap));
	temp->size=0;
	temp->capacity = cap;
	temp->posofnode = (int*)malloc(sizeof(int)*cap);
	temp->harr = (heapNode**)malloc(sizeof(heapNode*)*cap);
	return temp;
}
int isEmpty(minHeap* mh)
{
	if(mh->size == 0)
		return 1;
	return 0;
	
}
void heapify(minHeap* mh,int i)
{
	int smallest = i;
	int l=2*i+1;
	int r= 2*i+2;
	if(l < mh->size && mh->harr[l]->dist < mh->harr[smallest]->dist)
		smallest = l;
	if(r < mh->size && mh->harr[r]->dist < mh->harr[smallest]->dist)
		smallest = r;
	if(smallest!=i)
	{//swap(&mh->harr[i],&mh->harr[smallest]);
		swap(mh,i,smallest);
		heapify(mh, smallest);
	}			
}

void decreaseDist(minHeap* mh, int src,int dist_src)
{
	int i= mh->posofnode[src];
	mh->harr[i]->dist = dist_src;
	int parent = (i-1)/2;
	while(i!=0 && mh->harr[parent]->dist > mh->harr[i]->dist)
	{
		swap(mh,parent,i);
		i = parent;
		parent = (i-1)/2;
	}
}
heapNode* extractMin(minHeap* mh)
{
	if(isEmpty(mh)) return NULL;
	heapNode* temp = mh->harr[0];
	swap(mh,0,mh->size-1);
	mh->size--;
	heapify(mh,0);
	return temp;
}
int isInHeap(minHeap* mh,int v)
{
	if(mh->posofnode[v]<mh->size)
		return 1;
	return 0;
}
void dijkstra(graph* gr, int src,int dest)
{
	int i;
	int V = gr->V;
	minHeap* mH = createMinHeap(V);
	int *dist=(int*)malloc(sizeof(int)*V);
	for(i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		mH->harr[i] =  createHeapNode(i,dist[i]);
		mH->posofnode[i]=i;
	}
	mH->size = V;
	dist[src]=0;
	decreaseDist(mH,src,dist[src]);
	while(!isEmpty(mH))
	{
		heapNode* temp = extractMin(mH);
		int u = temp->v;
		node *p= gr->arr[u].head;
		while(p!=NULL)
		{
			int v = p->dstn;
			if(isInHeap(mH,v) && dist[u]!=INT_MAX && dist[v]>dist[u]+p->weight)
			{
				dist[v]=dist[u]+p->weight;
				decreaseDist(mH,v,dist[v]);
			}
			p = p->next;
		}
		
	}
	if(dist[dest] == INT_MAX)
		printf("NO\n");
	else
		printf("%d\n", dist[dest]);
	for(i=0;i<V;i++)
	{
		free(mH->harr[i]);
		mH->harr[i] = NULL;
	}
	free(mH);
	mH = NULL;
	
}
int main()
{
	graph* gr;
    int N,M,i,j,src,dest;
	int x,y,w;
    scanf("%d %d",&N,&M);
    gr = createGraph(N);
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		addEdge(gr, x-1,y-1, w);
	}
	scanf("%d %d", &src, &dest);
	if(M==0)
	{	printf("NO");
		return 0;
	}
    dijkstra(gr,src-1,dest-1);
	for(i=0;i<N;i++)
	{
		free(gr->arr[i].head);
		gr->arr[i].head = NULL;
	}
	free(gr->arr);
	gr->arr = NULL;
	free(gr);
	gr = NULL;
    return 0;
}
