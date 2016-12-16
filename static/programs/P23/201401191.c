#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int val;
	struct node* next;
};
int vis[1000000];
int stack[1000000];
int top=-1;
node* adj[1000000];
void insert(int,int);
void push(int num)
{
	stack[++top]=num;
}
void pop()
{
	if(top<0)
	{
		return;
	}
	if(top!=0)
	printf("%d ",stack[top--]+1);
	else
	{
		printf("%d\n",stack[top--]+1);
	}
}
void do_specdfs(int i)
{
	vis[i]=1;
	node* tt;
	for(tt=adj[i];tt!=NULL;tt=tt->next)
	{
		if(!vis[tt->val])
		{
			do_specdfs(tt->val);
		}
	}
	push(i);
}
int main()
{
	int n,m,i,j,k,v1,v2;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		adj[i]=NULL;
		vis[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&v1,&v2);
		v1--;
		v2--;
		insert(v1,v2);
	}
	for(i=n-1;i>=0;i--)
	{
		if(!vis[i])
		{
			do_specdfs(i);
		}
	}
	while(top!=-1)
	{
		pop();
	}
	return 0;
}
void insert(int v1,int v2)
{
	node* rmp=(node*)malloc(sizeof(node));
	rmp->val=v2;
	rmp->next=adj[v1];
	adj[v1]=rmp;
	return;
}
