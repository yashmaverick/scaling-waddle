#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
  int val;
  struct link *next;
}link;
link *head[1000000];
int top=-1;
int count,M,visit[1000000]={0},root;

void insert(int i)
{
  link *new=(link*)malloc(sizeof(link));
  link *hi=(link*)malloc(sizeof(link));
  hi->next=NULL;
  new->next=NULL;
  scanf("%d",&(new->val));
  hi->val=i+1;
  if(head[i]!=NULL)
    {
      new->next=head[i];
    }
  if(head[new->val-1]!=NULL)
    hi->next=head[new->val-1];  
  head[i]=new;
  head[new->val-1]=hi;
}

void depth(int n)
{
  if(head[n]!=NULL)
    {
      link *p=head[n];
      visit[n]=1;
      while(p!=NULL)
	{ 
	  if(visit[p->val-1]==0)
	    {
	      count=count+1;
	      if(M<count)
		{
		  M=count;
		  root=p->val;
		}
	      depth((p->val)-1);
	      count--;
	    }
	  p=p->next;
	}
      visit[n]=0;
    }
}

int main()
{
  int n,m,i,t;
  scanf("%d",&t);
  while(t!=0)
    {
      root=-1;count=1;M=0;
      scanf("%d",&n);
      if(n>1)
	{
	  for(i=0;i<=n;i++)
	    head[i]=NULL;
	  i=n;
	  while(n-1>0)
	    {
	      scanf("%d",&m);
	      if(i==n)
		root=m;
	      if(m!=0)
		insert(m-1);
	      n--;
	    }
	  depth(root-1);
	  M=0;count=1;
	  depth(root-1);
	  printf("%d\n",M);
	}
      else
	{
	  for(i=n;i>0;i--)
	    scanf("%d",&m);
	  printf("%d\n",n);
	}
      t--;
    }
  return 0;
}

  
