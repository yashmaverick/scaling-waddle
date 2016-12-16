#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *next;
} node;

node* insert(node *l,int v)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	t->data=v;
	t->next=l;
	return t;
}

int depth=0;
int leaf=1;

void finddepth(node **g,int p,int c,int d)
{
	if(d>depth)
	{
		depth=d;
		leaf=c;
	}
	node *t=g[c];
	while(t!=NULL)
	{
		if(t->data!=p)
			finddepth(g,c,t->data,d+1);
		t=t->next;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,u,v;
		scanf("%d",&n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		node **list;
		list=(node **)calloc(n+1,sizeof(node *));
		for(i=0;i<=n;i++)
			list[i]=NULL;
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			list[u]=insert(list[u],v);
			list[v]=insert(list[v],u);
		}
		depth=0;
		list[0]=insert(list[0],1);
		finddepth(list,0,1,0);
		depth=0;
		list[0]->data=leaf;
		finddepth(list,0,leaf,0);
		printf("%d\n",depth+1);
	}
	return 0;
}
