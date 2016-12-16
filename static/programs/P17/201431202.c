#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;
	NODE *root;
int j=1;
int pre[100000]={},in[100000]={};
int LCA(NODE *root,int a,int b)
{
	if(root==NULL)
	{
		return -1;
	}
	if(root->data==a || root->data==b)
		return root->data;
	int left=LCA(root->left,a,b);
	int right=LCA(root->right,a,b);
	if(left!=-1 && right!=-1)
		return root->data;
	else
	{
		if(left==-1)
			return right;
		else
			return left;
	}
}
int search(int n,int tof)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(in[i]==tof)
		{
			break;
		}
	}
	return i;
}
NODE *buildtree(int n,int low,int high)
{
	if(low>high)
	{
		return NULL;
	}
	NODE *root=malloc(sizeof(NODE));
	root->data=pre[j++];
	if(low==high)
		return root;
	int f=search(n,root->data);
	root->left=buildtree(n,low,f-1);
	root->right=buildtree(n,f+1,high);
	return root;
}
void print(NODE *root)
{
	if(root==NULL)
		return ;
	printf("%d ",root->data);
	print(root->left);
	print(root->right);
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&in[i]);
	}
	root=buildtree(n,1,n);
	//printf("********\n");
	//print(root);
	int t,c,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&c,&b);
		printf("%d\n",LCA(root,c,b));
	}
	return 0;
}
