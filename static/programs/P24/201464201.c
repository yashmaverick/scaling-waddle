#include<stdio.h>
#include<stdlib.h>
typedef struct avl
{
	int data;
	struct avl *left;
	struct avl *right;
	int height;
	int rc;
	int lc;
	int tot;
}node;

node *rr(node *q)
{
	node *x,*t2;
	x=q->left;
	t2=x->right;
	x->right=q;
	q->left=t2;
	int lc;
	int rc;
	lc=lcount(q->left);
	q->lc=lc;
	rc=rcount(q->right);
	q->rc=rc;
	q->tot=lc+rc+1;
	int h1,h2;
	int u=1;
	while(u!=1)
	{
		if(u!=1)
		{
			break;
		}
	}
	h1=height(q->left);
	h2=height(q->right);
	if(h1>h2)
	{
		q->height=h1+1;
	}
	else
	{
		q->height=h2+1;
	}
	lc=lcount(x->left);
	x->lc=lc;
	rc=rcount(x->right);
	x->rc=rc;
	x->tot=lc+rc+1;
	h1=height(x->left);
	h2=height(x->right);
	if(h1>h2)
	{
		x->height=h1+1;
	}
	else
	{
		x->height=h2+1;
	}
	return x;
}

node *lr(node *q)
{
	node *y;node *t2;
	y=q->right;
	t2=y->left;
	y->left=q;
	q->right=t2;
	int lc;
	int rc;
	lc=lcount(q->left);
	q->lc=lc;
	rc=rcount(q->right);
	q->rc=rc;
	q->tot=lc+rc+1;
	int h1,h2;
	h1=height(q->left);
	h2=height(q->right);
	if(h1>h2)
	{
		q->height=h1+1;
	}
	else
	{
		q->height=h2+1;
	}
	lc=lcount(y->left);
	y->lc=lc;
	rc=rcount(y->right);
	y->rc=rc;
	y->tot=lc+rc+1;
	h1=height(y->left);
	h2=height(y->right);
	if(h1>h2)
	{
		y->height=h1+1;
	}
	else
	{
		y->height=h2+1;
	}
	return y;
}
int lcount(node *q)
{
	if(q==NULL)
	{
		return 0;
	}
	else
	{
		return q->tot;
	}
}
int rcount(node *q)
{
	if(q==NULL)
	{
		return 0;
	}
	else
	{
		return q->tot;
	}
}
node *insert(node *q,int val)
{
	if(q==NULL)
	{
		q=(node *)malloc(sizeof(node));
		q->data=val;
		q->left=NULL;
		q->right=NULL;
		q->height=1;
		q->lc=0;
		q->rc=0;
		q->tot=1;
		return q;
	}
	else if(val<q->data)
	{
		q->left=insert(q->left,val);
	}
	else if(val>q->data)
	{
		q->right=insert(q->right,val);
	}
	int lc;
	int rc;
	lc=lcount(q->left);
	q->lc=lc;
	rc=rcount(q->right);
	q->rc=rc;
	q->tot=lc+rc+1;
	int h1;
	int h2;
	h1=height(q->left);
	h2=height(q->right);
	if(h1>h2)
	{
		q->height=h1+1;
	}
	else
	{
		q->height=h2+1;
	}
	int diff=h1-h2;
	if(diff>1)
	{
		if(val>q->left->data)
		{
			q->left=lr(q->left);
			return rr(q);
		}
		else
		{
			return rr(q);
		}
	}
	else if(diff<-1)
	{
		if(val>q->right->data)
		{
			return lr(q);
		}
		else
		{
			q->right=rr(q->right);
			return lr(q);
		}
	}
	return q;
}


