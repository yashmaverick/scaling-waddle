#include <stdio.h>
typedef long long int LL;
LL result;
int stk[5000000];
int stkptr;
int empty()
{
   if(stkptr==0)
      return 1;
   else
      return 0;
}
int poptill(LL x)
{
   LL popequal;
   int prev_val;
   while(!empty() && stk[stkptr-1]<x)
   {
      prev_val = stk[stkptr-1];
      popequal = 0;
      while(!empty() && prev_val==stk[stkptr-1])
      {
         stkptr--;
         popequal++;
      }
      //Now popequal number of equal elements has been popped.
      //popequal C 2 will give all interactions between themselves , they will also interact with x;
      result += (popequal*(popequal-1))/2 + popequal;
      //and now if stack ! empty then they will interact with the peek element of stack
      if(!empty())
         result += popequal;
      //This process ensures that popped elements interact properly with the rest of the array.
      //This will be done iterative work.
   }
   return 0;
}
int showstk()
{
   int i;
   for(i=0;i<stkptr;i++)
      printf("%d ",stk[i]);
   printf("\n");
}
int main()
{
   int i,temp;
   LL n;
   scanf("%d",&n);
   while(n!=0)
   {
      result = 0;
      stkptr = 0;
      for(i=0;i<n;i++)
      {
         scanf("%d",&temp);
         if(empty())
         {
            stk[stkptr] = temp;
            stkptr++;
            continue;
         }
         if(temp>stk[stkptr-1])
         {
            poptill(temp);
            stk[stkptr]=temp;
            stkptr++;
         }
         else
         {
            stk[stkptr]=temp;
            stkptr++;
         }
      }
      //Now we need to make stack empty
      LL popequal;
      int prev_val;
      while(!empty())
      {
         prev_val = stk[stkptr-1];
         popequal = 0;
         while(!empty() && prev_val==stk[stkptr-1])
         {
            stkptr--;
            popequal++;
         }
         result += ((popequal*(popequal-1))/2);
         //and now if stack ! empty then they will interact with the peek element of stack
         if(!empty())
            result += popequal;
         //This process ensures that popped elements interact properly with the rest of the array.
         //This will be done iterative work.
      }
      result = ((n*(n-1))/2 - result);
      printf("%lld\n",result);
      scanf("%d",&n);
   }
   return 0;
}
