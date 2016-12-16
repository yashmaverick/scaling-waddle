#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n);

typedef struct dabba
{
  int num;
  struct dabba* next;
}node;

node *arr[1000005];
int visited[1000005];
int max,maxpos;

void dfs(int pos,int depth)
{
  node *temp=arr[pos];
  visited[pos]=1;
  while(temp!=NULL)
    {
      if(visited[temp->num]==0)
	dfs(temp->num,depth+1);
      
      if(depth>max)
	{
	  max=depth;
	  maxpos=pos;
	}
      temp=temp->next;
    }
}

int main()
{
  int n,m,t,a;
  int node1,node2;
  node *temp;

  sc(t);
  
  while(t)
    {
      for(a=0;a<=1000000;a++)
	arr[a]=NULL;
      sc(n);
      a=0;
      while(a<n-1)
	{
	  sc(node1);
	  sc(node2);
	  if(arr[node1]==NULL)
	    {
	      arr[node1]=(node*)malloc(sizeof(node));
	      arr[node1]->num=node2;
	    }
	  else
	    {
	      temp=(node*)malloc(sizeof(node));
	      temp->num=node2;
	      temp->next=arr[node1]->next;
	      arr[node1]->next=temp;
	    }

	  if(arr[node2]==NULL)
	    {
	      arr[node2]=(node*)malloc(sizeof(node));
	      arr[node2]->num=node1;
	    }
	  else
	    {
	      temp=(node*)malloc(sizeof(node));
	      temp->num=node1;
	      temp->next=arr[node2]->next;
	      arr[node2]->next=temp;
	    }

	  a++;
	}

      for(a=0;a<=n;a++)
	visited[a]=0;

      max=1;
      maxpos=0;
      dfs(1,1);

      for(a=0;a<=n;a++)
	visited[a]=0;

      //printf("%d %d\n",max,maxpos);

      max=1;
      dfs(maxpos,1);
      printf("%d\n",max);
      t--;
    }
  return 0;
}
