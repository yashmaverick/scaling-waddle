#include<stdio.h>
#include<malloc.h>
struct node
{
	long long int data;
	long long int weight;
	struct node *next;
};
long long int u,v;
long long int min=100000000000000;
struct node *a[500001];
void insert(long long int x,long long int y,long long int w)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=y;
	temp->weight=w;
	temp->next=a[x];
	a[x]=temp;
}
void dfs(long long int x,long long int count[],int visited[])
{
//	visited[x]=1;
	struct node *root;
	root=a[x];
	while(root!=NULL)
	{
	//	if(visited[root->data]==0)
	//	{
			int te=count[root->data];
			count[root->data]=count[x]+root->weight;
			if(te<count[root->data])
				count[root->data]=te;
			dfs(root->data,count,visited);
	//	}	
		root=root->next;
	}
}
void print(long long int n)
{
	long long int i;
	struct node *root;
	for(i=1;i<=n;i++)
	{
		root=a[i];
		printf("%d:- ",i);
		while(root!=NULL)
		{
			printf("%lld:%lld->",root->data,root->weight);
			root=root->next;
		}
		printf("\n");
	}
}
int main()
{
	long long int n,m;
	scanf("%lld%lld",&n,&m);
	long long int i,j,w;
	for(i=1;i<=n;i++)
	{
		//a[i]=(struct node*)malloc(sizeof(struct node));
		a[i]=NULL;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		insert(u,v,w);
	}
	scanf("%lld%lld",&u,&v);
	//print(n);
	long long int count[500001];
	int visited[n+1];
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		count[i]=min;
	}
	count[u]=0;
	dfs(u,count,visited);
//	for(i=1;i<=n;i++)
//		printf("%d ",count[i]);
//	printf("\n");
	if(count[v]<100000000000000)
	printf("%lld\n",count[v]);
	else
		printf("NO\n");
	return 0;
}
