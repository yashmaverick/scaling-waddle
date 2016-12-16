#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *next;
	long long int v;
}node;
long long int n,vis[1000002];
node *a[1000003];
void adjlist(long long int v1,long long int v2);
void dfs(long long int d,long long int c1);
long long int c=0,go;
int main()
{
	int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		c=0;
		long long int n,v1,v2,i;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			a[i]=NULL;
			vis[i]=0;
		}
		for(i=1;i<=(n-1);i++)
		{
			scanf("%lld %lld",&v1,&v2);
			adjlist(v1,v2);
		}
		dfs(1,0);
		//printf("ak: %d,go: %d\n",ak,go);
		c=0;
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		dfs(go,0);
		printf("%lld",c);
		printf("\n");
	}
	return 0;
}
void dfs(long long int d,long long int c1)
{
	c1++;
	node *p;
	if(c<c1)
	{
		//printf("a: %lld ",d);
		go=d;
		c=c1;
	}
	//printf("\n%lld",d);
	p=a[d];
	vis[d]=1;	
	while(p!=NULL)
	{
		d=p->v;
		if(!vis[d])
			dfs(d,c1);
		p=p->next;
	}
}
void adjlist(long long int v1,long long int v2)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node));
	q->v=v2;
	q->next=NULL;
	if(a[v1]==NULL)
		a[v1]=q;
	else
	{
		p=a[v1];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	
	}

	node *p1,*q1;
	q1=(node*)malloc(sizeof(node));
	q1->v=v1;
	q1->next=NULL;
	if(a[v2]==NULL)
		a[v2]=q1;
	else
	{
		p1=a[v2];
		while(p1->next!=NULL)
			p1=p1->next;
		p1->next=q1;
	
	}
}
