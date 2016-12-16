#include<stdio.h>
#include<stdlib.h>

int main (){
     long long int  st[100010],in[100010],a[100010],i,j,k,n,count,r[100010];

     long  i2=0,i3=0,ar,ar2;
     long long int max=0,ans,ans1;
     n=1;
     while(n!=0)
     {    i2=0;max=0;i3=0; count=0;
          scanf("%lld",&n);
           if(n==0)
                break;
          for(i=0;i<n;i++)
               scanf("%lld",&a[i]);


          i2=0; 
          st[i2++]=0;
          in[0]=0;
          for(i=1;i<n;i++)
          {
               if(a[i] > a[st[i2-1]])
               {           //     printf("push %d %d\n",i2,i3);
                    st[i2++]=i;
                    in[i]=0;
               }

               else if(a[i] <= a[st[i2-1]])
               {    count=0;ans=0;
                    while(a[st[i2-1]] >= a[i] && i2 >0)
                    { 
                         count++; 
                         ans+=in[st[i2-1]]; i2--;
                    }
                   st[i2++]=i;
                   in[i]=count+ans;          // printf("val=%lld,,%d\n",ans,count);

               }
          
          }

         i2=0; 
          st[i2++]=n-1; 
          r[n-1]=0;
          for(i=n-2;i>=0;i--)
          {
               if(a[i] >a[st[i2-1]])
               {                                //printf("push %d %d\n",i2,i3);
                    st[i2++]=i;
                    r[i]=0;
               }

               else if(a[i] <= a[st[i2-1]])
               {    count=0; ans=0;
                    while(a[st[i2-1]] >= a[i] && i2 >0)
                    {     //  printf("stinside");
                         ans+=r[st[i2-1]]; 
                         i2--; 
                         count++;
                    }
                   st[i2++]=i;
                   r[i]=count+ans;                 //printf("val2=%lld,,%d\n",ans,count);
               }
          
          }
         // for(i=0;i<n;i++) printf("%d %d\n",in[i],r[i]);   printf("\n");
           max=0;
           for(i=0;i<n;i++)
           {
                ans=a[i]*(in[i]+r[i]+1);
                if(ans > max)
                     max=ans;
           }
     
     
         printf("%lld\n",max);
     }
     return 0;
}
