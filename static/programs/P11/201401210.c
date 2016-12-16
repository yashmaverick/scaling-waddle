#include<stdio.h>
#include<stdlib.h>

#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)

long long max(long long a , long long b)
{
    return ((a<b)?b:a);
}

long long val[100005] ;
long long heightf[100005] , heightb[100005] , heightt[100005] , ih = 0 ;

struct stack
{
    long long stk[100005];
    long long h[100005];
    long long top;
};
typedef struct stack STACK;
STACK s;

void push(long long N , long long l)
{
    if(s.top == -1) 
    {
        s.top = 0;
        s.stk[s.top] = N;
        heightf[ih++] = s.h[s.top] = l;
    }
    else if(N <= s.stk[s.top])
    {
        long long t = s.h[s.top] + l;
        s.top--;
        push(N , t);
    }
    else
    {
        s.top++;
        s.stk[s.top] = N;
        heightf[ih++] = s.h[s.top] = l;
    }
}

int main()
{
    long long t , i;
    do
    {
        inll(t);
        long long m = 0;
        s.top = -1;
        ih = 0;
        
        for(i=0 ; i<t ; i++)
            inll(val[i]);
        
        for(i=t-1 ; i>=0 ; i--)
            push(val[i] , 1);
        
        for(i=0 ; i<t ; i++)
            heightb[i] = heightf[i];
                
        s.top = -1;
        ih = 0;
        
        for(i=0 ; i<t ; i++)
            push(val[i] , 1);
        
        for(i=0 ; i<t ; i++)
            heightt[i] = heightf[i] + heightb[t-i-1] - 1;
        
        for(i=0 ; i<t ; i++)
            m = max(m , (heightt[i]*val[i]));
        
        if(t != 0)
            outll(m);
        
    }while(t != 0);
    return 0;
}