#include<stdio.h>

int main()
{
    long long int x[100000],i,n,max,minindex;
    int t;

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%lld",&n);

        minindex=0;
        max=0;

        for(i=0;i<n;i++)
        {
            scanf("%lld",&x[i]);

            if(x[i]<x[minindex])
                minindex=i;
            if((x[i]-x[minindex])>max)
                max=x[i]-x[minindex];
        }

        printf("%lld\n",max);
    }
    return 0;
}
