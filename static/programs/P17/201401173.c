#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#define MAX 1000001
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
typedef struct node node;
struct node{
	int val;
	node* next;
};
node* graph[MAX];
int h[MAX];
int pre[MAX],in[MAX],n;
int parent[MAX],visit[MAX];
node* insert(node* head,int x){
	node* t=(node*)malloc(sizeof(node));
	t->val=x;
	t->next=head;
	return t;
}
void edge(int u,int v){
	if(v==-1)
		return;
	graph[u]=insert(graph[u],v);
	graph[v]=insert(graph[v],u);
	return;
}
void mp(int p,int c){
	if(c==-1)
		return;
	parent[c]=p;
	return;
}
void fun(int pl,int ph,int il,int ih){
	if(pl>ph||il>ih)
		return;
	int r=pre[pl];
	int nl=h[r]-il;
	int nr=ih-h[r];
	//if(pl+nl+1>ph)
	//	return;
	int left,right;
	if(nl==0)
		left=-1;
	else
		left=pre[pl+1];
	if(nr==0)
		right=-1;
	else
		right=pre[pl+nl+1];
	//edge(r,left);
	//edge(r,right);
	mp(r,left);
	mp(r,right);
	fun(pl+1,pl+nl,il,il+nl-1);
	fun(pl+nl+1,ph,h[r]+1,ih);
	return;
}
void print(int n){
	int i;
	node* tmp;
	loop(1,n+1){
		tmp=graph[i];
		printf("%d ",i);
		while(tmp!=NULL){
			printf("%d ",tmp->val);
			tmp=tmp->next;
		}
		printf("\n");
	}
	return;
}
void print1(int n){
	int i;
	loop(1,n+1)
		printf("%d:%d ",i,parent[i]);
	return;
}
int lca(int u,int v){
	int x,y;
	SET(visit,0);
	x=u;
	while(parent[x]!=-1){
		visit[x]=1;
		x=parent[x];
	}
	visit[x]=1;
	y=v;
	while(!visit[y])
		y=parent[y];
	return y;
}
int main(){
	int i,t,a,b;
	loop(0,n)
		graph[i]=NULL;
	si(n);
	loop(0,n)
		si(pre[i]);
	loop(0,n){
		si(in[i]);
		h[in[i]]=i;
	}
	fun(0,n-1,0,n-1);
	parent[pre[0]]=-1;
	si(t);
	while(t--){
		si(a);
		si(b);
		sout(lca(a,b));
	}
	return;
	//print1(n);
}
