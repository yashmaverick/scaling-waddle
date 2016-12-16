#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long int
typedef struct node
{
	ll data;
	struct node *left,*right;
	int h,val,sz,ls,rs;
}node;

int d,c,j;
ll m;
int max(int a,int b)
{
	return a>b?a:b;
}

node * leftshift(node * x)
{
	node * y=x->right;
	node * tmp=y->left;
	y->left=x;
	x->right=tmp;
	//heights
	if(x->left!=NULL&&x->right!=NULL)
	{
		x->h=max(x->left->h,x->right->h)+1;
		x->ls=x->left->sz+1;
		x->rs=x->right->sz+1;
	}
	else if(x->left==NULL&&x->right==NULL)
	{
		x->h=0;x->ls=0;x->rs=0;
	}
	else if(x->left!=NULL)
	{
		x->h=x->left->h+1;
		x->ls=x->left->sz+1;
		x->rs=0;
	}
	else if(x->right!=NULL)
	{
		x->h=x->right->h+1;
		x->ls=0;
		x->rs=x->right->sz+1;
	}
	x->sz=x->rs+x->ls;

	if(y->left!=NULL&&y->right!=NULL)
	{
		y->h=max(y->left->h,y->right->h)+1;
		y->ls=y->left->sz+1;
		y->rs=y->right->sz+1;
	}
	else if(y->left==NULL&&y->right==NULL)
	{
		y->h=0;y->ls=0;y->rs=0;
	}
	else if(y->left!=NULL)
	{
		y->h=y->left->h+1;
		y->ls=y->left->sz+1;
		y->rs=0;
	}
	else if(y->right!=NULL)
	{
		y->h=y->right->h+1;
		y->ls=0;
		y->rs=y->right->sz+1;
	}
	y->sz=y->rs+y->ls;
	//printf("l %d\n",y->data);
	return y;
}

node * rightshift(node * x)
{
	node * y;
	y=x->left;
	node * tmp=y->right;
	y->right=x;
	x->left=tmp;
	//heights
	if(x->left!=NULL&&x->right!=NULL)
	{
		x->h=max(x->left->h,x->right->h)+1;
		x->ls=x->left->sz+1;
		x->rs=x->right->sz+1;
	}
	else if(x->left==NULL&&x->right==NULL)
	{
		x->h=0;x->ls=0;x->rs=0;
	}
	else if(x->left!=NULL)
	{
		x->h=x->left->h+1;
		x->ls=x->left->sz+1;
		x->rs=0;
	}
	else if(x->right!=NULL)
	{
		x->h=x->right->h+1;
		x->ls=0;
		x->rs=x->right->sz+1;
	}
	x->sz=x->ls+x->rs;

	if(y->left!=NULL&&y->right!=NULL)
	{
		y->h=max(y->left->h,y->right->h)+1;
		y->ls=y->left->sz+1;
		y->rs=y->right->sz+1;
	}
	else if(y->left==NULL&&y->right==NULL)
	{
		y->h=0;y->ls=0;y->rs=0;
	}
	else if(y->left!=NULL)
	{
		y->h=y->left->h+1;
		y->ls=y->left->sz+1;
		y->rs=0;
	}
	else if(y->right!=NULL)
	{
		y->h=y->right->h+1;
		y->ls=0;
		y->rs=y->right->sz+1;
	}
	y->sz=y->rs+y->ls;
	//printf("l %d\n",y->data);
	return y;
}

node * check(node * cur,int val)
{
	//printf("b\n");
	if(cur->left!=NULL&&cur->right!=NULL)
	{
		cur->h=max(cur->left->h,cur->right->h)+1;
		d=cur->right->h+1-cur->left->h-1;
		cur->ls=cur->left->sz+1;
		cur->rs=cur->right->sz+1;
	}
	else if(cur->left==NULL&&cur->right==NULL)
	{
		d=0;
		cur->h=0;cur->ls=0;cur->rs=0;
	}
	else if(cur->left!=NULL)
	{
		d=-cur->left->h-1;
		cur->h=cur->left->h+1;
		cur->ls=cur->left->sz+1;
		cur->rs=0;
	}
	else if(cur->right!=NULL)
	{
		d=cur->right->h+1;
		cur->h=cur->right->h+1;
		cur->ls=0;
		cur->rs=cur->right->sz+1;
	}
	cur->sz=cur->ls+cur->rs;
	//printf("%d\n",d);
	if(d<0)
	{
		d=-d;
		if(d>1)
		{
		//	printf("a\n");
			if(cur->left->data<val)
			{
				cur->left=leftshift(cur->left);
				//			printf("cur->left %d\n",cur->left->data);
			}
			cur=rightshift(cur);
		}
	}
	else if(d>1)
	{
		if(cur->right->data>=val)
		{
			cur->right=rightshift(cur->right);
			//		printf("cur->right %d\n",cur->right->data);
		}
		cur=leftshift(cur);
	}
	//printf("c %d\n",cur->data);
	return cur;
}

