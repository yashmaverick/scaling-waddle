#include <stdio.h>
#include <stdlib.h>

#define MAX 1010
#define MAXN ((int)2e6)

struct node_t{
    int v, c;
};

int P[MAX], dn, R[MAX];

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
	if(R[u]==R[v]){
		R[u] = R[v]+1;
		P[v] = u;
	}
	else if(R[u]>R[v]){
		P[v] = u;
	}
	else{
		P[u] = v;
	}
}
void reset_p(int *A, int n){
	int i;
	for(i=0; i<n; i++)
		A[i] = i;
}
void reset_v(int *A, int n, int v){
	int i;
	for(i=0; i<n; i++)
		A[i] = v;
}

typedef struct node_t node;
node adj[MAX],list[MAXN];
int n, in;
node adjinv[MAX], listinv[MAXN];

void insert(node *adj, node *list, int u, int v, int *x){
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
	*x = n;
}
void print_adj_list(node *adj, node *list, int N){
    int i, j;
    for(i=1; i<=N; i++){
        fprintf(stderr, "%d: ", i);
        for(j=adj[i].v; j!=0; j=list[j].c){
            fprintf(stderr, "%d ", list[j].v);
        }
        fprintf(stderr, "\n");
    }
}
void debug_stack(int *S, int n){
	int i;
	fprintf(stderr, "Stack: ");
	for(i=0; i<n; i++){
		fprintf(stderr, "%d ", S[i]);
	}
	fprintf(stderr, "\n");
}

void dfs(int x, int *vis, int *P, int *p){
	vis[x] = 1;
	int i, u;
	for(i=adj[x].v; i!=0; i=list[i].c){
		u = list[i].v;
		if(!vis[u]){
			dfs(u, vis, P, p);
		}
	}
	*p = *p + 1;
	P[*p] = x;
}
void reset_graph(int V){
	int i;
	for(i=0; i<=V; i++){
		adj[i].v = 0;
		adjinv[i].v = 0;
		adj[i].c = 0;
		adjinv[i].c = 0;
	}
	n = 0;
	in = 0;
}
int kosaraju(int V){
	int S[MAX], s=-1, svis[MAX]={0};
	int P[MAX], p=-1, pvis[MAX]={0};
	int count[MAX]={0};
	int root;
	int i, u, x, v;
	for(i=1; i<=V; i++){
		if(!svis[i]){
			dfs(i, svis, P, &p);
		}
	}
	reset_v(svis, V+1, 0);
	s = -1;
	root = P[p];
	dfs(root, svis, S, &s);
	for(i=1; i<=V; i++){
		if(!svis[i])
			return 0;
	}
	//Generate inverse graph
	for(i=1; i<=V; i++){
		for(x=adj[i].v; x!=0; x=list[x].c){
			insert(adjinv, listinv, list[x].v, i, &in);
		}
	}
	//Run DFS on inverse, merge set
	s = -1;
	while(p>=0){
		x = P[p--];
		if(!pvis[x]){
			S[++s] = x;
			pvis[x] = 1;
			while(s>=0){
				v = S[s--];
				for(i=adjinv[v].v; i!=0; i=listinv[i].c){
					u = listinv[i].v;
					if(!pvis[u]){
						merge(x, u);
						count[find(x)] += 1;
						S[++s] = u;
					}
					pvis[u] = 1;
				}
			}
		}
	}

	return count[find(root)]+1;
}




int main(int argc, char *argv[]){
	int V, v, m, u, T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &V);
		reset_graph(V);
		reset_p(P, V+1);
		reset_v(R, V+1, 0);
		for(v=1; v<=V; v++){
			scanf("%d", &m);
			while(m--){
				scanf("%d", &u);
				insert(adj, list, u, v, &n);
			}
		}
		printf("%d\n", kosaraju(V));
	}
	return 0;
}
