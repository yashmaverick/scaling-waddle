#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
     int  st[500010],i,j,a[500010],i2,fl=0,l[500010];
     long long  mx=0,ansl=0,ansr=0,ps,pe,sb,n,ct;
     n=1;
     while(1)
     {   // memset(r,-1,sizeof(r)); memset(l,-1,sizeof(l));
          scanf("%lld",&n);
          i2=0;ansl=0;ansr=0;mx=0; ct=0;
          if(n==0)
               break;

          for(i=0;i<n;i++)
               scanf("%d",&a[i]);

          st[i2++]=0;
          l[i2-1]=1;
          for(i=1;i<n;i++)
          {                             //  printf("ct top=%lld\n",ct);
              // for(j=0;j<i2;j++) printf("stack=%d ,freq=%d\n",a[st[j]],l[j]); printf("\n"); 
               if(a[i]<=a[st[i2-1]])                     // push
               {
                    if(a[i]==a[st[i2-1]])
                    {    ct+=l[i2-1];
                         l[i2-1]++;                        //   printf("if eq \n");
                    } 
                                                              // printf("if eq 2\n");
                    else
                    {    ct++;                                          
                         st[i2++]=i;
                         l[i2-1]=1;
                         continue;                   //printf("else\n");
                    }

                    if(i2>1)
                    {
                         if(a[i]<a[st[i2-2]])
                         {                     //  printf("main if\n");
                              if(l[i2-2]!=2)
                              {
                                   ct++;                //     printf("single if \n");
                              }
                              else 
                                   ct++;
                         }
                    }

               }


               else if(a[i] > a[st[i2-1]])                          // pop
               {    sb=0;
                    while(a[i] > a[st[i2-1]] && i2>0)  
                    {    sb++;
                         ct+=l[i2-1];
                         i2--;   
                    }

                    if(a[i]==a[st[i2-1]])
                    {
                         ct+=l[i2-1];
                         l[i2-1]++; 
                    }
                    else if(a[i]!=a[st[i2-1]])
                    {    st[i2++]=i;
                         l[i2-1]=1; 
                         if(i2!=1)ct++;
                         continue;
                    }
               
                    if(i2>1){ if(a[i] < a[st[i2-2]]){ if(l[i2-2]!=2)ct++;
                     else ct++;} }
               
               
               }

              // for(j=0;j<i2;j++) printf("stack=%d ,freq=%d\n",a[st[j]],l[j]); printf("\n"); 
              // printf("ct=%d\n",ct);
          }

       //   printf("ct=%d\n",ct);
         // for(j=0;j<i2;j++) printf("stack=%d ,freq=%d\n",a[st[j]],l[j]); printf("\n"); 

     
          printf("%lld\n",((n-1)*n)/2-ct);
     }


     return 0;
}
