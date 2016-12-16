#include<stdio.h>
#include<stdlib.h>

#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d" , deci)
#define outll(lldeci) printf("%lld" , lldeci)
#define outstr(str) printf("%s" , str)
#define max( a , b ) return ((a > b) ? a : b)

int A[100005];

struct stack
{
    int stk[100005];
    int lev[100005];
    int top;
};
typedef struct stack STACK;
STACK s;

void pop()
{
    s.top--;
}

void push(int N , int l)
{
    if(s.top == -1) 
    {
        s.top = 0;
        s.stk[s.top] = N;
        s.lev[s.top] = l;
    }
    else if(N < s.stk[s.top])
    {
        int t = s.lev[s.top] + 1;
        
//         outi(s.stk[s.top]);
//         outstr(" ");
//         outi(t);
//         outstr("\n");
        pop();
        push(N , t);
    }
    else
    {
        int t;
        if(l == 0)
            t = s.lev[s.top] + 1;
        else
            t = l;
        s.top++;
        s.stk[s.top] = N;
        s.lev[s.top] = t;
    }
}

int main()
{
    int t , N , i;
    ini(t);
    while(t--)
    {
        int mdeep = 0;
        int mval = 0;
        s.top = -1;
        ini(N);
        for(i=0 ; i<N ; i++)
            ini(A[i]);
        for(i=N-1 ; i>=0 ; i--)
        {
            push(A[i] , 0);
//             outi(s.stk[s.top]);
//             outstr(" ");
//             outi(s.lev[s.top]);
//             outstr("\n");
            if(s.lev[s.top] >= mdeep)
            {
                
                mdeep = s.lev[s.top];
                mval = s.stk[s.top];
            }
            
        }
        printf("%d %d\n", mval , mdeep);
    }
}