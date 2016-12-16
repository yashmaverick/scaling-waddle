#include<stdio.h>
#include<stdlib.h>
#define f(a,b) scanf("%lld%lld",&a,&b)
#define g(x) scanf("%lld",&x)
long long int front=0,rear=0,a,number=0;
typedef struct link
{
    long long int value;
    long long int index;
}links;
links *stack;
void push(long long int p,long long int inde)
{
    stack[rear].value=p;
    stack[rear].index=inde;
    rear++;
}
long long int pop()
{rear--;
    return stack[rear].value;
}

int main()
{
    long long int i,j,t,N,K,*q,w=0,k,count=0;
    g(t);
    for(i=0;i<t;i++)
    {front=0;
        rear=0;
        f(N,K);
        count=0;
        q=malloc(sizeof(long long int)*N);
        stack=malloc(sizeof(links)*(N+10));
        for(j=0;j<N;j++)
            g(q[j]);
        for(j=0;j<=K-1;j++)
        {if(rear == 0)
                push(q[j],j);
            else
            {
                if(q[j]>=stack[rear-1].value)
                    push(q[j],j);
                else
                {
                    while(q[j]<stack[rear-1].value && rear>0)
                    {
                        pop();
                    }
                    push(q[j],j);
                }
            }
        }
        printf("%lld",stack[front].value);
        count++;
        if(count!=(N-K+1))
            printf(" ");
        a=1;
        for(k=j;count<(N-K+1);k++)
        {
            if(front == rear )
            {
                push(q[k],k);
            }
            else
            {
                if(q[k]>=stack[rear-1].value)
                    push(q[k],k);
                else
                {
                    while(q[k]<stack[rear-1].value && rear>front)
                    {
                        pop();
                    }
                   // if( rear == front)
                     //   a=1;
                    push(q[k],k);
                }}
            if(stack[front].index == (k-K))
              front++;
          //  if(count==(N-K))
            //    break;
            printf("%lld",stack[front].value);
            count++;
            if(count!=(N-K+1))
                    printf(" ");
            }
            printf("\n");
            free(q);
            free(stack);
        }
    return 0;
}
