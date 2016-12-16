/*Longest path in a tree*/

#include<stdio.h>
//#include<malloc.h>
#include<string.h>

struct node
{
	int num;
	struct node *next;
};

struct node *adjlist[1000005];
char visited[1000005];
int dist[1000005];

void dfs(int, int);

int main()
{
	int i, max, maxdist, N, u, v, t;
	struct node *nodeptr;
	struct node *ptr;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			adjlist[i] = NULL;
		memset(visited, 0, sizeof(char)*(N + 1));
		for (i = 1; i < N; i++)
		{
			scanf("%d %d", &u, &v);
			nodeptr = (struct node *)malloc(sizeof(struct node));
			nodeptr->num = v;
			nodeptr->next = adjlist[u];
			adjlist[u] = nodeptr;
			nodeptr = (struct node *)malloc(sizeof(struct node));
			nodeptr->num = u;
			nodeptr->next = adjlist[v];
			adjlist[v] = nodeptr;
		}
		dist[1] = 0;
		dfs(1, 0);
		max = 0;
		for (i = 1; i <= N; i++)
			if (dist[max] < dist[i])
				max = i;
		memset(visited, 0, sizeof(char)*(N + 1));
		dfs(max, 0);
		maxdist = 0;
		for (i = 1; i <= N; i++)
			if (maxdist < dist[i])
				maxdist = dist[i];
		printf("%d\n", maxdist + 1);
		for (i = 1; i <= N; i++)
		{
			nodeptr = adjlist[i];
			while (nodeptr != NULL)
			{
				ptr = nodeptr->next;
				free(nodeptr);
				nodeptr = ptr;
			}
		}
	}
	return 0;
}

void dfs(int u, int n)
{
	struct node *nodeptr;
	visited[u] = 1;
	dist[u] = n;
	for (nodeptr = adjlist[u]; nodeptr != NULL; nodeptr = nodeptr->next)
		if (!visited[nodeptr->num])
			dfs(nodeptr->num, n + 1);
}