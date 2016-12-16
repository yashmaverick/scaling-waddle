#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char str[101];
str buffer[10005];

int front = -1 ;
int rear = -1 ; 
int size;

void append();
void delete();
void list();

int main()
{
    scanf("%d", &size);
    char input;
    int n;
    getchar();
    do
    {
        scanf("%c", &input);
        if(input=='A')
        {
            scanf("%d", &n);
            while (n--)
                append();
        }
        
        else if(input=='R')
        {
            scanf("%d", &n);
            while (n--)
                delete();
            
        }
        else if(input=='L')
        {
            list();
            getchar();
        }
    }while(input!='Q');
    return 0;
}

void append()
{
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
    }
    else 
    {
        if(rear==size-1)
            rear=0;
        else
            rear++;
        if(rear==front)
        {
//             printf("OMG\n");
            if(front==size-1)
                front=0;
            else
                front++;
//             printf("%d %d\n" , front , rear);
        }
    }
    char w[100];
    scanf(" %s" , w);
    strcpy(buffer[rear] , w);
    return;
}

void delete()
{
    if(front==-1&&rear==-1)
        return;
    if(front==rear)
    {
//         printf("It happened!!!\n");
        front=-1;
        rear=-1;
    }
    else if(front==size-1)
        front=0;
    else
        front++;
//     printf("%d %d\n" , front , rear);
}

void list()
{    
    int i = front;
    if(front == -1)
        return;
    while(i != rear)
    {
        puts(buffer[i]);
        i++;
        i %= size;
    }
    puts(buffer[rear]);
    return;
}