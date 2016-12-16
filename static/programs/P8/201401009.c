#include <stdio.h>
#include<stdlib.h>
#define MOD 1000000007
long long int *a;
long long int pr(long long int a, long long int b,long long int mod)
{
        long long int ans=1,val=a;
        while(b>0)
        {
                if(b%2)
                        ans*=(val*(b%2));
                ans%=mod;
                b=b>>1;
                val*=val;
                val%=mod;
        }
        return ans;
}
int main() 
{
        long long int t;
        scanf("%lld",&t);
        while(t--)
        {
                long long int u,d,m,n,i,j,k,ans,x,y,z;
                long long int tmp,tmp1=0;
                scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
                a=(long long int *)malloc(n*sizeof(long long int));
                for(i=0;i<n && i<=u;i++)
                        a[i]=pr(i,d,n);
                for(i=0;i<n && i<=u;i++)
                {
                        for(j=0;j<n && j<=u;j++) 
                        {
                                for(k=0;k<n && k<=u;k++)
                                {
                                        x=(a[i]+a[j]+a[k])%n;
                                        if(x==m)
                                        {
                                                x=1+(u-i)/n;
                                                y=1+(u-j)/n;
                                                z=1+(u-k)/n;
                                                tmp=(((x*y)%MOD)*z)%MOD; 
                                                tmp1=tmp1+tmp;
                                                tmp1=tmp1%MOD;
                                        }
                                }
                        }
                }
                ans=tmp1;
                printf("%lld\n",ans);
        }
        return 0;
} 
