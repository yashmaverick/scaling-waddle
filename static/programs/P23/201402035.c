#include<stdio.h>
#include<stdlib.h>
int vertex_count=0;
int list_count=0;
int n_min;
struct edge{
	int value;
	struct edge *next;
}edge;

struct vertex{
	int val;
	struct edge *next;
}vertex;

struct vertex list[200007];
struct vertex array[200009];

void insert_vertex(int key){
	vertex_count++;
	array[vertex_count].val=key;
	array[vertex_count].next=NULL;
}

void insert_list(int key){
	list_count++;
	list[list_count].val=key;
	list[list_count].next=NULL;
}

void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void insert_min(int min[],int x){
	int tmp,l;
	n_min+=1;
	min[n_min]=x;
	l=n_min;
	while((l/2>=1) && (min[l/2]>min[l]))
	{
		swap(&min[l/2],&min[l]);
		l=l/2;
	}
}

int delete_min(int min[]){
	int k,l,m,root;
	root=min[1];
	min[1]=min[n_min];
	min[n_min]=10000009;
	n_min--;
	k=1;
	while((min[k]>min[2*k] || min[k]>min[2*k+1]) && (2*k<=n_min)){
		if((min[k]>min[2*k]) && (min[2*k]<=min[2*k+1]))	{
			swap(&min[2*k],&min[k]);
			k=k*2;
		}
		else{
			swap(&min[k],&min[2*k+1]);
			k=2*k+1;
		}
	}
	return root;
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
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++){
	insert_vertex(i);
	insert_list(i);
}

int count[500007];
int x,y;
for(i=1;i<=n;i++)
	count[i]=0;

for(i=1;i<=m;i++){
	scanf("%d%d",&x,&y);

	insert_edge(y,x);
	count[y]+=1;
}

//for(i=1;i<=n;i++)
//printf("%d ",count[i]);

//printf("\n");
int num=0;
n_min=0;
int min[200005];
for(i=1;i<=n;i++)
	if(count[i]==0)
		insert_min(min,i);
	
	int p=0;
	while(p<n){
	y=delete_min(min);
	struct edge *ed=list[y].next;
	while(ed){
		//printf("e_value=(%d)and y= <%d>\n",e->value,y);
		if(count[ed->value]>0)
			count[ed->value]-=1;
		
		if(count[ed->value]==0)
			insert_min(min,ed->value);
		ed=ed->next;
	}
	num++;
	if(num<n)
		printf("%d ",y);
	else
		printf("%d\n",y);
	p++;
}
return 0;
}
