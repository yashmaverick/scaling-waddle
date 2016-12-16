#include<stdio.h>
#include<stdlib.h>
int max,front=-1,rear=-1,m,top=-1,count;
typedef struct node
{
	int val;
	struct node* next;
}node;
node* a[1000009];
int vis[1000009];
//int q[1000009],s[1000009];
void insert(int x,int y)
{
	node* temp=NULL;
	node* new1=malloc(sizeof(node));
	new1->val=y;
	new1->next=NULL;
	if(a[x]!=NULL)
	{
		temp=a[x]->next;
		new1->next=temp;
		a[x]->next=new1;
	}
	else a[x]=new1;
	//new1->next=temp;
	//vice versa
	node* new2=malloc(sizeof(node));
	new2->val=x;
	new2->next=NULL;
	if(a[y]!=NULL)
	{
		temp=a[y]->next;
		new2->next=temp;
		a[y]->next=new2;
	}	
	else a[y]=new2;
}
/*void push(int val)
{
	s[++top]=val;
}
int pop()
{
	if(top==-1)return;
	else return s[top--];
}
*/
/*
void enqueue(int x)
{
	if(rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=x;
	}
	else
		q[++rear]=x;

}*/
/*
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
}*/
/*void bfs(int b)
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
}*/
/*int dfs(int b)
{
//	node* temp2=a[b];
	node* temp=NULL;
	int v,max=0;
	push(b);
	vis[b]=1;
	count=0;
	while(top!=-1)
	{
		v=pop();
		node* temp2=a[v];
		if(temp2!=NULL)
		if(v==temp2->val)
		{
			count=1;
			temp2=temp2->next;
		}
		count++;
		if(count>max)
		{
			max=count;
			m=v;
		}
	//	printf("%d ",v);
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
//	return v;
	return max;
}*/
void dfs(int i,int c)
{
	if(vis[i]!=1)
	{
		c++;
		vis[i]=1;
		if(c>max)
		{
			max=c;
			m=i;
		}
		node* temp=a[i];
		while(temp!=NULL)
		{
			dfs(temp->val,c);
			temp=temp->next;
		}
	}
}
int main()
{
	int n,x,y,i,j,t,b;
	node* temp=NULL;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=NULL;
		vis[i]=0;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
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
	}*/
	max=0;
	dfs(1,0);
//	printf("%d\n%d\n",max,m);
	for(i=1;i<=n;i++)
		vis[i]=0;
	max=0;
	dfs(m,0);
	printf("%d\n",max);
	}
//	printf("\n");
//	for(i=1;i<=n;i++)
//		vis[i]=0;
//	printf("%d\n",m);
//	printf("%d\n",dfs(m));
	return 0;
}
