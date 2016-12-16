#include<stdio.h>
#include<stdlib.h>
#define g(x) scanf("%lld",&x)
 long long int front=0,stack[1000000];
void push(long long int i)
{
    stack[front]=i;
    front++;
}
long long int pop()
{
    front--;
    return stack[front];
}
int main()
{long long int area;
    long long int i,j,k,l,*q,c,a,b,d,w;
    g(c);
    while(c!=0)
    {area=0;
        q=malloc(sizeof(long long int)*c);
        g(q[0]);
        push(0);
        for(i=1;i<c;i++)
        {
            g(q[i]);
            if(front!=0 && q[i]<q[stack[front-1]])
            {
                while(q[i]<q[stack[front-1]] && front!=0)
                {d=i-1-stack[front-1];
                    if(front == 1)
                        b=stack[front-1];
                    else
                        b=stack[front-1]-1-stack[front-2];
                            if((q[stack[front-1]]*(b+d+1))>area)
                                area=q[stack[front-1]]*(b+d+1);
                    pop();
                }
            }
            if(q[i]>=q[stack[front-1]] || front == 0)
            push(i);
                   //    printf("%lld ",area);
        }
        //for(i=0;i<front;i++)
          //  printf("%d ",stack[i]);
        while(front!=0)
        {b=c-1-stack[front-1];
            if(front==1)
            d=stack[front-1];
            else
                d=stack[front-1]-1-stack[front-2];
//            printf("%lld %lld",b,d);
            if((q[stack[front-1]]*(b+d+1))>area)
                area=q[stack[front-1]]*(b+d+1);
            w=pop();
       // printf("%lld ",area);
        }
        printf("%lld\n",area);
        free(q);
        g(c);
    }
    return 0;
}





    


