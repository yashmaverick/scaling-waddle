#include<stdio.h>
#include<stdlib.h>
 long long int stack1[100005];
 long long int stack2[100005];
long long int s1=0,s2=0;
long long int ind[100005];


typedef struct tree
{
	long long int val;
	struct tree * left;
	struct tree * right;
}tree;

tree *root;



void insert(long long int x)
{
	tree *temp=root;
//	prlong long intf("x %lld\n",x);
	if(temp==NULL)
	{
//		prlong long intf("enter\n");
		root=(tree *)malloc(sizeof(tree));
		root->val=x;
		return;
	}
	else
	{
		while(temp!=NULL)
		{
			if(ind[x]<ind[temp->val])
			{
				if(temp->left==NULL)
				{
					temp->left=(tree *)malloc(sizeof(tree));
					temp->left->val=x;
					return;
				}
				else
					temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=(tree *)malloc(sizeof(tree));
					temp->right->val=x;
					return;
				}
				else
					temp=temp->right;
			}
		}

	}
}




void lca(long long int n1,long long int n2)
{
	s1=0;
	s2=0;
	tree * temp=root;
	long long int d;
	while(temp!=NULL)
	{
		d=ind[n1]-ind[temp->val];
		if(d<0)
		{	s1++;
			stack1[s1]=temp->val;
			temp=temp->left;
		}

		else if(d>0)
		{
			s1++;
			stack1[s1]=temp->val;
			temp=temp->right;
		}
		else
		{
			s1++;
			stack1[s1]=temp->val;
			break;
		}
	}

	 temp=root;
	while(temp!=NULL)
	{
		d=ind[n2]-ind[temp->val];
		if(d<0)
		{	s2++;
			stack2[s2]=temp->val;
			temp=temp->left;
		}

		else if(d>0)
		{
			s2++;
			stack2[s2]=temp->val;
			temp=temp->right;
		}
		else
		{
			s2++;
			stack2[s2]=temp->val;
			break;
		}
	}
	long long int i=1,lca=1;
//	for(i=1;i<=s1;i++)
//		printf("s1 %lld\n",stack1[i]);
	
//	for(i=1;i<=s2;i++)
//		printf("s2 %lld\n",stack2[i]);
	i=1;
	while(stack1[i]==stack2[i] && i <=s1 && i<=s2 )
	{
		lca=stack1[i];
	
//	printf("l %lld\n",lca);
		i++;
	}
	printf("%lld\n",lca);
}
void pre(tree * t)
{
	if(t==NULL)
		return;
	else
	{
	printf("t %lld \n",t->val);
	pre(t->left);
	pre(t->right);
	}
}


	long long int main()
	{
		long long int arr[100005];
		long long int p,n,n1,n2,i,x;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
		scanf("%lld",&arr[i]);
		for(i=0;i<p;i++)
		{
			scanf("%lld",&x);
			ind[x]=i;
		}
		for(i=0;i<p;i++)
			insert(arr[i]);
//		pre(root);
		scanf("%lld",&n);
		while(n--)
		{
			scanf("%lld %lld",&n1,&n2);
			lca(n1,n2);
		}



		return 0;
	}
