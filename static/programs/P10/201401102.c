#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* a[100000]={NULL};
int front=-1,last=-1,N;
void enq(char* val)
{
        char* temp=a[front];
        if(last==N-1)
                last=-1;
        a[++last]=val;
        if(front==last)     
        {
                free(temp);
                front++;
                if(front==N)
                        front=0;
        }
        if(front==-1)
                front++;
}   
void deq()
{
        char* temp=a[front];
        free(temp);
        front++;
        if(front==last+1)
        {       front=-1;
                last=-1;
        }    
        if(front==N)
                front=0;
}
void printq()
{
        if(front!=-1&&last!=-1)
        {
                int temp=front;
                {
                        while(temp!=last)
                        {
                                printf("%s\n",a[temp++]);
                                if(temp==N)
                                        temp=0;
                        }
                        printf("%s\n",a[temp]);
                }
        }
        /*if(front==-1)
                printf("Empty\n");*/
        //printf("%d %d\n",front,last);
}
int main()
{
        char opt,s[101];
        int n,i,j;
        scanf("%d",&N);
        while(1)
        {
                scanf("%c",&opt);
                if(opt=='A')
                {
                        scanf("%d",&n);
                        for(i=0;i<n;i++)
                        {
                                scanf("%s",s);
                                getchar();
                                int len=strlen(s);
                                char* temp=(char* )malloc((len+1)*sizeof(char));
                                for(j=0;j<=len;j++)
                                        temp[j]=s[j];                                                    
                                
                                enq(temp);
                        }
                }
                else if(opt=='R')
                {
                        scanf("%d",&n);
                        for(i=0;i<n;i++)
                                deq();
                }
                else if(opt=='L')
                {
                        printq();
                }
                else if(opt=='Q')
                        break;
        }
        return 0;
}
