#include <stdio.h>
#include <string.h>

char buffer[10005][105];
int N;
int front=-1;
int rear=-1;
int no_of_elements=0;

void insert()
{
  int n;
  scanf("%d",&n);
  no_of_elements+=n;
  if(no_of_elements>N)
    no_of_elements=N;
  while(n--)
    {
      if(rear==-1)
	front=0;
      else if((rear+1)%N==front)
	front=(front+1)%N;
      rear=(rear+1)%N;
      scanf("%s",buffer[rear]);
    }
}

void rem()
{
  int n;
  scanf("%d",&n);
  no_of_elements-=n;
  front=(front+n)%N;
  if(no_of_elements==0)
    {
      front=-1;
      rear=-1;
    }
}

void list()
{
  if(no_of_elements==0)
    return;
  /* static int i=0; */
  /* printf("%dth call:\n",i++); */
  int i;
  //printf("%d %d %d\n",front,rear,no_of_elements);
  if(front<=rear)
    for(i=front;i<=rear;i++)      
      printf("%s\n",buffer[i]);
  else
    {
    for(i=front;i<N;i++)
      printf("%s\n",buffer[i]);
    for(i=0;i<=rear;i++)
      printf("%s\n",buffer[i]);
    }
}

char read_choice()
{
  char c;
  c=getchar();
  while(c=='\n')
    {
      c=getchar();
    }
  return c;
}

int main()
{
  scanf("%d",&N);
  char c;
  c=read_choice();
  while(c!='Q')
    {
      switch(c)
	{
	case 'A':insert();
	  break;
	case 'R':rem();
	  break;
	case 'L':list();
	  break;
	}
      c=read_choice();
    }
  return 0;
}

