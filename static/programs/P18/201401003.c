#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
	long long int ver;
	struct list *next;
}list;
long long int visited[10009];
void insert(list *a[],long long int i, long long int v)
{
	list *temp=(list *)malloc(sizeof(list));
	temp->ver=v;
	temp->next=a[i];
	a[i]=temp;
	return ;
}
void dfs(list *a[],long long int u)
{
//	printf("%lld\n",u);
	visited[u]=1;
	list *temp=a[u];
	while(temp)
	{
		if(!visited[temp->ver])
		{
			dfs(a,temp->ver);
		}
		temp=temp->next;
	}
	return ;
}
int main()
{
	list *adj[1009],*adj2[1009];
	long long int t,n,m,i,j,flag,ans,v,p;
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		for(i=0;i<1009;i++)
		{
			adj[i]=NULL;
			adj2[i]=NULL;
		}
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&m);
			for(j=0;j<m;j++)
			{
				scanf("%lld",&v);
				insert(adj,v-1,i);
				insert(adj2,i,v-1);
			}
		}
		/*		for(i=0;i<n;i++)
				{
				printf("%lld:",i);
				list *temp=adj[i];
				while(temp)
				{
				printf("%lld ",temp->ver);
				temp=temp->next;
				}
				printf("\n");
				}*/
		memset(visited,0,sizeof(visited));
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				p=i;
				dfs(adj,i);
			}
		}
//		printf("%lld\n",p);
		flag=0;
		memset(visited,0,sizeof(visited));
		dfs(adj,p);
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
//				printf("%lld\n",i);
				flag=1;
			}
		}
		
		if(flag)
			printf("0\n");
		else
		{
			memset(visited,0,sizeof(visited));
			dfs(adj2,p);
			for(i=0;i<n;i++)
			{
				if(visited[i])
				{
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
