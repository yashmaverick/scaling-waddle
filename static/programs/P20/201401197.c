#include<stdio.h>
#include<stdlib.h>

struct list{
	int val;
	struct list *next;
};

void freelist(int);
void pushin(int,int);
void dfs(int,int);
struct list *adj[1000006];
char vis[1000006],set;
int maxdist,thatnode;
int main(){
	int t,n,i,j,k;
	for(i=0;i<1000006;i++){
		adj[i]=NULL;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			vis[i]=0;
			freelist(i);
		}
		for(i=1;i<n;i++){
			scanf("%d %d",&j,&k);
			j--;k--;
			pushin(j,k);
			pushin(k,j);
		}
		maxdist=0;thatnode=0;
		set=1;
		dfs(0,0);
		set=2;
		maxdist=0;
		dfs(thatnode,0);
		printf("%d\n",maxdist+1);
	}
	return 0;
}

void freelist(int ind){
	struct list *todel;
	while(adj[ind]!=NULL){
		todel=adj[ind];
		adj[ind]=todel->next;
		free(todel);
	}
}

void pushin(int ind,int val){
	struct list *temp;
	temp=adj[ind];
	adj[ind]=(struct list *)malloc(sizeof(struct list));
	adj[ind]->val=val;
	adj[ind]->next=temp;
}

void dfs(int now,int dep){
	struct list *temp;
	if(vis[now]==set){
		return ;
	}
	vis[now]=set;
	if(dep>maxdist){
		thatnode=now;
		maxdist=dep;
	}
	temp=adj[now];
	dep++;
	while(temp!=NULL){
		dfs(temp->val,dep);
		temp=temp->next;
	}
}
