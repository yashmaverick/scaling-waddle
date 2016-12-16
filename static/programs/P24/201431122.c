#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int h;
	int val;
	int re,le;
	struct node * right,*left;
}node;

node * root;
int rcount;
int mh(node * rt)
{
	int h;
		if(rt->right!=NULL && rt->left!=NULL)
		{
			if(rt->right->h > rt->left->h)
				h=rt->right->h;
			else
				h=rt->left->h;
		}
		if(rt->right!=NULL && rt->left==NULL)
			h=rt->right->h;
		if(rt->right==NULL && rt->left!=NULL)
			h=rt->left->h;
		if(rt->right==NULL && rt->left==NULL)
			h=0;
		return h;
}
node * Lrotate(node * rt)
{
	node * y=rt->right;
	node * t2=y->left;
	rt->re=y->le;
	y->le=rt->re+rt->le+1;
	y->left=rt;

	rt->right=t2;
rt->h=mh(rt)+1;
y->h=mh(y)+1;

	return y;
}

node * Rrotate(node * rt)
{
	node * y=rt->left;
	node * t3 =y->right;
	rt->le=y->re;
	y->re=rt->re+rt->le+1;
	rt->left=t3;
	y->right=rt;
	rt->h=mh(rt)+1;
	y->h=mh(y)+1;
	return y;
}
node * insert(node * rt,int k)
{
	if(rt==NULL)
	{
		node * temp=(node *)malloc(sizeof(node));
		temp->val=k;
		temp->h=1;
		temp->re=0;
		temp->le=0;
		return temp;
	}
	else
	{
		if(k < rt->val)
		{
			rt->le = rt->le+1;
			rt->left=insert(rt->left,k);
		}
		else
		{
			rt->re=rt->re+1;
			rt->right=insert(rt->right,k);
		}
		if(rt->right!=NULL && rt->left!=NULL)
		{
			if(rt->right->h > rt->left->h)
				rt->h=rt->right->h;
			else
				rt->h=rt->left->h;
		}
		rt->h=mh(rt)+1;
		
int d;
		if(rt->right!=NULL && rt->left!=NULL)
			d=rt->left->h-rt->right->h;
		if(rt->right==NULL && rt->left!=NULL)
			d=rt->left->h;
		if(rt->right!=NULL && rt->left==NULL)
			d=0-rt->right->h;
		if(rt->right==NULL && rt->left==NULL)
			d=0;

		if(d<-1 && k > rt->right->val)
			return(Lrotate(rt));
		if(d<-1 && k < rt->right->val)
		{
			rt->right= Rrotate(rt->right);
			return(Lrotate(rt));
		}
		if(d > 1 && k > rt->left->val)
		{
			rt->left = Lrotate(rt->left);

			return(Rrotate(rt));
		}
		if(d > 1 && k < rt->left->val)
			return(Rrotate(rt));

		return rt;

	}
}
int find(int d)
{
	node * temp=root;
	while(temp!=NULL)
	{
		if(temp->val==d)
			return 1;
		else if(temp->val < d)
			temp=temp->right;
		else
			temp=temp->left;
	}
	return 0;
}



int rotten(int d)

{
	int count=0;
	node * temp=root;
//	printf("d-%d\n",d);
	while(temp!=NULL)
	{
		//printf("d %d count %d\n",d,count);
		if(temp->val==d)
		{
//			printf("yes\n");
//				printf("left %d\n",temp->left->h);
				 count +=temp->le;
					 return count;
		}
		else if(temp->val < d)
		{
			count+=temp->le;
			count++;
				temp=temp->right;
		}
		else
			temp=temp->left;

	}
	return count;

}

int ai;
int arr[1000000];
void inorder(node *rt)
{
	if(rt==NULL)
		return;
	inorder(rt->left);
	arr[ai++]=rt->val;
	inorder(rt->right);
}

void pre(node *rt)
{
	if(rt==NULL)
		return;
	printf("pr %d h-%d re->%d le-%d\n",rt->val,rt->h,rt->re,rt->le);
	pre(rt->left);
	pre(rt->right);

}
int main()
{
	char c[15];
	int d,f=0;
	int l,i;
	int el=0;
	while(1)
	{
		scanf("%s",c);
		l=strlen(c);
		if(c[0]=='S')
		{
			scanf("%d",&d);
			root=insert(root,d);
//			pre(root);
//			printf("\n");
			el++;

		}
	
			if(c[0]=='R')
			{
				
				scanf("%d",&d);
		rcount=rotten(d);
					
				printf("%d\n",rcount);
			}
			if(c[0]=='C')
			{
				scanf("%d",&d);
				if(find(d))
					printf("YES\n");
				else
					printf("NO\n");
				
			}
		

		if(c[0]=='H')
		{
			scanf("%d",&d);
			if(d<=el)
			{
				ai=0;
				inorder(root);
				if(arr[d-1])
				printf("%d\n",arr[d-1]);	
				else
					printf("NONE\n");
			}
			else
				printf("NONE\n");
		}
		if(c[0]=='Q')
		{
//			pre(root);
			break;
		}
	}


return 0;
}
