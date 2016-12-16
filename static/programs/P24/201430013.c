#include<stdio.h>
#include<stdlib.h>
#define print(m) printf("%d\n",m)
#define scan(m) scanf("%d",&m)
#define scans(m) scanf("%s",m)
typedef struct node node;
int height(node* root);
int mod(int m)
{
	if(m<0)
		return -m;
	return m;
}
int max(int m,int n)
{
	if(m>n)
	{
		return m;
	}
	return n;
}
struct node{
	int val;
	node* left;
	node* right;
	int height;
	int count1;
	int count2;
};
node *remake_tree(node* root);
int check(node *root)
{
	if(mod(height(root->right)-height(root->left))<=1)
	{
		return 1;
	}
	return 0;
}
int height(node *root)
{
	if(root==NULL)
		return 0;
	return root->height;
}
void func(node* root)
{
	root->count1=0;
	root->count2=0;
	if(root->left!=NULL)
		root->count1+=root->left->count1+root->left->count2+1;
	if(root->right!=NULL)
		root->count2+=root->right->count1+root->right->count2+1;
}
void fine(node* root)
{
	if(root!=NULL)
		root->height=max(height(root->left),height(root->right))+1;
}
node* insert(node *root,int value)
{
	if(root==NULL)
	{
		node* r=(node*)malloc(sizeof(node));
		r->val=value;
		r->left=NULL;
		r->right=NULL;
		r->height=1;
		r->count1=0;
		r->count2=0;
		return r;
	}
	if(root->val>value)
		root->left=insert(root->left,value);
	else
		root->right=insert(root->right,value);
	fine(root);
	func(root);
	if(check(root)!=1)
	{
		node* new=remake_tree(root);
		return new;
	}
	else
		return root;
}
node *remake_tree(node* root)
{
	node *new=root;
	if(height(root->left)>height(root->right))
	{
		if(height(root->left->left)>height(root->left->right))
		{
			root=root->left;
			new->left=root->right;
			root->right=new;
			fine(new);
			fine(root);
			func(new);
			func(root);
			return root;
		}
		else
		{
			root=root->left->right;
			new->left->right=root->left;
			root->left=new->left;
			new->left=root->right;
			root->right=new;
			fine(root->left);
			fine(new);
			fine(root);
			func(new);
			func(root->left);
			func(root);
			return root;
		}
	}
	else if(height(root->right)>height(root->left))
	{
		if(height(root->right->left)<height(root->right->right))
		{
			root=root->right;
			new->right=root->left;
			root->left=new;
			fine(new);
			fine(root);
			func(new);
			func(root);
			return root;
		}
		else
		{
			root=root->right->left;
			new->right->left=root->right;
			root->right=new->right;
			new->right=root->left;
			root->left=new;
			fine(new);
			fine(root->right);
			fine(root);
			func(new);
			func(root->right);
			func(root);
			return root;
		}
	}
}
int find(node* root,int q)
{
	if(root->count1==q-1)
		return root->val;
	if(root->count1>=q)
		return find(root->left,q);
	else
		return find(root->right,q-root->count1-1);
}
int move(node* root,int q)
{
	if(root==NULL)
		return 0;
	if(root->val==q)
		return root->count1;
	if(root->val>q)
		return move(root->left,q);
	else
		return  root->count1+1+move(root->right,q);
}
int abc(node* root,int value)
{
	if(root==NULL)
		return 0;
	if(root->val==value)
		return 1;
	if(root->val>value)
		return abc(root->left,value);
	else
		return abc(root->right,value);
}
int main()
{
	int n,j;
	scanf("%d",&n);
	int i;
	node* root=NULL;
	char s[200];
	while(1)
	{
		int q;
		scans(s);
		if(s[0]=='C')
		{
			scan(q);
			if(abc(root,q)==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		if(s[0]=='S')
		{
			scan(q);
			root=insert(root,q);
		}
		if(s[0]=='H')
		{
			scan(q);
			if(root->count1+root->count2+1<q)
				printf("NONE\n");
			else
			{
				int result=find(root,q);
				printf("%d\n",result);
			}
		}
		if(s[0]=='R')
		{
			scan(q);
			printf("%d\n",move(root,q));
		}
		if(s[0]=='Q')
			break;
	}
	return 0;
}
