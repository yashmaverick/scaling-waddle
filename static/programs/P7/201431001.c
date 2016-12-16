#include<stdio.h>

long long int compare (const void * a, const void * b)
{
    return ( *(long long int*)a - *(long long int*)b );
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,data[1000001],count=1,ans=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&data[i]);
        qsort(data,n,sizeof(long long int),compare);

        long long int temp=data[0];
        for(i=0;i<n-1;i++)
        {
            if(data[i]==data[i+1])
            {
                count++;
            }
            else
            {
                ans+=(count*(count-1))/2;
                count=1;
            }
        }
        ans+=(count*(count-1))/2;
        printf("%lld\n",ans);
    }
    return 0;
}
