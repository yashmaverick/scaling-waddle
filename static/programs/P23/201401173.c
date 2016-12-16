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
#define MAX 100005
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
typedef struct vert{
	int val;
	struct vert* next;
}vert;
vert* ins(vert* head,int x){
	vert* new=(vert*)malloc(sizeof(vert));
	new->val=x;
	new->next=head;
	return new;
}
vert* graph[MAX];
int deg[MAX];
typedef struct node{
	int val;
}node;
typedef struct heap{
	int last;
	node* H;
}heap;
node mn(int x){
	node n;
	n.val=x;return n;
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
int top(heap* h){
return h->H[1].val;
}
void print(heap* h){
	if(h->last==0)return;
	int i;
	loop(1,h->last+1)
		printf("%d ",h->H[i].val);
	printf("\n");
	return;
}
void topo(int a[],int n){
	int i,k=0;
	heap* h=NULL;
	h=make(h,MAX);
	loop(1,n+1){if(deg[i]==0){h=insert(h,mn(i));}}
	while(!is_empty(h)){
		int t=top(h);
		a[++k]=t;
		h=delete(h);
		vert* temp=graph[t];
		while(temp){
			deg[temp->val]--;
			if(deg[temp->val]==0)h=insert(h,mn(temp->val));
			temp=temp->next;
		}
	}
	return;
}
int main(){
	int i;
	int n,m,u,v;
	SET(deg,0);
	loop(0,MAX){
		free(graph[i]);
		graph[i]=NULL;
	}
	int order[MAX];
	si(n);
	si(m);
	while(m--){
		si(u);
		si(v);
		graph[u]=ins(graph[u],v);
		deg[v]++;
	}
	topo(order,n);
	loop(1,n)printf("%d ",order[i]);
	printf("%d\n",order[n]);
	return 0;
}
