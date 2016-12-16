#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  struct node *left;
  struct node *right;
  long long height;
  long long val;
  long long nl,nr;
}node;
node *head=NULL;
long long found,count;
void cyclops(node *root)
{
  if(root!=NULL && root->left!=NULL&&root->right!=NULL)
    {	
       cyclops(root->left);
       cyclops(root->right);
    }
  else
    {
      if(root!=NULL && root->left==NULL && root->right==NULL)
	root->height=0;
    }
  long long l=-1,r=-1,max,nor=0,nol=0;
  if(root!=NULL)
    {
      if(root->left!=NULL)
	{
	  l=(root->left)->height;
	  nol=1+(root->left)->nl+(root->left)->nr;	    
	}
      if(root->right!=NULL)
	{
	  r=(root->right)->height;
	  nor=1+(root->right)->nl+(root->right)->nr;
	}
      max=l>r?l:r;
      root->height=max+1;
      root->nl=nol;
      root->nr=nor;
    }
}
node* avl(node *root)
{
  long long l=0,r=0;
  if(root->left!=NULL)
    l=(root->left)->height;
  if(root->right!=NULL)
    r=(root->right)->height;
  long long s,max;
  max=l>r?l:r;
  s=l>r?l-r:r-l;
  if(s>=2)
    {
	if(max==l)
	  {
	    node *x=root->left;
	    node *y=root;
	    l=x->left==NULL?-1:x->left->height;
	    r=x->right==NULL?-1:x->right->height;
	    if(r>l)
	      {
		root=root->left->right;
		x->right=root->left;
		root->left=x;
		y->left=root->right;
		root->right=y;
	      }
	    else
	      {
		root=root->left;
		y->left=root->right;
		root->right=y;
	      }
	  }
	else
	  {
	    node *x=root->right;
	    node *y=root;
	    l=x->left==NULL?-1:x->left->height;
	    r=x->right==NULL?-1:x->right->height;
	    if(l>r)
	      {
		root=root->right->left;
		x->left=root->right;
		root->right=x;
		y->right=root->left;
		root->left=y;
	      }
	    else
	      {
		root=root->right;
		y->right=root->left;
		root->left=y;
	      }
	  }
	cyclops(root);
    }
  return root;
}
node *insert(node *root,long long value)
{
  if(root==NULL)
    {
      root=(node*)malloc(sizeof(node));
      root->val=value;
      root->left=NULL;
      root->right=NULL;
      root->height=0;
      root->nl=0;
      root->nr=0;
      return root;
    }
  if(value < root->val)
    root->left=insert(root->left,value);
  else
    if(value > root->val)
      root->right=insert(root->right,value);
  long long l=0,r=0,nol=0,nor=0;
  if(root->left!=NULL)
    {
      l=(root->left)->height;
      nol=1+(root->left)->nl+(root->left)->nr;
    }
  if(root->right!=NULL)
    {
      r=(root->right)->height;
      nor=1+(root->right)->nl+(root->right)->nr;
    }
  l=l>r?l:r;
  root->height=l+1;
  root->nl=nol;
  root->nr=nor;
  root=avl(root);
  return root;
}
void inorder(node *root,long long val)
{
  if(root != NULL && found==0)
    {
      inorder(root->left,val);
      count++;
      if(count==val)
	{
	  printf("%lld\n",root->val);
	  found=1;
	}
      inorder(root->right,val);
    }
}
 
void search(node *p,long long value)
{
  while(p!=NULL && found==0)
    {
      if(p->val==value)
	{
	  count=p->nl+count;
	  found=1;
	  break;
	}
      if(value < p->val)
	p=p->left;
      else
	{
	  count=1+(p->nl)+count;
	  p=p->right;
	}
    }
}

int main()
{
  long long i,x;
  char str[15];
  scanf("%s",str);
  head=NULL;
  while(strcmp(str,"Quit")!=0)
    {
      found=0;count=0;
      if(strcmp(str,"SetHealthy")==0)
	{
	  scanf("%lld",&x);	  
	  head=insert(head,x);
	}
      else
	if(strcmp(str,"CheckHealthy")==0)
	  {
	    scanf("%lld",&x);
	    search(head,x);
	    if(found==1)
	      printf("YES\n");
	    else
	      printf("NO\n");
	  }
	else
	  if(strcmp(str,"Healthy")==0)
	    {
	      scanf("%lld",&x);
	      inorder(head,x);
	      if(found==0)
		printf("NONE\n");
	    }
	  else
	    if(strcmp(str,"RottenBefore")==0)
	      {
		scanf("%lld",&x);
		search(head,x);
		printf("%lld\n",count);
	      }	 
        scanf("%s",str);
    }
  return 0;
}


