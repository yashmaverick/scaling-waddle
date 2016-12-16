#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000006

//Global, or problem. WTF, gcc?
int S[MAX], L[MAX];
int vis[MAX];

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


int main(){
	int V, i, T;
	int v=1, u=1;
	list *adj;
	node *t;
	int maxv, maxl=0, l;
	int top;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &V);
		adj = gen_adj(V);
		for(i=1; i<V; i++){
			scanf("%d %d", &u, &v);
			add_edge(adj, u, v);
			add_edge(adj, v, u);
		}
		//Run DFS, then find maxdepth vertex. Run DFS from there, find max depth vertex
		memset(vis, 0, sizeof(int)*(V+1));
		maxl = 0;
		maxv = u;
		top = 0;
		S[top] = u;
		L[top] = 0;
		while(top!=-1){
			u = S[top];
			l = L[top];
			top = top - 1;
			if(l>maxl){
				maxl = l;
				maxv = u;
			}
			vis[u] = 1;
			for(t=adj[u].head; t!=NULL; t=t->next){
				if(!vis[t->v]){
					top = top+1;
					S[top] = t->v;
					L[top] = l+1;
				}
			}
		}

		//Time to DFS again.
		memset(vis, 0, sizeof(int)*(V+1));
		top = 0;
		maxl = 0;
		S[top] = maxv;
		L[top] = 0;
		while(top!=-1){
			u = S[top];
			l = L[top];
			top = top - 1;
			if(l>maxl){
				maxl = l;
				maxv = v;
			}
			vis[u] = 1;
			for(t=adj[u].head; t!=NULL; t=t->next){
				if(!vis[t->v]){
					top = top+1;
					S[top] = t->v;
					L[top] = l+1;
				}
			}
		}
		printf("%d\n", maxl+1);
		destroy_graph(&adj);
	}
	return 0;
}
