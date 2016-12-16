#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int vertex;
};
struct stack
{
	int data;
	struct stack *next;
};
typedef struct stack stack;
stack *top;
void push(int x)
{
	stack *new=malloc(sizeof(stack));
	new->data=x;
	new->next=top;
	top=new;
}
int top1()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
		return -1;
	}
	else
		return top->data;
}
void print()
{
	stack *temp=top;
	while(temp!=NULL)
	{
		printf("%d%c",temp->data,(temp->next==0)?'\n':' ');
		temp=temp->next;
	}
	//printf("\n");
	return ;
}
struct node* A[1000008];
int visited[1000008];
int max,maxvertex;
void dfs(int);
void insert(int,int);
int main()
{
	int m,i,n;
	int a,b,edge;
	int test;
	//scanf("%d",&test);
	//while(test)
	//{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;A[i++]=NULL);
		//for(i=0;i<n;i++)
		//{
		//scanf("%d",&edge);
		//edge=n-1;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			insert(a,b);
			//insert(b,a);
		}
		//}
		for(i=0;i<=n;i++)
			visited[i]=0;
		//int count;
		//count=0;
		//max=0;
		//maxvertex=1;
		//dfs(1,count);
		//printf("%d %d\n",max,count);
		//count=0;
		//max=0;
		for(i=n;i>=1;i--)
		{
			if(visited[i]==0)
				dfs(i);
		}
		print();
		//dfs(maxvertex,count);
		//printf("%d\n",max);
		//test--;
	//}
	return 0;
}
void insert(int a,int b)
{
	struct node *m,*n;
	n=(struct node*)malloc(sizeof(struct node));
	n->vertex=b;
	n->next=NULL;
	if(A[a]==NULL)
		A[a]=n;
	else
	{
		m=A[a];
		while(m->next!=NULL)
			m=m->next;
		m->next=n;
	}
}
void dfs(int i)
{
	struct node *m;
	m=A[i];
	//printf("%d\n",i);
	visited[i]=1;
	while(m!=NULL)
	{
		if(!visited[m->vertex])
			dfs(m->vertex);
		m=m->next;
	}
	push(i);
}
