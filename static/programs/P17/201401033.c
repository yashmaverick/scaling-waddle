#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
}node;
node* root;
int mycnt=0;
node* tree(int pre[],int in[],int low,int high)
{
	if(low>high)
		return NULL;
	node* temp=malloc(sizeof(node));
	temp->val=pre[mycnt++];
	temp->left=NULL;
	temp->right=NULL;
	if(low==high)
		return temp;
	int i,ind;
	for(i=low;i<=high;i++)
	{
		if(in[i]==temp->val)
		{
			ind=i;
			break;
		}
	}
	temp->left=tree(pre,in,low,ind-1);
	temp->right=tree(pre,in,ind+1,high);
	return temp;
}
node* lca(node* root,int x,int y)
{
	if(root==NULL)
		return NULL;
	if(root->val==x || root->val==y)
		return root;
	node *lefti=lca(root->left,x,y);
	node* righti=lca(root->right,x,y);
	if(lefti && righti)
		return root;
	if(lefti!=NULL)
		return lefti;
	return righti;
}
/*void printpost(node* t)
  {
  if(t!=NULL)
  {
  printpost(t->left);
  printf("%d ",t->val);
  printpost(t->right);
  }
  }*/
int main()
{
	int tc,n,i,x,y;
	scanf("%d",&n);
	int *pre=malloc(n*sizeof(int));
	int *in=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	root=tree(pre,in,0,n-1);
	//printpost(root);
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&x,&y);
		node* t=lca(root,x,y);
		printf("%d\n",t->val);
	}
	return 0;
}
