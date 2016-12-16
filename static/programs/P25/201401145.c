#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10009
#define rep(i,n) for(i=1;i<=n;i++)
void in(int *address){
	scanf("%d",address);
}
void out(int *pointer){
	printf("%d\n",*pointer);
}
typedef struct node{
	int val;
	int weight;
	struct node *next;
}node;
node* a[MAX];
int heap[MAX],dis[MAX],size=0,pos[MAX],par[MAX];
bool vis[MAX];
void shuffleup(int pos1){
	int i=pos1,temp,p;
	while(i>1){
		p=i/2;
		if(dis[heap[p]]>dis[heap[i]]){
			temp=pos[heap[i]];
			pos[heap[i]]=pos[heap[p]];
			pos[heap[p]]=temp;
			temp=heap[i];
			heap[i]=heap[p];
			heap[p]=temp;
			i=p;
		}
		else break;
	}
}
void insert(int value){
	heap[++size]=value;
	pos[value]=size;
	shuffleup(size);
}
void shuffledown(int pos1){
	int i=pos1,temp,p;
	while(i<=size/2 && (dis[heap[i]]>dis[heap[2*i]]|| dis[heap[i]]>dis[heap[2*i+1]])){
		if(dis[heap[2*i]]<dis[heap[2*i+1]]) p=2*i;
		else p=2*i+1;
		temp=pos[heap[i]];
		pos[heap[i]]=pos[heap[p]];
		pos[heap[p]]=temp;
		temp=heap[i];
		heap[i]=heap[p];
		heap[p]=temp;
		i=p;	
	}
}
int deletemin(){
	int min=heap[1];
	heap[1]=heap[size--];
	pos[heap[1]]=1;
	shuffledown(1);
	return min;
}
void dfs(int src){
	node *tmp=a[src];
	vis[src]=1;
	while(tmp!=NULL){
		if(!vis[tmp->val])
			dfs(tmp->val);
		tmp=tmp->next;
	}
}
void prim(int src,int n){
	int cur,i,j;
	node *tmp;
	for(i=1;i<=n;i++){
		dis[i]=100000000;
		heap[i]=i;
		vis[i]=0;
		pos[i]=i;
		par[i]=0;
	}
	size=n;
	dis[1]=0;
	while(size!=0){
		cur=deletemin();
		vis[cur]=1;
		tmp=a[cur];
		while(tmp!=NULL){
			if(!vis[tmp->val] && dis[tmp->val]>tmp->weight){
				dis[tmp->val]=tmp->weight;
				par[tmp->val]=cur;
				shuffleup(pos[tmp->val]);
			}
			tmp=tmp->next;
		}
	}
}
int main(){
	int n,m,i,x,y,w,ans=0,no=-1;
	bool state=0;
	in(&n);
	in(&m);
	rep(i,n) a[i]=NULL;
	rep(i,m){
		in(&x);
		in(&y);
		in(&w);
		node *p,*q;
		p=(node *)malloc(sizeof(node));
		p->val=x;
		p->weight=w;
		p->next=a[y];
		a[y]=p;
		q=(node *)malloc(sizeof(node));
		q->val=y;
		q->weight=w;
		q->next=a[x];
		a[x]=q;
	}
	rep(i,n)vis[i]=0;
	dfs(1);
	rep(i,n)if(!vis[i])state=1;
	if(!state){
		rep(i,n)vis[i]=0;
		prim(1,n);
		rep(i,n)ans+=dis[i];
		out(&ans);
	}
	else out(&no);
	return 0;
}
