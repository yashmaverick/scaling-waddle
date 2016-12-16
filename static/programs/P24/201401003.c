//Shubham Vijayvargiya
#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a)>(b)?(a):(b)
typedef struct avl
{
	long long int data,height,lnodes,rnodes;
	struct avl *left,*right;
}avl;
long long int balance_factor(avl *root)
{
	if(!(root->left) && !(root->right))
		return 0;
	else if(!(root->left))
		return (-(root->right->height));
	else if(!(root->right))
		return (root->left->height);
	else
		return ((root->left->height)-(root->right->height));
}
avl* left_rotate(avl* root)
{
	avl* y=root->left;
	root->left=y->right;
	y->right=root;
	if(!(root->left))
		root->lnodes=0;
	else
		root->lnodes=(root->left->lnodes)+1+(root->left->rnodes);
	if(!(root->right))
		root->rnodes=0;
	else
		root->rnodes=(root->right->lnodes)+(root->right->rnodes)+1;
	if(!(y->left))
		y->lnodes=0;
	else
		y->lnodes=(y->left->lnodes)+1+(y->left->rnodes);
	if(!(y->right))
		y->rnodes=0;
	else
		y->rnodes=(y->right->lnodes)+(y->right->rnodes)+1;
	if(!(root->left) && !(root->right))
		root->height=1;
	else if(!(root->left))
		root->height=(root->right->height)+1;
	else if(!(root->right))
		root->height=(root->left->height)+1;
	else
		root->height=max(root->left->height,root->right->height)+1;
	if(!(y->left) && !(y->right))
		y->height=1;
	else if(!(y->left))
		y->height=(y->right->height)+1;
	else if(!(y->right))
		y->height=(y->left->height)+1;
	else
		y->height=max(y->left->height,y->right->height)+1;
	return y;
}
avl* right_rotate(avl* root)
{
	avl* y=root->right;
	root->right=y->left;
	y->left=root;
	if(!(root->left))
		root->lnodes=0;
	else
		root->lnodes=(root->left->lnodes)+1+(root->left->rnodes);
	if(!(root->right))
		root->rnodes=0;
	else
		root->rnodes=(root->right->lnodes)+(root->right->rnodes)+1;
	if(!(y->left))
		y->lnodes=0;
	else
	{
	//	printf("%lld %lld %lld\n",y->left->data,y->left->lnodes,y->left->rnodes);
		y->lnodes=(y->left->lnodes)+1+(y->left->rnodes);
	}
	if(!(y->right))
		y->rnodes=0;
	else
		y->rnodes=(y->right->lnodes)+(y->right->rnodes)+1;
	if(!(root->left) && !(root->right))
		root->height=1;
	else if(!(root->left))
		root->height=(root->right->height)+1;
	else if(!(root->right))
		root->height=(root->left->height)+1;
	else
		root->height=max(root->left->height,root->right->height)+1;
	if(!(y->left) && !(y->right))
		y->height=1;
	else if(!(y->left))
		y->height=(y->right->height)+1;
	else if(!(y->right))
		y->height=(y->left->height)+1;
	else
		y->height=max(y->left->height,y->right->height)+1;
	return y;
}
avl* insert(avl *root,long long int x)
{
	if(!(root))
	{
		root=(avl *)malloc(sizeof(avl));
		root->data=x;
		root->height=1;
		root->left=NULL;
		root->right=NULL;
		root->lnodes=0;
		root->rnodes=0;
		return root;
	}
	if(x>(root->data))
	{
		root->right=insert(root->right,x);
		root->rnodes=(root->right->rnodes)+(root->right->lnodes)+1;
		if(!(root->left) && !(root->right))
			root->height=1;
		else if(!(root->left))
			root->height=(root->right->height)+1;
		else
			root->height=max(root->left->height,root->right->height)+1;
		if(balance_factor(root)==-2)
		{
			if((root->right->data)<x)
			{
				return right_rotate(root);
			}
			else
			{
				root->right=left_rotate(root->right);
				return right_rotate(root);
			}
		}
	}
	else
	{
		root->left=insert(root->left,x);
		root->lnodes=(root->left->lnodes)+1+(root->left->rnodes);
		if(!(root->left) && !(root->right))
			root->height=1;
		else if(!(root->right))
			root->height=(root->left->height)+1;
		else
			root->height=max(root->left->height,root->right->height)+1;
		if(balance_factor(root)==2)
		{
			if((root->left->data)>x)
			{
				return left_rotate(root);
			}
			else
			{
				root->left=right_rotate(root->left);
				return left_rotate(root);
			}
		}
	}
	return root;
}
long long int find(avl* root,long long int x)
{
	if(!(root))
		return 0;
	else if((root->data)==x)
		return 1;
	else if((root->data)>=x)
		return find(root->left,x);
	else
		return find(root->right,x);
}
long long int ind(avl* root,long long int x)
{
	if(!root)
		return -1;
	if(((root->lnodes)+1)==x)
		return root->data;
	else if(((root->lnodes)+1)>x)
		return ind(root->left,x);
	else
		return ind(root->right,x-((root->lnodes)+1));
}
/*void preorder(avl* root)
{
	if(!root)
		return ;
	printf("%lld %lld %lld\n",root->data,root->lnodes,root->rnodes);
	preorder(root->left);
	preorder(root->right);
}*/
long long int bound(avl* root,long long int x)
{
	if(!(root))
		return 0;
	else if((root->data)==x)
	{
		return root->lnodes;
	}
	else if((root->data)>=x)
	{
		return bound(root->left,x);
	}
	else
	{
		return ((root->lnodes)+(bound(root->right,x))+1);
	}
}
int main()
{
	long long int q,n,x,ans,flag=0;
	char str[50];
	avl *root=NULL;
	while(1)
	{
		scanf("%s",str);
		if(!strcmp(str,"SetHealthy"))
		{
			scanf("%lld",&x);
			root=insert(root,x);
		}
		else if(!strcmp(str,"CheckHealthy"))
		{
			scanf("%lld",&x);
			if(find(root,x)==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(!strcmp(str,"Healthy"))
		{
			scanf("%lld",&x);
			ans=ind(root,x);
			if(ans==-1)
				printf("NONE\n");
			else
				printf("%lld\n",ans);
		}
	/*	else if(!strcmp(str,"pre"))
		{
			preorder(root);
		}*/
		else if(!strcmp(str,"RottenBefore"))
		{
			scanf("%lld",&x);
			printf("%lld\n",bound(root,x));
		}
		else if(!strcmp(str,"Quit"))
		{
			flag=1;
		}
		if(flag)
			break;
	}
	return 0;
}
