#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt;
typedef struct tree
{
	int data,height,lc,rc;
	struct tree *left,*right;
}tree;
tree *root;
tree* createnode(int val)
{
	tree *temp=(tree*)malloc(sizeof(tree));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=val;
	temp->height=1;
	temp->lc=0;
	temp->rc=0;
	return temp;
}
tree* minimumnode(tree* node)
{
	tree* current=node;
	while(current!=NULL && current->left!=NULL)
		current=current->left;
	return current;
}
void postorder(tree* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d has lc=%d and rc=%d\n",root->data,root->lc,root->rc);
	}
}
tree* rightrot(tree *node)
{
	tree *l = node->left;
	tree *lr = l->right;

	//node->rc same
	node->lc=l->rc;
	
	//l->lc same
	l->rc=node->rc+node->lc+1;

	l->right=node;
	node->left=lr;
	int a,b;
	a=height(node->left,NULL),b=height(node->right,NULL);
	node->height=((a>b)?a:b)+1;
	a=height(l->left,NULL),b=height(l->right,NULL);
	l->height=((a>b)?a:b)+1;
	
	return l;
}
tree* leftrot(tree* node)
{
	tree *r = node->right;
	tree *rl = r->left;
	
	//node->lc is same
	node->rc=r->lc;
	
	//r->rc is same
	r->lc=node->lc+node->rc+1;
	
	r->left = node;
	node->right = rl;
	int a,b;
	a=height(node->left,NULL),b=height(node->right,NULL);
	node->height=((a>b)?a:b)+1;
	a=height(r->left,NULL),b=height(r->right,NULL);
	r->height=((a>b)?a:b)+1;
	return r;
}
void smallestk(tree* root,int k)
{
	while(k>0)
	{
		if(root==NULL)
		{
			printf("NONE\n");
			return;
		}
		if(root->lc>k-1)
			root=root->left;
		else if(root->lc==k-1)
		{
			printf("%d\n",root->data);
			return;
		}
		else
		{
			k-=root->lc+1;
			root=root->right;
		}
	}
}
int height(tree* a,tree* b)
{
	if(a==NULL && b==NULL)
		return 0;
	else if(a==NULL)
		return b->height;
	else if(b==NULL)
		return a->height;
	else
		return (a->height>b->height)?a->height:b->height;
}
tree* insert(tree* root,int val)
{
	if(root==NULL)
		return createnode(val);
	if(val<root->data)
	{
		root->lc+=1;
		root->left=insert(root->left,val);
	}
	else
	{
		root->rc+=1;
		root->right=insert(root->right,val);
	}
	root->height=height(root->left,root->right)+1;
	int bal=(root==NULL)?0:height(root->left,NULL)-height(root->right,NULL),ball=0,balr=0;
	if(bal<-1 || bal>1)
	{
		ball=(root->left==NULL)?0:height(root->left->left,NULL)-height(root->left->right,NULL);
		balr=(root->right==NULL)?0:height(root->right->left,NULL)-height(root->right->right,NULL);
	}
	if (bal>1 && ball>=0)
		return rightrot(root);
	if (bal<-1 && balr<=0)
		return leftrot(root);
	if (bal>1 && ball<0)
	{
		root->left=leftrot(root->left);
		return rightrot(root);
	}
	if (bal<-1 && balr>0)
	{
		root->right=rightrot(root->right);
		return leftrot(root);
	}
	return root;
}
int find(tree* root,int val)
{
	while(root!=NULL && root->data!=val)
		root=(root->data<val)?root->right:root->left;
	if(root==NULL)
		return 0;
	else
		return 1;
}
void count(tree* root,int val)
{
	if(root!=NULL)
	{
		if(root->data>=val)
			count(root->left,val);
		else
		{
			cnt+=root->lc+1;
			count(root->right,val);
		}
	}
}
int main()
{
	int val,tc;
	char c[30];
	char check[30]="CheckHealthy";
	char set[30]="SetHealthy";
	char heal[30]="Healthy";
	char rot[30]="RottenBefore";
	while(1)
	{
		scanf("%s",c);
		if(strcmp(c,check)==0)
		{
			scanf("%d",&val);
			if(!find(root,val))
				printf("NO\n");
			else
				printf("YES\n");
			continue;
		}
		if(strcmp(c,set)==0)
		{
			scanf("%d",&val);
			if(!find(root,val))
			{
				root=insert(root,val);
			}
			continue;
		}
		if(strcmp(c,heal)==0)
		{
			scanf("%d",&val);
			smallestk(root,val);
			continue;
		}
		if(strcmp(c,rot)==0)
		{
			cnt=0;
			scanf("%d",&val);
			count(root,val);
			printf("%d\n",cnt);
			continue;
		}
		break;
	}
	return 0;
}
