#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
struct node{
	int val;
	int hei;
	int ele;
	struct node* left;
	struct node* right;
};
typedef struct node node;
node* create_node(int n)
{
	node* x;
	x=malloc(sizeof(node));
	x->val=n;
	x->left=NULL;
	x->right=NULL;
	x->hei=1;
	x->ele=1;
	return x;
}
int height(node *head)
{
	if(head==NULL)
		return 0;
	return head->hei;
}
int element(node* head)
{
	if(head==NULL)
		return 0;
	return head->ele;
}
node* single(node *k1,node* k2,int a)
{
	if(a==1)
	{
		k1->right=k2->left;
		k2->left=k1;
	}
	else if(a==0)
	{
		k1->left=k2->right;
		k2->right=k1;
	}
	k1->hei=max(height(k1->left),height(k1->right))+1;
	k1->ele=element(k1->left)+element(k1->right)+1;
	k2->hei=max(height(k2->left),height(k2->right))+1;
	k2->ele=element(k2->left)+element(k2->right)+1;
	return k2;
}
node* balance(node* head,node *t,int n)
{
	if(head==NULL)
		return t;
	int fact,fact2,st=0;
	if(head->val < n)
		head->right=balance(head->right,t,n);
	else
		head->left=balance(head->left,t,n);
	fact=height(head->left)-height(head->right);
	if(fact>1)
	{
		fact2=height(head->left->left)-height(head->left->right);
		if(fact2>0)
			head=single(head,head->left,0);
		else
		{
			head->left=single(head->left,head->left->right,1);
			head=single(head,head->left,0);
		}
	}
	else if(fact<-1)
	{
		fact2=height(head->right->left)-height(head->right->right);
		if(fact2>0)
		{
			head->right=single(head->right,head->right->left,0);
			head=single(head,head->right,1);
		}
		else
			head=single(head,head->right,1);
	}
	head->hei=max(height(head->left),height(head->right))+1;
	head->ele=element(head->left)+element(head->right)+1;
//	if(head->val==3)
//		printf("%d\n",head->ele);
	return head;
}
int check(node* head,int x)
{
	if(head==NULL)
		return 0;
	if(head->val==x)
		return 1;
	else if(head->val>x)
		return check(head->left,x);
	else
		return check(head->right,x);
}
int ans;
void healthy(node* head,int x)
{
//	printf("%d\n",x);
	if(head==NULL)
		return;
	if(element(head->left)==x)
		ans=head->left->val;
	else if(element(head->left)>x)
		healthy(head->left,x);
	else if(element(head->left)+1==x)
		ans=head->val;
	else
		healthy(head->right,x-element(head->left)-1);
	return;
}
void rotten(node* head,int x)
{
	if(head==NULL)
		return;
	if(head->val>=x)
		rotten(head->left,x);
	else
	{
		ans+=element(head->left)+1;
		rotten(head->right,x);
	}
}
void post(node* head)
{
	if(head==NULL)
		return;
	post(head->left);
	post(head->right);
	printf("%d %d %d\n",head->val,head->ele,head->hei);
	return;
}
int main()
{
	int n,x,i;
	char s[30];
	node *tree=NULL,*temp;
	scanf(" %s",s);
	while(s[0]!='Q')
	{
		scanf("%d",&x);
		if(s[0]=='S')
		{
			if(check(tree,x)==0)
			{
				temp=create_node(x);
				tree=balance(tree,temp,x);
			}
		}
		else if(s[0]=='C')
		{
			if(check(tree,x))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(s[0]=='H')
		{
			ans=-1;
			healthy(tree,x);
			if(ans<0)
				printf("NONE\n");
			else
				printf("%d\n",ans);
		}
		else if(s[0]=='R')
		{
			ans=0;
			rotten(tree,x);
			printf("%d\n",ans);
		}
	//		post(tree);
		scanf("%s",s);
	}
	return 0;
}
