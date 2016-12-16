#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct node{
	int v;
	struct node * next;
}node;
node * a[1000005];
int N;
node * insert(node *root,int v){
	node *p=malloc(sizeof(node));
	p->v=v;
	p->next=root;
	return p;
}
void print(){
	int i;
	node *tempnode;
	for(i=1;i<=N;i++){
		printf("%d\t",i);
		tempnode=a[i];
		while(tempnode!=NULL){
			printf("%d\t",tempnode->v);
			tempnode=tempnode->next;
		}
		printf("\n");
	}

}
int stack[1000005];
int dist[1000005];
bool visit[1000005];
int rear=-1;
int dfs(int src,int flag){
	rear=-1;
	memset(dist,-1,sizeof(dist));
	memset(visit,0,sizeof(visit));
	stack[++rear]=src;
	visit[src]=1;
	dist[src]=0;
	int temp=0;
	int x;
	int vertex=src;
	node * tempnode;
	while(rear!=-1){
		tempnode=a[stack[rear]];
		x=stack[rear];
		rear--;
		while(tempnode!=NULL){
			if(!visit[tempnode->v]){
				visit[tempnode->v]=1;
				stack[++rear]=tempnode->v;
				dist[tempnode->v]=dist[x]+1;
				if(temp<dist[tempnode->v]){
					temp=dist[tempnode->v];	
					vertex=tempnode->v;
				}
			}
			tempnode=tempnode->next;
		}

	}
	if(flag)
		return vertex;
	else
		return temp;
}
int main()
{
	int t,x,y,i,abc=0,temp;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<1000005;i++)
			a[i]=NULL;
		scanf("%d",&N);
		for(i=1;i<N;i++){
			scanf("%d%d",&x,&y);
			a[x]=insert(a[x],y);
			a[y]=insert(a[y],x);
		}
		//print();
		abc=dfs(1,1);
		printf("%d\n",dfs(abc,0)+1);
	}
	return 0;
}
