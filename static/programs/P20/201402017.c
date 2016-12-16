#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *next;
};
struct node *arr[1000004];
int vis[1000004];
int dist[1000004];
void insert(struct node *arr[],int u,int v)
{
	struct node *t1;
	struct node *t2;
	t1=((struct node *)(malloc(sizeof(struct node))));
	t1->data=u;
	t1->next=NULL;
	t2=((struct node *)(malloc(sizeof(struct node))));
	t2->data=v;
	t2->next=NULL;
	t1->next=arr[v];
	arr[v]=t1;
	t2->next=arr[u];
	arr[u]=t2;
	return;
}
void dfs(int str,int val)
{
	vis[str]=1;
	dist[str]=val;
	//printf("%d ",str);
	struct node *itr=arr[str];
	//printf("%d ",itr->data);
	while(itr!=NULL)
	{
		if(vis[itr->data]==0)
		{
			dfs(itr->data,val+1);
		}
		itr=itr->next;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,u,v,n,m,max,max_i,max2;
		scanf("%d",&n);
		m=n-1;
		for(i=0;i<1000004;i++)
		{
			arr[i]=NULL;
			vis[i]=0;
			dist[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			insert(arr,u,v);
		}
		dfs(1,0);
		//printf("\n");
		max=-1;max_i=0;
		for(i=1;i<=n;i++)
		{
			//printf("%d:%d ",i,dist[i]);
			if(dist[i]>max)
			{
				max=dist[i];
				max_i=i;
			}
		}
		memset(vis,0,sizeof(vis));
		dfs(max_i,0);
		max2=-1;
		for(i=1;i<=n;i++)
		{
			//printf("%d ",dist[i]);	
			if(dist[i]>max2)
				max2=dist[i];
		}
		printf("%d\n",max2+1);
	}
	return 0;
}
