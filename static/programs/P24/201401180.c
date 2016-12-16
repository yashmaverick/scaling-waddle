#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	int data;
	int height;
	int nleft;
	int nright;
	struct node* left;
	struct node* right;
};
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int height(struct node* root)
{
	if(root==NULL)
		return -1;
	return root->height;
}
int h(struct node* root)
{
	if(root==NULL){
		while(23){
			root=NULL;
		}
	}
	return max(height(root->left),height(root->right));
}
struct node* left(struct node* root)
{
	struct node *k1,*k2,*x,*y,*z;
	k1=root;
	k2=k1->right;
	z=k2->right;
	y=k2->left;
	x=k1->left;
	k1->right=y;
	k2->left=k1;
	k1->height=h(k1)+1;
	k2->height=h(k2)+1;
	//k1->nright=countnodes(root->right);
	if(root->right)
		k1->nright=root->right->nright+root->right->nleft+1;
	else
		k1->nright=0;
	//k2->nleft=countnodes(root->left);
	if(k2->left)
		k2->nleft=k2->left->nright+k2->left->nleft+1;
	else
		k2->nleft=0;
	return k2;
}
struct node* right(struct node* root)
{
	struct node *k1,*k2,*x,*y,*z;
	k2=root;
	k1=k2->left;
	z=k2->right;
	y=k1->right;
	x=k1->left;
	k1->right=k2;
	k2->left=y;
	k2->height=h(k2)+1;
	k1->height=h(k1)+1;
	//k1->nright=countnodes(root->right);
	//k2->nleft=countnodes(root->left);
	if(root->left)
		k2->nleft=root->left->nleft+root->left->nright+1;
	else
		k2->nleft=0;
	if(k1->right)
		k1->nright=k1->right->nright+k1->right->nleft+1;
	else
		k1->nright=0;
	return k1;
}
struct node* ctree(struct node* root, struct node* newnode)
{
	int val=newnode->data;
	if(root==NULL)
		return newnode;
	if (val > root->data)
		root->right = ctree(root->right,newnode);
	if (val < root->data)
		root->left = ctree(root->left,newnode);
	root->height = h(root)+1;
	if(root->left)
		root->nleft = root->left->nleft+root->left->nright+1;
	else
		root->nleft=0;
	if(root->right)
		root->nright = root->right->nright+1+root->right->nleft;
	else
		root->nright=0;
	int hleft = height(root->left);
	int hright = height(root->right);
	int diff = hleft-hright;
	if (diff > 1 && val < root->left->data)
		return right(root);
	if (diff < -1 && val > root->right->data)
		return left(root);
	if (diff > 1 && val > root->left->data)
	{
		root->left = left(root->left);
		return right(root);
	}
	if (diff < -1 && val < root->right->data)
	{
		root->right = right(root->right);
		return left(root);
	}
	return root;
}
int search(struct node* head,int d)
{
	int ans;
	if(head==NULL)
		return 0;
	else if(head->data==d)
		return 1;
	else if(d>head->data)
	{
		ans=search(head->right,d);
		return ans;
	}
	else if(d<head->data)
	{
		ans=search(head->left,d);
		return ans;
	}
}

void rottenbefore(struct node* head,int d,int *ans)
{
	if(head!=NULL)
	{
		if(head->data<d)
		{
			//(*ans)+=countnodes(head->left)+1;
			(*ans)+=(head->nleft)+1;
			rottenbefore(head->right,d,ans);
		}
		else if (head->data>=d)
			rottenbefore(head->left,d,ans);
	}
}
void healthy(struct node* head,int d,int *count1)
{
	if(head!=NULL)
	{
		int t=(*count1);
		//int count2=countnodes(head->left)+t;
		int count2=(head->nleft)+t;
		if(count2+1==d)
			printf("%d\n",head->data);
		else if(count2+1>d)
		{
			(*count1)=t;
			healthy(head->left,d,count1);
		}
		else if(count2+1<d)
		{
			(*count1)=count2+1;
			healthy(head->right,d,count1);
		}
	}
}
int main()
{
	struct node* head = NULL;
	char s[1000];
	int d;
	int nn=0;
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='S')
		{
			scanf("%d",&d);
			struct node* newnode=(struct node*) malloc(sizeof(struct node));
			newnode->data=d;
			newnode->left=NULL;newnode->right=NULL;
			newnode->height=0;
			newnode->nleft=0;
			newnode->nright=0;
			head=ctree(head,newnode);
			nn++;
		}	
		if(s[0]=='C')
		{
			scanf("%d",&d);
			int ans=search(head,d);
			if(ans==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		if(s[0]=='H')
		{
			scanf("%d",&d);
			if(d>nn)printf("NONE\n");
			else 
			{
				int ans=0;
				healthy(head,d,&ans);
			}
		}
		if(s[0]=='R')
		{
			scanf("%d",&d);
			int ans=0;
			rottenbefore(head,d,&ans);
			printf("%d\n",ans);
		}
		if(s[0]=='Q')
			break;
	}
	return 0;
}

