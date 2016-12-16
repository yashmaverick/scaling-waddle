#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node{
  int val;
  node *next;
};

node *push(node *root,int data)
{
  node *tmp=(node *)malloc(sizeof(node));
  tmp->val=data;
  tmp->next=root;
  return tmp;
}


int max=0;

node *maxdep=NULL;

void dfs(node **a,int i,int *visited,int count)
{
  node **tmp=a;
  if(tmp[i]==NULL)
    {
      return;
    }
  else
    {
      if(tmp[i] != NULL && visited[tmp[i]->val] == 0)
	{
	  visited[tmp[i]->val]=1;
	  if(count > max)
	    {
	      max=count;
	      maxdep=tmp[i];
	    }
	  //printf("came to dfs for tmp[%d]->val is:%d with count is:%d\n",i,tmp[i]->val,count);
	  dfs(tmp,tmp[i]->val,visited,count+1);
	}
       if(tmp[i] != NULL && visited[tmp[i]->val] == 1)
	{
	  while(a[i] != NULL)
	    {
	      if(visited[tmp[i]->val] == 1)
		{
		  tmp[i]=tmp[i]->next;
		}
	      else
		{
		  // printf("came inside else of if with tmp[%d]->val is:%d count is:%d\n",i,tmp[i]->val,count);
		  if(count > max)
		    {
		      max=count;
		      maxdep=tmp[i];
		    }
		  visited[tmp[i]->val]=1;
		  dfs(tmp,tmp[i]->val,visited,count+1);
		}
	    }
	  if(tmp[i] == NULL)
	    {
	      // printf("came to return\n");
	      return;
	    }
	}
    }
}

int main()
{
  int i,t;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      node **a,**b;
      int n,j,k,r,s;
      scanf("%d",&n);
      a=(node **)malloc(sizeof(node*)*(n+1));
      b=(node **)malloc(sizeof(node*)*(n+1));
      for(j=0;j<n+1;j++)
	{
	  a[j]=NULL;
	  b[j]=NULL;
	}
      for(j=1;j<n;j++)
	{
	  scanf("%d%d",&r,&s);
	  a[r]=push(a[r],s);
	  b[r]=push(b[r],s);
	  a[s]=push(a[s],r);
	  b[s]=push(b[s],r);
	}
      j=1;
      max=0;
      int *vtd1=(int*)malloc(sizeof(node)*(n+1));
      int *vtd2=(int*)malloc(sizeof(node)*(n+1));
      for(j=0;j<n+1;j++)
	{
	  vtd1[j]=0;
	  vtd2[j]=0;
	}
      j=1;
      vtd1[j]=1;
      dfs(a,j,vtd1,1);
      max=0;
      if(maxdep ==NULL)
	printf("no\n");
      vtd2[maxdep->val]=1;
      dfs(b,maxdep->val,vtd2,1);
      free(a);
      free(b);
      free(vtd2);
      free(vtd1);
      printf("%d\n",max+1);
    }
  return 0;
}
