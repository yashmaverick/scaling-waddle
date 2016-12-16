#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int ver;
	struct node* next;
}node;
node* arr[1000001];
int visited[1000001],lnt=0,ans[1000001];
void push(int j){
	ans[lnt]=j;
	lnt++;
}
void dfs(int start){
	visited[start]=1;
	node* temp;
	temp=arr[start];
//	int j;
	//j=temp->ver;
	while(temp!=NULL){
	//		j=temp->ver;
		if(visited[temp->ver]==0){
			dfs(temp->ver);
	//		j=temp->ver;
		}
		temp=temp->next;
	}
//	printf("%d\n",start);
	push(start);
}
int main(){
	int nodes,b,tasks;
	scanf("%d %d",&nodes,&tasks);
	for(b=1;b<=nodes;b++){
		arr[b]=NULL;
	}
	for(b=0;b<tasks;b++){
		int start,end;
		scanf("%d %d",&start,&end);
		if(arr[start]==NULL){
			node* temp;
			temp=malloc(sizeof(node));
			arr[start]=temp;
			temp->ver=end;
			temp->next=NULL;
		}
		else{
			node* temp;
			temp=malloc(sizeof(node));
			temp->ver=end;
			temp->next=arr[start];
			arr[start]=temp;
		}
	}
	for(b=nodes;b>=1;b--){
		if(visited[b]==0)
			dfs(b);
	}
	for(b=lnt-1;b>=0;b--){
		if(b!=0)
			printf("%d ",ans[b]);
		else
			printf("%d\n",ans[b]);
	}
	return 0;
}
