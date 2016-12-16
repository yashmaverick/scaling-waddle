#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 200009
#define LL long long int
#define rep(i,n) for(i=1;i<=n;i++)
void in(LL *address){
	scanf("%lld",address);
}
void out(LL *pointer){
	printf("%lld\n",*pointer);
}
typedef struct node{
	LL val;
	LL weight;
	struct node *next;
}node;
node* a[MAX];
void swap(LL *a,LL *b){
	LL temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
LL heap[MAX],dis[MAX],size=0,pos[MAX],par[MAX],ans[MAX];
bool vis[MAX];
void shuffleup(LL pos1){
	LL i=pos1,temp,p;
	while(i>1){
		p=i/2;
		if(dis[heap[p]]>dis[heap[i]]){
			swap(&pos[heap[i]],&pos[heap[p]]);
			swap(&heap[i],&heap[p]);
			i=p;
		}
		else break;
	}
}
void insert(LL value){
	heap[++size]=value;
	pos[value]=size;
	shuffleup(size);
}
void shuffledown(LL pos1){
	LL i=pos1,temp,p;
	while(i<=size/2 && (dis[heap[i]]>dis[heap[2*i]]|| dis[heap[i]]>dis[heap[2*i+1]])){
		if(dis[heap[2*i]]<dis[heap[2*i+1]]) p=2*i;
		else p=2*i+1;
		swap(&pos[heap[i]],&pos[heap[p]]);
		swap(&heap[i],&heap[p]);
		i=p;
	}
}
LL deletemin(){
	LL min=heap[1];
	heap[1]=heap[size--];
	pos[heap[1]]=1;
	shuffledown(1);
	return min;
}
void djik(LL src,LL n){
	LL cur,i,j;
	node *tmp;
	for(i=1;i<=n;i++){
		dis[i]=1000000000;
		vis[i]=0;
	}
	dis[src]=0;
	insert(src);
	vis[src]=1;
	while(size!=0){
		cur=deletemin();
		tmp=a[cur];
		while(tmp!=NULL && tmp->val >0 ){
			if(!vis[tmp->val]){
				dis[tmp->val]=dis[cur]+tmp->weight;
				insert(tmp->val);
				par[tmp->val]=cur;
				vis[tmp->val]=1;
			}
			else if(dis[tmp->val]>dis[cur]+tmp->weight){
				dis[tmp->val]=dis[cur]+tmp->weight;
				par[tmp->val]=cur;
				shuffleup(pos[tmp->val]);
			}
			tmp=tmp->next;
		}
	}
}
int main()
{
	LL n,m,i,x,y,w;
	in(&n);
	in(&m);
	rep(i,n) {
		a[i]=NULL;
		pos[i]=0;
	}
	rep(i,m){
		in(&x);
		in(&y);
		in(&w);
		node *p,*q;
		q=(node *)malloc(sizeof(node));
		q->val=y;
		q->weight=w;
		q->next=a[x];
		a[x]=q;
	}
	in(&x);
	in(&y);
	djik(x,n);
	if(!vis[y])printf("NO\n");
	else out(&dis[y]);
	return 0;
}
