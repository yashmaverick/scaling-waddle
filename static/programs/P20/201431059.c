#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

typedef node* ptr;

ptr insert(ptr head,int val)
{
	ptr p = (ptr)malloc(sizeof(node));
	p->val = val;
	p->next = head;
	return p;
}
ptr erase(ptr head)
{
	if(!head)
		return NULL;
	head->next = erase(head->next);
	free(head);
	return NULL;
}

ptr graph[1000010];
int deg[1000010];
int dist[1000010];
int visited[1000010];
int dfs(int u)
{
	visited[u]=1;
	node* it;
	int mx = u;
	for(it=graph[u];it!=NULL;it = it->next)
		if(!visited[it->val])
		{
			dist[it->val] = dist[u]+1;
			int ret = dfs(it->val);
			if(dist[ret] > dist[mx])
				mx = ret;
		}
	return mx;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			graph[u] = insert(graph[u],v);
			graph[v] = insert(graph[v],u);
		}
		dist[1]=0;
		for(i=0;i<=(n+1);i++)
			visited[i]=0;
		int leaf = dfs(1);
		dist[leaf]=0;
		for(i=0;i<=(n+1);i++)
			visited[i]=0;
		int ans = dfs(leaf);
		printf("%d\n",dist[ans]+1);
		for(i=1;i<=n;i++)
			graph[i] = erase(graph[i]);
	}
	return 0;
}
