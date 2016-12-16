// #Authored : Jaipal Singh Goud
// Part of : DS Assignment 2 
// Date :
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define empty -1
void scanint(long long int *p);

long long int stack[100005];
long long int top , current;

long long int main()
{
    long long int i,j,k,n,test;
    long long int area = 0;
    long long int max = 0;
    long long int ctrl;
    long long int values[100001];
    n = 100;
    while( n != 0 )
    {
        top = empty;
        scanf("%lld",&n);
        
        // long long int *values = (long long int *)malloc(sizeof(long long int)*n);                         // Dynamically Create the ARRAY
        
        for(i=0;i<n;i++)
            scanf("%lld",&values[i]);

        i=0;
        max = area = 0;

        while(i < n)
        {
            if(top == empty || values[i] >= values[stack[top]])             // When the stack is empty
            {
                top = top + 1;
                stack[top] = i;
                i++;
            }
            else
            {
                current=stack[top];
                top--;

                if(top != empty)
                    ctrl = (i-1-stack[top]);
                else
                    ctrl = i;

                area = values[current] * ctrl;


                if(area>max)
                    max = area;

            }
        }
        while(top != empty)                                                 // To clear out the remaining elements in the stack
        {
            current=stack[top];
            top--;

            if(top != empty)
                ctrl = (i-1-stack[top]);
            else
                ctrl = i;

            area = values[current] * ctrl;

            if(area>max)
                max = area;
        }
        if(n != 0)
            printf("%lld\n",max);
    }
    return 0;
}
void scanint(long long int *p)
{
    register long long int c = getchar_unlocked();
    long long int x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked())
        ;
    for(;c>47 && c<58;c = getchar_unlocked())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    *p = x;
}

