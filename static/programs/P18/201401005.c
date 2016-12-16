#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *next;
} Node;

Node *arr[123456];
Node *vec[123456];
int vis[123456];
int count;

Node *insert(int data, Node *node)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = node;
	return temp;
}

void dfs(int v,Node *ar[])
{
	//	memset(vis, 0, sizeof(vis));
	vis[v] = 1;
	Node *temp = ar[v];

	while(temp != NULL)
	{
		if(!vis[temp->data])
			dfs(temp->data,ar);
		temp = temp->next;
	}
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
	int n, r, x, i, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%d", &r);
			while(r--)
			{
				scanf("%d", &x);
				arr[x] = insert(i, arr[x]);
				vec[i] = insert(x, vec[i]);
			}
		}
		int ans = 0,counter;
		for(i=1; i<=n; i++)
		{
			memset(vis, 0, sizeof(vis));
			count = 0;
			dfs(i,arr);
			int j;
			 counter=0;
			for(j=1;j<=n;j++)
				if(vis[j])
						counter++;
			if(counter==n)
				break;
		}
		memset(vis, 0, sizeof(vis));
		if(counter==n)
		{
			dfs(i,vec);
			counter=0;
			int j;
			for(j=1;j<=n;j++)
				if(vis[j])
						counter++;
			printf("%d\n",counter);
		}
		else
			printf("0\n");
		
		for(i=1; i<=n; i++)
		{
			arr[i] = NULL;
			vec[i]=NULL;
		}
	}

	return 0;
}
