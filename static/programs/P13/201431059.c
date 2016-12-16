#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 100002
int depth[N];
int A[N];
int S[N];
int L[N];
int head=-1;
int ans;
typedef struct node{
	int val;
	struct node* left;
	struct node* right;
}node;

typedef struct pair{
	int first;
	int second;
}pair;

void inOrder(node* head)
{
	if(head==NULL)
		return ;
	inOrder(head->left);
	printf("%d ",head->val);
	inOrder(head->right);
}

void preOrder(node* head)
{
	if(head==NULL)
		return ;
	printf("%d ",head->val);
	preOrder(head->left);
	preOrder(head->right);
}
void postOrder(node* head)
{
	if(head==NULL)
		return ;
	postOrder(head->left);
	postOrder(head->right);
	printf("%d ",head->val);
}




node* buildTree(int Left,int Right)
{
	//printf("%d %d\n",Left,Right);
	if(Left>Right)
		return NULL;
	//printf("%d %d %d\n",L,R,d);
	if(Left==Right)
	{
		node* leaf = (node*)malloc(sizeof(node));
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->val = A[Left];
		return leaf;
	}
	int n = Right;
	node* parent = (node*)malloc(sizeof(node));
	parent->left = NULL;
	parent->right = NULL;
	parent->val = A[n];
	Right = Right-1;
	if(Left<=L[n] && L[n]<=Right)
	{
		parent->left = buildTree(Left,L[n]);
		parent->right = buildTree(L[n]+1,Right);
	}
	else
		parent->right = buildTree(Left,Right);
	//printf("parent : %d left : %d right: %d\n",parent->val,(parent->left!=NULL?parent->left->val:-1),(parent->right!=NULL?parent->right->val:-1));
	return parent;
}

pair findMaxDepthElem(node* head)
{
	if(head->left==NULL && head->right==NULL)
	{
		pair ret;
		ret.first = head->val;
		ret.second = 0;
		return ret;
	}
	int l=0,r=0;
	pair left,right;
	if(head->left!=NULL)
	{
		left = findMaxDepthElem(head->left);
		left.second++;
		l=1;
	}
	if(head->right!=NULL)
	{
		right = findMaxDepthElem(head->right);
		right.second++;
		r = 1;
	}
	if(l&r)
	{
		if(left.second>right.second)
			return left;
		else if(left.second<right.second)
			return right;
		else
		{
			if(left.first<right.first)
				return left;
			else
				return right;
		}
	}
	else if(l)
		return left;
	else
		return right;

}

void deleteTree(node* head)
{
	if(head==NULL)
		return;
	deleteTree(head->left);
	deleteTree(head->right);
	free(head);
}


int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int i;
		int n;
		//int ans=-1;
		scanf("%d",&n);
		A[0]=-100000000;
		//depth[0]=-1;
		head=-1;
		S[++head]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",A+i);
			while(A[i]<A[S[head]])
				head--;
			L[i]=S[head];
			S[++head]=i;
		}
		node* head=buildTree(1,n);
		pair ans = findMaxDepthElem(head);
		printf("%d %d\n",ans.first,ans.second);
		deleteTree(head);
	}
	return 0;
}
