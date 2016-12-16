#include<stdio.h>
long long int a[100];
long long int numofsol(int ul,int N,int n)
{
    if(n<=ul%N)
        return (ul/N)+1;
    else
        return ul/N;
} 
long long int powmod(int a,int b,int m)
{
    long long int ret=1;
    while(b>0)
    {
        if(b%2==1)
            ret=(ret%m*a%m)%m;
        b=b/2;
        a=(a%m*a%m)%m;
    }
    return ret;
}
/*
long long int powmod(int a,int b,int m)
{
    if(b==0)
        return 1;
    else if(b%2==0)
        return (powmod(a%m,b/2,m)*powmod(a%m,b/2,m))%m;
    else
        return (((a%m)%m)*(powmod(a%m,b/2,m)*powmod(a%m,b/2,m)%m))%m;
}*/
int main()
{
    int t,i,j,k,l;
    long long int count,temp;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int ul,d,N,m;
        count=0;
        temp=0;
        scanf("%d%d%d%d",&ul,&d,&m,&N);
        for(j=0;j<N;j++)
            a[j]=powmod(j,d,N);
        for(j=0;j<N;j++)
        {
            for(k=0;k<N;k++)
            {
                for(l=0;l<N;l++)
                {
                    if((a[j]+a[k]+a[l])%N==m)
                    {
                        temp=(numofsol(ul,N,j)%1000000007)*(numofsol(ul,N,k)%1000000007)%1000000007;
                        temp=((temp%1000000007)*(numofsol(ul,N,l)%1000000007))%1000000007;
                        count=(count%1000000007+temp%1000000007)%1000000007;
                    }
                }
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
