#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct avl
{
	int data;
	struct avl* parent;
	struct avl* left;
	struct avl* right;
	int height;
	int left_elem;
	int right_elem;
}avl;

avl* root=NULL;

void assign_h(avl *temp)
{
	int l,r;
	while(temp!=NULL)
    {
		if(temp->left==NULL)
			l=0;
		else
			l=temp->left->height;
		if(temp->right==NULL)
			r=0;
		else
			r=temp->right->height;
		temp->height=(l>r)?l:r;
		temp->height++;
		temp=temp->parent;
    }
}

void insert_node(avl* temp,avl* base)
{
	if(temp->data<=base->data)
		if(base->left==NULL)
		{
			base->left_elem++;
			base->left=temp;
			temp->parent=base;
		}
		else
		{
			base->left_elem++;
			insert_node(temp,base->left);
		}
	else
		if(base->right==NULL)
		{
			base->right=temp;
			temp->parent=base;
			base->right_elem++;
		}
		else
		{
			base->right_elem++;
			insert_node(temp,base->right);
		}
}

void rotate_right(avl *x,avl *y)
{
	if(x==NULL||y==NULL)
		return;
	y->left_elem=x->right_elem;
	x->right_elem=y->left_elem+y->right_elem+1;
	if(y->parent==NULL)
    {
		root=x;
		x->parent=NULL;
    }
	else
    {
		if(y->parent->left==y)
			y->parent->left=x;
		else
			y->parent->right=x;
		x->parent=y->parent;
    }
	y->left=x->right;
	if(x->right!=NULL)
		x->right->parent=y;
	x->right=y;
	y->parent=x;
	y->height-=2;
	assign_h(x);
}

void rotate_left(avl *x,avl *y)
{
	if(x==NULL||y==NULL)
		return;
	x->right_elem=y->left_elem;
	y->left_elem=x->right_elem+x->left_elem+1;
	if(x->parent==NULL)
    {
		root=y;
		y->parent=NULL;
    }
	else
    {
		if(x->parent->left==x)
			x->parent->left=y;
		else
			x->parent->right=y;
		y->parent=x->parent;
    }
	x->right=y->left;
	if(y->left!=NULL)
		y->left->parent=x;
	y->left=x;
	x->parent=y;
	x->height-=2;
	assign_h(y);
}

int ret_balance(avl *temp)
{
	if(temp==NULL)
		return 0;
	int l=0,r=0;
	if(temp->left!=NULL)
		l=temp->left->height;
	if(temp->right!=NULL)
		r=temp->right->height;
	return l-r;
}

void balance_tree(avl *temp)
{
	if(temp==NULL)
		return;
	int h;
	int lower;
	h=ret_balance(temp);
	if(h>1)          //left heavy
    {
		lower=ret_balance(temp->left);
		if(lower>0)          //left heavy
		{
			rotate_right(temp->left,temp);
		}
		else if(lower<0)          //right heavy
		{
			rotate_left(temp->left,temp->left->right);
			rotate_right(temp->left,temp);
		}
    }
	else if(h<-1)          //right heavy
    {
		lower=ret_balance(temp->right);
		if(lower<0)          //right heavy
		{
			rotate_left(temp,temp->right);
		}
		else if(lower>0)          //left heavy
		{
			rotate_right(temp->right->left,temp->right);
			rotate_left(temp,temp->right);
		}
    }
	balance_tree(temp->parent);
}

void create_node(int data)
{
	avl* temp=(avl*)malloc(sizeof(avl));
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	temp->data=data;
	temp->height=1;
	temp->left_elem=0;
	temp->right_elem=0;
	if(root==NULL)
		root=temp;
	else
    {
		insert_node(temp,root);
		assign_h(temp);
		balance_tree(temp);
    }
}

avl* find(int data,avl* pos)
{
	if(pos==NULL)
		return NULL;
	if(data==pos->data)
		return pos;
	else if(data<pos->data)
		return find(data,pos->left);
	else
		return find(data,pos->right);
}

avl *q[100005];
int front=-1,rear=0;

void level_order()
{
	if(root==NULL)
		return;
	int count;
	q[++front]=root->left;
	q[++front]=root->right;
	printf("%d:%d\n",root->data,root->height);
	count=2;
	while(front!=rear-1)
    {
		count=front-rear+1;
		while(count--)
		{
			avl *temp=q[front];
			if(temp==NULL)
				printf("' ':' '|");
			else
				printf("%d:%d|",temp->data,temp->height);
			if(temp!=NULL)
			{
				q[++front]=temp->left;
				q[++front]=temp->right;
			}
			rear++;
		}
		printf("\n");
    }
}

void pre_order(avl *node)
{
	printf("%d",node->data);
	if(node->left!=NULL)
    {
		printf("(");
		pre_order(node->left);
		printf(")");
    } 
	if(node->right!=NULL)
    {
		printf("(");
		pre_order(node->right);
		printf(")");
    }
}

void in_order(avl *node)
{
	if(node->left!=NULL)
    {
		printf("(");
		in_order(node->left);
		printf(")");
    }
	printf("%d:%d[%d:%d]",node->data,node->height,node->left_elem,node->right_elem);
	if(node->right!=NULL)
    {
		printf("(");
		in_order(node->right);
		printf(")");
    }
}

int count;
int query;

void check_health(avl *node)
{
	if(node->left!=NULL)
		check_health(node->left);
	count++;
	if(query==count)
		printf("%d\n",node->data);
	if(node->right!=NULL)
		check_health(node->right);
}

void rotten_before(int num,avl* temp)
{
	if(temp==NULL)
		return;
	if(temp->data>=num)
		rotten_before(num,temp->left);
	else
	{
		count+=temp->left_elem+1;
		rotten_before(num,temp->right);
	}
}

void post_order(avl *node)
{
	if(node->left!=NULL)
    {
		printf("(");
		post_order(node->left);
		printf(")");
    }    
	if(node->right!=NULL)
    {
		printf("(");
		post_order(node->right);
		printf(")");
    }
	printf("%d",node->data);
}

int main()
{
	char input[15];
	int temp;
	while(1)
    {
		scanf("%s",input);
		if(strcmp(input,"SetHealthy")==0)
		{
			scanf("%d",&temp);
			create_node(temp);			
		}
		else if(strcmp(input,"CheckHealthy")==0)
		{
			scanf("%d",&temp);
			if(find(temp,root)==NULL)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else if(strcmp(input,"Healthy")==0)
		{
			scanf("%d",&temp);
			count=0;
			query=temp;
			check_health(root);
			if(count<temp)
				printf("NONE\n");			
		}
		else if(strcmp(input,"RottenBefore")==0)
		{
			scanf("%d",&temp);
			count=0;
			rotten_before(temp,root);
			printf("%d\n",count);			
		}
		else
			return 0;
	}
	return 0;
}
