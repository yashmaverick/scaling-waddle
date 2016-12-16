#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    int weight;
    struct node* next;
};

typedef struct set{
	int parent;
	int rank;
}set;

typedef struct jugaad{
	int x,y;
	long long int w;
}jugaad;

struct node **A;
jugaad *G;
set *s;
int *visited;
int *stack;
int pte;

void push(int *stack, int value) {
	stack[pte++] = value;
}
int pop(int *stack) {
	return stack[--pte];
}
int isEmpty(int *stack) {
	if(pte == 0)
		return 1;
	return 0;
}
int peek(int *stack) {
	return stack[pte-1];
}


struct node* insert(struct node* root,int n,int w)
{
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->val=n;
    temp->weight=w;
    temp->next=root;
    return temp;
}

void make_set(set *s,int x) {
	s[x].parent = x;
	s[x].rank = 0;
}

int find_set(set *s,int x) {
	if(s[x].parent != x)
		s[x].parent = find_set(s,s[x].parent);
	return s[x].parent;
}

void union_set(set *s,int x,int y) {
	int xroot = find_set(s,x);
	int yroot = find_set(s,y);
	if (xroot == yroot) {
		return;
	}
	if(s[xroot].rank > s[yroot].rank) {
		s[yroot].parent = xroot;
	}
	else if(s[yroot].rank > s[xroot].rank) {
		s[xroot].parent = yroot;
	}
	else {
		s[yroot].parent = xroot;
		s[xroot].rank++;
	}
}

int cmpfnc(const void *a,const void *b)
{
	jugaad l = *(jugaad *)a;
	jugaad m = *(jugaad *)b;
	return l.w > m.w;
}

void kruskal(jugaad G[],int V,int E) 
{
	int i;	
	for(i=1;i<=V;i++) {
		make_set(s,i);
	}
	qsort(G,E,sizeof(jugaad),cmpfnc);
	for(i=0;i<E;i++)
	{
		if(find_set(s,G[i].x) != find_set(s,G[i].y))
		{
				A[G[i].x] = insert(A[G[i].x],G[i].y,G[i].w);
				A[G[i].y] = insert(A[G[i].y],G[i].x,G[i].w);
				union_set(s,G[i].x,G[i].y);
		}
	}
}

long long int dfs_sum(struct node **A,int V) 
{
	int vertex;
	long long int sum = 0;
	while(isEmpty(stack) == 0) 
	{
		vertex = pop(stack);
		visited[vertex - 1] = 1;
		struct node* tmp=A[vertex];
		while(tmp!= NULL)
		{
			if(visited[tmp->val - 1] == 0) 
			{
				sum += tmp->weight; 
				push(stack,tmp->val);
				visited[tmp->val - 1] = 2;
			}
			tmp=tmp->next;
		}
	}
	return sum;
}

long long int connected_sum(struct node **A,int V,int *visited) 
{
	int i;
	visited[0] = 2;
	push(stack,1);
	long long int sum = dfs_sum(A,V);
	for(i=1;i<=V;i++) {
		if(visited[i-1] == 0){
			return -1;
		}
	}
	return sum;
}

int main(){
	int N,M;
	int i,x,y;
	long long int w;
	scanf("%d%d",&N,&M);
	
	G = (jugaad *)malloc(sizeof(jugaad)*M);
	A = (struct node **)malloc(sizeof(struct node *)*(N+1));
	s = (set *)malloc(sizeof(set)*(N+1));
	visited = (int *)malloc(sizeof(int)*N+1);
	stack = (int *)malloc(sizeof(int)*N+1);
	pte = 0;
	
	for(i=1;i<=N;i++) {
		A[i] = NULL;
	}
	
	for(i=0;i<M;i++) {
		scanf("%d%d%lld",&x,&y,&w);
		G[i].x = x;
		G[i].y = y;
		G[i].w = w;
	}
	
	kruskal(G,N,M);
	
	printf("%lld\n",connected_sum(A,N,visited));
	
	return 0;
}
