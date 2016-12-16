#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int value;
	struct tree *left;
	struct tree *right;
}tree;

int inorder(int in[],int x,int low,int high)
{
	int l;
	for(l=low;l<=high;l++)
	{
		if(in[l]==x)
		{
			return l;
		}
	}
}

tree *buildtree(int pre[],int in[],int low,int high)
{
	int x;
	static int j=0;
	tree *root;
	if(low>high)
	{
		return NULL;
	}
	root=(tree *)malloc(sizeof(tree));
	root->value=pre[j++];
	if(low==high)
	{
		return root;
	}
	x=inorder(in,root->value,low,high);
	root->left=buildtree(pre,in,low,x-1);
	root->right=buildtree(pre,in,x+1,high);
	return root;
}

void printinorder(tree *root)
{
	if(root==NULL)
	{
		return ;
	}
	else
	{
		printinorder(root->left);
		printf("%d ",root->value);
		printinorder(root->right);
	}
}

tree *leastca(tree *root,int a,int b)
{
	tree *temp1,*temp2;
	if(root==NULL)
	{
		return NULL;
	}
	if(root->value==a || root->value==b)
	{
		return root;
	}
	temp1=leastca(root->left,a,b);
	temp2=leastca(root->right,a,b);
	if(temp1 && temp2)
	{
		return root;
	}
	if(temp1!=NULL)
	{
		return temp1;
	}
	else
	{
		return temp2;
	}
}

int main()
{
	int n,x,a,b,i;
	tree *root;
	int y;
	scanf("%d",&n);
	int pre[n],in[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	root=buildtree(pre,in,0,n-1);
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d %d",&a,&b);	
		y=leastca(root,a,b)->value;
		printf("%d\n",y);
	}
	return 0;
}
