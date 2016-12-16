#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
typedef struct modulus
{
    int mod;
    long long int count;
}modulus;
int power(int i, int d,int n)
{
    int res=1;
    while(d>0)
    {
        if(d%2)
            res = (res*i)%n;
        i = (i*i)%n;
        d/=2;
    }
    return res%n;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int u,d,m,n,i,j,k;
        long long int sum=0;
        modulus *a;
        scanf("%d %d %d %d",&u,&d,&m,&n);
        a = (modulus *)malloc(sizeof(modulus)*n);
        for(i=0;i<n;i++)
        {
            a[i].mod = power(i,d,n);
            a[i].count = (long long int)u/n + ((u%n)>=i);
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    if((a[i].mod+a[j].mod+a[k].mod)%n == m)
                    {
                        sum += ((((a[i].count)*(a[j].count))%MOD)*(a[k].count))%MOD;
                        sum = sum%MOD;
                    }
        printf("%lld\n",sum);
    }
    return 0;
}
