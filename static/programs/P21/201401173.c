//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#define l(x) 2*(x)
#define r(x) 2*(x)+1
#define p(x) (x)/2
#define MAX 100001
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
lli inf=1000000000000000000;
typedef struct vertex{
	int v;
	int d;
	struct vertex* next;
}vertex;
vertex* ins(vertex* head,int v,int c){
	vertex* new=(vertex*)malloc(sizeof(vertex));
	new->v=v;
	new->d=c;
	new->next=head;
	return new;
}
typedef struct node{
	int val;
	int v;
}node;
typedef struct heap{
	int last;
	node* H;
}heap;
int i;
int visited[MAX];
lli dist[MAX];
vertex* graph[MAX];
node mn(int d,int v){
	node n;
	n.val=d;
	n.v=v;
	return n;
}
void swap(node* a,node* b){
	node tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}
heap* make(heap* h,int size){
	h=(heap*)malloc(sizeof(heap));
	h->last=0;
	h->H=(node*)malloc(size*sizeof(node));
	return h;
}
int is_empty(heap* h){
	return h->last==0?1:0;
}
heap* insert(heap* h,node x){
	h->H[++(h->last)]=x;
	int k=h->last;
	while(k!=1&&h->H[k].val<h->H[k/2].val){
		swap(&h->H[k],&h->H[k/2]);
		k=p(k);
	}
	return h;
}
heap* delete(heap* h){
	if(h->last==0)return h;
	h->H[1]=h->H[(h->last)--];
	int k=1,t;
	while(k<=h->last){
		if(l(k)>h->last)break;
		if(r(k)>h->last){
			if(h->H[k].val>h->H[l(k)].val){swap(&h->H[k],&h->H[l(k)]);k=l(k);}
			else break;
		}
		else{
			if(h->H[k].val<h->H[l(k)].val&&h->H[k].val<h->H[r(k)].val)break;
			else{
				t=h->H[l(k)].val<h->H[r(k)].val?l(k):r(k);
				swap(&h->H[k],&h->H[t]);
				k=t;
			}
		}
	}
	return h;
}
node top(heap* h){
return h->H[1];
}
void print(heap* h){
	if(h->last==0)return;
	int i;
	loop(1,h->last+1)
		printf("%d ",h->H[i].val);
	printf("\n");
	return;
}
void dij(int s){
	dist[s]=0;
	heap* h=NULL;
	h=make(h,MAX);
	h=insert(h,mn(dist[s],s));
	while(!is_empty(h)){
		node t=top(h);
		delete(h);
		if(!visited[t.v]){
			visited[t.v]=1;
			vertex* tmp=graph[t.v];
			while(tmp){
				if(dist[t.v]+tmp->d<dist[tmp->v]){
					dist[tmp->v]=dist[t.v]+tmp->d;
					insert(h,mn(dist[tmp->v],tmp->v));
				}
				tmp=tmp->next;
			}
		}
	}
	return;
}
int main(){
	int n,e,u,v,c,src,dest;
	si(n);
	si(e);
	loop(0,MAX){
		free(graph[i]);
		graph[i]=NULL;
	}
	while(e--){
		si(u);
		si(v);
		si(c);
		graph[u]=ins(graph[u],v,c);
		//graph[v]=ins(graph[v],u,c);
	}
	si(src);
	si(dest);
	SET(visited,0);
	loop(1,n+1)dist[i]=inf;
	dij(src);
	lli ans=dist[dest];
	if(ans==inf)
		printf("NO\n");
	else
		printf("%lld\n",ans);
	return 0;
}
