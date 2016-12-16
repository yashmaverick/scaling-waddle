#include<stdio.h>

int main()
{
    int t;
    int a[100000],i,n,max,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        max=n-1,ans=0;
        for(i=n-1;i>=0;i--)
        {
            if((a[max]-a[i])>ans)
                ans=a[max]-a[i];
            if(a[max]<a[i])
                max=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}





