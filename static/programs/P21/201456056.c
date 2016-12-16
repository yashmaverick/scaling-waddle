#include <stdio.h>
#include <stdlib.h>

#define MAX 1000006
#define INF 1000000007

//Distance array
int d[MAX];

void reset(int A[], int n, int v){
	int i;
	for(i=0; i<n; i++)
		A[i] = v;
}

//Graph
typedef struct node_t{
	int v, w;
	struct node_t *next;
}node;
typedef struct{
	node *head, *tail;
	int indeg;
}list;

list* gen_adj(int N){
	list *A = (list*)(malloc(sizeof(list)*(N+1)));
	int i;
	for(i=0; i<=N; i++){
		A[i].head = NULL;
		A[i].tail = NULL;
		A[i].indeg = 0;
	}
	return A;
}
void reset_graph(list *adj, int N){
	int i;
	node *t, *p;
	for(i=1; i<=N; i++){
		for(t=adj[i].head; t!=NULL;){
			p = t;
			t = t->next;
			free(p);
		}
		adj[i].head = NULL;
		adj[i].tail = NULL;
		adj[i].indeg = 0;
	}
}
void destroy_graph(list **adj){
	free(*adj);
	*adj = NULL;
	
}
node *getnode(int v, int w){
	node *t = (node*)malloc(sizeof(node));
	t->v = v;
	t->w = w;
	t->next = NULL;
	return t;
}
void add_edge(list *adj, int u, int v, int w){
	node *t = getnode(v, w);
	if(adj[u].head == NULL){
		adj[u].head = t;
		adj[u].tail = t;
	}
	else{
		(adj[u].tail)->next = t;
		adj[u].tail = t;
	}
	adj[v].indeg += 1;
}
void print_graph(list *adj, int N){
	int i;
	node *t;
	for(i=1; i<=N; i++){
		fprintf(stderr, "%d(%d): ", i, adj[i].indeg);
		for(t=adj[i].head; t!=NULL; t=t->next){
			fprintf(stderr, "%d ", t->v);
		}
		fprintf(stderr, "\n");
	}
}

//Heap
typedef struct{
	int A[MAX];
	int n;
}heap;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int priority(int a, int b){
	return d[a]<=d[b];
}
void heap_init(heap *h){
	h->n = 1;
}
void shuffle_up(heap *h, int n){
	int i;
	for(i=n; i>1; i=(i>>1)){
		if(priority(h->A[i], h->A[i/2])){
			swap(&(h->A[i]), &(h->A[i/2]));
		}
		else
			return;
	}
}
void shuffle_down(heap *h, int i){
	int p;
	while(2*i+1<= h->n){
		p = i;
		if(priority(h->A[2*i], h->A[p]))
			p = 2*i;
		if(2*i+1< h->n && priority(h->A[2*i+1], h->A[p]))
			p = 2*i + 1;
		if(p==i) return;
		swap(&(h->A[p]), &(h->A[i]));
		i=p;
	}


}
int heap_empty(heap *h){
	return (h->n<=1);
}
void heap_insert(heap *h, int x){
	h->A[h->n] = x;
	h->n += 1;
	shuffle_up(h, (h->n)-1);
}
int heap_extract(heap *h){
	int tmp = h->A[1];
	h->A[1] = h->A[h->n-1];
	h->n -= 1;
	shuffle_down(h, 1);
	return tmp;
}
void print_heap(heap *h){
	int i;
	fprintf(stderr, "Heap: ");
	for(i=1; i<h->n; i++)
		fprintf(stderr, "%d ", h->A[i]);
	fprintf(stderr, "\n");
}


void dijkstra(list *adj, int N, int s, int e){
	int v;
	node *t=NULL;
	heap ht, *h = &ht;
	heap_init(h);
	//Set all distances to infinity
	reset(d, N+1, INF);
	//Initialize distance of source to zero
	d[s] = 0;
	heap_insert(h, s);
	while(!heap_empty(h)){
		//print_heap(h);
		v = heap_extract(h);
		if(v==e)
			break;
		for(t=adj[v].head; t!=NULL; t=t->next){
			//If existing distance to t->v greater than that of the path through v
			if(d[t->v] > d[v] + t->w ){
				//Update distance, insert into heap
				d[t->v] = d[v] + t->w;
				heap_insert(h, t->v);
			}
		}
	}

	//Unreachable, distance still not updated
	if(d[e]==INF)
		printf("NO\n");
	else
		printf("%d\n", d[e]);
}
int main(){
	int N, M;
	int u, v, w;
	int i;
	scanf("%d", &N);
	scanf("%d", &M);
	list *adj = gen_adj(N);
	for(i=1; i<=M; i++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(adj, u, v, w);
	}
	//print_graph(adj, N);
	scanf("%d %d", &u, &v);
	dijkstra(adj, N, u, v);
	return 0;
}
