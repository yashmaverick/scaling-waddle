#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int llu;

llu nextpow(llu v)
{
     v--;
     v |= v >> 1;
     v |= v >> 2;
     v |= v >> 4;
     v |= v >> 8;
     v |= v >> 16;
     v++;
     return v;
}

llu ctpow(llu n)
{  llu i,ct=0;
     while(n!=1)
     {
          n=n/2;
          ct++;
     }
     return ct+1;
}

llu fpow(llu a,llu x)
{
     llu y=a;
     llu t=1;

     while(x>0)
     {
          if(x&1)
          {
               t=t*y;
          }
          x=x/2;
          y=y*y;
     }

     return t;
}


int main(){
     llu n,q,i,j,p,r,ans,i1;

     scanf("%llu",&n);

     for(i1=0;i1<n;i1++)
     {
          scanf("%llu",&q);

          if(q==1)
          {
               printf("0\n");
               continue;
          }
          r=ctpow(q);
                          //  printf("r=%llu\n",r);
          p=fpow(2,r)-1;
                            //   printf("p=%llu\n",p);
          if(q > p-(p+1)/4 )
          {                        //    printf("if \n");
               ans=2*(r-1);
          }
          else
               ans=(r-2)*2+1;
     
     
       printf("%llu\n",ans);
     }

return 0;
}
    
