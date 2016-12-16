#include <stdio.h>
#include <stdlib.h>

#define MAX 50000
int vis[MAX], in[MAX], comp[MAX];
typedef struct node 
{
	int v;
	struct node * next;
}node;
node *a[MAX], *b[MAX];
node * insert(int v, node* root)
{
	node * tmp = (node *)malloc(sizeof(node));
	tmp->v = v;
	tmp->next = root;
	return tmp;
}
int stk1[MAX * 10], itr=-1;
void dfs1(int source)
{
	vis[source] = 1;
	node *temp = a[source];
	while (temp)
	{
		if (!vis[temp->v])
			dfs1(temp->v);
		temp = temp->next;
	}
	stk1[++itr] = source;
	free(temp);
}
void dfs2(int source, int count)
{
	vis[source] = 0;
	comp[source] = count;
	node *temp = b[source];
	while (temp)
	{
		if (vis[temp->v])
			dfs2(temp->v, count);
		temp = temp->next;
	}
	free(temp);
}
int main()
{
	int i, t, n, m, u, cnt, ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i <= n; i++)
		{
			vis[i] = in[i] = 0;
			a[i] = b[i] = NULL;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			while (m--)
			{
				scanf("%d", &u);
				a[u] = insert(i, a[u]);
				b[i] = insert(u, b[i]);
			}
		}
		/*node *temp;
		for (i = 1; i <= n; i++)
		{
			temp = a[i];
			while (temp)
			{
				printf("%d ", temp->v);
				temp = temp->next;
			}
			puts("");
		}
		for (i = 1; i <= n; i++)
		{
			temp = b[i];
			while (temp)
			{
				printf("%d ", temp->v);
				temp = temp->next;
			}
			puts("");
		}*/
		itr = -1;
		for (i = 1; i <= n; i++)
			if (!vis[i])
				dfs1(i);
		cnt = 0;
		for (i = itr; i >= 0; i--)
			if (vis[stk1[i]])
				dfs2(stk1[i], cnt++);
		for (i = 1; i <= n; i++)
		{
			node *temp = a[i];
			while (temp)
			{
				if (comp[i] != comp[temp->v])
					in[comp[temp->v]]+=1;
				temp = temp->next;
			}
			free(temp);
		}
		ans = 0;
		for (i = 0; i < cnt; i++)
			if (!in[i])
				ans++;
		if (ans > 1)
			printf("0\n");
		else
		{
			ans = 0;
			for (i = 1; i <= n; i++)
				if (!in[comp[i]])
					ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}