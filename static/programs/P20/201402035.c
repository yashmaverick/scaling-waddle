#include<stdio.h>
#include<stdlib.h>
int flag2;
int flag1;
int length[1000000];
int last[1000000];
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

struct vertex array[1000000];
int vertex_count=1;

void insert_vertex(int key){
array[vertex_count].val=key;
array[vertex_count].next=NULL;
vertex_count++;
}

void insert_edge(int v1,int v2){
struct edge *e,*e1,*e2;
e=array[v1].next;
while(e && e->next)
{
e=e->next;
}
e1=(struct edge*)malloc(sizeof(struct edge));
e1->value=v2;
e1->next=NULL;

if(e)
	e->next=e1;
else 
	array[v1].next=e1;

e=array[v2].next;
while(e && e->next)
	e=e->next;

e2=(struct edge*)malloc(sizeof(struct edge));
e2->value=v1;
e2->next=NULL;
if(e)
	e->next=e2;
else
	array[v2].next=e2;
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
	last[l]=0;
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
		last[tmp->data]=l;
		flag[tmp->data]=1;
		e=e->next;
	}
else{
tmp->next=head;
head=tmp;
last[tmp->data]=l;
flag[tmp->data]=1;
e=e->next;	
		}
	}
}
}
return;
}

int pop(int flag[]){
	node *var;
	int x;
	x=head->data;
	var=head;
	head=head->next;
	free(var);
		p++;
		return x;
}

/*void print(){

int i;
struct edge *e;
for(i=1;i<vertex_count;i++){
	printf("(%d)",array[i].val);

	e=array[i].next;
	while(e){
		printf("->%d",e->value);
		e=e->next;
	}
printf("\n");
}
}
*/
int main(){
	
		int test;
		scanf("%d",&test);
		while(test--)
		{
		int t,n,v1,v2,l,x,i,j,k,op,count,no;
		int src,max=0;
		flag2=0;
		p=0;
		head=NULL;
		int max_index;
		int flag[1000000]={0};
		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			length[i]=0;
			last[i]=0;
			flag[i]=0;
		}

		for(i=1;i<=n;i++){
			insert_vertex(i);
		}
		for(i=0;i<n-1;i++){
			scanf("%d%d",&v1,&v2);
				insert_edge(v1,v2);
			}
//		print();
			src=v1;
//		printf("%d\n",src);
			length[src]=0;
			t=n;
			while(p<t){
				push(src,flag);
				src=pop(flag);
				length[src]=length[last[src]]+1;
				if(length[src]>max){
					max=length[src];
					max_index=src;
				}
			}
		for(i=1;i<=n;i++){
			length[i]=0;
			last[i]=0;
			flag[i]=0;
		}
		
		head=NULL;
		src=max_index;
		p=0;
		t=n;
		flag2=0;
		length[src]=0;
		max=0;
		while(p<t){
			push(src,flag);
			src=pop(flag);
			length[src]=length[last[src]]+1;
				if(length[src]>max){
					max=length[src];
				}
		}
		printf("%d\n",max);
			for(i=1;i<=n;i++){
				array[i].val=0;
				array[i].next=NULL;
			}

		}
		return 0;
	}
