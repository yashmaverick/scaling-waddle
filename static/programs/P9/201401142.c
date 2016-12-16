#include <stdio.h>
#include <stdlib.h>
#define GETINT(X) scanf("%d",&X)
#define MAXMOD 1000000007
typedef long long int LL;
typedef struct pair {
   int sum;
   int items;
   int* head;
}PAIR;
int funcmp (const void * a, const void * b)
{
   const PAIR *x = (const PAIR *)a;
   const PAIR *y = (const PAIR *)b;
   const int p = x->sum;
   const int q = y->sum;
   return p - q;
}
PAIR x[1001];
int main()
{
   int num,i,items,xsum,weight,mod,j;
   //Initialising The Pairs.
   GETINT(num);
   GETINT(mod);
   for(i=0;i<num;i++)
   {
      GETINT(items);
      x[i].items = items;
      xsum = 0;
      x[i].head = (int *)malloc(sizeof(int)*items);
      for(j=0;j<items;j++)
      {
         GETINT(weight);
         x[i].head[j] = weight;
         xsum += weight;
         xsum = xsum%mod;
      }
      x[i].sum = xsum;
   }
   qsort(x,num,sizeof(PAIR),funcmp);
   for(i=0;i<num;i++)
   {
      printf("%d\n",x[i].sum);
      for(j=0;j<x[i].items;j++)
         printf("%d\n",x[i].head[j]);      
      printf("\n");
   }
   return 0;
}
