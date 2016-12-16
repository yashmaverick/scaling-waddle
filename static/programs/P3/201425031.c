#include<stdio.h>

int main()
{
    int N,m,i,j,k;
    long long int arr[100001],maxdiff,min;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%lld",&arr[i]);
        min=arr[0];
        maxdiff=0;
        for(i=0;i<m;i++)
        {
            if(arr[i]<=min)
            {    min=arr[i];}

            if((arr[i]-min)>=maxdiff)
            {   maxdiff=(arr[i]-min);}
        }
        printf("%lld\n",maxdiff);
    }
    return 0;
}
