#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}node;
int dest,max=0;

node *head[1000006];

node *insert(node *root,int n)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=n;
	temp->next=root;
	return temp;
}

int status[1000006];
void dfs(int src,int level)
{
	if(level>max)
	{
		max=level;
		dest=src;
	}
	node *temp=head[src];
	while(temp!=NULL)
	{
		if(status[temp->data]==0)
		{
			status[temp->data]=1;
			dfs(temp->data,level+1);
		}
		temp=temp->next;
	}
}

int main()
{
	int n,l,j,i,t;
	scanf("%d",&t);
	while(t--)
	{

		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			status[i]=0;
			head[i]=NULL;
		}
		max=0;

		l=n-1;
		while(l--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			head[x]=insert(head[x],y);
			head[y]=insert(head[y],x);
		}
		int level=1;
		int src=1;
		status[src]=1;
		dfs(src,level);
		//	printf("%d %d\n",max,dest);

		for(i=0;i<=n;i++)
			status[i]=0;
		src=dest;
		status[src]=1;
		level=1;
		max=0;
		dfs(src,level);
		printf("%d\n",max);
	}
	return 0;
}
