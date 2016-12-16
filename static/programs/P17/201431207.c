#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

int search(int arr[], int strt, int end, int value);
struct node* newNode(int data);

struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if(inStrt > inEnd)
		return NULL;

	struct node *tNode = newNode(pre[preIndex++]);

	if(inStrt == inEnd)
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->data);

	tNode->left = buildTree(in, pre, inStrt, inIndex-1);
	tNode->right = buildTree(in, pre, inIndex+1, inEnd);

	return tNode;
}

int search(int arr[], int strt, int end, int value)
{
	int i;
	for(i = strt; i <= end; i++)
	{
		if(arr[i] == value)
			return i;
	}
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
int findLCA(struct node* root, int n1, int n2)
{
	if (root == NULL) return -2;
	if (root->data == n1 || root->data == n2)
		return root->data;      
	int left_lca  = findLCA(root->left, n1, n2);
	int right_lca = findLCA(root->right, n1, n2);
	if (left_lca!=-2 && right_lca!=-2)  return root->data;                
	return (left_lca != -2)? left_lca: right_lca;                  
}
int main()
{
	int count,pre[100000],in[100000],test,i,ans;
	scanf("%d",&count);
	for(i=0;i<count;i++)       	
		scanf("%d",&pre[i]);
	for(i=0;i<count;i++)       	
		scanf("%d",&in[i]);
	struct node *root = buildTree(in, pre, 0, count-1);
	scanf("%d",&test);
	int n1,n2;
	while(test--)
	{
		scanf("%d%d",&n1,&n2);
		ans=findLCA(root,n1,n2);
		printf("%d\n",ans);
	}
	return 0;
}
