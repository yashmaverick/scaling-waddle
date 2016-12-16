#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	struct node *next;
	int data;
}node;

node *a[1000005];
void addedge(int u,int v)
{
	node *temp=malloc(sizeof(node));
	temp->data=u;
	temp->next=a[v];
	a[v]=temp;
	temp=malloc(sizeof(node));
	temp->data=v;
	temp->next=a[u];
	a[u]=temp;
}
int vis[1000005];
int q[1000005];
int lev[1000005];
int flag=0;
int bfs(int u)
{
	int front=0;
	int rear=0;
	vis[u]=1;
	q[front]=u;
	lev[u]=0;
	while(front<=rear)
	{
		int t=q[front];
		node *temp=a[t];
		while(temp!=NULL)
		{
			if(!vis[temp->data])
			{
		//		printf("rear is %d\n",rear);
				rear++;
				q[rear]=temp->data;
				vis[temp->data]=1;
				lev[temp->data]=lev[t]+1;
			}
			temp=temp->next;
		}
		front++;
	}
	if(flag==0)
	{
		memset(vis,0,sizeof(vis));
		memset(lev,0,sizeof(lev));
		flag=1;
	//	printf("rear is %d\n",rear);
		return bfs(q[rear]);

	}
	else return lev[q[rear]];


}
void printlist(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",i);
		node *temp=a[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int i=0;
	int t;
	scanf("%d",&t);
	while(t--)
	{

		memset(vis,0,sizeof(vis));

		memset(lev,0,sizeof(lev));
		memset(q,0,sizeof(q));
		int n;
		i=1;
		flag=0;
		scanf("%d",&n);
		for(;i<n;i++)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			addedge(p,q);
		}
		
		printf("%d\n",bfs(1)+1);
		for(i=1;i<=n;i++)
		{
			a[i]=NULL;
		}
	}
	return 0;
}









