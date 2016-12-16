#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list *next;
}list;
list *a[1000010];
int maxdepth,front,node;
int stack[1000010],visited[1000010];
void insert(int x,int y);
void dfs(int i,int depth);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,x,y;
		maxdepth=0,front=0;
		scanf("%d",&n);
		for(i=1;i<1000010;i++)
			a[i]=NULL;
		for(i=1;i<=n;i++)
			visited[i]=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&x,&y);
			insert(x,y);
			insert(y,x);
		}
		dfs(1,0);
//		printf("maxdepth: %d",maxdepth);
//		printf("node: %d\n",node);
		front=0;
		for(i=1;i<=n;i++)
			visited[i]=0;
		dfs(node,0);
	//	maxdepth=0;
//		printf("\n");
		for(i=1;i<1000010;i++)
			a[i]=NULL;
		printf("%d\n",maxdepth+1);
	}
return 0;
}
void insert(int x,int y)
{
	list *temp;
	list *new=(list *)malloc(sizeof(list));
	new->data=y;
	if(a[x]==NULL)
	{
		a[x]=new;
		new->next=NULL;
	}
	else
	{
		temp=a[x];
		a[x]=new;
		new->next=temp;
	}
}
void dfs(int i,int depth)
{
	list *p=a[i];
	visited[i]=1;
	if(maxdepth<depth)
	{
		maxdepth=depth;
		node=i;
	}
	if(p==NULL)
		return;
	while(p!=NULL)
	{
		if(visited[p->data]==0)
		{	//node=p->data;
			dfs(p->data,depth+1);
		}
		//node=p->data;
		p=p->next;
	}
}

