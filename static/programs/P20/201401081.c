#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 1000005

int n,e;
int max_depth;
int max_node;

typedef struct adjl
{
	int val;
	struct adjl* next;
}adjl;

adjl *adjlist[NUM];
int visited[NUM];

void print_list()
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d: ",i);
		adjl *temp=adjlist[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}
}

void dfs(int node,int depth)
{
	int i;
	if(visited[node])
		return;
	else
		visited[node]=1;
	if(depth>max_depth)
	{
		max_depth=depth;
		max_node=node;
	}
	adjl *temp=adjlist[node];
	while(temp!=NULL)
	{
		dfs(temp->val,depth+1);
		temp=temp->next;
	}
}


int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<NUM;i++)
			adjlist[i]=NULL;
		scanf("%d",&n);
		e=n-1;
		max_depth=0;
		max_node=0;
		int e1,e2;
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&e1);
			scanf("%d",&e2);
			adjl *temp;
			temp=(adjl*)malloc(sizeof(adjl));
			temp->val=e2;
			temp->next=NULL;
			if(adjlist[e1]!=NULL)
				temp->next=adjlist[e1];
			adjlist[e1]=temp;
			temp=(adjl*)malloc(sizeof(adjl));
			temp->val=e1;
			temp->next=NULL;
			if(adjlist[e2]!=NULL)
				temp->next=adjlist[e2];
			adjlist[e2]=temp;
		}
		//print_list();
		memset(visited,0,sizeof(int)*NUM);
		dfs(1,1);
		//printf("%d::%d\n",max_node,max_depth);
		memset(visited,0,sizeof(int)*NUM);
		dfs(max_node,1);
		printf("%d\n",max_depth);
	}
	return 0;
}
