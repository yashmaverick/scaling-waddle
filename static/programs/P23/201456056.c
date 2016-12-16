#include <stdio.h>
#include <stdlib.h>

#define MAX 1000006

//Graph
typedef struct node_t{
	int v;
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
node *getnode(int v){
	node *t = (node*)malloc(sizeof(node));
	t->v = v;
	t->next = NULL;
	return t;
}
void add_edge(list *adj, int u, int v){
	node *t = getnode(v);
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
	return (a<b);
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
		if(2*i+1 < h->n && priority(h->A[2*i+1], h->A[p]))
			p = 2*i + 1;
		if(p==i) return;
		swap(&(h->A[p]), &(h->A[i]));
		i = p;
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

int main(){
	int N, M;
	int u, v;
	int i;
	node *t = NULL;
	scanf("%d", &N);
	scanf("%d", &M);
	list *adj = gen_adj(N);
	heap ht, *h = &ht;
	heap_init(h);
	for(i=0; i<M; i++){
		scanf("%d %d", &u, &v);
		add_edge(adj, u, v);
	}
	/* 
	 * Find all independant tasks. Add them to the heap
	 * Invariant = Heap contains only independant tasks
	 */
	for(i=1; i<=N; i++){
		if(adj[i].indeg == 0){
			heap_insert(h, i);
		}
	}
	/*
	 * v = Extract minimum from heap
	 * Relax edges directed from v->u
	 * decrease indeg[u] by 1
	 * if indeg[u] becomes zero it no longer depends on any other tasks.
	 */
	while(!heap_empty(h)){
		v = heap_extract(h);
		printf("%d", v);
		for(t=adj[v].head; t!=NULL; t=t->next){
			u = t->v;
			adj[u].indeg -= 1;
			if(adj[u].indeg == 0){
				heap_insert(h, u);
			}
		}

		if(!heap_empty(h))
			printf(" ");
	}
	printf("\n");
	return 0;
}
