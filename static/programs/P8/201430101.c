#include<stdio.h>
#include<math.h>
typedef long long int ll;
#define mod 1000000007
ll arr[40];
ll pows(ll a,ll k,ll m)
{
    if( a == 0 && k == 0 )  
        return 1;
    ll pow = 1;

    while(k > 0)
    {
        if( k % 2 )
            pow = (pow*a)%m ; 

        a = (a*a)%m;
        k /= 2;
    }
    return pow;
}
/*
 * ll pows(ll a, ll b, ll n)
 {
 ll base, result;
 result = 1 % n;
 base = a % n;
 while (b > 0)
 {
 if (b&1)
 result = (result%n * base%n) % n;
 b >>= 1;
 base = (base%n * base%n) % n;
 }
 return result%n;
 }
 */

ll nums(ll u,ll n,ll x)
{
    //ll as;
    // if(x<=(u%n))
    //    as=(u/n)+(u%n);
    // else
    //   as=(u/n);
    //return as;
    return (u/n)+(x<=(u%n));
}

int main()
{
    int test,i,j,k;
    scanf("%d",&test);
    while(test--)
    {
        ll u,d,m,n,ans=0,temporary;
        scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
        for(i=0;i<n;i++)
        {
            arr[i]=pows(i,d,n);
        }

        //	for(i=0;i<n;i++)
        //		printf("%lld--",arr[i]);
        //	printf("\n");

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if((arr[i]+arr[j]+arr[k])%n==m)
                    {
                        /*
                         * temporary = nums(u,n,i)*nums(u,n,j);     
                        if(temporary >= mod) temporary %= mod;
                        temporary *= nums(u,n,k);       
                        if(temporary >= mod) temporary %= mod;
                        ans += temporary;        
                        if(ans >= mod) ans %= mod;
                        */

                        if(((arr[i]%n+arr[j]%n)%n+arr[k]%n)%n==m)
                                      {
                                                      ans=(ans+((((nums(u,n,i)%mod)*(nums(u,n,j)%mod))%mod)*(nums(u,n,k)%mod))%mod)%mod;
                                                                }
                    }

                }
            }
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}

