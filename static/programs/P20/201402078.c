#include<stdio.h>
#include<stdlib.h>
int visited[1000002],r,max=0,count=0,num;
typedef struct node
{
	int val;
	struct node *next;
}node;
node *a[1000001];
void insert(int x,int y)
{
	node *temp,*tmp;
	node *new=malloc(sizeof(node));
	new->val=y;
	new->next=NULL;
	if(a[x]==NULL)
		a[x]=new;
	else
	{
		new->next=a[x];
		a[x]=new;;
	}
	if(x!=y)
	{
		node *ne=malloc(sizeof(node));
		ne->val=x;
		ne->next=NULL;
		if(a[y]==NULL)
		{
			a[y]=ne;
		}
		else
		{
			ne->next=a[y];
			a[y]=ne;
		}
	}
}
void dfs(int x)
{
	count++;
	visited[x]=1;
	node *p;
	p=a[x];
	//	printf("x -- %d\n",x);
	if(count>max)
	{
		max=count;
		num=x;
	}
	while(p!=NULL)
	{
		r=p->val;
		if(visited[r]==0)
		{
			dfs(r);
			count--;
		}
		p=p->next;
	}
}
int main()
{
	int i,j,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		max=0;
		for(i=0;i<1000002;i++)
			a[i]=NULL;
		scanf("%d",&n);
		for(i=0;i<1000002;i++)
			visited[i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			insert(j,k);
		}
		dfs(1);
		count=max=0;
		for(i=0;i<1000002;i++)
			visited[i]=0;
		dfs(num);
		printf("%d\n",max);
	}
}
