#include<stdio.h>
#include<stdlib.h>
#define SIZE 100001
struct link{
	int data;
	struct link *next;
}*head[100001];

typedef struct link link;

link *head[100001];
int s[100001];
int visited[100001];

void insert(int s,int v);
void print_list(link *s);
void print_stack(int n);
void push(int val);
int pop();
int con(int a,int b);
void topo_sort(int n);
void which(int val);
void dfs(int val);
int front=-1,back=-1,top=-1;
int main(){

	int n,m,x,y,i,val,ch;
	link *tmp;

	scanf("%d %d",&n,&m);

	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		insert(x,y);
	}

	for(i=0;i<=n;i++){
		visited[i]=0;
		s[i]=0;
	}
	topo_sort(n);	
	/*while(top!=-1){
		printf("%d ",s[top]);
		pop();
	}
	printf("\n");*/
	return 0;
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

void print_list(link *s){
	if(s==NULL)
		return;
	else{
		printf("%d ",s->data);
		print_list(s->next);	
	}
}

void dfs(int val){
	int r;
	link *temp=NULL;
	visited[val]=1;
	temp=head[val];	
	while(temp!=NULL){
		if(visited[temp->data]!=1){
			dfs(temp->data);
		}
		temp=temp->next;
	}
	//which(val);
	push(val);
}

void which(int val){
int x;
	if(top!=-1&&val > s[top] && con(val,s[top])==0){
		x=pop();
		which(val);
		push(x);
	}
	else
		push(val);

}

void topo_sort(int n){
	int i;
	for(i=0;i<=n;i++)
		visited[i]=0;
	for(i=n;i>=1;i--){
		if(visited[i]==0)
			dfs(i);
	}
	print_stack(n);
}

int con(int a,int b){
	link *temp;
	int fl=0;
	temp=head[a];
	while(temp){
		if(temp->data==b)
			fl=1;
		temp=temp->next;
	}

	temp=head[b];
	while(temp){
		if(temp->data==a)
			fl=1;
		temp=temp->next;
	}

	return fl;
}
/*void dfs(int val){
  int r;
  link *temp=NULL;
  push(val);
  visited[val]=1;

  while(top!=-1){
  r=pop();
  if(r!=0)
  printf("%d ",r);
  visited[r]=1;
  temp=head[r];	
  while(temp!=NULL){
  if(visited[temp->data]!=1){
  push(temp->data);
  visited[temp->data]=1;
  }
  temp=temp->next;
  }
  }
  printf("\n");
  }
 */
void push(int val){
	s[++top]=val;
}

int pop(){
	if(top==-1)
		return 0;
	else
		top--;
	return s[top+1];
}

void print_stack(int n){
int k;
for(k=n-1;k>0;k--)
printf("%d ",s[k]);
printf("%d\n",s[0]);
}
