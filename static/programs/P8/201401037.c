#include<stdio.h>
#include<stdlib.h>
#define modi 1000000007

typedef unsigned long long int lld;
void swap(int *a,int *b)
{
     int temp=*a;
     *a=*b;
     *b=temp;
}

lld poe(lld a,lld x)
{
     if(x==0)
          return 1;
     else if(x%2==0)
          return poe(a*a,x/2);
     else if(x%2!=0)
          return a*poe(a*a,(x-1)/2);
}

lld gcd(lld a,lld b)
{
     lld r;
     while(b!=0)
     {
          r=a%b;
          a=b;
          b=r;
     }

     return a;
}
          
lld power(lld a,lld x,lld mod)   // power function
{
     lld t=1;
     lld p=a%mod;
     while(x>0)
     {
          if(x%2!=0)
          {
               t=((t%mod)*(p%mod))%mod;
          }

          x=x/2;
          p=((p%mod)*(p%mod))%mod;
     }

     return t;
}
lld a[1000];    // global declaration of array

void start(lld *a,lld n,lld d,lld u)
{
     int i,p;

     for(i=0;i<n;i++)
     {
       a[i]=power(i,d,n);
     }
}

lld  calcu(lld x,lld n,lld u)
{
     if( x<=u%n)
          return (u/n +1)%modi;
     else
          return (u/n)%modi;
}

int main (){
     lld i1,test,i,j,n,m,u,d,k,ans;
     scanf("%llu",&test);

     for(i1=0;i1<test;i1++)
     {    ans=0;
          scanf("%llu%llu%llu%llu",&u,&d,&m,&n);

          start(a,n,d,u);
       //  for(i=0;i<n;i++) printf("%llu\n",a[i]);

         for(i=0;i<n;i++)
         {
              for(j=0;j<n;j++)
              {
                   for(k=0;k<n;k++)
                   {
                        if((a[i]+a[j]+a[k])%n == m)
                        {
                             ans+=((calcu(i,n,u)%modi)*((calcu(j,n,u)*calcu(k,n,u))%modi))%modi;
                        }
                   }
              }
         }
 
         printf("%llu\n",ans%modi);
     }

return 0;
}
