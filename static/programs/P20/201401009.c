#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct adj{
	node *head;
}adj;

adj *arr;
int *visit;

void newedge(adj *ar,int s,int d){
	node* temp=(node *)malloc(sizeof(node));
	temp->data=d;
	temp->next=ar[s].head;
	ar[s].head=temp;
}

void print(adj *ar,int n){
	int i;
	node *temp;
	temp=(node *)malloc(sizeof(node));
	for(i=1;i<n;i++){
		temp=ar[i].head;
		printf("%d-->",i);
		while(temp){
			printf("%d-",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int maxheight=0,maxheight1=0,j;

void dfs1(adj *ar,int s,int visit[],int height){
	int i;
  //  printf("%d-%d--",s,height);
//    printf("b-");
	visit[s]=1;
	if(maxheight1<height){
		maxheight1=height;
		j=s;
	}
	node* temp=(node *)malloc(sizeof(node));
  //  printf("a-");
	temp=ar[s].head;
    //printf("%d-",temp->data);
	while(temp){
      //      printf("%d-%d ",temp->data,visit[temp->data]);
		if(visit[temp->data]==0){
			dfs1(ar,temp->data,visit,height+1);
		}
//		else{
//			return ;
//		}
		temp=temp->next;
		if(maxheight1<height){
			maxheight1=height;
			j=s;
		}
	}
	if(maxheight1<height){
		maxheight1=height;
		j=s;
	}
	return ;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
	    maxheight=0;
        maxheight1=0;
        int n,i;
		scanf("%d",&n);
		arr=(adj *)malloc((n+1)*(sizeof(adj)));
		visit=(int *)malloc((n+1)*(sizeof(int)));
		for(i=0;i<=n;i++){
			arr[i].head=NULL;
			visit[i]=0;
		}
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			newedge(arr,a,b);
			newedge(arr,b,a);
		}
		dfs1(arr,1,visit,1);
		//printf("%d %d\n",maxheight,j);
		for(i=1;i<=n;i++){
		//	printf("%d--",visit[i]);
			visit[i]=0;
          //  printf("%d--",visit[i]);
		}
       // printf("\n");
		dfs1(arr,j,visit,1);
//		print(arr,n);
		printf("%d\n",maxheight1);
	}
	return 0;
}
