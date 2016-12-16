#include<stdio.h>

int mini(int a,int b)
{
     if(a>b)
          return b;
     else 
          return a;
}

int main(){
     int a[101001],b[100011],pr[100011],i,j,t,x,y,n;
     int i1,q,r,pi,rg,rg1,st,i11;

     scanf("%d",&n);

     for(i=1;i<=n;i++)
          scanf("%d",&a[i]);

     for(i=1;i<=n;i++)
          scanf("%d",&b[i]);

     scanf("%d",&t);

     for(i1=0;i1<t;i1++)
     {
          scanf("%d%d",&x,&y);
          if(x==y)
               printf("%d\n",x);
          else
          {
               j=0; st=0;
               for(i=1;i<=n;i++)
               {
                    if((b[i]==x || b[i]==y) && st==0)
                    {    st=1;
                         // pr[j++]=b[i];
                    }

                    else if((b[i]==x || b[i]==y) && st==1)
                    {
                         pr[j++]=b[i];
                         break;
                    }

                    if(st==1)
                         pr[j++]=b[i];
               }
               int fl=0;
               for(i=1;i<=n;i++)
               {
                    for(i11=0;i11<j;i11++)
                    {
                         if(a[i]==pr[i11])
                         {    fl=1;
                              break;
                         }
                    }

                    if(fl==1)
                         break;
               }

               printf("%d\n",a[i]);
          }
     }

     return 0;
}
