#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *next;
} Node;

Node *arr[1000001];

Node *insert(int v, Node *node)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = v;
	temp->next = node;
	return temp;
}

int vis[1000001];
int lev[1000001];

void dfs(int v)
{
	vis[v] = 1;
	Node *temp = arr[v];
	while(temp != NULL)
	{
		if(!vis[temp->data])
		{
			lev[temp->data] = lev[v]+1;
			dfs(temp->data);
		}
		temp = temp->next;
	}
}

int max(int n)
{
	int max=0, idx;
	int i;
	for(i=1; i<=n; i++)
	{
		if(lev[i] > max)
		{
			max = lev[i];
			idx = i;
		}
	}
	return idx;
}

void print(int n)
{
	int i;
	for(i=1; i<=n; i++)
	{   
		Node *curr = arr[i];
		printf("%d --> ", i); 
		while(curr != NULL)
		{   
			printf("%d ", curr->data);
			curr = curr->next;
		}   
		printf("\n");
	}   
}

int main()
{
	int t, n, i, u, v, idx;
	scanf("%d", &t);
	while(t--)
	{
		idx = 0;
		memset(vis, 0, sizeof(vis));
		memset(lev, 0, sizeof(lev));
		scanf("%d", &n);
		for(i=0; i<n-1; i++)
		{
			scanf("%d%d", &u, &v);
			arr[u] = insert(v, arr[u]);
			arr[v] = insert(u, arr[v]);
		}

		dfs(1);

		/*	print(n);
			for(i=1; i<=n; i++)
			printf("%d ", vis[i]);
			printf("\n");
			for(i=1; i<=n; i++)
			printf("%d ", lev[i]);
			printf("\n");
		*/
		
		idx = max(n);

//		memset(vis, 0, sizeof(vis));
//		memset(lev, 0, sizeof(lev));
		
		for(i=0; i<=n; i++)
		{
			vis[i] = 0;
			lev[i] = 0;
		}

		dfs(idx);
		printf("%d\n", lev[max(n)]+1);
		
		for(i=1; i<=n; i++)
			arr[i] = NULL;

//		memset(vis, 0, sizeof(vis));
//		memset(lev, 0, sizeof(lev));
		
		for(i=0; i<=n; i++)
		{
			vis[i] = 0;
			lev[i] = 0;
		}
	}
	return 0;
}
