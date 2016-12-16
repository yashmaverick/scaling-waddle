#include<stdio.h>
#include<math.h>

#define mod 1000000007

long long int fu(long long int a, long long int n,long long int m)
{
    long long int c=1;
    while(n)
    {
        if(n&1)
        {
            c=((c%m)*(a%m))%m;
        }
        n=n>>1;
        a=((a%m)*(a%m))%m;
    }
    return c%m;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,u,d,m,ans=0,p;
        long long int i,j,k;
        scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
        p=n;
        for(i=0;i<p;i++)
        {
            for(j=0;j<p;j++)
            {
                for(k=0;k<p;k++)
                {
                    if((fu(i,d,n)+fu(j,d,n)+fu(k,d,n))%n==m)
                    {
                        long long int func(long long int i)
                        {
                            long long int a = ((u-i)/n) +1 ;
                            if(u-i<0)
                                return 0 ;

                            else
                                return a;
                        }
                        ans = (ans + (func(i)*func(j))%mod*func(k)%mod)%mod;
                    }
                }
            }
        }
        printf("%lld\n",ans%mod);
    }
    return(0);
}
