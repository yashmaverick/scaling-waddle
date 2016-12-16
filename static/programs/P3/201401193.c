#include<stdio.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int a,b=0,i,ans,max,maxn,c=0;
        ans=max=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
	    if(i!=0)
            max+=a-b;
            if(max<0)
                max=0;
            if(max>ans)
                ans=max;
	    b=a;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
