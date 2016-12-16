#include<stdio.h>
int front=-1,rear=-1;
int qin(char a[][101],int n)
{
  if(front==(rear+1)%n&&n!=1)
    front=(front+1)%n;
//  printf("F:%d  ",front); 
  if(front==-1)
    front=(front+1)%n;
//  printf("f:%d  ",front);
  rear=(rear+1)%n;
//  printf("R:%d\n",rear);
  scanf("%s",a[(rear%n)]);
  return 0;
}
int qdel(char a[][101],int n)
{
  if(front==-1)
    {
      //   printf("Underflow\n");
      return 0;
    }
  if(front==rear)
    {
      front=rear=-1;
      //        printf("right place\n");
    }
  else
    {
      front=(front+1)%n;
      //      printf("wrong place\n");
    }

  return 0;
}
int qprint(char a[][101],int n)
{
  if(front!=-1 && rear!=-1)
    {
      int i,m;    
      if(front<=rear)
	m=rear;
      if(rear<front)
	m=n+rear;
      for(i=front;i<=m;i++)
	printf("%s\n",a[i%n]);
    }
  return 0;
}
int main()
{
  int n,k,i;
  scanf("%d",&n);
  char a[10100][101],choice='z';
  while(choice!='Q')
    {
      scanf("%c",&choice);
      if(choice=='A')
	{
	  scanf("%d",&k);
	  if(n!=0)
	    for(i=0;i<k;i++)
	      qin(a,n);
	}
      if(choice=='R')
	{
	  scanf("%d",&k);
	  if(n!=0)
	    for(i=0;i<k;i++)
	      qdel(a,n);
	}
      if(choice=='L')
	if(n!=0)
	  qprint(a,n);
    }
  return 0;
}
