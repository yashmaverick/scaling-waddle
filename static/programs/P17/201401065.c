#include<stdio.h>
#include<stdlib.h>

/*typedef struct tree
{
	int data;
	struct tree *l;
	struct tree *r;
} node;*/

int h=0;

void genparent(int a[20],int b[20],int x,int y,int par[20],int p,int l[20],int lev)
{
	if(x>y)
		return;
	par[a[h++]]=p;
	l[a[h-1]]=lev;
	if(x==y)
		return;
	p=a[h-1];
	int idx=b[a[h-1]];
	genparent(a,b,x,idx-1,par,p,l,lev+1);
	genparent(a,b,idx+1,y,par,p,l,lev+1);
}

/*void preorder(node *g)
{
	if(g!=NULL)
	{
		printf("%d ",g->data);
		preorder(g->l);
		preorder(g->r);
	}
}*/

int main()
{
	int n,pre[100000],revin[100000],i,t,parent[100000],level[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		revin[t]=i;
	}
	genparent(pre,revin,0,n-1,parent,0,level,0);
	//preorder(root);
	//for(i=1;i<=n;i++) printf("%d ",parent[i]);printf("\n");
	//for(i=1;i<=n;i++) printf("%d ",level[i]);printf("\n");
	scanf("%d",&t);
	while(t--)
	{
		int a,b,pa,pb;
		scanf("%d %d",&a,&b);
		if(level[a]>=level[b])
		{
			pa=a;pb=b;
			int c=level[a]-level[b];
			while(c--)
				pa=parent[pa];
			while(pa!=pb)
			{
				pa=parent[pa];
				pb=parent[pb];
			}
		}
		else if(level[a]<level[b])
		{
			pa=a;pb=b;
			int c=level[b]-level[a];
			while(c--)
				pb=parent[pb];
			while(pa!=pb)
			{
				pa=parent[pa];
				pb=parent[pb];
			}
		}
		printf("%d\n",pa);
	}
	return 0;
}
