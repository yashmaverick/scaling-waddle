#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,t,n,count,m,z;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d",&n);
          if(n==0 || n==1)
              printf("0\n");
          else
          {
               j=n;
               count=0;
               while(j!=1)
               {  
               if(j%2)
                    j=j-1;
               j=j/2;
               count++;
  
              }
               m=pow(2,count);
               z=pow(2,count+1);
               if(n>=m && n < m+(z-m)/2)
                    printf("%d\n",2*count-1);
               else
                    printf("%d\n",2*count);



     }
     }
          return 0;
}
