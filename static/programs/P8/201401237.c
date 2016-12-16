#include<stdio.h>

#define mod 1000000007

long long int func(long long a,long long u, long long n)
{
    if(a>u)
        return 0;
    return ((u-a)/n+1)%mod;
}

long long int fastexp(long long int a, long long int b, long long int c)
{
    long long int result = 1;

    while (b)
    {
        if (b&1)
        {
            result *= a;
        }
        b >>=1 ;
        a *= a ;
        a=a%c;
        result=result%c;
    }
    return result;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int u,d,n,m,i,j,k,ans=0;
        scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if((fastexp(i,d,n)+fastexp(j,d,n)+fastexp(k,d,n))%n==m)
                    {   
                        ans=(ans+(((func(i,u,n)*func(j,u,n))%mod)*func(k,u,n))%mod)%mod;
                    }       
                }
            }
        }
        printf("%lld\n",ans);
    }
}
