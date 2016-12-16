#include<stdio.h>
#define g(t) scanf("%lld",&t)
#include<stdlib.h>
int main()
{
    long long int i,j,a,b,count,*q,c,max;
    g(c);
    while(c!=0)
    {count=0;
    q=malloc(sizeof(long long int)*c);
    for(i=0;i<c;i++)
        g(q[i]);
    for(i=0;i<=(c-2);i++)
    {max=q[i+1];
        for(j=i+1;j<c;j++)
        {
            if(q[j]<max)
                count++;
            if(q[j]>q[i])
            {
                count+=c-1-j;
                break;
            }
            if(q[j]>max)
            {
                max=q[j];
            }
        }
        //printf("%d ",count);
    }
    printf("%lld\n",count);
    free(q);
    g(c);
    }
    return 0;
}


    

