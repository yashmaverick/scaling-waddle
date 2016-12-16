#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct circular_queue
{
    char str[123];
}cq;

cq q[100000];

int front,rear,max;

void enq(char input[])
{
    if(((front==0) && (rear==max-1)) || (front==rear+1))
    {
        strcpy(q[front].str,input);
        if(front==max-1)
            front=0;
        else
            front++;
        if(front==0)
            rear=max-1;
        else
            rear=front-1;
        return;
    }

    if(front==-1)
    {
        front=rear=0;
    }
    else
    {
        if(rear==max-1)
            rear=0;
        else
            rear++;
    }

    strcpy(q[rear].str,input);

}

void deq()
{
    //char temp[101];
    /*
    if(front==-1)
    {
        printf("Queue underflow!!!\n");
        return;
    }
    */

    //strcpy(temp,q[front].str);

    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        if(front==max-1)
            front=0;
        else
            front++;
    }

    //printf("Successfully deleted value: %s\n",temp);

    return;
}

void display()
{
    //char temp[101];
    int i;

    
    /*if(front==rear && front==-1)
        printf("Queue Underflow!!!\n");
    else
        for(i=front;i!=rear;i=i%max)
            printf("%s\n",q[i].str);
    printf("\n");*/
    //if(front==-1)
        //printf("queue underflow\n");
    //else 
    if(front==-1 && front==rear)
    {
        return;
    }
    else if(rear>=front)
        for(i=front;i<=rear;i++)
            printf("%s\n",q[i].str);
    else
    {
        for(i=front;i<=max-1;i++)
            printf("%s\n",q[i].str);
        for(i=0;i<=rear;i++)
            printf("%s\n",q[i].str);
    }
    return;
}

int main()
{
    char command,input[101];
    int n,i;

    scanf("%d",&max);
    //printf("Size of buffer: %d\n\n",max);

    front=rear=-1;

    do
    {
        scanf("%c",&command);

        switch(command)
        {
            case 'A': scanf("%d",&n);
                      for(i=0;i<n;i++)
                      {
                          scanf("%s",input);
                          //printf("enquing\n");
                          enq(input);
                          //printf("enq'd\n");
                      }
                      break;
            case 'R': scanf("%d",&n);
                      for(i=0;i<n;i++)
                      {
                          deq();
                      }
                      break;
            case 'L': display();
                      break;
            case 'Q': break;
        }
    }while(command!='Q');

    return 0;
}
