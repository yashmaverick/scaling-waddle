#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Node;

Node *root = NULL;
int idx[123456];

Node *preintree(int pre[], int in[], int l, int r)
{
	static int ind = 0;

	if(l > r)
		return NULL;
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = pre[ind++];
	temp->left = NULL;
	temp->right = NULL;
	if(l == r)
		return temp;

	temp->left = preintree(pre, in, l, idx[temp->data]-1);
	temp->right = preintree(pre, in, idx[temp->data]+1, r);

	return temp;
}


Node *lca(Node *node, int u, int v)
{
	if(node == NULL)
		return NULL;
	if(node->data==u || node->data==v)
		return node;

	Node *lst = lca(node->left, u, v);
	Node *rst = lca(node->right, u, v);

	if(lst!=NULL && rst!=NULL)
		return node;
	else
	{
		if(lst != NULL)
			return lst;
		else
			return rst;
	}
}

int main()
{
	int n, t, u, v, i;
	int pre[123456], in[123456];
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &pre[i]);
	for(i=0; i<n; i++)
		scanf("%d", &in[i]);
	for(i=0; i<n; i++)
		idx[in[i]] = i;
	root = preintree(pre, in, 0, n-1);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(root,u,v)->data);
	}


	return 0;
}
