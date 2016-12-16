#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,ans,max=0;
        scanf("%lld",&n);
        ans = n;
        while(ans)
        {
            ans >>= 1;
            max++;
        }
        //printf("Debug n>>max-1,max %d %d\n",n>>(max-2),max);
        if(n == 0 || n == 1)
            max = 0;
        else if((n>>(max-2))%2)
            max = 2*max-2;
        else
            max = 2*max-3;
        printf("%lld\n",max);
    }
    return 0;
}
