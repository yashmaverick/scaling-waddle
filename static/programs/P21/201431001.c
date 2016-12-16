#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
typedef struct node{
    long long int dest;
    long long int weight;
    struct node* next;
}node;
 
typedef struct list{
    node *head;
}list;
 
typedef struct Graph{
    long long int V;
    list* array;
}Graph;

long long int dist[5000001];

node* newnode(long long int dest, long long int weight)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 
Graph* createGraph(long long int V)
{
    Graph* graph = (Graph* )malloc(sizeof(Graph));
    graph -> V = V;
    graph -> array = (list * )malloc(V * sizeof(list));
 
    long long int i;
    for(i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}
 
void addEdge(Graph* graph, long long int src, long long int dest, long long int weight)
{
    node *newNode = newnode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    //newNode = newnode(src, weight);
    //newNode->next = graph->array[dest].head;
    //graph->array[dest].head = newNode;
}
 
typedef struct MinHeapNode
{
    long long int  v;
    long long int dist;
}MinHeapNode;
 
typedef struct MinHeap
{
    long long int size;
    long long int capacity;
    long long int *pos;
    MinHeapNode **array;
}MinHeap;
 
MinHeapNode* newMinHeapNode(long long int v, long long int dist)
{
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode -> v = v;
    minHeapNode -> dist = dist;
    return minHeapNode;
}
 
MinHeap* createMinHeap(long long int capacity)
{
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap -> pos = (long long int *)malloc(capacity * sizeof(long long int));
    minHeap -> size = 0;
    minHeap -> capacity = capacity;
    minHeap -> array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}
 
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(MinHeap* minHeap, long long int index)
{
    long long int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;
 
    if(left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
 
    if(right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;
 
    if(smallest != index)
    {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* indexNode = minHeap->array[index];
 
        minHeap->pos[smallestNode->v] = index;
        minHeap->pos[indexNode->v] = smallest;
 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}
 
MinHeapNode* extractMin(MinHeap* minHeap)
{
    if (minHeap->size == 0)
        return NULL;
 
    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}
 
void decreaseKey(MinHeap* minHeap, long long int v, long long int dist)
{
    long long int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
 
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
/* 
void print(long long int n)
{
    long long int i;
    for (i = 0; i < n; ++i)
        prlong long intf("%d-------%d\n", i, dist[i]);
}
*/
void dijkstra(Graph* graph, long long int src)
{
    long long int V = graph->V;
    MinHeap* minHeap = createMinHeap(V);
 
    long long int v;
    for (v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
 
    minHeap -> array[src] = newMinHeapNode(src, dist[src]);
    minHeap -> pos[src] = src;
    dist[src] = 0;

    decreaseKey(minHeap, src, dist[src]);
    minHeap -> size = V;
 
    while(minHeap->size)
    {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        long long int u = minHeapNode->v; 

        node *pCrawl = graph->array[u].head;
        while(pCrawl != NULL)
        {
            long long int v = pCrawl->dest;
            if(minHeap->pos[v] < minHeap->size && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    //prlong long int(V);
}
 
long long int main()
{
    long long int V,E;
    scanf("%lld %lld",&V,&E);
    Graph* graph = createGraph(V);
    
    long long int i;
    for(i = 0;i < E;i++)
    {
        long long int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        addEdge(graph,u-1,v-1,w);
    }

    long long int s,t;
    scanf("%lld %lld",&s,&t);
    
    dijkstra(graph, s-1);
    
    if(dist[t-1] != INT_MAX)
        printf("%lld\n", dist[t-1]);
    else printf("NO\n"); 
    
    return 0;
}