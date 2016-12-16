#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int a[1000001]={0},i,n;
        long long count=0,tempc=1;
        scanf("%d",&n);
        for( i=0 ; i<n ; i++)
            scanf("%d",&a[i]);
        qsort(a,n,4,cmpfunc);
        for(i=1;i<n;i++)
        {
            if( a[i] == a[i-1] )
                tempc++;
            else 
            {
                count += tempc*(tempc-1)/2;
                tempc=1;
            }
        }
        count=count+(tempc*(tempc-1))/2;
        printf("%lld\n",count);
        t--;
    }
    return 0;
}
