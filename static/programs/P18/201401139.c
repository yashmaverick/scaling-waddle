#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n);

typedef struct dabba
{
  int num;
  struct dabba* next;
}node;


node *arr[1005];
node *backarr[1005];
int visited[1005];
int count;

void backward(int pos)
{
  node *temp2=backarr[pos];
  visited[pos]=1;
  count++;
  while(temp2!=NULL)
    {
      if(visited[temp2->num]==0)
	{
	  backward(temp2->num);
	}
      temp2=temp2->next;
    }
}

void winner(int pos)
{
  node *temp2=arr[pos];
  visited[pos]=1;
  count++;
  while(temp2!=NULL)
    {
      if(visited[temp2->num]==0)
	{
	  winner(temp2->num);
	}
      temp2=temp2->next;
    }
}

int main()
{
  int n,m,t,pos,max,greater;
  int a,b,c,net;
  node *temp,*temp2;
  sc(t);
  while(t>0)
    {
      for(a=0;a<1005;a++)
	{
	  backarr[a]=arr[a]=NULL;
	  visited[a]=0;
	}
      sc(n);
      a=1;
      max=count=0;
      pos=1;
      while(a<=n)
	{
	  sc(m);
	  b=0;
	  while(b<m)
	    {
	      sc(greater);
	      if(arr[greater]==NULL)
		{
		  arr[greater]=(node*)malloc(sizeof(node));
		  arr[greater]->num=a;
		}
	      else
		{
		  temp=(node*)malloc(sizeof(node));
		  temp->num=a;
		  temp->next=arr[greater]->next;
		  arr[greater]->next=temp;
		}

	      if(backarr[a]==NULL)
		{
		  backarr[a]=(node*)malloc(sizeof(node));
		  backarr[a]->num=greater;
		  temp2=backarr[a];
		}
	      else
		{
		  temp2->next=(node*)malloc(sizeof(node));
		  temp2->next->num=greater;
		  temp2=temp2->next;
		}

	      b++;
	    }
	  
	  a++;
	}
      
      for(a=1;a<=n;a++)
	{
	  count=0;
	  winner(a);
	  for(b=0;b<=n;b++)
	    visited[b]=0;
	  if(count==n)
	    break;
	}
      count=0;
      if(n!=0 && a<=n)
	backward(a);

      printf("%d\n",count);
      t--;
    }
  return 0;
}
