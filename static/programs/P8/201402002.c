#include<stdio.h>
#include<math.h>
#define MOD 1000000007

long long int modulo_power(long long int base, long long int exp, long long int mod)
{
    long long int eprime=1,c=1;
    if(exp==0)
        return 1;
    else if(exp%2==1)
    {
        long long temp=modulo_power(base,exp/2,mod);
        temp=(temp*temp)%mod;
        return (base*temp)%mod;
    }
    else 
    {
        long long temp=modulo_power(base,exp/2,mod);
        temp=(temp*temp)%mod;
        return temp%mod;
    }

}
/*
   long long modulo_power(long long base, long long exp, long long n)
   {
   long long res=1;
   while(exp>0)
   {
   if(exp&1==1)
   res=(res*base)%n;
   base=(base*base)%n;
   exp/=2;
   }
   return res%n;
   }
   */
int main()
{

    long long t,tcount;
    scanf("%lld",&t);
    for(tcount=0;tcount<t;tcount++)
    {
        long long int i=0,j=0,k=0,ct=0;

        long long int ul,d,n,m;
        scanf("%lld %lld %lld %lld",&ul ,&d ,&m ,&n);

        long long int store[n];
        long long int MMD[n];
        long long int ans=0,diff=ul/n;

        for(i=0;i<n;i++)
        {
            store[i]=diff;
            if(i<=ul%n)
                store[i]++;
        }
        //        for(i=0;i<n;i++)
        //           printf("%lld ",store[i]);
        //      printf("\n");

        for(i=0;i<n;i++)
            MMD[i]=modulo_power(i,d,n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                {
                    if ((MMD[i]+MMD[j]+MMD[k])%n == m)
                    {
                        long long temp=(store[i]*store[j])%MOD;
                        temp=(temp*store[k])%MOD;
                        ans+=temp;
                        ans%=MOD;
                    }
                }

        printf("%lld\n",ans);
    }
    return 0;
}

