#include<stdio.h>
struct bag 
{
     long long int sum;
     
     int value;
     int z;
};
int main()
{
     int n,m,i,j,k,l=0,mod;
     struct bag p[1000];
     int a[1000010];
     scanf("%d%d",&n,&mod);
     for(i=0;i<n;i++)
     {
          p[i].sum=0;
          scanf("%d",&m);
          p[i].value=m;
          p[i].z =l;
          for(j=l;j<l+m;j++)
          {
               scanf("%d",&a[j]);
               p[i].sum=p[i].sum+(a[j])%mod;
          }
          p[i].sum=(p[i].sum)%mod;
         
          l=l+m;
     }
     for(i=0;i<n-1;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].sum > p[j].sum)
               {
                    struct bag tmp;
                    tmp=p[i];
                         p[i]=p[j];
                         p[j]=tmp;
               }

          }
     }
     for(i=0;i<n;i++)
     {
                        printf("%lld\n",p[i].sum);
                        for(j=p[i].z;j<p[i].z+p[i].value;j++)
                        {
                             printf("%d\n",a[j]);
                             
                        }
                        printf("\n");
     }
     return 0;
}

