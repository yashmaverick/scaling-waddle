#include<stdio.h>
#include<stdlib.h>
int t;
int max1;
typedef struct node
{
	struct node *next;
	int vertex;
}node;
node *G[1000000];
int visited[1000000];
void insert(int a,int b);
void dfs(int u,int max)
{
	node *p;
	p=G[u];
	visited[u]=1;
	max=max+1;
	while(p!=NULL)
	{
		u=p->vertex;
		if(visited[u]==0)
		{
			dfs(u,max);
                }
		p=p->next;
	}
	if(max>=max1)
	{
		max1=max;
                t=u;
	}
}
int main()
{
	int test,count,a,b;
	scanf("%d",&test);
	for(count=0;count<test;count++)
	{
		int n,i,val;
                max1=0;
		scanf("%d",&n);
	        for(i=0;i<n;i++)
		{
			G[i]=NULL;
                        visited[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&a,&b);
			insert(a-1,b-1);
                        insert(b-1,a-1);
		}
		dfs(0,0);
                max1=0;
                for(i=0;i<n;i++)
                 {
			 visited[i]=0;
                 }
                dfs(t,0);
                printf("%d\n",max1+1);
	}
return 0;
}
void insert(int a,int b)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node));
	q->vertex=b;
	q->next=NULL;
	if(G[a]==NULL)
	{
		G[a]=q;
	}
	else
	{
		p=G[a];
		while(p->next!=NULL)
		{
			p=p->next;
                }
			p->next=q;
	}
}
