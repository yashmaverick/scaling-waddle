#include<stdio.h>
#include<stdlib.h>
int top=-1,stack[1000006],visited[1000006];

typedef struct node
{
	int val;
	struct node* next;	
}node;
node* a[100006];
void insert ( int j , int k)
{
	node* tee=(node*)malloc(sizeof(node));
	tee->val  = k;
	tee->next = a[j];
	a[j]=tee;
}
void push(int i)
{
	//printf("Pushing %d ",i);
	stack[++top]=i;
}
int pop()
{
	return stack[top--];
}
void dfs(int i)
{
//printf("%d ",i);
	int v;
	node *s;
	s=a[i];
	visited[i]=1;
	while(s!=NULL)
	{
		v=s->val;
		if(!visited[v])
			dfs(v);
		s=s->next;
	}
	push(i);
}
int main()
{
	int k;
	int i,t,v1,v2,n1,n2,n;
	scanf("%d%d",&n1,&n2);
	for(k=1;k<=n1;k++)
	{
		visited[k]=0;
		//	a[k]=(node*)malloc(sizeof(struct node));
		//	a[k]->val=k;
		//	a[k]->next=NULL;
			a[k]=NULL;
	}
	for(i=0;i<n2;i++)
	{
		scanf("%d%d",&v1,&v2);
		insert(v1,v2);
	}
	node* w;
	for(w=a[1];w!=NULL;w=w->next)
	{
	//	printf("%d ",w->val);
	}
	for(i=n1;i>0;i--)
	{
		if(!visited[i])
			dfs(i);	
	}
	while(top!=-1)
	{
		if(top==0)
		{
			printf("%d",pop());
		}
		else
		printf("%d ",pop());
	} 
	printf("\n");
	return 0;
}
