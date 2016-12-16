// #Authored  Jaipal Singh Goud
// Part of : DS - Assignment 2 
// Date : 6/3/2015
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define MAX 100001 

int min(int a,int b);

int main()
{
    int input[MAX]; 
    int left_array[MAX]; 
    int right_array[MAX];
    int min_val[MAX]; 

    int i,j,k,test; 
    int n,w;
    int comparisions;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&w);

        k = n-w+1; // k windows ban jaati hai

        for(i=1;i<=n;i++)
        {
            scanf("%d",&input[i]);
            min_val[i] = input[i];
        }
        if(w != 1)
        {

            for(i=1;i<=n;i++)
            {
                if(i%w == 1)
                    left_array[i] = input[i];
                else
                    left_array[i] = min(left_array[i-1], input[i]);        
            }

            for(i=n;i>=1;i--)
            {
                if(i == n)
                    right_array[i] = input[i]; 
                else if(i%w == 0)
                    right_array[i] = input[i];
                else
                    right_array[i] = min(right_array[i+1], input[i]);
            }

            for(i=1;i<=k;i++)
                min_val[i] = min(right_array[i], left_array[i+w-1]);
        }
        for(i=1;i<=k;i++)
        {
            if(i!=k)
                printf("%d ",min_val[i]);
            else
                printf("%d",min_val[i]);
        }
                
        printf("\n");
    }
    return 0;
}
int min(int a , int b )
{
    if(a>b)
        return b;
    return a;
}
