#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char A[1000];
    struct node *next;
}queue;

queue *front,*rear,*temp1,*temp2;
char B[1000];
int count = 0;
void enqueue()
{
    if(rear == NULL)
    {
        rear = (queue *)malloc(sizeof(queue));
        scanf("%s",rear->A);
        rear->next=NULL;
        front = rear;
    }
    else
    {
        temp1 = (queue *)malloc(sizeof(queue));
        scanf("%s",temp1->A);
        temp1->next = NULL;
        rear->next = temp1;
        rear = temp1;
    }
    count++;
}

void dequeue()
{
    temp2 = front;
    if(temp2 == NULL)
        return;
    else
    {
        if(temp2->next ==NULL)
        {
            free(front);
            front = NULL;
            rear = NULL;
        }
        else
        {
            temp2 = temp2->next;
            free(front);
            front = temp2;
        }
    }
    count--;
}

void display()
{
    temp2 = front;
    if(temp2 == NULL && rear == NULL)
        return;
    while(temp2 != rear)
    {
        printf("%s\n",temp2->A);
        temp2 = temp2->next;
    }
    if(temp2 == rear)
        printf("%s\n",temp2->A);
}

int main()
{
    int size,n,i;
    scanf("%d",&size);
    char ch;
    scanf("%c",&ch);
    scanf("%c",&ch);
    while(ch != 'Q')
    {
        if(ch == 'A')
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                if(count == size)
                    dequeue();
                enqueue();
            }
        }
        else if(ch == 'R')
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
                dequeue();
        }
        else
            display();
        scanf("%c",&ch);
        scanf("%c",&ch);
    }
    return 0;
}
