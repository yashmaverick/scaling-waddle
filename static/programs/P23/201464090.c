#include<stdio.h>
#include<stdlib.h>
int sz=0,a[100001],vis[100001];
typedef struct node
{
	int val;
	struct node *next;
}node;
node *matrix[500001];
void push(int i)
{
	a[sz]=i;
	sz++;
}
void insert(int i,int j)
{
	node *new=malloc(sizeof(node));
	new->val=j;
	if(matrix[i]==NULL)
		matrix[i]=new;
	else
	{
		new->next=matrix[i];
		matrix[i]=new;
	}
}
void dfs(int index)
{
	if(vis[index]==1)
		return;
	vis[index]=1;
	node *temp=matrix[index];
	while(temp!=NULL)
	{
		dfs(temp->val);
		temp=temp->next;
	}
	push(index);
	return;
}
int main()
{
	int n,m,i,u,v,j;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		insert(u,v);
	}
	for(j=1;j<=n;j++)
		vis[j]=0;
	for(i=n;i>=1;i--)
		dfs(i);
	for(i=sz-1;i>=0;i--)
	{
		if(i!=0)
			printf("%d ",a[i]);
		if(i==0)
			printf("%d\n",a[i]);
	}
	return 0;
}
