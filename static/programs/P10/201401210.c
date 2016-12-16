#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)

typedef char string[105];
string q[10001];
int N , front=-1 , rear=-1;

void app()
{
    if(front == -1)
        front = rear = 0;
    else
    {
        if(rear == N-1)
            rear = 0;
        else
            rear++;
        if(rear == front)
            if(front == N-1)
                front = 0;
            else
                front++;
    }
    char word[100];
    instr(word);
    strcpy(q[rear] , word);
//     printf("inputted\n");
    return;
}

void del()
{
    if(front == -1)
        return;
    else
    {
        if(front == rear)
            front = rear = -1;
        else
        {
            if(front == N-1)
                front = 0;
            else
                front++;
        }   
    }
}

void disp()
{
    int i = front;
    if(front == -1)
        return;
    while(i != rear)
    {
        if(q[i] != "\n")
            puts(q[i]);
        i++;
        i %= N;
    }
    puts(q[rear]);
    return;
}

int main()
{
    char c ;
    int no;
    ini(N);
    getchar();
    do
    {
        scanf("%c", &c);
//         printf("This is c : %c\n" , c);
        if(c == 'A' || c== 'R')
            ini(no);
        if(c == 'A')
            while(no--)
                app();
        else if(c == 'R')
            while(no--)
                del();
        else if(c == 'L')
            disp();
    }while(c != 'Q');
    return 0;
}
