#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long int a[n];
        int i,k;
        long long int min,maxProfit,diff;
        
        maxProfit=min=0;

        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        
        for(i=0;i<n;i++)
        {
            if(a[i]<a[min])
                min=i;
            
            diff=a[i]-a[min];
            
            if(diff>maxProfit)
                maxProfit=diff;
        }
        
        printf("%lld\n",maxProfit);
        
        maxProfit=min=0;
    }
    return 0;
}




