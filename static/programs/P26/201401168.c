#include<stdio.h>
#include<stdlib.h>

typedef struct link
{
  int val;
  struct link *next;
}link;
link *head[10010];
int front=-1,rear=-1,max=10010,found,count,troll;
int qin(int a[],link *p,int visit[])
{
  if(front==rear+1||(front==0&rear==max-1))
    {    
      return 0;
    }
  while(p!=NULL)
    {
      if(visit[(p->val)-1]==0)
	{
	  visit[(p->val)-1]=1;
	  if(rear==max-1)
	    rear=0;
	  else
	    rear++;
	  if(front==-1)
	    front=rear=0;
	  a[rear]=p->val;
	}
      p=p->next;
    }
  return 0;
}
int qdel(int a[],int visit[])
{
  int x;
  if(front==-1)
    {
      return 0;
    }
  if(front==rear)
    {x=a[front];front=rear=-1;}
  else
    {
      if(front==max-1)
	{x=a[front];front=0;}
      else
	{x=a[front];front++;}
    }
  return x;
}

void insert(int i,int value)
{
  link *new=(link*)malloc(sizeof(link));
  link *hi=(link*)malloc(sizeof(link));
  hi->next=NULL;
  new->next=NULL;
  new->val=value;
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

void breadth(int n,int dest)
{
  int a[10010],visit[10010]={0},x;
  a[0]=n+1;visit[n]=1;
  front=0;rear=0;
  while(front!=-1 && rear!=-1)
    {
      x=qdel(a,visit);
      troll--;
      qin(a,head[x-1],visit);
      if(visit[dest]==1 && troll==0)
	{
	  count++;
	  found=1;
	  break;
	}
      if(troll==0)
	{
	  count++;
	  troll=rear-front+1;
	  //	  printf("troll= %d\n",troll);
	}

    }
}

int main()
{
  int sieve[10010]={0},t,i,j;
  for(i=2;i<5000;i++)
    {
      int u=10000/i;
      for(j=2;j<=u;j++)
	  sieve[(i*j)]=1;
    }
  for(i=1009;i<9974;i++)
    {
      if(sieve[i]==0)
	{
	  for(j=1;j<=36;j++)
	    {
	      int u,l;
	      if(j<=9)
		{
		  l=i%10;
		  u=(j%10)+l<10 ? (j%10) : (10- ((j%10)+l));	
		}
	      else
		if(j<=18)
		  {
		    l=(i/10)%10;
		    u=((j+1)%10)+l<10 ? ((j+1)%10)*10 : (100 - (((j+1)%10)*10 + l*10));
		  }
		else
		  if(j<=27)
		    {
		      l=(i/100)%10;
		      u=((j+2)%10)+l<10 ? ((j+2)%10)*100 : (1000-(((j+2)%10)*100 + l*100));
		    }
		  else
		    {
		      l=(i/1000)%10;
		      u=((j+3)%10)+l<10 ? ((j+3)%10)*1000 : (10000 - (((j+3)%10)*1000 + l*1000));
		    }
	      u=u+i;
	      if(u!=i && sieve[u]==0)
		{
		  insert(i-1,u);
		}
	    }
	}
    }
  scanf("%d",&t);
  while(t!=0)
    {
      found=0;count=0;troll=1;
      scanf("%d %d",&i,&j);
      breadth(i-1,j-1);
      if(i==j)
	count=0;
      if(found==1)
	  printf("%d\n",count);
      else
	printf("Impossible\n");
      t--;
    }
  return 0;
}
