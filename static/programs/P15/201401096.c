#include<stdio.h>
#define size 20020
long long int front,rear;
long long int n;
long long int input[10010];
long long int q[size];
void enq(long long int v){// printf("pushed:%lld\n",input[v]);
    q[++rear]=v;}
void deq1()
{ //printf("popped:%lld\n",input[q[front]]);
    front++;}
void deq(){//printf("popped behind:%lld\n",input[q[rear]]);
    rear--;}
int main()
{
    long long int  test,t;
    scanf("%lld",&test);
    long long int i,k;
    t=0;
    
    while(t<test)
    {   front=10006;rear=10005;
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&input[i]);
        }
        i=0;

        for(i=0;i<=k-1;i++)    
        {

            while(front<=rear&&input[i]<=input[q[rear]])
            {deq();}

            enq(i);
        }

        for(;i<n;i++)
        {
           printf("%lld ",input[q[front]]);

            while(front<=rear&&q[front]<=i-k)
                deq1();

            while(front<=rear&&input[i]<=input[q[rear]])
                deq();

                enq(i);
        }
        printf("%lld\n",input[q[front]]);
        
        t++;

    }
    return 0;
}

