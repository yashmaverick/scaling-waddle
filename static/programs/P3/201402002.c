#include<stdio.h>

int main()
{

    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        scanf("%d",&n);
        int arr[n];
        long long int profit=0,min=1000000000,max=-1;

        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            if (arr[j]<min)
            {
                min=arr[j];
                max=-1;
            }
            if (arr[j]>max)
                max=arr[j];
            if ((max-min)>profit)
                profit=max-min;
        }
        printf("%lld\n",profit);
    }

    return 0;
}
