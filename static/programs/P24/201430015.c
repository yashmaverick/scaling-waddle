#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int val;
	int ht;
	int nr;
	int nl;
	struct node *left;
	struct node *right;
}node;

node *head;

int lft(node *p)
{
	if(p->left==NULL)
	{
		return 0;
	}
	else
	{
		p->nl=p->left->nl+p->left->nr+1;
	}
	return p->nl;
}

int rght(node *p)
{
	if(p->right==NULL)
	{
		return 0;
	}
	else
	{
		p->nr=p->right->nr+p->right->nl+1;
	}
	return p->nr;
}


int height(node *p)
{
	if(p==NULL)
	{
		return -1;
	}
	if((p->left==NULL)&&(p->right==NULL))
	{	p->ht=0;
	}
	else if(p->left==NULL)
	{
		p->ht=p->right->ht+1;
	}
	else if(p->right==NULL)
	{
		p->ht=p->left->ht+1;
	}
	else if(p->right->ht>p->left->ht)
	{
		p->ht=p->right->ht+1;
	}
	else 
	{
		p->ht=p->left->ht+1;
	}
	return p->ht;
}

node *rshift(node *z)
{
	node *y,*temp;
	y=z->left;
	temp=y->right;
	y->right=z;
	z->left=temp;
	z->ht=height(z);
	z->nl=lft(z);
	z->nr=rght(z);	
	y->ht=height(y);
	y->nl=lft(y);
	y->nr=rght(y);	
	return y;
}

node *lshift(node *z)
{
	node *y,*temp;
	y=z->right;
	temp=y->left;
	y->left=z;
	z->right=temp;
	z->ht=height(z);
	y->ht=height(y);
	z->nl=lft(z);
	z->nr=rght(z);	
	y->ht=height(y);
	y->nl=lft(y);
	y->nr=rght(y);	
	return y;
}

node *insert(node *p,int x)
{
	int factor;
	if(p==NULL)
	{
		p=(node *)(malloc(sizeof(node)));
		p->left=NULL;
		p->right=NULL;
		p->val=x;
		p->ht=0;
		p->nl=0;
		p->nr=0;
		return p;
	}
	if(x<p->val)
	{
		p->left=insert(p->left,x);
		p->nl++;
	}
	else
	{
		p->right=insert(p->right,x);
		p->nr++;
	}
	p->ht=height(p);
	factor=height(p->left)-height(p->right);
	if(factor>1)
	{
		if(height(p->left->left)>height(p->left->right))
		{
			p=rshift(p);
		}
		else{
			p->left=lshift(p->left);
			p=rshift(p);
		}
	}
	else if(factor<-1)
	{
		if(height(p->right->right)>height(p->right->left))
		{
			p=lshift(p);
		}
		else{
			p->right=rshift(p->right);
			p=lshift(p);
		}
	}
	return p;
}
int located;
int locate(int x,node *p)
{
	if(p==NULL)
	{
		return;
	}
	if(p->nl==x-1)
	{
		located=p->val;
		return;
	}
	else if((p->nl)>x-1)
	{
		locate(x,p->left);
	}
	else 
	{
		locate(x-(p->nl)-1,p->right);
	}
}
int count;
void less(node *p,int x)
{
	if(p==NULL)
	{
		return;
	}
	if(p->val==x)
	{
		count+=p->nl;
	}
	else if(x>p->val)
	{
		count+=p->nl+1;
		less(p->right,x);
	}
	else if(x<p->val)
	{
		less(p->left,x);
	}
}
int find_flag;
void find(int x,node *p)
{
	if(p==NULL)
	{
		return;
	}
	if(x==p->val)
	{
		find_flag=1;
		return;
	}
	else if(x<p->val)
	{
		find(x,p->left);
	}
	else
	{
		find(x,p->right);
	}
}
/*
void inorder(node *p)
{
	if(p==NULL)
	{
		printf("\n");
		return;
	}
	inorder(p->left);
	printf("%d:%d, ",p->val,p->ht);
	inorder(p->right);
}

void preorder(node *p)
{
	if(p==NULL)
	{
		return;
	}
	printf("%d ",p->val);
	preorder(p->left);
	preorder(p->right);
}
*/
int main()
{
	int n,i,x;
	char str[20];
	str[0]='1';
	while(1)
	{
		scanf("%s",str);
		if(str[0]=='Q')
		{
			break;
		}
		scanf("%d",&x);

		if(str[0]=='S')
		{
			head=insert(head,x);
		}
		else if(str[0]=='C')
		{
			find_flag=0;
			find(x,head);
			if(find_flag==1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else if(str[0]=='H')
		{
			located=-1;
			locate(x,head);
			if(located==-1)
			{
				printf("NONE\n");
			}
			else
			{
				printf("%d\n",located);
			}
		}
		else if(str[0]=='R')
		{
			count=0;
			less(head,x);
			printf("%d\n",count);
		}
	}
	return 0;
}
