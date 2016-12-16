#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct graph
{
	int data;
	struct graph *next;
} node;

node* insert(node *l,int v)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	t->data=v;
	t->next=l;
	return t;
}

void print(node *l)
{
	while(l!=NULL)
	{
		printf("%d ",l->data);
		l=l->next;
	}
}

int check(int b[1001],int n)
{
	int i;
	for(i=1;i<=n;i++)
		if(b[i]==0)
			return 0;
	return 1;
}

void checkdfs(node **g,int i,int b[1001])
{
	b[i]=1;
	node *t=g[i];
	while(t!=NULL)
	{
		if(b[t->data]==0)
			checkdfs(g,t->data,b);
		t=t->next;
	}
}

int s=0;

/*int find1(node **g,int i,int b[1001])
{
	b[i]=1;
	node *t=g[i];
	while(t!=NULL)
	{
		if(b[t->data]==0)
			return find1(g,t->data,b);
		t=t->next;
	}
	return i;
}*/

void findall(node **g,int i,int b[1001])
{
	b[i]=1;
	s++;
	node *t=g[i];
	while(t!=NULL)
	{
		if(b[t->data]==0)
			findall(g,t->data,b);
		t=t->next;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		node **list;
		list=(node **)calloc(n+1,sizeof(node *));
		node **tlist;
		tlist=(node **)calloc(n+1,sizeof(node *));
		for(i=1;i<=n;i++)
			tlist[i]=NULL;
		for(i=1;i<=n;i++)
		{
			int m;
			scanf("%d",&m);
			list[i]=NULL;
			while(m--)
			{
				int a;
				scanf("%d",&a);
				list[i]=insert(list[i],a);
				tlist[a]=insert(tlist[a],i);
			}
		}
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		int bv[1001],fl=0,st;
		for(i=1;i<=n;i++)
		{
			memset(bv,0,sizeof(bv));
			checkdfs(tlist,i,bv);
			if(check(bv,n))
			{
				st=i;
				fl=1;
				break;
			}
		}
		s=0;
		if(fl)
		{
			memset(bv,0,sizeof(bv));
			findall(list,st,bv);
		}
		printf("%d\n",s);
		free(list);
		free(tlist);
	}
	return 0;
}
