#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1,rear=-1,n,count=0,flag;
char r[10001][105];
void push(char s[105])
{count++;
    flag=0;
    count=count%n;
        if(top==-1)
        {
            top++;
            rear++;
            strcpy(r[top],s);
        }
        else if(rear-top==1||top-rear==n-1)
        {
            top++;
            top=top%n;
            rear++;
            rear=rear%n;
            strcpy(r[top],s);
        }
        else
        {
            top++;
            top=top%n;
            strcpy(r[top],s);
        }
}

void display()
{if(top==-1)
    return;
    if(top-rear>=0)
    {
        int u=rear;
        while(u<=top)
        { 
        printf("%s\n",r[u]);
        u++;
        }
    }
    else
    {
        int p;
        for(p=rear;p<n;p++)
            printf("%s\n",r[p]);
        for(p=0;p<=top;p++)
            printf("%s\n",r[p]);
    }
}

void pop()
{
    if(rear==top)
        flag=1;
    count--;
    rear++;
    rear=rear%n;
    if(flag==1)
    {
        top=-1;
        rear=-1;
    }
}
int main()
{
    scanf("%d",&n);
    int d=0;
    char ch;
    scanf("%c",&ch);
    if(ch=='A'||ch=='R')
    scanf("%d",&d);

    while(ch!='Q')
    {
        char str[105];
        switch(ch)
        {
            case 'A':
                while(d--)
                {scanf("%s",str);
                push(str);
                }
                break;
            case 'R':
                while(d--)
                {
                    pop();
                }
                break;
            case 'L':display();
                     break;
        }
    scanf("%c",&ch);
    if(ch=='A'||ch=='R')
    scanf("%d",&d);
        }
    //pop();
    //pop();
    //display();
    return 0;
}
    
