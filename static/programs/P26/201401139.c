#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n);

typedef struct dabba
{
  int num;
  struct dabba *next;
}node;

node *arr[10000];
int prime[10002];
int queue[100000];
int visited[10005];
int rear,front;

void sieve()
{
  int a,b,p=2;
  
  for(b=2;b<=101;b++)
    {
      if(prime[b]==0)
	{
	  p=b;
	  for(a=p+p;a<10000;a+=p)
	    {
	      prime[a]=1;
	    }
	}
    }
}

void make(int src,int dest)
{
  if(arr[src]==NULL)
    {
      arr[src]=(node*)malloc(sizeof(node));
      arr[src]->num=dest;
    }
  else
    {
      node* temp=(node*)malloc(sizeof(node));
      temp->num=dest;
      temp->next=arr[src]->next;
      arr[src]->next=temp;
    }
}

void construct(int a)
{
  int num=a,digit,initial;
  int i,j,rand=1;
  for(i=0;i<4;i++)
    {
      digit=(num%(rand*10)-num%(rand))/rand;
      initial=num-digit*rand;
      if(i==3)
	{
	  j=1;
	  initial+=rand;
	}
      else 
	j=0;
      for(j;j<10;j++)
	{
	  if(prime[initial]==0 && j!=digit)
	    make(a,initial);
	  initial+=rand;
	}
      rand*=10;
    }
}

int min,counter,flag;
int endnode;
void bfs(int pos)
{
  node *temp=arr[pos];
  if(visited[pos]==0)
    {
      visited[pos]=1;
      
      while(temp!=NULL)
	{
	  if(visited[temp->num]==0)
	    {
	      //printf("%d ",temp->num);
	      if(temp->num == endnode)
		{
		  //printf("##################\n");
		  min++;
		  flag=1;
		  break;
		} 
	      else
		queue[++front]=temp->num;
	    }
	  temp=temp->next;
	}
    }
  
  counter--;
  if(counter==0 && flag!=1)
    {
      min++;
      counter=front-rear;
    }
  
  
  if(flag!=1 && rear != front-1)
    bfs(queue[++rear]);
  else
    return;
  
}

int main()
{
  int a,b,c,source,dest,t;
  int count;
  node *temp;
  sieve();
  
  for(a=1000;a<10000;a++)
    {
      if(prime[a]==0)
	{
	  construct(a);
	}
    }
  
  /*for(a=1000;a<=10000;a++)
    {
      if(prime[a]==0)
	{
	  temp=arr[a];
	  printf("%d ",a);
	  while(temp!=NULL)
	    {
	      printf("%d ",temp->num);
	      temp=temp->next;
	    }
	  printf("\n");
	}
    }*/
  sc(t);
  while(t--)
    {
      for(a=0;a<10000;a++)
	visited[a]=0;

      sc(source);
      sc(endnode);
  
      front=rear=0;
      min=flag=0;
      if(source!=endnode)
	{
	  counter=1;
	  queue[0]=source;
	  bfs(source);
      //printf("%d\n",endnode);
      //printf("%d\n",flag);
	}
      printf("%d\n",min);
    }
  return 0;
}
