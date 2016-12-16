#include <stdlib.h>
#include <stdio.h>
typedef struct stack
{
	 int stak[100000];
     int top;
}stack ;
stack s ;

void push(long long int num)
{
        s.top = s.top + 1;
        s.stak[s.top] = num;
    return;
}
int empty()
{
   if(s.top==-1)
        return 1 ;
    return 0 ;
}
void pop ()
{
    long long int num;
        num = s.stak[s.top];
        s.top = s.top - 1;
    return;
}

long long int getMaxArea(long long int a[],long long int n)
{
    int r ;
    s.top = -1 ;
    long long int max_area = 0,i=0,tp,area_with_top,j;
    while(i<n)
    {
        if(empty() || a[s.stak[s.top]] <= a[i])
        {
        	push(i) ;
            i = i +1 ;
        }
        else
        {
            tp = s.stak[s.top];
            if(!empty())
                pop() ;
            area_with_top = a[tp] * (empty() ? i : i - s.stak[s.top] - 1);
            if (max_area < area_with_top)
            {
                max_area = area_with_top;
            }
        }
    }
    while(empty()==0)
    {
        tp = s.stak[s.top];
        if(!empty())
            pop() ;
        area_with_top = a[tp] * (empty() ? i : i - s.stak[s.top] - 1);
        if (max_area < area_with_top)
        {
            max_area = area_with_top;
        }
    }
    return max_area;
}

int main()
{
    long long int n,i ,maxA;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            return 0 ;
        long long int A[n];
        for(i=0;i<n;i++)
            scanf("%lld",&A[i]) ;
        maxA= getMaxArea(A,n) ;
        printf("%lld\n",maxA );
    }
    return 0;
}

