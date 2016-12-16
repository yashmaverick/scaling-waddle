#include <stdio.h>

#define MAX ((int)1e6+5)
#define INF ((int)1e9)
//Weird, complicated constructs to prevent dynamic allocations
struct node_t{
    int v, w;
};
typedef struct node_t node;
typedef struct {
    int v, w, c;
}lnode;

//Who likes global variables?
node heap[MAX], adj[MAX];
lnode list[MAX];
int d[MAX], h, n, l; //Why the fuck did I define n?

//Heap functions
int compare(const node *a, const node *b){
    return (a->w<b->w);
}
void swap(node *a, node *b){
    node tmp = *a;
    *a = *b;
    *b = tmp;
}
void heap_insert(node x){
    int i;
    heap[++h] = x;
    for(i=h; i>1; i/=2){
        if(compare(&heap[i], &heap[i/2]))
            swap(&heap[i], &heap[i/2]);
        else
            break;
    }
}
node heap_extract(){
    int i=1, min=i;
    swap(&heap[i], &heap[h]);
    node tmp = heap[h];
    heap[h].v = 0;
    heap[h].w = INF;
    while(2*i+1 <= h){
        if(compare(&heap[2*i], &heap[min]))
            min = 2*i;
        if(compare(&heap[2*i+1], &heap[min]))
            min = 2*i+1;
        if(min!=i)
            swap(&heap[min], &heap[i]);
        else
            break;
        i = min;
    }
    h = h-1;
    return tmp;
}
void debug_heap(){
    int i;
    for(i=1; i<=h; i++){
        fprintf(stderr, "(%d, %d)", heap[i].v, heap[i].w);
    }
    fprintf(stderr, "\n");
}

//Adjacency list shit
void add_edge(int u, int v, int w){
    l = l+1;
    list[l] = (lnode){v, w, 0};
    if(!adj[u].v){
        adj[u].v = l;
        adj[u].w = l;
    }
    else{
        list[adj[u].w].c = l;
        adj[u].w = l;
    }
}
void add_edges(int u, int v, int w){
    add_edge(u, v, w);
    add_edge(v, u, w);
}
void debug_adjlist(int V){
    int i, j;
    for(i=1; i<=V; i++){
        fprintf(stderr, "%d: ", i);
        for(j=adj[i].v; j!=0; j=list[j].c){
            fprintf(stderr, "(%d, %d) ", list[j].v, list[j].w);
        }
        fprintf(stderr, "\n");
    }
}

//The algorithm, and I have memory in hand
int dijkstra(int s, int e, int V){
    node x;
    int i, v, u, w;
    for(i=1; i<=V; i++)
        d[i] = INF;
    d[s] = 0;
    heap_insert((node){s, 0});
    while(h>0){
        x = heap_extract();
#ifdef DEBUG
        fprintf(stderr, "Extract (%d, %d)\n", x.v, x.w);
#endif
        u = x.v;
        if(u == e) 
            return d[e];
        for(i=adj[u].v; i!=0; i=list[i].c){
            v = list[i].v;
            w = list[i].w;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                heap_insert((node){v, d[v]});
            }
        }
#ifdef DEBUG
        debug_heap();
#endif

    }
    return d[e];
}
int main(int argc, char *argv[]){
    int V, E, v, u, i, w, res;
    scanf("%d %d", &V, &E);
    for(i=0; i<E; i++){
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
#ifdef DEBUG
    debug_adjlist(V);
#endif
    scanf("%d %d", &u, &v);
    res = dijkstra(u, v, V);
    if(res!=INF)
        printf("%d\n", res);
    else
        printf("NO\n");
    return 0;
}
