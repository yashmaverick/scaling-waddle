#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t!=0)
    {
        long long int *stack,*array,i,k=0,j=0,area=0,max=-1;
        array = (long long int *)malloc(sizeof(long long int)*t);
        stack = (long long int *)malloc(sizeof(long long int)*t);
        for(i=0;i<t;i++)
            scanf("%lld",&array[i]);
        i-=t;
        while(i<t)    
        {
            if( k==0 || array[stack[k-1]] <= array[i])
                stack[k++]=i++;
            else
            {
                j=stack[k-1];
                k--;
                if(k==0)
                    area = array[j]*i;
                else
                    area = array[j]*(i-stack[k-1]-1);
                if(area>max)
                    max=area;
            }
        }
        while(k)
        {
            j=stack[k-1];
            k--;
            if(k==0)
                area = array[j]*i;
            else
                area = array[j]*(i-stack[k-1]-1);
            if(area>max)
                max=area;
        }
        printf("%lld\n",max);
        scanf("%lld",&t);
        free(array);
        free(stack);
    }
    return 0;
}
