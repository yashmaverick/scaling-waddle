#include<stdio.h>
#include<stdlib.h>

typedef struct dabba
{
  char word[105];
  struct dabba *next;
}node;

node *start,*front,*rear;
int MAX;

void append(int n)
{
  int a=0;
  if(front==NULL && n!=0)
    {
      front=rear=start;
      scanf("%s",front->word);
      n--;
    }
  
  for(a=0;a<n&&MAX!=0;a++)
    {
      if(front->next==rear)
	rear=rear->next;
      front=front->next;
      scanf("%s",front->word);
    }
}

void printbuff()
{
  node *top=rear;
  if(front!=NULL)
    {
      while(top!=front)
	{
	  printf("%s\n",top->word);
	  top=top->next;
	}
      printf("%s\n",top->word);
    }
}

void delete(int n)
{
  int a;
  
  
  for(a=0;a<n;a++)
    {
      rear=rear->next;
    }
      
  if(n!=0 && rear==front->next )
    rear=front=NULL;
  
}

int main()
{
  node *top,*head;
  int n,a,val;
  char choice;
  scanf("%d",&n);
  MAX=n;
  if(n!=0)
    {
      start=(node*)malloc(sizeof(node));
      top=start;
      for(a=0;a<n-1;a++)
	{
	  head=(node*)malloc(sizeof(node));
	  top->next=head;
	  top=head;
	}
      top->next=start;
    }
  
  front=rear=NULL;
  
  do
    {
      scanf("%c",&choice);
      switch(choice)
	{
	case 'A': scanf("%d",&val);
	  append(val);break;

	case 'R': scanf("%d",&val);
	  delete(val);break;

	case 'L': 
	  printbuff(val);break;

	}
    }while(choice!='Q');

  return 0;
}
  
