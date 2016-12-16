// #Authored : Jaipal Singh Goud
// Part of : DS - Assignment 2 
// Date : 4/3/2015 KAL HOLI HAI :P
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define empty -1

long long int stack[500001];
long long int top;
long long int counter = 0;                          // Number of times the dragons can see each other
long long int a[500001];

void push(long long int n);
long long int pop();
void check_equal(long long int i);

long long int main()
{
    long long int i,j,k,n,test;
    long long int temp = 0;

    scanf("%lld",&n);
    while(n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        i = 0;
        top = -1;
        counter = 0;
        for(i=0;i<n;i++)
        {
            if(top == empty)
            {
                push(a[i]);
                if( i!=0 )
                    counter++;
            }
            else if(stack[top] > a[i])
            {
                push(a[i]);
                counter++;
            }
            else if(stack[top] < a[i])
            {
                while(stack[top] < a[i] && top != empty)
                {
                    temp = pop();
                    counter++;
                }
                push(a[i]);
                if(top != 0)
                    counter++;
                if(top != 0 && a[i]==stack[top-1])
                    check_equal(i);              // Check if there are repeating elements dans la stack pour incremente
            }
            else                            // This is the condition if stack[top] == a[i] We've now gotten ourselves into repeating elements.
            {
                push(a[i]);
                counter++;
                temp = top-2;
                while(stack[temp] == a[i])  // Traverse till you find a mountain whose height is not equal to that of the current mountain or you exhaust the stack
                {
                    temp--;
                    counter++;              // Across two mountains of the same height
                }
                if(temp == -1)              // If there is no mountain higher than the current one
                    ;
                else
                    counter++;              // There is some mountain which is higher than the current one.
            }
        }
        long long int total = (n*(n-1))/2;
        long long int answer = total - counter;
        printf("%lld\n",answer);
        scanf("%lld",&n);
    }
    return 0;
}
void push(long long int n)
{
    top++;
    stack[top] = n;
}
long long int pop(long long int n)
{
    long long int temp = top;
    top--;
    return stack[temp];
}
void check_equal(long long int i)
{
    long long int temp = top - 2;
    while(stack[temp] == a[i])  // Traverse till you find a mountain whose height is not equal to that of the current mountain or you exhaust the stack
    {
        temp--;
        counter++;              // Across two mountains of the same height
    }
    if(temp == -1)              // If there is no mountain higher than the current one
        ;
    else
        counter++;              // There is some mountain which is higher than the current one.
}
