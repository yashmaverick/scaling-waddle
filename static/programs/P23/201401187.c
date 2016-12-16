#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
node* a[1000010];
int top=-1,visited[1000010]={0},stack[10000010];
void insert(int x,int y)
{
	node* new=(node*)malloc(sizeof(node));
	new->val=y;
	node* head=a[x];
	if(head==NULL)
	{
		a[x]=new;
		new->next=NULL;
	}
	else
	{
		while(head->next!=NULL&&head->next->val<new->val)
			head=head->next;
		node* temp=head->next;
		head->next=new;
		new->next=temp;
	}
}

void topological(int v)
{
	visited[v]=1;
	node* temp=a[v];
	while(temp!=NULL)
	{
		if(visited[temp->val]==0)
			topological(temp->val);
		temp=temp->next;
	}
	top++;
	stack[top]=v;
	return;
}
int main()
{
	int n,m,u,v,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		a[i]=NULL;
	while(m--)
	{
		scanf("%d%d",&u,&v);
		insert(u,v);
	}
/*	for(i=1;i<=n;i++)
	{
		printf("%d--->",i);
		node* temp=a[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}*/
	for(i=n;i>0;i--)
		if(visited[i]!=1)
			topological(i);
	while(top!=0)
		printf("%d ",stack[top--]);
	printf("%d\n",stack[0]);
	return 0;
}
