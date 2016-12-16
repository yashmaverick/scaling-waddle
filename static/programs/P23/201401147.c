#include<stdio.h>// DFS code from lab
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct node{
	int v;
	struct node *next;
}node;
long long int N;
node * insert(node *x,int v){
	node *y;
	y=malloc(sizeof(node));
	y->v=v;
	y->next=x;
	return y;
}
int stack[100005];
int rear=0;
node *a[100005];
bool visit[100005];
void printstack(){
	int i;
	for(i=rear;i>=2;i--)
		printf("%d ",stack[i]);
	printf("%d\n",stack[1]);
	return ;
}
void dfsprint(int v){
	//printf("v is %d\n",v);
	node *temp;
	temp=a[v];
	visit[v]=1;
	//printf("%d\t",v);
	while(temp!=NULL){
		//	printf("hello\n");
		if(!visit[temp->v])
			dfsprint(temp->v);
		temp=temp->next;
	}
	stack[++rear]=v;
	return ;
}	
void print(){
	int i;
	for(i=0;i<N;i++){
		printf("%d\t",i);
		node *temp=a[i];
		while(temp!=NULL){
			printf("%d\t",temp->v);
			temp=temp->next;
		}
		printf("\n");
	}
	return ;
}
int main()
{
	int x,y,i;
	long long int M;
	scanf("%lld%lld",&N,&M);
	for(i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		a[x]=insert(a[x],y);
	}
	//print();
	memset(visit,0,sizeof(visit));
	for(i=N;i>=1;i--){
		if(!visit[i])
			dfsprint(i);
	}
	printstack();
	return 0;
}
