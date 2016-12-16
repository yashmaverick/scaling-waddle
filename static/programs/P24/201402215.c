#include<stdio.h>
#include<stdlib.h>
int count=0,flag=0;
struct node{
	int val;
	int h;
	struct node *r;
	struct node *l;
	int left;
	int right;
};
typedef struct node node;
void order(node *root)
{
	if(root==NULL)
		return ;
	order(root->l);
	printf("%d ",root->val);
	order(root->r);
}
void inorder(node *root,int k)
{
	//printf("afasdf\n");
	if(root==NULL)
	{

	//	printf("NONE\n");
		return ;
	}
	//printf("root val is %d and no. of left child are %d\n",root->val,root->left);
	if(root->left>k-1)
	{
		inorder(root->l,k);
	}
	if(root->left<k-1)
	{
		inorder(root->r,k-root->left-1);
	}
	if(root->left==k-1)
	{
		printf("%d\n",root->val);
		flag=1;
		return ;
	}


}
void rotten(node *root,int k)
{
	//printf("afasdf\n");
	if(root==NULL)
		return ;

	if(root->val<k)
	{	count+=root->left+1;
		rotten(root->r,k);
	}
	if(root->val==k)
	{
		count+=root->left;

		printf("%d\n",count);
		flag=1;
		return ;
	}
	if(root->val>k)
	{
		rotten(root->l,k);
	}
}




node *single1(node *key1,node *key2)
{
	node *rootp;
	rootp=key2->r;

	key2->r=key1;
	key1->l=rootp;
	key1->h=height(key1);
	key2->h=height(key2);
	key1->left=key2->right;
	key2->right=key2->right+key1->right+1;
	return key2;
}
node *single2(node *key1,node *key2)
{
	node *rootp;
	rootp=key2->l;
	key2->l=key1;
	key1->r=rootp;
	key1->h=height(key1);
	key2->h=height(key2);
	key1->right=key2->left;
	key2->left=1+key1->left+key1->right;
	return key2;
}

int height(node *root)
{
	if(root->l==NULL&&root->r==NULL)
		return 0;
	else if(root->l!=NULL&&root->r!=NULL)
	{
		if(root->l->h>root->r->h)
			return 1+height(root->l);
		else
			return 1+height(root->r);
	}
	else
	{
		if(root->l!=NULL)
			return 1+height(root->l);
		if(root->r!=NULL)
			return 1+height(root->r);
	}
}

node* insert(node *root, int k)
{
	node *temp;
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->l=root->r=NULL;
		root->val=k;
		root->left=0;
		root->right=0;

		return root;

	}
	else
	{
		if(k<=root->val)
		{
			root->l=insert(root->l,k);
			root->left++;
			root->h=height(root);
			//	printf("%d %d\n",root->val,root->h);
			if(root->r!=NULL)
			{

				if(root->l->h-root->r->h>1||root->l->h-root->r->h<-1)
				{

					if(k<=root->l->val)
					{
						//		printf("1\n");
						root=single1(root,root->l);
					}
					else
					{
						//		printf("2\n");
						root->l=single2(root->l,root->l->r);
						root=single1(root,root->l);
					}
				}
			}
			else
			{
				//printf("%d %d\n",root->val,root->h);
				if(root->l->h>=1)
				{
					if(k<=root->l->val)
					{
						//		printf("3\n");
						root=single1(root,root->l);
					}
					else
					{
						//		printf("4\n");
						root->l=single2(root->l,root->l->r);
						root=single1(root,root->l);
					}
				}
			}
			return root;
		}
		else
		{
			root->r=insert(root->r,k);
			root->right++;
			root->h=height(root);
			//	printf("%d %d\n",root->val,root->h);
			if(root->l!=NULL)
			{

				if(root->l->h-root->r->h>1||root->l->h-root->r->h<-1)
				{
					if(k>root->r->val)
					{
						//	printf("5\n");
						root=single2(root,root->r);
					}
					else
					{
						//	printf("6\n");
						root->r=single1(root->r,root->r->l);
						root=single2(root,root->r);
					}
				}
			}
			else
			{

				if(root->r->h>=1)
				{
					//      printf("kasjdf\n");
					if(k>root->r->val)
					{
						//	printf("7\n");
						//      printf("hei\n");
						//      printf("%d\n",root->r->r->val);
						root=single2(root,root->r);
						//      printf("ajsdjf\n");
					}
					else
					{
						//	printf("8\n");
						root->r=single1(root->r,root->r->l);
						//	printf("%d %d\n",root->val,root->h);
						//	printf("%d %d\n",root->r->val,root->r->h);
						root=single2(root,root->r);
					}
				}
			}

			return root;
		}
	}
}

int search(node *root,int k)
{
	if(root==NULL)
	{	
		return 0;
	}
	if(root->val==k)
		return 1;
	else
	{       if(root->val>k)
		return search(root->l,k);
		else
			return search(root->r,k);
	}
}

int main()
{
	char s[15],c;
	int k;
	count=0;
	node *root=NULL;

	while(1)
	{
		count=0;
		flag=0;
		scanf(" %s",s);
		
		if(s[0]=='Q')
		{
			break;
		}
		 if(s[0]=='S')
		{
			scanf("%d",&k);
			root=insert(root,k);
		//	order(root);
		}

		if(s[0]=='C')
		{
			scanf("%d",&k);
			if(search(root,k))
				printf("YES\n");
			else
				printf("NO\n");
		}
		if(s[0]=='H')
		{
			scanf("%d",&k);
			inorder(root,k);
			if(flag==0)
				printf("NONE\n");
		}
		if(s[0]=='R')
		{
			scanf("%d",&k);
			rotten(root,k);	
			if(flag==0)
				printf("%d\n",count);
		}
		
	}
	return 0;
}



