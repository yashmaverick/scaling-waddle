#include<stdio.h>
int n,size=500000;
long long int stack[500000];
int top;
long long int input[500000];
void push(long long int el)
{
    if (top==size-1)
    {
        return;
        printf("OVERFLOW");
    }    
    top=top+1;
    stack[top]=el;
}
long long int pop()
{
    if(top==-1)
        return -1;
    long long int prev=stack[top];
    top=top-1;
    return prev;
}
long long int peek()
{
    if(top==-1) return -1;
    else
        return stack[top];
}
void print_stack()
{

    int i;
    printf("elements: \n");
    for(i=top;i>=0;--i)
        printf("%lld ",stack[i]);

    printf("\n");
}
int main()
{
    int flag=1;
    long long int ans;
    int b;
    int breaker;
    int trail;
    while(flag)
    {
        top=-1;
        ans=0;

        scanf("%d",&n);
        if(n==0)
            break;
        for(b=0;b<n;++b)
            scanf("%lld",&input[b]);
        b=0;
        while(b<n)
        {

            if(top==-1||input[b]<=stack[top])
            {
                push(input[b]);trail=top;
                while(top>=0&&stack[trail]==stack[top])
                    trail--;

                if(trail>0)ans+=trail;
                b++;
            }
            else
            {
                breaker=b;pop();ans=ans+n-breaker-1;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}




