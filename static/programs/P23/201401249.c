#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
node *head[1000001];
int vis[1000001];
int stack[1000001];
int point=-1;
void push(int k)
{
	if(point==1000000)
		return ;
	point++;
	stack[point]=k;
}
int str,ans;
void sort(node *temp)
{
	int k;
	while(temp->next!=NULL && temp->val < (temp->next)->val)
	{
		k=temp->val;
		temp->val=(temp->next)->val;
		(temp->next)->val=k;
		temp=temp->next;
	}
}

void create(int l,int m,node **head)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=m;
	if(head[l]!=NULL)
	{
		temp->next=head[l];
		head[l]=temp;
		sort(head[l]);
		return ;
	}
	head[l]=temp;
	return;
}
void dfs(node **head,int k)
{
	if(head==NULL || vis[k]==1)
		return ;
	vis[k]=1;
	node *temp=head[k];
	while(temp!=NULL)
	{
		if(vis[temp->val]!=1)
			dfs(head,temp->val);
		temp=temp->next;
	}
	push(k);
	return ;
}
int main()
{
	int i,j,k,l,m,n,e,v;
//	scanf("%d",&m);
//	while(m--)
//	{
		scanf("%d",&v);
		for(j=1;j<=v;j++)
			head[j]=NULL;
		scanf("%d",&e);
		//	scanf("%d",&e);
		for(j=1;j<=e;j++)
		{
			scanf("%d %d",&l,&m);
			create(l,m,head);
		}
		for(i=1;i<=v;i++)
		{
			vis[i]=0;
		}
		for(j=v;j>0;j--)
		{
		if(vis[j]==0)
		dfs(head,j);
		}
		node *temp;
	/*	for(j=1;j<=v;j++)
		{
			printf("%d->",j);
			temp=head[j];
			while(temp!=NULL)
			{
				printf("%d ",temp->val);
				temp=temp->next;
			}
			printf("\n");
		}*/
		for(j=point;j>0;j--)
		{
			printf("%d ",stack[j]);
		}
		if(point>=0)
		printf("%d",stack[0]);
//	}
		printf("\n");
	return 0;
}








































































































































































