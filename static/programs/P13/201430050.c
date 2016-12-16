#include<stdio.h>
#include<stdlib.h>
//typedef struct node node;
//typedef struct stack stack;
typedef struct node
{int val;
	struct node *left;
	struct node *right;
}node;
typedef struct stack
{
	int top;
	int capacity;
	struct node* *array;

}stack;
void postorder(node *root)
{ 
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\n",root->val);


}
void push(stack* stac,node* root)
{
	(stac->top)++;
	stac->array[stac->top]=root;

}
node* pop(stack* stac)
{	if(stac->top==-1)
	return NULL;

	(stac->top)--;
	return stac->array[(stac->top)+1];
}
node* new(int value)
{
	node *tmp1=NULL;
	tmp1=(node*)malloc(sizeof(node));
	tmp1->val=value;
	tmp1->left=NULL;
	tmp1->right=NULL;
	return tmp1;

}
int depth[100010];
void tree_(int pre[],int size)
{int index=0;      
	//int depth[100010];
	//printf("1c\n");
	stack* stac=(stack*)malloc(sizeof(stack));
	stac->top=-1;
	stac->capacity=size;
	stac->array=(node**)malloc(size*sizeof(node*));
	node* root=NULL;
	/*root=(node*)malloc(sizeof(node));
	  root->val=pre[0];
	  root->left=NULL;
	  root->right=NULL;	*/
	root=new(0);
		//printf("1d\n");
	push(stac,root);
	depth[0]=0;
		//printf("1e\n");
	int i;
	int max=0;
	for(i=1;i<size;i++)
	{ node* tmp=NULL;
		while((stac->top)!=-1 && pre[i]<pre[stac->array[stac->top]->val])
		{tmp=pop(stac);
		//printf("1f\n");
		}
		if(tmp!=NULL)
	{       depth[i]=depth[tmp->val]+1;
			tmp->left=new(i);
			push(stac,tmp->left);
		//printf("1g\n");
 
		}
		else
		{stac->array[stac->top]->right=new(i);
			depth[i]=depth[stac->array[stac->top]->val]+1;
			push(stac,stac->array[stac->top]->right);
		//printf("1h\n");
		}
		
		if(depth[i]>=max)
		{if(depth[i]==max)
			{if(pre[i]<pre[index])
				index=i;
			}
			else
				if(depth[i]>max)
			{max=depth[i];
		         index=i;}
         	}
	}
	printf("%d %d\n",pre[index],max);
	return;
}
void inorder(node *root)
{    
	if(root==NULL)
	return;
            inorder(root->left);
	    printf("%d\n",root->val);
	    inorder(root->right);
	  //  printf("%d",root->val);
}
void preorder(node* root)
{ 
      if(root==NULL)
	      return;
	//preorder(root);
	printf("%d\n",root->val);
	preorder(root->left);
	preorder(root->right);
}
int main()
{int i,t,n;
	int a[100010],post[100010];
 scanf("%d",&t);
 while(t--)
  {node* root=NULL;
	  scanf("%d",&n);
	  int i1,j;
	  for(i1=0;i1<n;i1++)
		  scanf("%d",&post[i1]);
	  int k=n-1;
	  for(j=0;j<n;j++)
		  a[j]=post[k--];
                   tree_(a,n);
		    /*printf("postorder is\n");
	  postorder(root);
	  printf("preorderis\n");
	  preorder(root);
	  printf("inorderis\n");
	  inorder(root);
	  printf("\n");
	  */
		    


   }
 return 0; 
}
