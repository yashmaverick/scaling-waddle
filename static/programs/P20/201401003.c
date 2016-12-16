#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
	long long int ver;
	struct list* next;
}list;
list* adj[1000009];
long long int visited[1000009],level,node;
list* insert(long long int u,long long int v)
{
	list* temp=(list *)malloc(sizeof(list));
	temp->ver=v-1;
	temp->next=adj[u-1];
	return temp;
}
void dfs(long long int u,long long int l)
{
	visited[u]=1;
	if(l>level)
	{
		level=l;
		node=u;
	}
	list* temp=adj[u];
	while(temp)
	{
		if(!visited[temp->ver])
		{
			dfs(temp->ver,l+1);
		}
		temp=temp->next;
	}
	return ;
}
int main()
{
	long long int t,n,u,v,i;
	scanf("%lld",&t);
	while(t--)
	{
		for(i=0;i<1000009;i++)
		{
			adj[i]=NULL;
		}
		scanf("%lld",&n);
		for(i=1;i<n;i++)
		{
			scanf("%lld %lld",&u,&v);
			adj[u-1]=insert(u,v);
			adj[v-1]=insert(v,u);
		}
		level=0;
		memset(visited,0,sizeof(visited));
		dfs(0,1);
		level=0;
		memset(visited,0,sizeof(visited));
		dfs(node,1);
		printf("%lld\n",level);
	}
	return 0;
}
