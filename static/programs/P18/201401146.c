#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int val;
	node *down;
};
node* insert(node* head,int x)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->val=x;
	tmp->down=head;
	return tmp;
}
node* adj[1001];
int* jda[1001];
int vis[1001],N;
void reset(int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		adj[i]=NULL;
		jda[i]=NULL;
	}
	return;
}
void reset_vis(int n)
{
	int i;
	for(i=1;i<=n;i++)
		vis[i]=0;
	N=0;
	return;
}
void print(int n)
{
	int i,l,j;
	int *tmp;
	for(i=1;i<=n;i++)
	{
		tmp=jda[i];
		l=tmp[0];
		for(j=1;j<=l;j++)
			printf("%d-->%d\n",i,tmp[j]);
	}
}
void printG(node *adj[],int n)
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
}
void DFS(int x)
{
	N++;
	node *tmp;
	tmp=adj[x];
	vis[x]=1;
	while(tmp)
	{
		if(!vis[tmp->val])
			DFS(tmp->val);
		tmp=tmp->down;
	}	
	return;
}
void DFS_after(int x)
{
	int *tmp;
	tmp=jda[x];
	vis[x]=1;
	int i,l;
	l=tmp[0];
	for(i=1;i<=l;i++)
	{
		if(!vis[tmp[i]])
		{
			DFS_after(tmp[i]);
			N++;
		}
	}	
	return;
}
int main()
{
	int n,i,a,b,t,s,j,flag,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		reset(n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&s);
			jda[i]=(int*)malloc((sizeof(int))*(s+1));
			jda[i][0]=s;
			for(j=1;j<=s;j++)
			{
				scanf("%d",&x);
				adj[x]=insert(adj[x],i);
				jda[i][j]=x;	
			}
		}
		//print(n);
		//printG(adj,n);
		flag=0;
		for(i=1;i<=n;i++)
		{
			reset_vis(n);
			if(adj[i])
				DFS(i);
			if(N==n)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("0\n");
			continue;
		}
		//printf("%d\n",i);
		reset_vis(n);
		N=1;
		DFS_after(i);
		printf("%d\n",N);
	}
	return 0;
}
