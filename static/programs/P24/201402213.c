#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a,height,size;
	struct node *left;
	struct node *right;
}node;
int state;
int max(int a,int b)
{
	return a>b?a:b;
}
int gh(node *root)
{
	if(root==NULL)
		return -1;
	else
		return root->height;
}
int gs(node *root)
{
	if(root==NULL)
		return 0;
	else
		return root->size;
}
node * leftrot(node *root)
{
	node *temp=root->right;
	root->right=temp->left;
	temp->left=root;
	root=temp;
	root->left->height=max(gh(root->left->left),gh(root->left->right))+1;
	root->left->size=gs(root->left->left)+gs(root->left->right)+1;
	root->height=max(gh(root->left),gh(root->right))+1;
	root->size=gs(root->left)+gs(root->right)+1;
	return root;
}
node * rightrot(node *root)
{	
	node *temp=root->left;
	root->left=temp->right;
	temp->right=root;
	root=temp;
	root->right->height=max(gh(root->right->left),gh(root->right->right))+1;
	root->right->size=gs(root->right->left)+gs(root->right->right)+1;
	root->height=max(gh(root->left),gh(root->right))+1;
	root->size=gs(root->left)+gs(root->right)+1;
	return root;
}
node * insert(int val,node *root)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->a=val;
		root->height=0;
		root->size=gs(root->left)+gs(root->right)+1;
		return root;
	}
	if(val<root->a)
		root->left=insert(val,root->left);
	else
		root->right=insert(val,root->right);
	root->height=max(gh(root->left),gh(root->right))+1;
	root->size=gs(root->left)+gs(root->right)+1;
	int l=gh(root->left),r=gh(root->right);
	if(l>=r+2)
	{
		if(gh(root->left->left)<gh(root->left->right))
			root->left=leftrot(root->left);
		root=rightrot(root);
	}
	if(r>=l+2)
	{
		if(gh(root->right->right)<gh(root->right->left))
			root->right=rightrot(root->right);
		root=leftrot(root);
	}
//	printf("%d ",root->size);
	return root;
}
void search(int val,node *root)
{
	if(root==NULL)
		return;
	if(root->a==val)
	{
		state=1;
		return;
	}
	if(val<root->a)
		search(val,root->left);
	else
		search(val,root->right);
}
int kth(int val,node *root,int smm)
{
	if(gs(root->left)+smm==val-1)
		return root->a;
	if(gs(root->left)+smm>val-1)
		return kth(val,root->left,smm);
	else
		return kth(val,root->right,smm+gs(root->left)+1);
}
int rot(int val,node *root,int smm)
{
	if(root==NULL)
		return smm;
	if(root->a==val)
		return gs(root->left)+smm;
	if(val<root->a)
		return rot(val,root->left,smm);
	else
		return rot(val,root->right,smm+gs(root->left)+1);
}
void in(node *root)
{
	if(root==NULL)
		return;
	in(root->left);
	printf("%d %d",root->a,gs(root));
	in(root->right);
}
int main()
{
	char s[20];
	int ss=0,maxnum=-1;
	scanf("%s",s);
	node *root=NULL;
	while(strcmp(s,"Quit")!=0)
	{
		int val;
		scanf("%d",&val);
		if(strcmp(s,"SetHealthy")==0)
		{
			ss++;
			root=insert(val,root);
		}
		if(strcmp(s,"CheckHealthy")==0)
		{
			state=0;
			search(val,root);
			if(state==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		if(strcmp(s,"Healthy")==0)
		{
			if(val>ss)
				printf("NONE\n");
			else
				printf("%d\n",kth(val,root,0));
		}
		if(strcmp(s,"RottenBefore")==0)
			printf("%d\n",rot(val,root,0));
		scanf("%s",s);
	}
	return 0;
}
