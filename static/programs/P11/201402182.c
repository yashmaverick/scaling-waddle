#include <stdlib.h>
#include <stdio.h>
#define max 100000
typedef struct stack
{
	 int stk[max];
     int top;
}STACK ;
STACK s ;

void push(long long int num)
{
    if(s.top==(max-1))
    {
        return;
    }
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
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
    if (s.top == - 1)
    {
       
    }
    else
    {
        num = s.stk[s.top];
        s.top = s.top - 1;
    }
    return;
}

long long int getMaxArea(long long int a[],long long int n)
{
    int r ;
    s.top = -1 ;
    long long int max_area = 0,i=0,tp,area_with_top,j;
    while(i<n)
    {
        r = empty() ;
       // printf("%d\n",r);
        //printf("%d\n",s.top);
        /*for(j=0;j<n;j++)
        {
      //      printf("%d ",s.stk[j]) ;
        }*/
     //   printf("\n");
        if(empty() || a[s.stk[s.top]] <= a[i])
        {
            r= empty();
            push(i) ;
            i = i +1 ;
         
        }
        else
        {
            tp = s.stk[s.top]; 
           // printf(" top%lld\n",tp);
            if(!empty())
            {
                pop() ;
             
            }
            area_with_top = a[tp] * (empty() ? i : i - s.stk[s.top] - 1);
            if (max_area < area_with_top)
            {
                max_area = area_with_top;
            }
                    }
    }
    while(empty()==0)
    {
        tp = s.stk[s.top];
       // printf("%lld\n",tp);
        if(!empty())
            pop() ;
        area_with_top = a[tp] * (empty() ? i : i - s.stk[s.top] - 1);
        if (max_area < area_with_top)
        {
            max_area = area_with_top;
           // printf("thi=%lld\n",max_area );
        }
    }
    return max_area;
}

int main()
{
    long long int n,i ,ans;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            return 0 ;
        long long int a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]) ;
        ans= getMaxArea(a,n) ;
        printf("%lld\n",ans ); 
    }
    return 0;
}
