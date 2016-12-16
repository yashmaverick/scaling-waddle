// #Authored : Jaipal Singh Goud
// Part of : DS - Assignment 2 
// Date : 6/3/2015
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>


int main()
{
    unsigned long long int i;
    i = 0;
    unsigned long long int x;
    long long int test;
    long long int n;
    long long int level = 0;
    x = 1;
    scanf("%lld",&test);
    while(test--)
    {
        x=1; i=0; level=0;
	scanf("%lld",&n);
        while(x<=n)
        {
            x = x<<1;
            i++;
        }
        
        x = x>>1;
        i = i-1;

        if( n==x )                        // Check if present at extreme Node of left tree
        {
            level = i+i-1;
        }
        else if(x+(x/2) <= n)             // Check if present in right sub-tree
        {
            level = i+i;
        }
        else
        {
            level = i+i-1;
        }
        if(n == 1)
            printf("0\n");
        else
            printf("%lld\n",level);
    }
    return 0;
}
