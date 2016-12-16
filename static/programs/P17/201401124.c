#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node *left;
	struct node *right;
}node;

node* lca(node* tree,int u,int v)
{
	if(tree==NULL)
		return NULL;
	if(tree->val==u)
		return tree;
	if(tree->val==v)
		return tree;
	node * llca=lca(tree->left,u,v);
	node * rlca=lca(tree->right,u,v);
	if(llca!=NULL && rlca!=NULL)
		return tree;
	if(llca!=NULL)
		return llca;
	else
		return rlca;
}
node* make(int in[],int pre[],int start,int end)
{
	//printf("enterted func\n");
	//printf("%d",index);
	static int index=0;
	//printf("%d",index);

	int ind,i;
	if(start > end)
		return NULL;
	node* tr=(node*)malloc(sizeof(node));
	tr->left=NULL;
	tr->right=NULL;
	tr->val=pre[index++];
	//index++;
	if(start==end)
		return tr;
	for(i=start;i<=end;i++)
	{
		if(in[i]==tr->val)
		{
			ind=i;
			break;
		}
	}
	tr->left=make(in,pre,start,ind-1);
	tr->right=make(in,pre,ind+1,end);
	return tr;
	
}
/*void inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->val);
		inorder(temp->right);
	}
	else return;
} 
*/
int main()
{
	int n,i,u,v,t;
	scanf("%d",&n);
	int in[n],pre[n];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
//node* tree=(node*)malloc(sizeof(node));
	node *tree=make(in,pre,0,n-1);
	scanf("%d",&t);
	node *ans=(node*)malloc(sizeof(node));
	while(t--)
	{
		scanf("%d %d",&u,&v);
		ans=lca(tree,u,v);
		printf("%d\n",ans->val);
	}
	return 0;
}
