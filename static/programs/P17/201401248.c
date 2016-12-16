#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node {
  int val;
  node *lt,*rt;
};

void print(node *root)
{
  if(root == NULL)
    return;
  else
    {
      print(root->lt);
      printf("%d ",root->val);
      print(root->rt);
    }
}

void inorder(node *root)
{
  if(root == NULL)
    return ;
  else
    {
      printf("%d ",root->val);
      inorder(root->lt);
      inorder(root->rt);
    }
}

int main()
{
  int n;
  scanf("%d",&n);
  if(n == 0)
    return 0;
  int j,pos[1000000];
  node *root=NULL;
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  for(j=0;j<n;j++)
    {
      scanf("%d",&a[j]);
    }
  for(j=0;j<n;j++)
    {
      scanf("%d",&b[j]);
      pos[b[j]]=j;
    }
  int v,l,q1,q2;
  scanf("%d",&v);
  for(l=0;l<v;l++)
    {
      scanf("%d%d",&q1,&q2);
      for(j=0;j<n;j++)
	{
	  if((pos[q1] > pos[a[j]] && pos[q2] > pos[a[j]]) || (pos[q1] < pos[a[j]] && pos[q2] < pos[a[j]]))
	    continue;
	  else
	    {
	      printf("%d\n",a[j]);
	      break;
	    }
	}
    }
  return 0;
}
