#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
        int n,front=-1,rear=-1,nmbr,i,k,x;
        scanf("%d",&n);
        getchar();
        char c,a[n][105];
        scanf("%c",&c);
        while(1)
        {
                if(c=='A')
                {
                        scanf("%d",&nmbr);
                        while(nmbr--)
                        {
                                if((rear+1)%n==front)
                                {
                                        front=(front+1)%n;
                                        rear=(rear+1)%n;
                                }
                                else
                                {
                                        if(front==-1) 
                                                front=0;
                                        rear= (rear+1)%n;
                                }
                                scanf("%s",a[rear]);
                        }
                }
                else if(c=='L')
                {
                        /*                       if(rear>front) x = rear-front+1;
                                                 else x= (n-front) + (rear+1);
                         */                        for(i=front;1;i=(i+1)%n)
                        {
                                if(front==-1)
                                        break;
                                printf("%s\n",a[i]);
                                if(i==rear)
                                        break;
                        }
                }
                else if(c=='R')
                {
                        scanf("%d",&nmbr);

                        if(rear>front) x = rear-front+1;
                        else if(rear==front)
                                x=1;
                        else
                                x= (n-front) + (rear+1);
                        if(nmbr >= x) {front=-1;rear=-1;}
                        else 
                             front=(front+nmbr)%n;
                }
                else if(c=='Q') 
                                return 0;
                        getchar();
                        scanf("%c",&c);
                }
                return 0;
        }
