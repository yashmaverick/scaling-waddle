#include <stdio.h>
#include <stdlib.h>

#define MS 10006
#define INF ((int)1e7)
struct node_t{
	int v, c;
};
typedef struct node_t node;

int sieve[MS];
node adj[MS],list[MS], heap[MS];
int d[MS], vis[MS], pv[MS];
int n, pn, h;

void reset_d(){
	int i;
	for(i=0; i<MS; i++)
		d[i] = INF;
}

//Graph functions
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
	int i, j, k;
	for(k=0; k<pn; k++){
		i = pv[k];
		fprintf(stderr, "%d: ", i);
		for(j=adj[i].v; j!=0; j=list[j].c){
			fprintf(stderr, "%d ", list[j].v);
		}
		fprintf(stderr, "\n");
	}
}
void add_edges(int x){
	if(vis[x])
		return;
	vis[x] = 1;
	int i, tmp=x, j;
	for(j=1; j<=1000; j *= 10){
		i = tmp%10;
		while(i>0){
			if(x-(i*j) > 1000 && !sieve[x-i*j] ){
				insert(x, x-i*j);
				insert(x-i*j, x);
				add_edges(x-i*j);
			}
			i--;
		}
		tmp = tmp/10;
	}
}
void gen_graph(){
	int i;
	for(i=pn-1; i>=0; i--){
		add_edges(pv[i]);
	}
}

//Sieve Functions
void print_sieve(){
	int i;
	for(i=2; i<MS; i++){
		if(!sieve[i]){
			fprintf(stderr, "%d ", i);
		}
	}
	fprintf(stderr, "\n");
}
void gen_sieve(){
	int i,  j; 
	pn = 0;
	sieve[0] = 1;
	sieve[1] = 1;
	for(i=2; i*i < MS; i++){
		if(!sieve[i]){
			for(j=i*i; j<MS; j+=i){
				sieve[j] = 1;
			}
		}
	}
	for(i=2; i < MS; i++){
		if(!sieve[i]){
			pv[pn++] = i;
		}
	}

}
void debug_sieve(){
	int i;
	for(i=0; i<pn; i++){
		fprintf(stderr, "%d ", pv[i]);
	}
	fprintf(stderr, "\n");
}

//Heap functions
int compare(const node *a, const node *b){
    return (a->c<b->c);
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
    heap[h].c = INF;
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
        fprintf(stderr, "(%d, %d)", heap[i].v, heap[i].c);
    }
    fprintf(stderr, "\n");
}

int sssp(int s, int e){
	reset_d();
	int i, u;
	node x;
	h = 0;
	d[s] = 0;
	heap_insert((node){s, 0});
	while(h>0){
		x = heap_extract();
		if(x.v==e)
			return d[e];
		for(i=adj[x.v].v; i!=0; i=list[i].c){
			u = list[i].v;
			if(d[x.v]+1<d[u]){
				d[u] = d[x.v]+1;
				heap_insert((node){u, d[u]});
			}
		}
		//traverse x
	}
	return d[e];
}

int main(int argc, char *argv[]){
	int s, e, T, res;
	gen_sieve();
	gen_graph();
#ifdef DEBUG
	//print_sieve();
	//debug_sieve();
	print_adj_list(MS-1);
	fprintf(stderr, "%d\n", pn);
	fprintf(stderr, "%d\n", sssp(1033, 8179));
#endif

	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &s, &e);
		res = sssp(s,e);
		if(res!=INF)
			printf("%d\n", res);
		else
			printf("Impossible\n");
	}
	return 0;
}
