/*
 * p20.c
 * 2015 umeshksingla <umeshksingla@umeshksingla-SVF15215SNW>
 * MIT license.
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct node{
	int d;
	struct node*next;
};
typedef struct node node;

int visited[1000005]={0};
node*head[1000005]={NULL};

void insert(int x,int y){
	node*temp=NULL;
	if(head[x]==NULL){
		head[x]=(node*)malloc(sizeof(node));
		head[x]->d=y;
		head[x]->next=NULL;
		return;
	}
	temp=(node*)malloc(sizeof(node));
	temp->d=y;
	temp->next=head[x];
	head[x]=temp;
	return;	
}
/*
void print(int x){
	node*temp=head[x];
	while(temp!=NULL){
		printf(" %d",temp->d);
		temp=temp->next;
	}
	printf("\n");
	return;
}*/
int max=0;
int last;
void dfs(int e,int h){
	if(visited[e]!=1){
		if(max<h){
			last=e;
			max=h;
		}
//		printf("e=%d h=%d\n",e,h);
		visited[e]=1;
		node *temp=head[e];
		while(temp!=NULL){
			dfs(temp->d,h+1);
			temp=temp->next;
		}
	}
	else
		return;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j,k,n,u,v;
		scanf("%d",&n);
		n--;
		while(n--){
			scanf("%d%d",&u,&v);
			insert(u,v);
			insert(v,u);
		}
//		for(i=0;i<1000005;i++)
//			if(head[i]!=NULL)
//				print(i);
//		printf("\ndfs\n");
		dfs(1,1);
//		printf("\nmax = %d last = %d\n",max,last);
		for(i=0;i<1000005;i++)
			visited[i]=0;
//		printf("\ndfs\n");
		max=0;
		dfs(last,1);
//		printf("\nmax = %d last = %d\n",max,last);
		printf("%d\n",max);
		for(i=0;i<1000005;i++){
			head[i]=NULL;
			visited[i]=0;
		}
		max=0;
	}
	return 0;
}
