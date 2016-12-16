#include <stdio.h>
#define INTS(X) scanf("%d",&X)
#include <stdlib.h>
#include <string.h>
#define SIZ 1001
typedef struct node{
   struct node* n;
   int d;
}N;
typedef N* L;
L ver[SIZ],ulta[SIZ];
char used[SIZ],dp[SIZ];
void destroy();
void clearver();
void clearver()
{
   int i;
   for(i=0;i<SIZ;i++)
   {
      destroy(ver[i]);
      destroy(ulta[i]);
      ver[i] = NULL;
      ulta[i] = NULL;
   }
   return;
}
void destroy(L what)
{
   if(what!=NULL)
      destroy(what->n);
   else
      return;
   free(what);
   return;
}
int num;
int dfsiz,result;
void dfs(int where)
{
   dfsiz++;
   used[where] = 1;
   L temp = ver[where];
   while(temp!=NULL)
   {
      if(!used[temp->d])
         dfs(temp->d);
      temp = temp->n;
   }
   return;
}
void udfs(int where)
{
   result++;
   dp[where]=1;
   L temp = ulta[where];
   while(temp!=NULL)
   {
      if(!dp[temp->d])
         udfs(temp->d);
      temp = temp->n;
   }
   return;
}
int main()
{
   int t,i;
   INTS(t);
   while(t--)
   {
      int min;
      clearver();
      result = 0;
      memset(dp,0,SIZ);
      INTS(num);
      for(i=1;i<=num;i++)
      {
         int m,j;
         INTS(m);
         for(j=0;j<m;j++)
         {
            L new = (L)malloc(sizeof(N));new->d = i;
            int where;INTS(where);
            new->n = ver[where];
            ver[where] = new;
            L other = (L)malloc(sizeof(N));other->d = where;
            other->n = ulta[i];
            ulta[i] = other;
         }
      }
      /*/Print ulta
      printf("Printing ver\n");
      for(i=1;i<=num;i++)
      {
         L temp = ver[i];
         printf("%d -> ",i);
         while(temp!=NULL){
            printf("%d ",temp->d);
            temp = temp->n;
         }
         puts("");
      }
      printf("Printing ulta\n");
      for(i=1;i<=num;i++)
      {
         L temp = ulta[i];
         printf("%d -> ",i);
         while(temp!=NULL){
            printf("%d ",temp->d);
            temp = temp->n;
         }
         puts("");
      }
      */
      for(i=1;i<=num;i++)
      {
         memset(used,0,SIZ);
         dfsiz = 0;
         if(!dp[i])
            dfs(i);
         if(dfsiz==num)
               udfs(i);
      }
      printf("%d\n",result);
   }
   return 0;
}