int height(node *q)
{
	if(q==NULL)
	{
		return 0;
	}
	return q->height;
}
int check(node *q,int val)
{
	if(q==NULL)
	{
	//	printf("NO\n");
		return 0;
	}
	else if(q->data==val)
	{
	//	printf("YES\n");
		return 1;
	}
	else
	{
		while(q->data!=val)
		{
			//	printf("%d\n",q->data);
			if(val<q->data)
			{
				q=q->left;
			}
			else if(val>q->data)
			{
				q=q->right;
			}
			if(q==NULL)
			{
		//		printf("NO\n");
				return 0;
				break;
			}
			else if(q->data==val)
			{
		//		printf("YES\n");
				return 1;
				break;
			}
		}
	}
}
void inorder(node *q)
{
	if(q!=NULL)
	{
		inorder(q->left);
		inorder(q->right);
		printf("%d %d %d\n",q->data,q->height,q->tot);
	}
}
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int rotten(int a[],int x,int front,int last)
{
	long long int mid=(front+last)/2;
	if(x>a[last])
	{
		return last+1;
	}
	else if(a[mid]==x)
	{
		return mid;
	}
	else if(a[mid]<x && a[mid+1]>x)
	{
		return mid +1;
	}
	else if(a[mid]>x && a[mid-1]<x)
	{
		return mid;
	}
	else if(x<a[mid])
	{
		rotten(a,x,front,mid-1);
	}
	else if(x>a[mid])
	{
		rotten(a,x,mid+1,last);
	}
}
void rottenbefore(node *q,int val)
{
	int count=0;
	if(q->data==val)
	{
		count=q->lc;
	}
	else
	{
		while(q->data!=val)
		{
			if(q->left==NULL && q->right==NULL)
			{
				if(q->data<val)
					count++;
				break;
			}	
			if(q->left==NULL && q->right->data<val)
			{
				count=count+1;
				q=q->right;
			}
			else if(q->left==NULL && q->right->data>=val)
			{
				if(q->data<val)
				{
					count=count+q->lc+1;
					q=q->right;
				}
				else
				{
					count=count+q->lc;
					break;
				}
			}
			else if(q->right==NULL && q->left->data>val) 
			{
				q=q->left;
			}
			else if(q->right==NULL && q->left->data<=val)
			{
				if(q->data<val)
				{
					count=count+q->lc+1;
					break;
				}
				else
				{
			//		count=count+q->lc;
					q=q->left;
				}
			}/*
			else if(q->left->data<val && q->right->data>val && q->data!=val)
			{
				if(q->data<val)
				{
					count=count+q->lc+1;
					break;
				}
				else
				{
					count=count+q->lc;
					break;
				}
			}*/
			else if(q->data>val)
			{
				q=q->left;

			}
			else if(q->data<val)
			{
				count=count+q->lc+1;
				q=q->right;
			}
			if(q->data==val)
			{
				count=count+q->lc;
				break;
			}

		}
	}
	printf("%d\n",count);
}

void health(node *q,int val)
{
	if(q->lc==val-1)
	{
		printf("%d\n", q->data);
	}
	else
	{
		if(q->lc>val-1)
		{
			health(q->left,val);
		}
		else
		{
			health(q->right,val-q->lc-1);
		}
	}
}	
int main()
{
	node *root;
	root=NULL;
	int i,j,k,x,p,ind,max,min,flag=0,test=0;
	p=-1;
	int count=0;
	char s[102];
	max=0;
	while(1)
	{	
		scanf("%s", s);
		if(s[0]=='Q')
		{
			return 0;
		}
		scanf("%d", &x);
		if(s[0]=='S')
		{
			test=check(root,x);
		//	printf("%d\n", test);
			if(test==0)
			{
				root=insert(root,x);
				count++;
			}
			//	inorder(root);
			if(flag==0)
			{
				min=x;
				flag=1;
			}
			if(x<min)
			{
				min=x;
			}
			if(x>max)
			{
				max=x;
			}
		}
		else if(s[0]=='C')
		{
		
			//		inorder(root);
			test=check(root,x);
			if(test==1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else if(s[0]=='H')
		{
		
			if(x>count)
			{
				printf("NONE\n");
			}
			else
			{
				health(root,x);
			}
		}
		else if(s[0]=='R')
		{
			if(x<=min)
			{
				printf("0\n");
			}
			else if(x>max)
			{
				printf("%d\n",count);
			}
			else
			{
				rottenbefore(root,x);
			}
		}
	}
	return 0;
}


