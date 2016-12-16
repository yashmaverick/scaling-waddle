#include<stdio.h>
#include<stdlib.h>
int ans;
int flag2;
int p;
typedef struct node node;
struct node{
	int data;
	node *next;
};
node *head;

struct edge{
	int vertex_index;
	int value;
	struct edge *next;
}edge;


struct vertex{
	int val;
	struct edge *next;
}vertex;

struct vertex list[1009];
int list_count;
struct vertex array[1009];
int vertex_count;

void insert_vertex(int key){
	array[vertex_count].val=key;
	array[vertex_count].next=NULL;
	vertex_count++;
}

void insert_list(int key){
	list[list_count].val=key;
	list[list_count].next=NULL;
	list_count++;
}

node* push(int l,int flag[]){
	struct edge *e;
	int a;
	node *tmp;
	if(flag2==0){
		tmp=(node*)malloc(sizeof(node));
		tmp->data=l;
		tmp->next=NULL;
		flag[l]=1;
		head=tmp;
		flag2=1;
		return head;
	}

	else{
		e=array[l].next;

		while(e){
			tmp=(node*)malloc(sizeof(node));
			tmp->data=e->value;
			tmp->next=NULL;
			if(flag[e->value]==1){
				if(e->next==NULL)
					return;
				else
					e=e->next;
			}
			else{
				if(head==NULL)
				{	
					head=tmp;
					flag[tmp->data]=1;
					e=e->next;
				}
				else{
					tmp->next=head;
					head=tmp;
					flag[tmp->data]=1;
					e=e->next;	
				}
			}
		}
	}
	return;
}

node* push_list(int l,int flag[]){
	struct edge *e;
	int a;
	node *tmp;
	if(flag2==0){
		tmp=(node*)malloc(sizeof(node));
		tmp->data=l;
		tmp->next=NULL;
		flag[l]=1;
		head=tmp;
		flag2=1;
		return head;
	}

	else{
		e=list[l].next;

		while(e){
			tmp=(node*)malloc(sizeof(node));
			tmp->data=e->value;
			tmp->next=NULL;
			if(flag[e->value]==1){
				if(e->next==NULL)
					return;
				else
					e=e->next;
			}
			else{
				if(head==NULL)
				{	
					head=tmp;
					flag[tmp->data]=1;
					e=e->next;
				}
				else{
					tmp->next=head;
					head=tmp;
					flag[tmp->data]=1;
					e=e->next;	
				}
			}
		}
	}
	return;
}

int pop_list(){
	node *var;
	int x;
	x=head->data;
	var=head;
	head=head->next;
	free(var);
	p++;
	return x;
}


int pop(){
	node *var;
	int x;
	x=head->data;
	var=head;
	head=head->next;
	free(var);
	p++;
	return x;
}
void insert_edge(int v1,int v2){
	struct edge *e,*e1,*e2;
	e=array[v1].next;
	while(e && e->next){
		e=e->next;
	}
	
	e1=(struct edge*)malloc(sizeof(struct edge));
	e1->value=v2;
	e1->next=NULL;

	if(e)
		e->next=e1;
	else 
		array[v1].next=e1;

	e=list[v2].next;
while(e && e->next){
	e=e->next;
}

e2=(struct edge*)malloc(sizeof(struct edge));
e2->value=v1;
e2->next=NULL;
if(e)
	e->next=e2;
else
	list[v2].next=e2;
}


int main(){
	int n,test;
	scanf("%d",&test);

while(test--){
	vertex_count=1;
	list_count=1;
	int m,x,y;
	int i,j,k,l;
	int flag[1009];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		insert_vertex(i);
		insert_list(i);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&x);
			insert_edge(x,i);

		}
	}
	//print();
	int visited[1009];
	int count_flag,src;
	
	for(i=1;i<=n;i++){
		flag2=0;
		src=i;
		head=NULL;
		p=0;
		count_flag=0;
		while(p<n){
			push(src,flag);
			if(head==NULL)
				break;
			src=pop();
		}
			count_flag=0;	
		for(j=1;j<=n;j++)
			if(flag[j]==1)
				count_flag+=1;
		
		for(k=1;k<=n;k++)
			flag[k]=0;

		if(count_flag==n){
			ans=i;
			break;
		}
		
	}
visited[ans]=1;
src=ans;
flag2=0;	
	head=NULL;
p=0;
	while(p<n){
		push_list(src,flag);
			if(head==NULL)
				break;
		src=pop_list(flag);
		visited[src]=1;
	}
int final;
final=0;

for(i=1;i<=n;i++)
	if(visited[i]==1)
	final+=1;
	
	printf("%d\n",final);

	for(i=1;i<=n;i++){
	array[i].val=0;
	array[i].next=NULL;
	list[i].val=0;
	list[i].next=NULL;
	visited[i]=0;
	flag[i]=0;
	}
}
	return 0;
}