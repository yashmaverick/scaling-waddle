#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000009
int v=0;
typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
	int height;
	int child;
}node;

node* root;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int height(node* head)
{
	if(head==NULL)
		return 0;
	return head->height;
}
int child(node* head)
{
	if(head==NULL)
		return 0;
	return head->child;
}
int balval(node* temp)
{
	if(temp==NULL)
		return 0;
	return height(temp->left)-height(temp->right);
}
node* leftrotate(node* x)
{
	//printf("LeftR\n");
	node* y=x->right;	
	node* t2=y->left;
	int t=y->child;
	y->child+=child(x->left)+1;
	x->child+=-t+child(t2);
	y->left=x;
	x->right=t2;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
node* rightrotate(node* x)
{
	//printf("RightR\n");
	node* y=x->left;
	node* t3=y->right;
	int t=y->child;
	y->child+=child(x->right)+1;
	x->child+=-t+child(t3);
	y->right=x;
	x->left=t3;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;	
	return y;
}

node* insert(node* into,int key)
{
	int p,q;
	if(into==NULL)
	{
		node* temp=malloc(sizeof(node));
		temp->val=key;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		temp->child=1;
		return temp;
	}
	else if(key>into->val)
	{
		into->right=insert(into->right,key);
		into->child++;
	}
	else
	{
		into->left=insert(into->left,key);
		into->child++;
	}
	p=height(into->left),q=height(into->right);
	into->height=max(p,q)+1;
	//into->child=child(into->left)+child(into->right)+1;
	int bal=p-q;
	if(bal==2 && key<=into->left->val)//leftleft
	{
		into=rightrotate(into);
	}
	else if(bal==2 && key>into->left->val)//leftright
	{
		into->left=leftrotate(into->left);
		into=rightrotate(into);
	}	
	else if(bal==-2 && key<=into->right->val)//rightleft
	{
		into->right=rightrotate(into->right);
		into=leftrotate(into);
	}
	else if(bal==-2 && key>into->right->val)//rightright
	{
		into=leftrotate(into);
	}
	return into;
}

int search(node* into,int key)
{
	if(into==NULL)
		return 0;
	else if(into->val==key)
		return 1;
	else if(into->val>key)
		return search(into->left,key);
	else
		return search(into->right,key);
}

int qwe=0;
void func(node* head,int key)
{
	if(head!=NULL)
	{
		node* temp=head;
		if(key>temp->val)
		{
			v+=child(temp->left)+1;
			func(temp->right,key);
		}
		else
			func(temp->left,key);
	}
}
int func1(node* head,int key)
{
	while(head!=NULL)
	{
		int lf=child(head->left);
		if(key<=lf)
		{
			head=head->left;
		}
		if(key==lf+1)
		{
			return head->val;
		}
		if(key>lf+1)
		{
			key-=lf+1;
			head=head->right;
		}
	}
	return 0;
}
int main()
{
	int n,t,op,key;
	char str[30];
	char q[30]="Quit",sh[30]="SetHealthy",ch[30]="CheckHealthy",h[30]="Healthy",rb[30]="RottenBefore";
	//	scanf("%d",&n);
	while(1)
	{
		//	scanf("%d",&op);
		scanf("%s",str);
		if(strcmp(str,sh)==0)
		{
			scanf("%d",&key);
			if(search(root,key)==0)
			{
				root=insert(root,key);
			}
			//	myprint(root);
			//	printf("\n");
		}
		else if(strcmp(str,ch)==0)
		{
			scanf("%d",&key);
			t=search(root,key);
			if(t==1)
				printf("YES\n");
			else if(t==0)
				printf("NO\n");
		}	
		else if(strcmp(str,h)==0)
		{
			qwe=0;
			scanf("%d",&key);
			//print(root);
			int ans=func1(root,key);
			//	rotten(root);
			if(ans==0)
				printf("NONE\n");
			else
				printf("%d\n",ans);
		}
		else if(strcmp(str,rb)==0)
		{
			qwe=0;
			scanf("%d",&key);
			//print(root);
			v=0;
			func(root,key);
			printf("%d\n",v);
		}
		else if(strcmp(str,q)==0)
			break;	
	}
	return 0;
}
