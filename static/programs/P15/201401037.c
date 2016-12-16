#include<stdio.h>
#include<stdlib.h>
long long int f=0,e=1,tl=0,hd=0;
//int n;
void enqueu(long long int *a,long long int l,long long int n)
{
     if(e==1)
          e=0;
     a[tl]=l;
     if(f==1)
     {   
          // hd=(hd+1)%n;
          tl=(tl+1)%n;
          hd=(hd+1)%n;
     }
     else
          tl=(tl+1)%n;
     if(tl==hd)
     {
          f=1;
     }
}

void dequeu(long long int *a,long long int n) {
     if(f==1)
          f=0;
     a[hd]=0;
     if(e==1)
          return; 

     hd=(hd+1)%n;

     if(hd==tl)
     {
          e=1;
          hd=0;
          tl=0;
     }


}
void pop(long long int *a,long long int n)
{                               //   printf("hd=%d,tl=%d\n",hd,tl);
     if(f==1)
          f=0;
     if(e==1)
     {    hd=0; tl=0;
          return ;
     }
     if(tl==0 && e!=1)
     {                                  //     printf("1stif\n");
          // if(hd!=tl)
          tl=n-1;
     }
     else
          tl--;
     if(hd==tl && f!=1)
     {                                    // printf("empty\n");
          e=1;
          hd=0;
          tl=0;
     }
}


long long  head(long long int *a)
{
     printf("%lld\n",a[hd]);
}

void print(long long int *a,long long int n,long long int* b)
{    long long int i3;
     if(hd<tl)
     {
          for(i3=hd;i3<tl;i3++)
          {
               printf("st=%lld ",a[i3]);
          }
     }

     else if(hd>=tl)
     {
          for(i3=hd;i3<n;i3++)
               printf("%lld ",a[i3]);
          for(i3=0;i3<tl;i3++)
               printf("%lld ",a[i3]);
     }

     printf("\n");
}


int main (){
     long long  p,l,q,i1,i2,n,test,a[10010],b[10010],c[10010],k,i;
     scanf("%lld",&test);
     for(i1=0;i1<test;i1++)
     {
          scanf("%lld%lld",&n,&k);


          for(i=1;i<=n;i++) 
               scanf("%lld",&b[i]);
         
          if(k>n)
          {    p=b[1];
               for(i=1;i<=n;i++)
                    if(b[i] < p)
                         p=b[i];

               printf("%lld\n",p);
               continue;
          }
          
          else if(k==0)
          {
               for(i=0;i<n;i++)
               {
                    printf("1000000001 ");
                    //  printf("\n");
               }
               printf("\n");
               continue;
          }
          
          else if(k==1)
          {
               for(i=1;i<n;i++)
                    printf("%lld ",b[i]);
               printf("%lld\n",b[n]);
               continue;
          }

          else
          {
               i2=0; hd=0; tl=0;e=1; f=0;
               a[tl++]=b[1];

               for(i=2;i<=n;i++)
               {
                                               // printf("a[tl-1]=%lld\n",a[tl-1]);
                    if(i>k)
                         if(a[hd]==b[i-k])
                              hd++;

                    //  dequeu(a,k) ;  printf("start hd=%lld,tl=%lld\n",hd,tl);

                    if(b[i] > a[tl-1])
                    {                                    //     printf("enqueu\n");
                         if(tl-hd>=k)
                              hd++;
                         a[tl++]=b[i];
                    }

                    else if(b[i] <=a[tl-1])
                    {                                  //     printf("deueue\n");
                         while(a[tl-1] > b[i] && tl>hd)
                         {                           //  printf("inwhilehd=%lld,tl=%lld\n",hd,tl);
                              tl--;
                         }

                        // printf("after whilehd=%lld,tl=%lld\n",hd,tl);
                         a[tl++]=b[i];
                    }

                    if(i>=k)
                    {
                         c[i2++]=a[hd];//head(a);   
                        //  printf("\n\nc[]=%lld\n",c[i2-1]);
                    }

              //    print(a,k,b);

               //    printf("end hd=%lld , tl=%lld\n",hd,tl);
               }

            
                for(i=0;i<i2-1;i++) printf("%lld ",c[i]);   //printf("\n");
                printf("%lld\n",c[i2-1]);}
          
     }

     return 0;
}
