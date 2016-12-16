#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int vertex;
	struct node *next;
}node;
node *graph[1000010];
int visited[1000010];
void undirected(int vertex1,int vertex2)
{

	if(graph[vertex1]!=NULL)
	{
		node *kottha=(node *)malloc(sizeof(node));
		kottha->vertex=vertex2;
		kottha->next=graph[vertex1];
		graph[vertex1]=kottha;
	}
	else
	{
		graph[vertex1]=(node *)malloc(sizeof(node));
		graph[vertex1]->vertex=vertex2;
		graph[vertex1]->next=NULL;
	}
}
int start=0,arr[1000010];
void dfs(int p)
{
	node *head;
	head=graph[p];
	if(visited[p]!=1)
	{
		visited[p]=1;
		while(head!=NULL)
		{
			if(visited[head->vertex]!=1)
				dfs(head->vertex);
			head=head->next;
		}
		arr[start++]=p;
	}
	return ;
}
int main()
{

	int n,m,i;
	scanf("%d%d",&n,&m);
	int l,o;
	for(i=0;i<=n;i++)
	{
		visited[i]=0;
		graph[i]=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&l,&o);
		undirected(l,o);
	}

	for(i=n;i>0;i--)
		if(visited[i]!=1)
				dfs(i);
	for(i=start-1;i>0;i--)
		printf("%d ",arr[i]);
	printf("%d\n",arr[0]);
	return 0;
}














