#include<stdio.h>

long long int A[100]={0};
long long int n,m;

long long int fastexpo(long long int a, long long int d)
{
        A[0]=0;
        long long int ii,i,j,k,sum=1;
        for(i=1;i<=a;i++)
        {
          //printf("BYE %lld\n", i);
               sum=1;
               k=d;
               ii=i;
               while(k!=0)
               {
                 if(k&1==1)
                   sum=(sum*ii)%n;
                 k=k>>1;
                 ii=(ii*ii)%n;
               }
               A[i]=sum;
        }
        return 0;
}

int main()
{
  long long int ii,jj,kk,fincount=0,upper,t,a,b,c,d,i,j,k,val1,val2,val3;
  scanf("%lld", &t);
  for(i=0;i<t;i++)
  {
    fincount=0;
    scanf("%lld%lld%lld%lld", &upper, &d, &m, &n);
    fastexpo(n,d);
    //printf("HI\n");
    for(ii=0;ii<n && ii<=upper;ii++)
    {
      for(jj=0;jj<n && jj<=upper;jj++)
      {
        for(kk=0;kk<n && kk<=upper;kk++)
        {
           if((A[ii]+A[jj]+A[kk])%n==m)
           {
                fincount=(fincount+(((((upper-ii)/n+1)*((upper-jj)/n+1))%1000000007)*((upper-kk)/n+1))%1000000007)%1000000007;
           }
        }
      }
    }
    printf("%lld\n", fincount);
  }
  return 0;
}