node * insert(node * cur,node * newnode)
{
	//printf("a\n");
	if(cur->left==NULL&&cur->data>=newnode->data)
	{
		//	printf("a %d\n",newnode->data);
		cur->left=newnode;
		cur=check(cur,newnode->data);
		//	printf("li %d\n",cur->data);
		return cur;
	}
	else if(cur->right==NULL&&cur->data<newnode->data)
	{
		cur->right=newnode;
		cur=check(cur,newnode->data);
		//	printf("ri %d\n",cur->data);
		return cur;
	}
	else if(cur->data>=newnode->data)
	{

		cur->left=insert(cur->left,newnode);
		cur=check(cur,newnode->data);
	}
	else if(cur->data<newnode->data)
	{
		cur->right=insert(cur->right,newnode);
		cur=check(cur,newnode->data);
	}
}

void postorder(node * cur)
{
	if(cur==NULL)
		return;
	postorder(cur->left);
	postorder(cur->right);
	printf("%lld %d %d %d %d\n",cur->data,cur->h,cur->ls,cur->rs,cur->sz);
}

int search(ll n,node * cur)
{
	while(cur!=NULL)
	{
		if(cur->data==n)
			return 1;
		else if(cur->data>n)
			cur=cur->left;
		else if(cur->data<n)
			cur=cur->right;
	}
	return 0;
}

void rb(ll n,node * cur)
{
	int sum=0;
	while(cur!=NULL)
	{
		if(cur->data==n)
		{
			sum+=cur->ls;
			printf("%d\n",sum);
			return ;
		}
		else if(cur->data>n)
			cur=cur->left;
		else if(cur->data<n)
		{
			sum+=cur->ls+1;
			cur=cur->right;
		}
	}
	printf("%d\n",sum);
	return;
}

void h(int n,node * cur)
{
	while(n>0&&cur!=NULL)
	{
		if(n==cur->ls+1)
		{
			printf("%lld\n",cur->data);
			return;
		}
		else if(n>cur->ls+1)
		{
			n-=cur->ls+1;
			cur=cur->right;
		}
		else if(n<cur->ls+1)
			cur=cur->left;
	}
}

char s[100];
int main()
{
	ll n;
	int t,i,f=0,x;
	node * newnode,*root;
	root=(node *)malloc(sizeof(node));
	while(1)
	{
		scanf("%s",s);
		//if(strcmp(s,"ch")==0)
		 if(strcmp(s,"CheckHealthy")==0)
		{
			scanf("%lld",&n);
			if(search(n,root))
				printf("YES\n");
			else
				printf("NO\n");
		}
		//else if(strcmp(s,"sh")==0)
		else if(strcmp(s,"SetHealthy")==0)
		{
			scanf("%lld",&n);
			newnode=(node *)malloc(sizeof(node));
			newnode->data=n;
			newnode->ls=0;newnode->rs=0;newnode->sz=0;
			newnode->h=0;
			if(f==0)
			{
				root=newnode;
				f=1;
			}
			else
				root=insert(root,newnode);
		}
		//else if(strcmp(s,"h")==0)
		else if(strcmp(s,"Healthy")==0)
		{
			scanf("%d",&x);
			//printf("%d %d %d\n",root->sz,root->ls,root->rs);
			if(x>root->sz+1)
				printf("NONE\n");
			else
				h(x,root);
		}
		else if(strcmp(s,"RottenBefore")==0)
		{
			scanf("%lld",&n);
			rb(n,root);
		}
		else if(strcmp(s,"Quit")==0)
			return 0;
	/*	else 
			postorder(root),printf("\n");*/
	}
	return 0;
}



