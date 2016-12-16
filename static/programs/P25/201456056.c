#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int v[MAX], u[MAX], w[MAX];
int I[MAX];

int compare(const void *a, const void *b){
	return w[*(int*)a]-w[*(int*)b];
}


struct dsd_t{
    int *P, *R;
	int N;
};
typedef struct dsd_t dsd;
void init(dsd *d, int N){
    int i;
	d->N = N;
    d->P = (int*)malloc(sizeof(int)*(N+2));
    d->R = (int*)malloc(sizeof(int)*(N+2));
    for(i=1; i<=N; i++){
        d->P[i] = i;
        d->R[i] = 0;
    }
}
int find(dsd *d, int x){
    if(d->P[x]==x)
        return x;
	d->P[x] = find(d, d->P[x]);
    return d->P[x];
}
void merge(dsd *d, int x, int y){
    int u, v;
    u = find(d, x);
    v = find(d, y);
	if(u==v)
		return;
    if(d->R[v]==d->R[u]){
        d->R[u] = d->R[v]+1;
        d->P[v] = u;
    }
	else if(d->R[v]>d->R[u]){
		d->P[u] = v;
	}
    else{
        d->P[v] = u;
    }
}



int main(){
	int V, E, i, c, j;
	long long min_weight = 0;
	dsd DP, *D=&DP;
	scanf("%d %d", &V, &E);
	init(D, V);
	for(i=0; i<E; i++)
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	for(i=0; i<E; i++)
		I[i] = i;
	qsort(I, E, sizeof(int), compare);
	c = 0;
	for(i=0; i<E; i++){
		j = I[i];
		if(find(D, v[j])!=find(D, u[j])){
			merge(D, v[j], u[j]);
			c += 1;
			min_weight += w[j];
			if(c==V-1)
				break;
		}
	}
	if(c!=V-1)
		printf("-1\n");
	else
		printf("%lld\n", min_weight);
	return 0;
}
