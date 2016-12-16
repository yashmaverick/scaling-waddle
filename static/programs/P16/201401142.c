#include <stdio.h>
typedef long long int LL;
typedef unsigned long long ull;
int main()
{
   ull t,n,i,num,count=0;
   scanf("%llu",&t);
   while(t--)
   {
      count = 1;
      scanf("%llu",&n);
      if(n==1)
      {
         printf("0\n");
         continue;
      }
      num = n;
      while(num>3)
      {
 //        printf("Num is %llu\n",num);
         num=num>>1;
         count++;
      }
   //   printf("Count is %llu\n",count);
      if(num&01)
         printf("%llu",2*count);
      else
         printf("%llu",2*count-1);
      printf("\n");
   }
   return 0;
}
