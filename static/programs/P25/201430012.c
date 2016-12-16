#include<stdio.h>
#include<stdlib.h>

struct edge_node
{
	int u, v;
	int cost;
};

struct nd
{
	int u;
	struct nd *next;
};
int node_parent[1000005], node_rank[1000005];
struct edge_node edge_list[1000005];
struct nd *arr[1000005];
int edge_comparator(const void *e1, const void *e2);
void union_set(int, int);
int find_root(int);
int visited[1000005];
void dfs(int i)
{
	visited[i]=1;
	struct nd *temp=arr[i];
	while(temp)
	{
		if(!visited[temp->u])
			dfs(temp->u);
		temp=temp->next;
	}
}
struct nd *insert(int v, struct nd *root)
{
	struct nd *tmp=(struct nd*)malloc(sizeof(struct nd));
	tmp->u=v;
	tmp->next=root;
	return tmp;
}
int main()
{
	int i, m, n, t;
	long long p, total_cost;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &(edge_list[i].u), &(edge_list[i].v), &(edge_list[i].cost));
		edge_list[i].u--;
		edge_list[i].v--;
		arr[edge_list[i].u]=insert(edge_list[i].v,arr[edge_list[i].u]);
		arr[edge_list[i].v]=insert(edge_list[i].u,arr[edge_list[i].v]);
	}
	qsort(edge_list, m,sizeof(struct edge_node), edge_comparator);
	for (i = 0; i < n; i++)
	{
		node_parent[i] = i;
		node_rank[i] = 0;
		visited[i]=0;
	}
	total_cost = 0;
	for (i = 0; i < m; i++)
	{
		if (find_root(edge_list[i].u) != find_root(edge_list[i].v))
		{
			union_set(edge_list[i].u, edge_list[i].v);
			total_cost += edge_list[i].cost;
		}
	}
	dfs(0);
	int cnt=0;
	for(i=0;i<n;i++)
		if(visited[i])
			cnt++;
	if(cnt==n)
		printf("%lld\n", total_cost);
	else
		puts("-1");
	return 0;
}
int edge_comparator(const void *e1, const void *e2)
{
	struct edge_node *element1, *element2;
	element1 = (struct edge_node *)e1;
	element2 = (struct edge_node *)e2;
	return element1->cost>element2->cost;
}

void union_set(int x, int y)
{
	int xroot, yroot;
	xroot = find_root(x);
	yroot = find_root(y);
	if (xroot == yroot)
		return;
	if (node_rank[xroot] < node_rank[yroot])
		node_parent[xroot] = yroot;
	else if (node_rank[xroot] > node_rank[yroot])
		node_parent[yroot] = xroot;
	else
	{
		node_parent[yroot] = xroot;
		node_rank[xroot]++;
	}
}

int find_root(int x)
{
	if (node_parent[x] != x)
		node_parent[x] = find_root(node_parent[x]);
	return node_parent[x];
}
