#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int val;
	node *down;
};
node* insert(node* root,int x)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->val=x;
	tmp->down=root;
	return tmp;
}
/*void printG(node *adj[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		node *tmp;
		tmp=adj[i];
		while(tmp)
		{
			printf("%d-->%d\n",i,tmp->val);
			tmp=tmp->down;
		}
	}
	return;
}*/
node* adj[1000000];
int vis[1000000],max,val;
void reset(int n)
{
	int i;
	for(i=0;i<=n;i++)
		adj[i]=NULL;
	return;
}
void vis_reset(int n)
{
	int i;
	for(i=0;i<=n;i++)
		vis[i]=0;
	max=0;
	return;
}
void DFS(int x,int d)
{
	if(d>max)
	{
		max=d;
		val=x;
	}
	if(vis[x])
		return;
	vis[x]=1;
	//printf("%d %d\n",x,d);
	node *tmp;
	tmp=adj[x];
	while(tmp)
	{
		if(!vis[tmp->val])
			DFS(tmp->val,d+1);
		tmp=tmp->down;
	}
	return;
}
int main()
{
	int n,x,i,a,b,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		reset(n);
		for(i=0;i<(n-1);i++)
		{
			scanf("%d%d",&a,&b);
			adj[a]=insert(adj[a],b);	
			adj[b]=insert(adj[b],a);	
		}
		//printG(adj,n);
		vis_reset(n);
		DFS(1,0);
		//printf("\n%d %d\n",val,max);
		vis_reset(n);
		DFS(val,0);
		printf("%d\n",max+1);
	}
	return 0;
}
