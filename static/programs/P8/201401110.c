#include<stdio.h>
#define mod 1000000007
long long int expon(long long int a,long long int b,long long int m)
{
  //  printf("ENTER 1\n");
  if(b==0)
    return 1;
  if(b==1)
  {
    return (a);
  }
  long long int x=expon(a,b/2,m);
  long long int y=(x%m*x%m)%m;
  if(b%2==0) // i is even
    return((y)%m);

  if(b%2!=0)
    return((y%m*a%m)%m);

}

int main()
{
  long long int ul,d,count,term;
  long long int a1,a2,a3,test,n,m,t,v,t1,t2,t3;
  scanf("%lld",&test);
  for(t=0;t<test;t++)
  {
    count=0;
    scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
    //          printf("M%N : %lld\n",m%n);
    /*   if((ul%40)<=ul)
         {
         for(a1=0;a1<=ul;a1++)
         {
         for(a2=0;a2<=ul;a2++)
         {
         for(a3=0;a3<=ul;a3++)
         {
         term=(((expon(a1,d,n)%mod)+(expon(a2,d,n)%mod)+(expon(a3,d,n)%mod))%mod);
         if((term%mod)==m)
         count=((count%mod)+(((((((ul-a1)/n)%mod)+1)%mod)*((((((ul-a2))/n)%mod)+1)%mod)*((((((ul-a3))/n)%mod)+1)))%mod)%mod);
    // printf("%lld\n",count);
    }
    }
    }
    }
    else{*/
  //  if(ul%40==ul)
    //  n=ul;
    for(a1=0;a1<n;a1++)
    {
      t1=expon(a1,d,n)%n;
      for(a2=0;a2<n;a2++)
      {
        t2=expon(a2,d,n)%n;
        for(a3=0;a3<n;a3++)
        {
          t3=expon(a3,d,n)%n;
          if(a1<=ul && a2<=ul && a3<=ul)
          {
          term=(t1+t2+t3)%n;
          if(term==m)
            count=(count+((((((ul-a1)/n)+1)%mod)*((((ul-a2)/n)+1)%mod)%mod)*((((ul-a3)/n)+1)%mod))%mod)%mod;
            }
            //            printf("%lld\n",count);
        }
      }
    }
    printf("%lld\n",count);
  }
  return 0;
}
