#include<stdio.h>
#include<stdlib.h>
int preindex=0;
struct node
{
	int data;
	struct node *l;
	struct node *r;
};
typedef struct node node;
node* treeform(int in[],int pre[],int start,int end)
{
	if(start > end)
		return NULL;
	node* root=(node*)malloc(sizeof(node));
	root->data=pre[preindex];
	root->l=NULL;
	root->r=NULL;
	int pointer;
	int i;
	for(i=start;i<=end;i++)
	{
		if(in[i]==pre[preindex])
		{
			pointer=i;
			break;
		}
	}
	preindex++;
	if(start==end)
		return root;
	else
	{
		root->l=treeform(in,pre,start,pointer-1);
		root->r=treeform(in,pre,pointer+1,end);
	}
	return root;
}
node* func(node* root,int a,int b)
{	
if(root==NULL)
		return root;
	if(root->data==a || root->data==b)
		return root;
	node* l=func(root->l,a,b);
	node* r=func(root->r,a,b);
	if(l&& r)
		return root;
	else
	{
		if(l)
			return l;
		else
			return r;
	}
}
int main()
{
	int nodes,query,i;
	scanf("%d",&nodes);
	int  pre[nodes];
	int  in[nodes];
	for(i=0;i<nodes;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<nodes;i++)
		scanf("%d",&in[i]);
	scanf("%d",&query);
	int js,ww;
	node* root=treeform(in,pre,0,nodes-1);
	while(query--)
	{
		scanf("%d %d",&js,&ww);	
		node* temp=func(root,js,ww);
		printf("%d\n",temp->data);
	}
	return 0;
}
