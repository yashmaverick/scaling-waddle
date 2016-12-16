#include <stdio.h>
#include <stdlib.h>
#define INF 999999999
struct list{
    long long int num;
    long long int weight;
    struct list * next;
}*head;
typedef struct list list;
struct heap_node
{
    long long int  v;
    long long int distance;
};
typedef struct heap_node hnode;
struct heap
{
    long long int size;  
    long long int cap; 
    long long int *position;    
    struct heap_node **array;
};
typedef struct heap sheap;
list * array[100010];
void insert(long long int e1,long long int e2,long long int w)
{
    
    list *temp;
    temp=(list *)malloc(sizeof(list));
    temp->next=array[e1];
    array[e1]=temp;
    temp->num=e2;
    temp->weight=w;
}
void dijkstra(long long int source,long long int dest,long long int V,long long int e);
int main()
{   long long int i,j,w,ch,co;
    long long int source, target,x,y;
    long long int ver,e;
    scanf("%lld%lld",&ver,&e);
        long long int u,v;
        for(i=1;i<=e;i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
            insert(u-1,v-1,w);
    }
        scanf("%lld%lld",&source,&target);
    dijkstra(source-1,target-1,ver,e);
    return 0;
}
hnode* new(long long int ver, long long int distance)
{
    hnode* heap_node=(hnode*)malloc(sizeof(hnode));
    heap_node->v=ver;
    heap_node->distance=distance;
    return heap_node;
}
void swap(hnode** a, hnode** b)
{
    hnode* t=*a;
    *a=*b;
    *b=t;
}
void heap_small(sheap* heap, long long int index)
{
    long long int small,left,right;
    small=index;
    left=2*index+1;
    right=2*index+2;

    if(left<heap->size    &&  heap->array[left]->distance  <  heap->array[small]->distance)
      small=left;

    if(right<heap->size   &&  heap->array[right]->distance <  heap->array[small]->distance)
      small=right;

    if(small!=index)
    {
        hnode *smallNode=heap->array[small];
        hnode *indexNode=heap->array[index];
        heap->position[smallNode->v]=index;
        heap->position[indexNode->v]=small;
        swap(&heap->array[small],&heap->array[index]);
        heap_small(heap,small);
    }
}
hnode* extractMin(sheap* heap)
{
    if (heap->size==0)
        return NULL;
    hnode* root=heap->array[0];
    hnode* lastNode=heap->array[heap->size - 1];

    heap->array[0]=lastNode;
    heap->position[root->v]=heap->size-1;
    heap->position[lastNode->v]=0;

    --heap->size;
    heap_small(heap, 0);
    return root;
}
void dijkstra(long long int source,long long int dest,long long int V,long long int e)
{
    long long int *distance=(long long int *)malloc(V*sizeof(long long int));
    
    sheap* heap=(sheap*) malloc(sizeof(sheap));//creating new node
    heap->position=(long long int *)malloc((V)* sizeof(long long int));
    heap->size=0;
    heap->cap=V;
    heap->array=(hnode**)malloc(V* sizeof(hnode*));
    
    long long int v; 
    for (v=0;v<V;++v)
    {
        distance[v]=INF;
        heap->array[v]=new(v, distance[v]);
        heap->position[v]=v;
    }
    heap->array[source]=new(source,distance[source]);
    heap->position[source]=source;
    distance[source]=0;
    long long int i = heap->position[source];
    heap->array[i]->distance=distance[source];
    while (i && heap->array[i]->distance<heap->array[(i-1)/2]->distance)
    {
        heap->position[heap->array[i]->v]=(i-1)/2;
        heap->position[heap->array[(i-1)/2]->v]=i;
        swap(&heap->array[i],&heap->array[(i-1)/2]);
        i=(i-1)/2;
    }
    heap->size = V;
    while (heap->size!=0)
    {
        hnode* heap_node = extractMin(heap);
        long long int u = heap_node->v;
       list * traverse = array[u];
        while (traverse!=NULL)
        {
            long long int v = traverse->num;
            if (heap->position[v] < heap->size &&distance[u]!=INF && traverse->weight+distance[u]<distance[v])
            {
                distance[v]=distance[u]+traverse->weight;
                long long int i = heap->position[v];
    heap->array[i]->distance=distance[v];
    while (i && heap->array[i]->distance<heap->array[(i-1)/2]->distance)
    {
        heap->position[heap->array[i]->v]=(i-1)/2;
        heap->position[heap->array[(i-1)/2]->v]=i;
        swap(&heap->array[i],&heap->array[(i-1)/2]);
        i=(i-1)/2;
    }
            }
            traverse=traverse->next;
        }
    }
    if(distance[dest]==INF)
    printf("NO\n");
    else
    printf("%lld\n",distance[dest]);
}