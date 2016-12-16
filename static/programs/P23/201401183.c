#include<stdio.h>
#include<stdlib.h>
int top=-1,vis[1000009];
typedef struct node
{
	int val;
	struct node* next;
}node;
node* a[1000009];
int s[1000009];
void insert(int x,int y)
{
	node* temp=a[x];
	node* new1=malloc(sizeof(node));
	new1->val=y;
	new1->next=NULL;
	if(temp==NULL)
		a[x]=new1;
	else
	{	
		if(temp!=NULL&&temp->val<y)
		{
		while(temp->val<y)
		{
//			printf("%d   1\n",temp->val);
			if(temp->next!=NULL)
			{
				if(temp->next->val<y)
					temp=temp->next;
			}
			else break;
		}
		new1->next=temp->next;
		temp->next=new1;
		}
		else if(temp!=NULL&&temp->val>=y)
		{
			a[x]=new1;
			new1->next=temp;
		}
	}
	//	temp=a[x]->next;
	//	new1->next=temp;
	//	a[x]->next=new1;
}
//	else a[x]=new1;
	//new1->next=temp;
	//vice versa
/*	node* new2=malloc(sizeof(node));
	new2->val=x;
	new2->next=NULL;
	if(a[y]!=NULL)
	{
		temp=a[y]->next;
		new2->next=temp;
		a[y]->next=new2;
	}	
	else a[y]=new2;*/
void push(int val)
{
	s[++top]=val;
}
void pop()
{
	if(top==-1)return;
	else top--;
}
/*void enqueue(int x)
{
	if(rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=x;
	}
	else
		q[++rear]=x;

}
int dequeue()
{
	int x;
	if(front==-1)
		printf("-1\n");
	else if(front==rear)
	{
		x=q[front];	
		front=-1;
		rear=-1;
		return x;
	}
	else
	{
 		x=q[front];
		++front;
		return x;
	}
}
void bfs(int b)
{
	node* temp=NULL;
	int v;
	enqueue(b);
	vis[b]=1;
	while(front!=-1&&rear!=-1)
	{
		v=dequeue();
		printf("%d ",v);
		vis[v]=1;
		temp=a[v];
		while(temp!=NULL)
		{
			if(vis[temp->val]!=1)
			{
				enqueue(temp->val);
				vis[temp->val]=1;
			}
			temp=temp->next;
		}
	}
}
void dfs(int b)
{
	node* temp=NULL;
	int v;
	push(b);
	vis[b]=1;
	while(top!=-1)
	{
		v=pop();
		printf("%d ",v);
		vis[v]=1;
		temp=a[v];
		while(temp!=NULL)
		{
			if(vis[temp->val]!=1)
			{
				push(temp->val);
				vis[temp->val]=1;
			}
			temp=temp->next;
		}
	}
}*/
void topo(int x)
{
	vis[x]=1;
	int i;
	node* temp=a[x];
	if(temp!=NULL)
	{
	for(i=temp->val;temp!=NULL;temp=temp->next)
		if(vis[i]==0)
			topo(i);
	}
	push(x);
}
int main()
{
	int n,m,x,y,i,j,b;
	node* temp=NULL;
//	node* temp=NULL;
	scanf("%d%d",&n,&m);
	//for(i=1;i<=n;i++)
	//	a[i]->next=NULL;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for(i=n;i>=1;i--)
	{
		if(vis[i]==0)
			topo(i);
	}
	while(top>0)
	{
		printf("%d ",s[top]);
		pop();
	}
	if(top==0)
		printf("%d\n",s[0]);
/*	for(i=1;i<=n;i++)
	{
		temp=a[i];
		printf("%d ----> ",i);
		while(temp!=NULL)
		{
			printf("%d ",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}
	printf("\n");*/
	return 0;
}