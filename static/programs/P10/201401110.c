#include<stdio.h>
#include<string.h>
int total;
char cq[10001][101];
int front,rear;
void enq(char str[])
{
  
  if(front==total-1)
  {
    front=0;
   // printf("front: %d\n",front);
  }
//  printf("IN ENQ\n");
//  printf("STR TO BE ENETRED: %s\n",str);
  if(front==-1&&rear==-1)
  {
 //   printf("FIRST TIME\n");
    front++;
    rear++;
    strcpy(cq[front],str); 
    strcpy(cq[rear],str); 
//    printf("CQ[front]: %s\n",cq[front]);
  }
  else if(rear==total-1)
  {
    if(front==0)
       front++;
     rear=0;
    strcpy(cq[rear],str);
  }
  else if(front==rear+1)
  {
    front++;
    rear++;
    strcpy(cq[rear],str);
 //   printf("CQ[front]: %s\n",cq[front]);
  }
 /* else if(rear==total-1)
  {
    printf("Entered special condition!\n");
    rear=0;
    strcpy(cq[rear],str); 
    printf("CQ[front]: %s\n",cq[front]);
  }*/
  else
  {
    rear++;
    strcpy(cq[rear],str); 
   // printf("CQ[front]: %s\n",cq[front]);
  }
}

void dq()
{
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else if(front==total-1)
            front=0;
    else front++;
}

void printq()
{
//  printf("IN PRINTQ\n");
//  printf("FRONT: %d REAR: %d\n",front,rear);
  int i=0;
  if(front==-1)
    return;
  else 
 {
    if(rear>=front)
    {
      for(i=front;i<=rear;i++)
        printf("%s\n",cq[i]);
    }
    else 
    {
      for(i=front;i<=total-1;i++)
        printf("%s\n",cq[i]);
      for(i=0;i<=rear;i++)
        printf("%s\n",cq[i]);
    }
  }
}



int main()
{
  int i,n;
  front=rear=-1;
  char str[105];
  char choice='a';
  scanf("%d",&total);
  if(total==0)
    return 0;
  while(choice!='Q')
  {
    scanf("%c",&choice);
    switch(choice)
    {
      case 'A':
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
          scanf("%s",str);
  //        printf("STR TO BE ENTERED %s\n",str);
          enq(str);
        }
        break;
      case 'R':
        scanf("%d",&n);
        for(i=0;i<n;i++)
          dq();
        break;
      case 'L':
        printq();
        break;
    }
  }
  return 0;
}


