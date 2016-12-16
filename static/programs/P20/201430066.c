#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	struct node *next;
	int vertex;
};
node *a[1000001];
int vis[1000001],count=0,l=0,m;
void  dfs(int i,int cc)
{	
	cc++;
	node *p;
	p=a[i];
	vis[i]=1;
	count++;
	if(count>l)
	{
		l=count;
		m=i;
	}
	for(;p!=NULL;p=p->next)
	{
		i=p->vertex;
		if(vis[i]==0)
		{			
			dfs(i,20);
			count--;		
		}
	}
}
void insert1(int x,int y,int xc)
{
	node *p,*q;
	xc++;
	q=(node*)malloc(sizeof(node));
	q->vertex=y;
	q->next=NULL;
	if(a[x]==NULL)
		a[x]=q;
	else
	{
		for(p=a[x];p->next!=NULL;p=p->next)
		{
		
		}
		p->next=q;

	}
}
int main()
{	int test;
	scanf("%d",&test);
	int iii;
	for(iii=0;iii<test;iii++)
	{
		count=l=0;
		int i,nodes,x,y,z;
		scanf("%d",&nodes);
		i=0;
		while(i<=nodes)
		{
			vis[i]=0;
			a[i]=NULL;
			i++;
		}
		i=0;
		while(i<nodes-1)
		{
			scanf("%d%d",&x,&y);
			insert1(x,y,20);
			insert1(y,x,22);
			i++;
		}
		dfs(x,20);
		count=l=0;
		i=0;
		while(i<=nodes)	
		{
			vis[i]=0;
			i++;
		}
		dfs(m,20);
		printf("%d\n",l);
	}
	return 0;
}
