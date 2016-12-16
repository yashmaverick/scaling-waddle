#include<stdio.h>
#include<stdlib.h>

struct link{
	int data;
	struct link *next;
}*head[1000001];

typedef struct link link;

link *head[1000001];
int visited[1000001];
int h,max_num,max;

void dfs(int val);
void insert(int s,int v);
void print_list(link *s);

int main(){
	int t,n,v,e,i,j,w;
	scanf("%d",&t);
	while(t--){
		max=0;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			head[i]=NULL;
		for(i=1;i<n;i++){
			scanf("%d %d",&v,&w);
				insert(v,w);
			insert(w,v);
		}
		for(i=0;i<=n;i++){
			visited[i]=0;
		}
		h=1;
		max=1;
		max_num=1;
		dfs(1);
//		printf("\n");
//		printf("length:%d deepest num=%d\n",max,max_num);

		for(i=0;i<=n;i++){
			visited[i]=0;
		}
		h=1;
		max=1;
		dfs(max_num);
//		printf("\n");
//		printf("length:%d deepest num=%d\n",max,max_num);
		printf("%d\n",max);

	}
	return 0;
}

void dfs(int val){
link *temp=NULL;
	visited[val]=1;
	//printf("%d ",val);

	temp = head[val];
	while(temp!=NULL){
		if(visited[temp->data]==0){
			h++;
			if(h > max){
				max = h;
				max_num=temp->data;
				}
			dfs(temp->data);
			}
		temp=temp->next;
	}
	h--;
}

void insert(int s,int v){
	link *temp,*t;
	temp=malloc(sizeof(link));
	temp->data=v;
	temp->next=NULL;
	if(head[s]==NULL)
		head[s]=temp;
	else{
		t=((head[s])->next);
		temp->next=t;
		((head[s])->next)=temp;		
	}
}

void print_list(link *d){
	if(d==NULL)
		return;
	else{
		printf("%d ",d->data);
		print_list(d->next);	
	}
}
