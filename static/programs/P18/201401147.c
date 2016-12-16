#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int v;
	struct node * next;
}node;
int stack[1000];
node *a[1001];
node *b[1001];
int N;
bool visit[1001];
int rear;
int dfs(int i,int flag){
	memset(visit,0,sizeof(visit));
	visit[i]=1;
	rear=-1;
	node *temp;
	int count=0;
	stack[++rear]=i;
	while(rear!=-1){
		if(flag)
			temp=a[stack[rear]];
		else
			temp=b[stack[rear]];
		rear--;
		while(temp!=NULL){
			if(!visit[temp->v]){
				visit[temp->v]=1;
				stack[++rear]=temp->v;
				count++;
			}
			temp=temp->next;
		}
	}
	return count;
}
node *insert(node *root,int v){
	node *p=malloc(sizeof(node));
	p->v=v;
	p->next=root;
	return p;
}
/*void print(node **x){
  int i;
  for(i=1;i<=N;i++){
  printf("%d\t",i);
  node *temp=x[i];
  while(temp!=NULL){
  printf("%d\t",temp->v);
  temp=temp->next;
  }		
  printf("\n");
  }


  }*/
int main()
{
	int t,realmcount=0,temp,i,j;
	scanf("%d",&t);
	while(t--){
		for(i=1;i<=1001;i++){
			a[i]=NULL;
			b[i]=NULL;
		}
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			int M,x;
			scanf("%d",&M);
			for(j=0;j<M;j++){
				scanf("%d",&x);
				a[x]=insert(a[x],i);// a[x] contains members weaker than x
				b[i]=insert(b[i],x);// b[i] contains members stronger than i
			}
		}
		//print(a);
		//print(b);
		for(i=1;i<=N;i++){
			temp=dfs(i,1);
			if(temp==N-1)
				break;//realmcount++;//break;
		}
		realmcount=0;
		if(i!=N+1)
		{	
		realmcount=dfs(i,0);
		realmcount++;
		}
		printf("%d\n",realmcount);
	}
}
