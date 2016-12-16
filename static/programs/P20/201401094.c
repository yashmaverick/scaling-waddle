#include<stdio.h>
#include<stdlib.h>
void print(int *a,int n)
{
	int i ;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

typedef struct adj{
	int val;
	struct adj* next;
}node;
node* insert(node* head,int val)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->val=val;
	temp->next=head;
	return temp;
}
void dfs(int st,node* *adj,int *dist)
{
	int q=0,max=0;
	node *head=adj[st];
	while(head!=NULL)
	{
		if(dist[head->val]==0)
		{	
			dist[head->val]=dist[st]+1;
			dfs(head->val,adj,dist);	
		}
		head=head->next;
	}
}
void frp(node *head)
{
	if(head!=NULL)
	{
		frp(head->next);
		free(head);
	}
}

int main()
{
	int t,n,q,a,b,i;
	node* head[1000006];
	int dist[1000006];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			head[i]=NULL;
			dist[i]=0;
		}

		for(i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			head[a]=insert(head[a],b);
			head[b]=insert(head[b],a);
		}
		dist[1]=1;
		dfs(1,head,dist);
	//	print(dist,n+1);
		int max=1;
		for(i=1;i<=n;i++)
		{
			if(dist[i]>dist[max])
				max=i;
		}
		for(i=0;i<=n;i++)
			dist[i]=0;
		dist[max]=1;
		dfs(max,head,dist);
//		print(dist,n+1);
		max=0;
		for(i=1;i<=n;i++)
		{
			if(dist[i]>max)
				max=dist[i];
		}
		printf("%d\n",max);	
		for(i=1;i<=n;i++)
		{
			frp(head[i]);
		}
	}
	return 0;
}

