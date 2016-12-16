#include<stdio.h>
#include<string.h>
void insert();
void rem();
void print();
int head=0,counter=0;
int N,mad=0;
char s[10001][101];
char sreeja[101];
int main()
{
  scanf("%d",&N);
  if(N!=0)
  {
    char ch;
    int val,i,c;
    //printf("enter the option\n");
    scanf("%c",&ch);
    //  printf("----hi mad3----\n");
    while(1)
    {
      if(ch=='A')    //Insert value
      {
	//printf("----hi mad1----\n");
	scanf("%d",&val);
	for(i=0;i<val ; i++)
	{
	  scanf("%s",sreeja);
	  insert();
	}
      }
      else if(ch=='R')   // Delete value
      {
	scanf("%d",&val);
	for(i=0 ; i<val ; i++)
	  rem();
      }
      else if(ch=='L')   // Print the entire linked list
      {
	print();
      }
      else if(ch=='Q')  // End the program
	break;
      //printf("enter the option\n");
      scanf("%c",&ch);
    }
  }
  return 0;
}
void insert()
{
  if(counter==0)
  {
  
  head=0;
  mad=0;
  
  }
  int i,x,y;
  x=head;
  y=counter;
  if(y!=N)
  {
    //printf("i am inside insert and head and counter are%d%d\n",x,y);
    //printf("----hi mad2----\n");
    if((x+y)<N)
    {
      strcpy(s[x+y],sreeja);
       //printf("i am inside insert s[x+y] when x+y<N is%s\n",s[x+y]);
      counter++;
    }
    else
    {
	mad=x+y-N;
      strcpy(s[mad],sreeja);
      //printf("u knoe i am mad%d and s[mad]= %s\n",mad,s[mad]);
      mad++;
      counter++;
    }
  }
  else
  {

  if(counter==0)
  {
  
  head=0;
  mad=0;
  }
  //printf("i am in else %d\n",counter);
    if(head!=N)
    {
      strcpy(s[x],sreeja);
      //printf("u knoe i am head!=N %d and s[x]= %s\n",x,s[mad]);
      mad++;
      head++;
    }
    if(head==N)
    {
    //  printf("i am inside head==N %d\n",head);
      head=0;
    }
  }
}
void rem()
{
  //printf("i am above  rem and value of counter=%d and head =%d",counter,head);
  if(counter==0)
  {
  
  head=0;
  mad=0;
  } 
  if(counter!=0)
  {
    if(head==N-1)
    {
      head=0;
      counter--;
    }
    else
    {
      head++;
      counter--;
    }
  }
}
void print()
{
  int i;
  int x=head,y=counter;
  if(counter!=0)
  for(i=0 ; i<y ; i++)
  {
    if((x+i)==N)
    {
      y=y-i;
      i=0;
      x=0;
    }
  //printf("====i am inside print and value of counter(y)=%d and head(x) =%d and i is %d==",y,x,i);
    if(y!=0)
    {
      printf("%s\n",s[x+i]);
    }
  }

}
