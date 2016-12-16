#include <stdio.h>
#define GETINT(X) scanf("%lld",&X);
typedef long long int LL;
LL logs[100000];
LL min1[100000];
LL min2[100000];
int main()
{
   LL n;
   GETINT(n);
   while(n!=0)
   {
   LL i;
   LL carea=0;
   LL marea=0;
   LL malogh = 0;
   LL malow = 0;
   min1[0] = -1;
   GETINT(logs[0]);
   for(i=1;i<n;i++)
   {
      GETINT(logs[i]);
      if(logs[i]>logs[i-1])
         min1[i]=i-1;
      else if(logs[i]==logs[i-1])
         min1[i] = min1[i-1];
      else 
      {
         //Look for previous element's min recursively .
         min1[i] = min1[i-1];
         while(min1[i]!=-1 && logs[min1[i]] >= logs[i])
            min1[i] = min1[min1[i]];
      }
   }
   min2[n-1] = n;
   for(i=n-2;i>=0;i--)
   {
      if(logs[i]>logs[i+1])
         min2[i] = i+1;
      else if(logs[i+1]==logs[i])
         min2[i] = min2[i+1];
      else
      {
         min2[i] = min2[i+1];
         while(min2[i]!=n && logs[min2[i]] >= logs[i])
            min2[i] = min2[min2[i]];
      }
   }
   for(i=0;i<n;i++)
   {
      //Analyse each log
      carea = logs[i]*((i - (min1[i]+1))  + (min2[i]-i));
      if(carea>marea)
      {
         marea=carea;
         malow = - min1[i] - 1 + min2[i] ;
         malogh = logs[i];
      }

   }
   /*
   printf("Logs\n");
   for(i=0;i<n;i++)
      printf("%lld ",logs[i]);
   printf("\nMins\n");
   for(i=0;i<n;i++)
      printf("%lld ",min1[i]);
   printf("\n");
   for(i=0;i<n;i++)
      printf("%lld ",min2[i]);
   printf("\n");
   printf("Marea:%lld\nMalogh:%lld\nMalow:%lld\n",marea,malogh,malow);
   */
   printf("%lld\n",marea);
   GETINT(n);
   }
   
   return 0;
}
