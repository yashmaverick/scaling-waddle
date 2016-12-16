#include<stdio.h>
long long int binary1(long long int c[],long long int low,long long int high,long long int k)
{
    if(low==high)
    {
        if(k>c[high])
            return high+1;
        return low;
    }
    long long int mid=(low+high)/2;
    if(k<=c[mid])
    {
        binary1(c,low,mid,k);
    }
    else if(k>c[mid])
    {
        binary1(c,mid+1,high,k);
    }

}
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int l,m,n,x,y,sum=0,i,a[100007],b[100007],c[100007],d[100007];
        scanf("%lld",&l);
        for(i=0;i<l;i++)
            scanf("%lld",&a[i]);
        scanf("%lld",&m);
        for(i=0;i<m;i++)
            scanf("%lld",&b[i]);
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&c[i]);
        x=(binary1(c,m-1,n-1,b[m-1]));
        d[m-1]=(n-x);
        for(i=m-2;i>=0;i--)
        {
            x=binary1(c,i,n-1,b[i]);
            d[i]=(n-x)+d[i+1];
        }
        for(i=0;i<l;i++)
        {
            x=binary1(b,i,m-1,a[i]);
            if(x<m)
            {
                sum+=d[x];
            //    printf("%lld ",sum);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
