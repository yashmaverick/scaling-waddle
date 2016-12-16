#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int ver;
	struct node* next;
}node;
node* arr[1000001];
int visited[1000001]={0},lnt,max=-1,finalver;
void dfs(int start){
	//printf("%d\n",lnt);
	//	int i;
	lnt++;
	visited[start]=1;
	if(max<lnt){
		max=lnt;
		finalver=start;
	}
	node* temp;
	//	temp=malloc(sizeof(node));
	temp=arr[start];
	//	if(temp!=NULL)
	//		temp=temp->next;
	while(temp!=NULL){
		if(visited[temp->ver]==0){
			dfs(temp->ver);
			lnt--;
			//	temp=temp->next;
		}
		temp=temp->next;
		//lnt--;
	}
	//lnt--;
	return;
}
int main(){
	int test,z;
	scanf("%d",&test);
	for(z=0;z<test;z++){
		int nodes,b,start;
		scanf("%d",&nodes);
		for(b=0;b<=nodes;b++){
			arr[b]=NULL;
		}
		for(b=1;b<nodes;b++){
			int end;
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
			if(arr[end]==NULL){
				node* temp;
				temp=malloc(sizeof(node));
				arr[end]=temp;
				temp->ver=start;
				temp->next=NULL;
			}
			else{
				node* temp;
				temp=malloc(sizeof(node));
				temp->ver=start;
				temp->next=arr[end];
				arr[end]=temp;
			}
		}
		dfs(start);
		for(b=1;b<=nodes;b++){
			visited[b]=0;
		}
		lnt=0;
		dfs(finalver);
		printf("%d\n",max);
		for(b=0;b<=nodes;b++){
			visited[b]=0;
			arr[b]=NULL;
		}
		max=-1;
		lnt=0;
	}
	return 0;
}
