#include <stdio.h>

long long int n,m,d,u,s,sol;
long long int a[1000000];
long long int M=1000000007;

long long int power(long long int x,long long int b)
{
    if(b==0)
        return 1;
        long long int v=(power(x,b/2));
        long long int y=(v*v)%n;
    if(b%2)
        return (x*y)%n;
    return y;
}
    

long long int noofsol(long long int x)
{
    long long int v,r;
    //:wq
    //if(x==0)
      //  return 0;
    r=u%n;
    if(r<x)
    {
        return (u/n);
    }
    else
    {
      
            return ((u/n)+1);
    }
}


void modi(long long int x,long long int y,long long int z)
{
    sol=(sol+(((noofsol(x)*noofsol(y))%M)*noofsol(z))%M)%M;
}


int main()
{
    long long int t,p,i,j,k;
    scanf("%lld",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%lld %lld %lld %lld",&u,&d,&m,&n);
        for(i=0;i<n;i++)
        {
            a[i]=(power(i,d))%n;
        //    printf("%lld ",a[i]);
        }
       // printf("\n");
        sol=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    s=(a[i]+a[j]+a[k])%n;
                    if(s==m)
                        modi(i,j,k);
                //    printf("modi sol=%lld\n",sol);
                }
            }
        }
        printf("%lld\n",sol);
    }
    return 0;
}


