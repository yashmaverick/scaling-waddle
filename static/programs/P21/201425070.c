#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define INF 99999999999
typedef struct AdjListNode
{
    int data;
    long long int weight;
    struct AdjListNode *next;
}node;

typedef struct AdjList
{
    node *head;
}list;

typedef struct MN
{
    int data;
    long long int distance;
}minheapnode;

typedef struct GG
{
    int size;
    list *value;
}Graph;

typedef struct mnhe
{
    int size;    
    int total;
    int *cur;   
    minheapnode* value[1000001];
}mnh;

minheapnode *makeMNode(int data ,long long int distance)
{
    minheapnode *new = (minheapnode *)malloc(sizeof(minheapnode));
    new->data = data;
    new->distance = distance;
    return new;
}

mnh *createmnh(int total)
{
    mnh *new =(mnh *) malloc(sizeof(mnh));
    new->cur = (int *)malloc(total * sizeof(int));
    new->size = 0;
    new->total = total;
    int i;
    for(i=0;i<= total+1;i++)
        new->value[i] = NULL;
    return new;
}

node *makeNode(int data , long long int w)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    new->weight = w;
    new->next = NULL;
    return new;
}

Graph *makeGraph(int v)
{
    Graph *graph;
    graph = (Graph *)malloc(sizeof(Graph));
    graph->size = v;
    graph->value = (list *)malloc(sizeof(list)*v);

    int i;
    for(i=0;i<v;i++)
        graph->value[i].head = NULL;

    return graph;
}

void insert(Graph *graph , int src , int dest , int w)
{
    node *new = makeNode(dest , w);
    new->next = graph->value[src].head;
    graph->value[src].head = new;

    // Include All this For an Undirected Graph
    //     new = makeNode(src , w);
    //     new->next = graph->value[dest].head;
    //     graph->value[dest].head = new;
}

void shuffle(mnh *Heap, int i)
{
    int min;
    int r , l , k;
    min = i;
    r= 2*i+2;
    l = 2*i+1;
    if (l < Heap->size)
        if(Heap->value[l]->distance < Heap->value[min]->distance)
            min = l;
    if (r < Heap->size)
        if(Heap->value[r]->distance < Heap->value[min]->distance )
            min = r;
    if (min != i)
    {
        minheapnode *y = Heap->value[i];
        minheapnode *x = Heap->value[min];
        Heap->cur[x->data] = i;
        Heap->cur[y->data] = min;
        minheapnode *t = Heap->value[min];
        Heap->value[min] = Heap->value[i];
        Heap->value[i] = t;
        shuffle(Heap, min);
    }
}

minheapnode* findMin(mnh* Heap)
{
    if (Heap->size == 0)
        return NULL;
    minheapnode *root = Heap->value[0];
    minheapnode *lastNode = Heap->value[Heap->size - 1];
    Heap->value[0] = lastNode;
    Heap->cur[root->data] = Heap->size-1;
    Heap->cur[lastNode->data] = 0;
    Heap->size = Heap->size - 1;
    shuffle(Heap, 0);

    return root;
}

void redPriority(mnh* Heap, int v, int distance)
{
    int i = Heap->cur[v];
    Heap->value[i]->distance = distance;
    while (i!=0 &&  Heap->value[i]->distance < Heap->value[(i - 1) / 2]->distance)
    {
        Heap->cur[Heap->value[i]->data] = (i-1)/2;
        Heap->cur[Heap->value[(i-1)/2]->data] = i;
        minheapnode *temp;
        temp = Heap->value[i];
        Heap->value[i] = Heap->value[(i - 1) / 2];
        Heap->value[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

long long int dijkstra(Graph* graph, int src , int dest)
{
    int gsize = graph->size;
    long long int distance[gsize];   
    int v , i , k , m;
    long long int alt;
    mnh* Heap = createmnh(gsize);

    for (v = 0; v < gsize; ++v)
    {
        distance[v] = INF;
        Heap->value[v] = makeMNode(v, distance[v]);
        Heap->cur[v] = v;
    }

    Heap->value[src] = makeMNode(src, distance[src]);
    Heap->cur[src]   = src;
    distance[src] = 0;
    redPriority(Heap, src, distance[src]);
    Heap->size = gsize;
    while (Heap->size != 0)
    {
        minheapnode* hn = findMin(Heap);
        k = hn->data;
        node *temp = graph->value[k].head;
        while (temp != NULL)
        {
            int v = temp->data;
            alt = distance[k]+temp->weight;
            if (Heap->cur[v] < Heap->size)
                if(distance[k] != INF && alt < distance[v])
                {
                    distance[v] = alt;
                    redPriority(Heap, v, distance[v]);
                }
            temp = temp->next;
        }
    }
    return distance[dest];
}

int main()
{
    int i , j ,k , test;
    int x , y ,  vert , edge;
    long long int w;
   // scanf("%d",&test);
   // while(test--)
   // {
        scanf("%d%d",&vert , &edge);
        Graph *graph = makeGraph(vert);
        while(edge-- && vert > 1)
        {
            scanf("%d%d%lld",&x,&y,&w);
            insert(graph , x-1 , y-1 , w);
        }
        scanf("%d%d",&x,&y);
        long long int answer = dijkstra(graph, x-1 , y-1);
        if( answer == INF || vert == 1 || vert == 0)
            printf("NO\n");
        else
            printf("%lld\n",answer);
   // }
    return 0;
}
