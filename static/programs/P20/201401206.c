#include<stdlib.h>
#include<stdio.h>
struct tree
{
	int no;
	struct tree *next;
};
typedef struct tree tree;
int max=0,found,vid[1000001];
void dfs(tree *new,int d,int ne,tree *root[])
{
	if(new->next==NULL && vid[new->no]==1)
	{
//		printf("%d %d\n",d,max);
		if(d>=max)
		{
			max=d;
			found=ne;
		}
		return;
	}
	while(new!=NULL)
	{
		if(vid[new->no]==0)
		{
			vid[new->no]=1;
			dfs(root[new->no],d+1,new->no,root);
		}
		new=new->next;
	}
}
tree* insert(tree *new,int u)
{
	if(new==NULL)
	{
		new=(tree*)malloc(sizeof(tree));
		new->no=u;
		new->next=NULL;
	}
	else
	{
		new->next=insert(new->next,u);
	}
	return new;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		int n,i;
		scanf("%d",&n);
		found=-1;
		tree *node[1000001]={NULL};
		int u,v;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			node[u]=insert(node[u],v);
			node[v]=insert(node[v],u);
			vid[i+1]=0;
		}
		vid[n]=0;
		vid[1]=1;
		dfs(node[1],0,1,node);
		for(i=1;i<=n;i++)
			vid[i]=0;
		vid[found]=1;
		max=0;
		dfs(node[found],1,found,node);
		printf("%d\n",max);
	}
	return 0;
}
