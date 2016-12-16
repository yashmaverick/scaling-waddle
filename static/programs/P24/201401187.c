#include<stdio.h>
#include<stdlib.h>
int f;
typedef struct node
{
	int val;
	int height;
	int c;
	struct node *left;
	struct node *right;
}node;
node* root=NULL;
/*void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}*/
int count(node* x)
{
	if(x==NULL)
		return 0;
	return x->c;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int high(node* x)
{
	if(x==NULL)
		return 0;
	return x->height;
}
node* newnode(int v)
{
	node* new=(node*)malloc(sizeof(node));
	new->val=v;
	new->left=NULL;
	new->right=NULL;
	new->height=1;
	new->c=1;
	return new;
}
node* rr(node* y)
{
	node* x=y->left;
	node* t2=x->right;
	x->right=y;
	y->left=t2;
	y->height=max(high(y->left),high(y->right))+1;
	y->c=count(y->left)+count(y->right)+1;
	x->height=max(high(x->left),high(x->right))+1;
	x->c=count(x->left)+count(x->right)+1;
	return x;
}
node* lr(node* x)
{
	node* y=x->right;
	node* t2=y->left;
	y->left=x;
	x->right=t2;
	x->height=max(high(x->left),high(x->right))+1;
	x->c=count(x->left)+count(x->right)+1;
	y->height=max(high(y->left),high(y->right))+1;
	y->c=count(y->left)+count(y->right)+1;
	return y;
}
node* insert(node* temp,int v)
{
	int bal;
	if(temp==NULL)
	{
		return(newnode(v));
	}
	if(v<temp->val)
		temp->left=insert(temp->left,v);
	else
		temp->right=insert(temp->right,v);
	temp->height=max(high(temp->left),high(temp->right))+1;
	temp->c=count(temp->left)+count(temp->right)+1;
	if(temp==NULL)
		bal=0;
	else
		bal=high(temp->left)-high(temp->right);
	if(bal>1&&v<temp->left->val)
	{
		temp=rr(temp);
		return temp;
	}
	if(bal<-1&&v>temp->right->val)
	{
		temp=lr(temp);
		return temp;
	}
	if(bal>1&&v>temp->left->val)
	{
		temp->left=lr(temp->left);
		temp=rr(temp);
		return temp;
	}
	if(bal<-1&&v<temp->right->val)
	{
		temp->right=rr(temp->right);
		temp=lr(temp);
		return temp;
	}
	return temp;
}
/*void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}*/
int healthy(node* a,int v)
{
//		printf("cnt=%d\n",count(a));
	if(v>count(a))
	{
		return -1;
	}
	if(count(a)==1)
		return a->val;
	if(v<(count(a->left)+1))
		return healthy(a->left,v);
	else if(v==count(a->left)+1)
		return a->val;
	else
		return healthy(a->right,v-count(a->left)-1);
}
void check(node* a,int v)
{
	if(a==NULL)
		return ;
	if(a->val==v)
		f=1;
	if(f!=1)
	{
		if(v<a->val)
			check(a->left,v);
		else
			check(a->right,v);
	}
}
int rotten(node* a,int v)
{
	if(a==NULL)
		return 0;
	if(a->val>=v)
		return rotten(a->left,v);
	else if(a->val<v)
		return count(a->left)+1+rotten(a->right,v);
}
int main()
{
	int x,h,v;
	char s[1000];
	while(1)
	{
		f=0;
		scanf("%s",s);
		if(s[0]=='C')
		{
			scanf("%d",&v);
			check(root,v);
			if(f==1)
				printf("YES\n");
			else
				printf("NO\n");
//			inorder(root);
//			printf("\n");
		}
		else if(s[0]=='S')
		{
			scanf("%d",&v);
			root=insert(root,v);
//			inorder(root);
//			printf("\n");
		}
		else if(s[0]=='H')
		{
			scanf("%d",&v);
			h=healthy(root,v);
			if(h!=-1)
				printf("%d\n",h);
			else
			{
//				printf("h=%d\n",h);
				printf("NONE\n");
			}
//			inorder(root);
//			printf("\n");
		}
		else if(s[0]=='R')
		{
			scanf("%d",&v);
			printf("%d\n",rotten(root,v));
		}
		else
			break;
	}
	//		scanf("%d",&x);
	//		root=insert(root,x);
	//	inorder(root);
	return 0;
}
