#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *right;
	struct node *left;
	int height;
	int leftsize;
	int rightsize;
	//	int rightcount;
}node;
int search(int a,node *head)
{
	if(head==NULL)
		return -1;
	else if(head->val==a)
		return 1;
	else if(a<head->val)
		return search(a,head->left);
	else return search(a,head->right);
}
int findatpos(int k,node *head)
{
	if(head==NULL)
		return -1;
	if(((head->leftsize)+(head->rightsize)+1)<k)
		return -1;
	if((head->leftsize+1)==k)
		return head->val;
	else if(k<head->leftsize)
		return findatpos(k,head->left);
	else return findatpos((k-(head->leftsize+1)),head->right);
}
int findless(int a,node *head,int ans)
{
	if(head==NULL)
		return ans;
	if(head->val==a)
		return (ans+head->leftsize);
	else if(a<head->val)
		return findless(a,head->left,ans);
	else return findless(a,head->right,((ans+1+(head->leftsize))));
}
int factor(node *head)
{
	if(head==NULL)
		return 0;
	return height(head->left)-height(head->right);
}
int height(node *head)
{
	if(head==NULL)
		return 0;
	return head->height;
}
node *rightrotate(node *head);
node *leftrotate(node *head);
int size(node *head)
{
	if(head==NULL)
		return 0;
	else return (1+head->leftsize+head->rightsize);
}
node *create(int a,node *head)
{
	if(head==NULL)
	{
		head=malloc(sizeof(node));
		head->val=a;
		head->right=NULL;
		head->left=NULL;
		head->height=1;
		head->leftsize=0;
		head->rightsize=0;
		//	head->leftcount=0;
		//	head->rightcount=0;
		return head;
	}
	else if(a<head->val)
	{
		//	head->leftcount++;
		head->left=create(a,head->left);
	}
	else if(a>=head->val)
	{
		//	head->rightcount++;
		head->right=create(a,head->right);
	}
	//return head;
	head->height=max(height(head->right),height(head->left))+1;
	int balance=factor(head);
	if(balance>1 && a<head->left->val)
		return rightrotate(head);
	if(balance<-1 && a>head->right->val)
		return leftrotate(head);
	if(balance>1 && a>head->left->val)
	{
		head->left=leftrotate(head->left);
		return rightrotate(head);
	}
	if(balance<-1 && a<head->right->val)
	{
		head->right=rightrotate(head->right);
		return leftrotate(head);
	}
	head->leftsize=size(head->left);
	head->rightsize=size(head->right);
	return head;
}


void preorder(node *head)
{
	if(head==NULL)
		return;
	//preorder(head->left);
	printf("%d\n",head->val);
	printf("lefttree szie=%d and right tree size=%d\n",head->leftsize,head->rightsize);
	preorder(head->left);
	preorder(head->right);
}
node *rightrotate(node *head)
{
	node *temp=head->left;
	head->left=temp->right;
	temp->right=head;
	head->height=max(height(head->left),height(head->right))+1;
	temp->height=max(height(temp->left),height(temp->right))+1;
	head->leftsize=size(head->left);
	head->rightsize=size(head->right);
	temp->leftsize=size(temp->left);
	temp->rightsize=size(temp->right);
	return temp;
}
node *leftrotate(node *head)
{
	node *temp=head->right;
	head->right=temp->left;
	temp->left=head;
	head->height=max(height(head->left),height(head->right))+1;
	temp->height=max(height(temp->left),height(temp->right))+1;
	head->leftsize=size(head->left);
	head->rightsize=size(head->right);
	temp->leftsize=size(temp->left);
	temp->rightsize=size(temp->right);
	return temp;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}
int main()
{
	int n,i,a,num,ans;
	char s[100],dummy;
	node *head=NULL;
	scanf("%s",s);
	while(1)
	{
		switch(s[0])
		{
			case('Q'):
				{
					return 0;
					break;
				}
			case('S'):
				{
					scanf("%d",&num);
					scanf("%c",&dummy);
					head=create(num,head);
					break;
				}
			case('C'):
				{
					scanf("%d",&num);
					scanf("%c",&dummy);
					ans=search(num,head);
					if(ans==-1)
						printf("NO\n");
					else printf("YES\n");
					break;
				}
			case('H'):
				{
					scanf("%d",&num);
					scanf("%c",&dummy);
					ans=findatpos(num,head);
					if(ans==-1)
						printf("NONE\n");
					else printf("%d\n",ans);
					break;
				}
			case('R'):
				{
					scanf("%d",&num);
					scanf("%c",&dummy);
					ans=findless(num,head,0);
					printf("%d\n",ans);
					break;
				}
		}
//		preorder(head);
		scanf("%s",s);
	}
	return 0;
}




