#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    int l;
    int r;
    struct node *left;
    struct node *right;
    int height;
}name;
typedef name* ptr;
int max(int a,int b)
{
    if(a>b)
    {
	return a;
    }
    else
    {
	return b;
    }
}
int mod(int a)
{
    if(a<0)
    {
	return -a;
    }
    return a;
}
int height(ptr root)
{
    if(root==NULL)
    {
	return 0;
    }
    return root->height;
}
ptr rightrotate(ptr y)
{
    ptr x=y->left;
    ptr tree2=x->right;
    int ly=y->l;
    int ry=y->r;
    int lx=x->l;
    int rx=x->r;
    x->right=y;
    y->left=tree2;
    y->l=rx;
    x->r=rx+ry+1;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
int condition(ptr root)
{
    if(root==NULL)
    {
	return 0;
    }
    return height(root->left)-height(root->right);
}
ptr leftrotate(ptr x)
{
    ptr y=x->right;
    ptr tree2=y->left;
    int ly=y->l;
    int ry=y->r;
    int lx=x->l;
    int rx=x->r;
    y->left=x;
    x->right=tree2;
    x->r=ly;
    y->l=1+lx+ly;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
ptr insert(ptr root,int n)
{
    if(root==NULL)
    {
	ptr tmp=(ptr)malloc(sizeof(name));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->l=0;
	tmp->r=0;
	tmp->value=n;
	tmp->height=1;
	return tmp;
    }
    if(n<(root->value))
    {
	root->l++;
	root->left=insert(root->left,n);
    }
    else
    {
	root->r++;
	root->right=insert(root->right,n);
    }
    root->height=max(height(root->left),height(root->right))+1;
    int cond=condition(root);
    if(cond>1&&n<root->left->value)
    {
	return rightrotate(root);
    }
    if(cond<-1&&n>=root->right->value)
    {
	return leftrotate(root);
    }
    if(cond>1&&n>root->left->value)
    {
	root->left=leftrotate(root->left);
	return rightrotate(root);
    }
    if(cond<-1&&n<root->right->value)
    {
	root->right=rightrotate(root->right);
	return leftrotate(root);
    }
    return root;
}
void preorder(ptr root)
{
    if(root==NULL)
    {
	return ;
    }
    else
    {
	printf("%d ",root->value);
	preorder(root->left);
	preorder(root->right);
    }
}
int binarys(ptr root,int x)
{
    if(root==NULL)
    {
	return 0;
    }
    else if(root->value==x)
    {
	return 1;
    }
    else if(x<(root->value))
    {
	return binarys(root->left,x);
    }
    else
    {
	return binarys(root->right,x);
    }
}
int binaryleft(ptr root,int x)
{
    int ans=0;
    ptr tmp=root;
    if(root==NULL)
    {
	return 0;
    }
    while(tmp!=NULL)
    {
	if(x<(tmp->value))
	{
	    tmp=tmp->left;
	}
	else if(x==tmp->value)
	{
	    ans=ans+tmp->l;
	    return ans;
	}
	else if(x>tmp->value)
	{
	    ans=ans+tmp->l+1;
	    tmp=tmp->right;
	}
    }
    return  ans;
}
int returx(ptr root,int x)
{
    if(root==NULL)
    {
	return 0;
    }
    if(x==root->l+1)
    {
	return root->value;
    }
    else if(x<=root->l)
    {
	return returx(root->left,x);
    }
    else
    {
	return returx(root->right,x-(root->l)-1);
    }
}
int main()
{
    char A[1000];
    ptr root = NULL;
    int x;
    while(1)
    {
	scanf("%s",A);
	if(A[0]=='S')
	{
	    scanf("%d",&x);
	    root=insert(root,x);
	}
	else if(A[0]=='C')
	{
	    scanf("%d",&x);
	    if(binarys(root,x))
	    {
		printf("YES\n");
	    }
	    else
	    {
		printf("NO\n");
	    }
	}
	else if(A[0]=='H')
	{
	    scanf("%d",&x);
	    int tmp=returx(root,x);
	    if(tmp==0)
	    {
		printf("NONE\n");
	    }
	    else
	    {
		printf("%d\n",tmp);
	    }
	}
	else if(A[0]=='R')
	{
	    scanf("%d",&x);
	    printf("%d\n",binaryleft(root,x));
	}
	else
	{
	    break;
	}
    }
    return 0;
}





