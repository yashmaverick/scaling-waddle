//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000001
typedef long long int lli;
int i,k;
typedef struct node{
	int val;
	struct node* next;
}node;
node* graph[MAX];
node* insert(node* head,int x){
	node* t=(node*)malloc(sizeof(node));
	t->val=x;
	t->next=head;
	return t;
}
int visited[MAX],dist[MAX],n;
void bfs(int u){
	dist[u]=0;
	visited[u]=1;
	int tail=-1,head=0,q[MAX];
	q[++tail]=u;
	while(!(head>tail)){
		int t=q[head];
		head++;
		node* tmp=graph[t];
		while(tmp!=NULL){
			if(!visited[tmp->val]){
				dist[tmp->val]=dist[t]+1;
				k=tmp->val;
				q[++tail]=tmp->val;
				visited[tmp->val]=1;
			}
			tmp=tmp->next;
		}
	}
	return;
}
int diameter(int root){
	SET(visited,0);
	//dist[0]=0;
	bfs(root);
	int m=k;
	k=0;
	SET(visited,0);
	dist[m]=0;
	bfs(m);
	return dist[k];
}
int main(){
	int t;
	si(t);
	while(t--){
		loop(0,MAX) graph[i]=NULL;
		int m,u,v,root;
		SET(visited,0);
		si(n);
		m=n-1;
		while(m--){
			si(u);
			si(v);
			graph[u]=insert(graph[u],v);
			graph[v]=insert(graph[v],u);
		}
		sout(diameter(1)+1);
	}
	return 0;
}
