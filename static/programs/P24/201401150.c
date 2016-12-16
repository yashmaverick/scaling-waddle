#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AvlNode struct AvlNode
#define s(n) scanf("%d",&n)
#define MAX 200007
typedef char string[20];
int HEALTHY[MAX],count;
AvlNode
{
	int val,height,noOfLC,noOfRC,lesserBeings;
	AvlNode *left, *right;
};

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int height(AvlNode* N)
{
	if(N==NULL)
		return -1;
	else
		return N->height;
}

int lc(AvlNode *N)
{
	if(N==NULL)
		return 0;
	AvlNode *T=N->left;
	if(T!=NULL)
		return 1 + T->noOfRC + T->noOfLC;
	else
		return 0;
}

int rc(AvlNode *N)
{
	if(N==NULL)
		return 0;
	AvlNode *T=N->right;
	if(T!=NULL)
		return 1 + T->noOfRC + T->noOfLC;
	else
		return 0;
}

int sumLC(AvlNode *N)
{
	if(N==NULL)
		return 0;
	return 1 + N->noOfLC;
}

AvlNode *leftROT(AvlNode *K)
{
	AvlNode *T=K->left;
	K->left=T->right;
	T->right=K;


	K->noOfLC=lc(K);
	K->noOfRC=rc(K);
	T->noOfLC=lc(T);
	T->noOfRC=rc(T);
	K->height=max(height(K->left),height(K->right))+1;
	T->height=max(height(T->left),height(T->right))+1;

	return T;
}

AvlNode *rightROT(AvlNode *K)
{
	AvlNode *T=K->right;
	K->right=T->left;
	T->left=K;
	
	K->noOfLC=lc(K);
	K->noOfRC=rc(K);
	T->noOfLC=lc(T);
	T->noOfRC=rc(T);
	K->height=max(height(K->left),height(K->right))+1;
	T->height=max(height(T->left),height(T->right))+1;

	return T;	
}

AvlNode *rightleftROT(AvlNode *K)
{
	K->left=rightROT(K->left);
	K=leftROT(K);
	return K;
}

AvlNode *leftrightROT(AvlNode *K)
{
	K->right=leftROT(K->right);
	K=rightROT(K);
	return K;
}

AvlNode *subTreeMin(AvlNode* N)
{
	if(N==NULL)
		return NULL;
	while(N->left!=NULL)
		N=N->left;
	return N;
}

AvlNode *subTreeMax(AvlNode* N)
{
	if(N==NULL)
		return NULL;
	while(N->right!=NULL)
		N=N->right;
	return N;
}
int LC=0;
AvlNode *insert(AvlNode *root,int i)
{
	if(root==NULL)
	{
		AvlNode* z=(AvlNode*)malloc(sizeof(AvlNode));
		z->val=i;z->height=0;
		z->noOfLC=0;
		z->noOfRC=0;
		z->left=z->right=NULL;
		root=z;
	}
	else
	{
		if(i<root->val)
		{
			//root->noOfLC++;
			root->left=insert(root->left,i);
			if(height(root->left)-height(root->right)==2)
			{
				
				if(i<root->left->val)
					root=leftROT(root);
				else
					root=rightleftROT(root);
			}
		}
		else if(i>root->val)
		{
			//root->noOfRC++;
			root->right=insert(root->right,i);
			if(height(root->right)-height(root->left)==2)
			{
				if(i>root->right->val)
					root=rightROT(root);
				else
					root=leftrightROT(root);
			}	
		}
	}

	root->noOfLC=lc(root);
	root->noOfRC=rc(root);
	root->height=max(height(root->left),height(root->right))+1;
	return root;
}


void healthyInorder(AvlNode *root,int x)
{
	//printf("Count:%d\n",count);
	if(root==NULL || count>x)
		return;
	healthyInorder(root->left,x);
	count++;
	HEALTHY[count]=root->val;
	healthyInorder(root->right,x);
}

int rotten(AvlNode *root,int x)
{
	if(root==NULL)
		return 0;
	AvlNode* T=root;
	int c=0;
	while(T!=NULL)
	{
		if(x==T->val)
			{
				c+=T->noOfLC;
				break;
			}
		else if(x<T->val)
			T=T->left;
		else
		{
			c+=sumLC(T);
			T=T->right;
		}
	}
	return c;	
}

void checkNode(AvlNode *root,int x)
{
	if(root==NULL)
	{printf("NO\n");return;}

	AvlNode *T=root;
	int f=0;
	while(T!=NULL)
	{
		if(x==T->val)
		{f=1;break;}
		else if(x<T->val)
			T=T->left;
		else
			T=T->right;
	}
	if(f==1)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	string Q;int x,i,j;
	AvlNode *root=NULL;
	//scanf("%s",Q);s(x);
	while(1)
	{
		scanf("%s",Q);		
		if(strcmp(Q,"Quit")==0)
			break;
		count=0;
		if(strcmp(Q,"SetHealthy")==0)
			{s(x);root=insert(root,x);}

		if(strcmp(Q,"CheckHealthy")==0)
			{s(x);checkNode(root,x);}

		if(strcmp(Q,"Healthy")==0)
		{
			s(x);
			healthyInorder(root,x);
			if(HEALTHY[x]==0)
				printf("NONE\n");
			else
				printf("%d\n",HEALTHY[x]);
			memset(HEALTHY,0,sizeof(HEALTHY)/sizeof(int));
		}
		if(strcmp(Q,"RottenBefore")==0)
		{s(x);printf("%d\n",rotten(root,x));}
	}
	return 0;

}