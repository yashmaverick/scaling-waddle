#include <stdio.h>
#include <stdlib.h>

#define MAX ((int)1e6+5)
#define INF ((int)1e9)

struct node_t{
    int v, c;
};


typedef struct node_t node;

int heap[MAX], indeg[MAX], ts[MAX];
node adj[MAX],list[MAX];
int n, hn, tsn;

void insert(int u, int v){
    n = n+1;
    list[n].v = v;
    list[n].c = 0;
    if(!adj[u].v){
        adj[u].v = n;
        adj[u].c = n;
    }
    else{
        list[adj[u].c].c = n;
        adj[u].c = n;
    }
}

void print_adj_list(int N){
    int i, j;
    for(i=1; i<=N; i++){
        fprintf(stderr, "%d: ", i);
        for(j=adj[i].v; j!=0; j=list[j].c){
            fprintf(stderr, "%d ", list[j].v);
        }
        fprintf(stderr, "\n");
    }
}

void heap_insert(int n){
    int i, tmp;
    heap[++hn] = n;
    for(i=hn; i>1; i/=2){
        if(heap[i]<heap[i/2]){
            tmp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = tmp;
        }
        else{
            break;
        }
    }
}

int heap_extract_min(){
    int i, tmp, min, st;
    i = 1;
    min = i;
    tmp = heap[i];
    heap[i] = heap[hn];
    heap[hn] = INF;
    while(2*i+1<=hn){
        //fprintf(stderr, "swapping %d %d\n", i, min);
        if(heap[2*i]<heap[min])
            min = 2*i;
        if(heap[2*i+1]<heap[min])
            min = 2*i+1;
        if(i!=min){
            st = heap[i];
            heap[i] = heap[min];
            heap[min] = st;
        }
        else{
            break;
        }
        i = min;
    }
    hn = hn-1;
    return tmp;
}

void debug_heap(){
    int i;
    for(i=1; i<=hn; i++)
        fprintf(stderr, "%d ", heap[i]);
    fprintf(stderr, "\n");
}

void topo_sort(int V){
    tsn = 0;
    int count = 0;
    int i, u;
    for(i=1; i<=V; i++){
        if(!indeg[i])
            heap_insert(i);
    }
    while(hn>0){
        count += 1;
        u = heap_extract_min();
        ts[tsn++] = u;
        for(i=adj[u].v; i!=0; i=list[i].c){
            indeg[list[i].v] -= 1;
            if(!indeg[list[i].v])
                heap_insert(list[i].v);
        }
        //debug_heap();
    }
    if(count!=V){
        printf("Sandro fails.\n");
    }
    else{
        for(i=0; i<tsn; i++){
            printf("%d%s", ts[i], (i==tsn-1)?"":" ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    int V, E, v, u, i;
    scanf("%d %d", &V, &E);
    n = 0;
    hn = 0;
    for(i=0; i<E; i++){
        scanf("%d %d", &u, &v);
        insert(u, v);
        indeg[v] += 1;
    }
    //print_adj_list(V);
    topo_sort(V);
    return 0;
}
