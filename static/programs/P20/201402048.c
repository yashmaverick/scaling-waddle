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
void  dfs(int i)
{	
	node *p;
	p=a[i];
	vis[i]=1;
	count++;
	//printf("i : %d\n",i);
	if(count>l)
	{
		l=count;
		m=i;
	}
	while(p!=NULL)
	{
		i=p->vertex;
		if(vis[i]==0)
		{			
			dfs(i);
			count--;		
		}
		p=p->next;
	}
}
void insert1(int x,int y)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node));
	q->vertex=y;
	q->next=NULL;
	if(a[x]==NULL)
		a[x]=q;
	else
	{
		p=a[x];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;

	}
}
/*void insert2(int x,int y)
  {	node *r,*s;
  r=(node*)malloc(sizeof(node));
  r->vertex=y;
  r->next=NULL;	
  }*/
/*void display(int n)
  {
  struct node *root;
  int i;
  for(i=1;i<=n;i++)
  {
  root=a[i];
  printf("%d:",i);
  while(root!=NULL)
  {
  printf("%d->",root->vertex);
  root=root->next;
  }
  printf("\n");
  }
  }*/
int main()
{	int test;
	scanf("%d",&test);
	while(test--)
	{
		count=l=0;
		int i,nodes,x,y,z;
		scanf("%d",&nodes);
		for(i=0;i<=nodes;i++)
		{
			vis[i]=0;
			a[i]=NULL;

		}
		for(i=0;i<nodes-1;i++)
		{
			scanf("%d%d",&x,&y);
			insert1(x,y);
			insert1(y,x);

		}
		//	display(nodes);
	//	printf("%d-_",x);
		dfs(x);
		count=l=0;
		for(i=0;i<=nodes;i++)	
			vis[i]=0;
	//	printf("%d\t",m);
		dfs(m);
		printf("%d\n",l);
	}
	return 0;
}
