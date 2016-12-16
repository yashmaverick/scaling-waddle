#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

int visited[1000000];
//int dist;
int root;
int level[1000000];

typedef struct edge{
	int val;
	struct edge* next;
}edge;

edge* graph[1000000];		//global list

int amax(int a[],int len){
	int i,max=0;
	for(i=1;i<len;i++)
		if(a[i]>a[max])
			max=i;
	return max;		
}

void dfs(int x){
	//root=x;
	//printf("Root is now %d\n",x);
	visited[x]=1;
	//dist++;
	//printf("Dist is %d for %d\n",dist,x);
	edge* temp=graph[x];
	while(temp!=NULL){
		if(visited[temp->val]==0){
			//printf("Function called from %d!\n",temp->val);
			level[temp->val]=level[x]+1;
			dfs(temp->val);
			//printf("Level of %d is %d\n",temp->val,level[temp->val]);
		}
		temp=temp->next;	
	}	
}

int main(){
	int t,i,j,k,n,x,y,ans;
	int m;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<1000000;i++)
			graph[i]=NULL;
		scanf("%d",&n);
		//m=0;
		for(i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			//m=max(m,max(x,y));
			if(graph[x]==NULL){
				graph[x]=(edge*)malloc(sizeof(edge));
				graph[x]->val=y;
				graph[x]->next=NULL;
				//printf("%d <==> %d\n",x,graph[x]->val);
			}
			else{
				edge* temp=graph[x];
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=(edge*)malloc(sizeof(edge));
				temp->next->val=y;
				temp->next->next=NULL;
				//printf("%d <==> %d\n",x,temp->next->val);	
			}
//			edge* temp=graph[x];
//			while(temp!=NULL){
//				printf("%d has edge with %d\n",x,temp->val);
//				temp=temp->next;
//			}
			if(graph[y]==NULL){
				graph[y]=(edge*)malloc(sizeof(edge));
				graph[y]->val=x;
				graph[y]->next=NULL;
				//printf("%d <==> %d\n",y,graph[y]->val);
			}
			else{
				edge* temp=graph[y];
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=(edge*)malloc(sizeof(edge));
				temp->next->val=x;
				temp->next->next=NULL;
				//printf("%d <==> %d\n",y,temp->next->val);
			}
			if(i==0)
				root=x;
//			temp=graph[y];
//			while(temp!=NULL){
//				printf("%d has edge with %d\n",y,temp->val);
//				temp=temp->next;
//			}			
		}
		//printf("Max node is %d\n",m);
		//printf("First root is %d\n",root);
		for(i=0;i<1000000;i++){
			visited[i]=0;
			level[i]=0;		
		}
		//dist=0;
		dfs(root);
		k=amax(level,sizeof(level)/sizeof(level[0]));
		//printf("Farthest node from %d is %d at level %d\n",root,k,level[k]);
		for(i=0;i<1000000;i++){
			visited[i]=0;
			level[i]=0;		
		}
		//ans=dist;
		//dist=0;
		root=k;
		//printf("Second root is %d\n",root);
		dfs(root);
		//ans=dist;
		//ans=amax(level,sizeof(level)/sizeof(level[0]))+1;
		m=0;
		for(i=1;i<sizeof(level)/sizeof(level[0]);i++)
			if(level[i]>level[m])
				m=i;
		ans=level[m]+1;	
		printf("%d\n",ans);
	}
	return 0;
}
