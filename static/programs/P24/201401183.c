#include<stdio.h>
#include<stdlib.h>
int fla,h,c,fl;
int flag,f;
typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
	int height;
	int count;
}node;
//int max(int a, int b);
int height(struct node *x)
{
	if (x==NULL)
		return 0;
	return x->height;
}
struct node* newNode(int val)
{
	node* n=(node*)	malloc(sizeof(node));
	n->val=val;
	n->left=NULL;
	n->right=NULL;
	n->height=1;  
	n->count=1;
	return n;
}
struct node *rightRotate(struct node *y)
{
	node *x=y->left;
	node *T=x->right;
	x->right=y;
	y->left=T;
	int a=height(y->left);
	int b=height(y->right);
	y->height=(y->height=a>b?a:b)+1;
	y->count=count(y->left)+count(y->right)+1;
	a=height(x->left);
	b=height(x->right);
	x->height=(x->height=a>b?a:b)+1;
	x->count=count(x->left)+count(x->right)+1;
	return x;
}
struct node *leftRotate(struct node *x)
{
	node *y=x->right;
	node *T=y->left;
	y->left=x;
	x->right=T;
	int a=height(x->left);
	int b=height(x->right);
	x->height=(x->height=a>b?a:b)+1;
	x->count=count(x->left)+count(x->right)+1;
	a=height(y->left);
	b=height(y->right);
	y->height=(y->height=a>b?a:b)+1;
	y->count=count(y->left)+count(y->right)+1;
	return y;
}
int balance(struct node *x)
{
	if (x==NULL)
		return 0;
	return (height(x->left)-height(x->right));
}
struct node* insert(struct node* node, int val)
{

	if(node==NULL)
		return newNode(val);

	if (val<node->val)
		node->left=insert(node->left, val);
	else
		node->right=insert(node->right, val);
	int h1,h2;
	h1=height(node->left);
	h2=height(node->right);
	node->height =( node->height=h1>h2?h1:h2) + 1;
	node->count=count(node->left)+count(node->right)+1;


	   
	int bal=balance(node);


	if (bal>1)
    {
            if(val>node->left->val)
            {
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
    }


	if (bal<-1)
	{
            if(val<node->right->val)
            {
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
    }
    if (bal>1&&val<node->left->val)
                    return rightRotate(node);


        if (bal<-1&&val>node->right->val)
                        return leftRotate(node);

	return node;
}
int count(struct node* x)
{
	if(x==NULL)
		return 0;
//	else return count(x->left)+count(x->right)+1;
	return x->count;
}
/*void inorder(struct node* x)
{
	if(x==NULL)
		return;
	else
	{
		inorder(x->left);
		printf("%d",x->val);
		inorder(x->right);
	}
}*/
void checkhealthy(struct node* x,int i)
{
	if(x==NULL)
		return;
	if(x->val==i)
		fla=1;
	if(fla!=1)
	{
		if(i<x->val)
			checkhealthy(x->left,i);
		else
			checkhealthy(x->right,i);
	}
}
/*void healthy(struct node* x,int i)
{
	if(x==NULL)
		return;
	else if(f!=1)
	{
		healthy(x->left,i);
		c++;
		if(c==i)
		{
			f=1;
			h=x->val;
		}
		healthy(x->right,i);
	}
}*/
int healthy(struct node* x, int i)
{
//	printf("x is %d x: %d i: %d \n",x->val,count(x),i);
	if(i>count(x))
		return -1;
	if(count(x)==1)return x->val;
	if(i<(count(x->left)+1))
	return healthy(x->left,i);
	else if(i==(count(x->left)+1))
	return x->val;
	else return healthy(x->right,i-count(x->left)-1);
}
/*void rotten(struct node* x,int i)
{
	if(x==NULL)
		return;
	else if(fl!=1)
	{
		rotten(x->left,i);
		if(x->val==i)
			fl=1;
		else if(fl!=1)count++;
		rotten(x->right,i);
	}
}*/
int rotten(struct node* x,int i)
{
	if(x==NULL)
		return 0;
	if(x->val>=i)
		return rotten(x->left,i);
	else if(x->val<i)
		return count(x->left)+1+rotten(x->right,i);
}
int main()
{
	char s[1000];
	int n,i;
	scanf("%s",s);
	struct node* root=NULL;
	while(s[0]!='Q')
	{
		flag=0;
		f=0,fl=0,fla=0,c=0;
		if(s[0]=='C')
		{
			scanf("%d",&n);
			checkhealthy(root,n);
			if(fla==1) printf("YES\n");
			else printf("NO\n");
		}
		else if(s[0]=='S')
		{
			scanf("%d",&n);
			root=insert(root,n);
//			inorder(root);
//			printf("\n");
		}
		else if(s[0]=='H')
		{
			scanf("%d",&n);
		//	healthy(root,n);
			//if(f==1) printf("%d\n",h);
	//		checkhealthy(root,n);
			h=healthy(root,n);
			if(h!=-1)
			{
				printf("%d\n",h);
			}
			else printf("NONE\n");
		}
		else if(s[0]=='R')
		{
			scanf("%d",&n);
			//rotten(root,n);
			//printf("%d\n",count);
			printf("%d\n",rotten(root,n));
		}
		scanf("%s",s);
	}
	return 0;
}

