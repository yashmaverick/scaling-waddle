#include <stdio.h>
#include <stdlib.h>
#define MAX ((int)1e6+1)

int P[MAX];
int find(int x){
	if(x==P[x])
		return x;
	P[x] = find(P[x]);
	return P[x];
}
void merge(int x, int y){
	int u, v;
	u = find(x);
	v = find(y);
	P[v] = u;
}

typedef struct{
	int u, v, w;
}edge;
edge S[MAX];

void set_p(int V){
	int i;
	for(i=1; i<=V; i++)
		P[i] = i;
}

int cmp(const void *x, const void *y){
	edge *a, *b;
	a = (edge*)x;
	b = (edge*)y;
	return (a->w - b->w);
}

void debug_edgelist(int N){
	int i;
	fprintf(stderr, "EdgeList:\n");
	for(i=0; i<N; i++)
		fprintf(stderr, "%d %d %d\n", S[i].u, S[i].v, S[i].w);
	fprintf(stderr, "\n");
};

int main(int argc, char *argv[]){
	int V, E, i, count;
	long long W;
	scanf("%d %d", &V, &E);
	set_p(V);
	for(i=0; i<E; i++){
		scanf("%d %d %d", &S[i].u, &S[i].v, &S[i].w);	
		merge(S[i].u, S[i].v);
	}
	int rep = find(1);
	for(i=1; i<=V; i++){
#ifdef DEBUG
		fprintf(stderr, "%d %d\n", find(i), rep);
#endif
		if(find(i)!=rep){
			printf("-1\n");
			return 0;
		}
	}

#ifdef DEBUG
	debug_edgelist(E);
#endif
	set_p(V); //Reset the parent array
	qsort(S, E, sizeof(edge), cmp); //Sort the edge_list

#ifdef DEBUG
	debug_edgelist(E);
#endif
	//Run Kruskals
	count = 0;
	i = 0;
	W = 0;
	while(count < V-1){
		if(find(S[i].v)!=find(S[i].u)){
#ifdef DEBUG
			fprintf(stderr, "Merging %d %d\n", S[i].u, S[i].v);
#endif
			count += 1;
			W += S[i].w;
			merge(S[i].v, S[i].u);
		}
		i++;
	}
	printf("%lld\n", W);
	return 0;
}

