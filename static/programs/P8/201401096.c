#include<stdio.h>
#define M 1000000007
//#include<math.h>
long long int expone(long long int base, long long int p,long long int m)
{ long long int result =1; 
    while(p) 
    {   
        if (p&1)
        {
            result=((result%m)*(base%m))%m ;
        }

        p >>=1 ;
        base=((base%m)*(base%m))%m;
    }   
    return result%m;
}



int main()
{int test;
    long long int d,a1,a2,a3;
    long long int upper,i,j,k,m;
    long long int ct=0,ln;
    long long int ans=0,n;
    scanf("%d",&test);
while(test--)
{
    scanf("%lld %lld %lld %lld",&upper,&d,&m,&n);
    ans=m;ct=0;

   // ln=log2(upper)/log2(d);

    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            for(k=0;k<n;++k)
            {
                if(i<=upper&&j<=upper&&k<=upper)
                if((expone(i,d,n)%n+expone(j,d,n)%n+expone(k,d,n)%n)%n==ans)
            ct=(ct+((((((upper-i)/n)+1)%M)*((((upper-j)/n)+1)%M)%M)*((((upper-k)/n)+1)%M))%M)%M;
            }
        printf("%lld\n",ct);
}
                    return 0;
}
