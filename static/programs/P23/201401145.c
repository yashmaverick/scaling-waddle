#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100005
#define rep(i,n) for(i=1;i<=n;i++)
int heap[MAX],ans[MAX],size=0;
int min(int x,int y){ return x<y?x:y; }
void swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b   = *a;
	*a   = temp;   
}
void in(int *address){
scanf("%d",address);
}
void out(int *pointer){
printf("%d ",*pointer);
}
void newl(int *pointer){
printf("%d\n",*pointer);
}
typedef struct node{
	int val;
	struct node *next;
}node;
node *lisins(node *head,int val){
	node *p;
	p=(node *)malloc(sizeof(node));
	p->val=val;
	p->next=head;
	return p;
}
node *a[MAX];
int degree[MAX];
void insert(int value){
	++size;
	int i=size,p;
	heap[i]=value;
	while(i>1 ){
		p=i/2;
		if(heap[p]>heap[i]){
			swap(&heap[p],&heap[i]);
			i=p;
		}
		else break;
	}
}
void minheapify(int value){
	int i=1,p;
	while(i<=size/2 && (value>heap[2*i]||value>heap[2*i+1])){
		if(heap[2*i]<heap[2*i+1]) p=2*i;
		else p=2*i+1; 
		swap(&heap[p],&heap[i]);
		i=p;
	}
}
int delmin(){
	int min=heap[1];
	heap[1]=heap[size--];
	minheapify(heap[1]);
	return min;
}
int ans[MAX],ind=0;
void solver(int n){
	int i,j;
	for(i=1;i<=n;i++){
		if(degree[i]==0) insert(i);
	}
	while(size!=0){
		j=delmin();
		ans[++ind]=j;
		node *tmp=a[j];
		while(tmp!=NULL){
			degree[tmp->val]--;
			if(degree[tmp->val]==0) insert(tmp->val);
			tmp=tmp->next;
		}
	}
}
int main()
{ 
	int i,j,n,m,x,y;
	scanf("%d%d",&n,&m);
	rep(i,n){
		a[i]=NULL;
		degree[i]=0;
	}
	rep(i,m){
		scanf("%d%d",&x,&y);
		degree[y]++;
		a[x]=lisins(a[x],y);
	}
	solver(n);
	rep(i,ind-1) out(&ans[i]);
	newl(&ans[ind]);
	return 0;
}
