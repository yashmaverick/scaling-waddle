#include<stdio.h>
#include<stdlib.h>
int vis[1001],n,count=0,vis2[1001];
typedef struct node
{
	int val;
	struct node *next;
}node;
node *matrix[1001],*rev[1001];
void insert(int index,int ele)
{
	node *new=malloc(sizeof(node));
	new->val=index;
	if(matrix[ele]==NULL)
		matrix[ele]=new;
	else
	{
		new->next=matrix[ele];
		matrix[ele]=new;
	}
}
void insert2(int index,int ele)
{
	node *new=malloc(sizeof(node));
	new->val=ele;
	if(rev[index]==NULL)
		rev[index]=new;
	else
	{
		new->next=rev[index];
		rev[index]=new;
	}
}
void dfs(int index)
{
	int ind;
	if(vis[index]==1)
		return;
	else
	{
		vis[index]=1;
		node *temp;
		temp=matrix[index];
		while(temp!=NULL)
		{
			ind=temp->val;
			dfs(ind);
			temp=temp->next;
		}
	}
	return;
}
void reverse(int index,int num)
{
	int ind;
	if(vis2[index]==1)
		return;
	else
	{
		vis2[index]=1;
		node *temp;
		temp=rev[index];
		if(num!=1)
			count++;
		while(temp!=NULL)
		{
			ind=temp->val;
			reverse(ind,num+1);
			temp=temp->next;
		}
	}
	return;
}
void search()
{
	int i,j,flag=0,winner;
	for(i=1;i<=n;i++)
	{
		flag=0;
		dfs(i);
		for(j=1;j<=n;j++)
		{
			if(vis[j]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			winner=i;
			count=1;
			break;
		}
		for(j=1;j<=n;j++)
			vis[j]=0;
	}
	reverse(winner,1);
	return;
}
int main()
{
	int t,i,m,x,j;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				insert(i,x);
				insert2(i,x);
			}
		}
		for(j=1;j<=n;j++)
			vis2[j]=0;
		search();
		printf("%d\n",count);
		for(j=1;j<=n;j++)
		{
			matrix[j]=NULL;
			rev[j]=NULL;
			vis[j]=0;
			vis2[j]=0;
		}
	}
	return 0;
}
