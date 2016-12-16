#include <stdio.h>
#define INF 2100000000
#define LEFT -1
#define RIGHT 1
typedef long long int LL;
int st[100001][3];
int x[100001];
int stpos;
int inside(int what)
{
   if(st[stpos][0]<what && what<st[stpos][1])
      return LEFT;

   if(st[stpos][1]<what && what<st[stpos][2])
      return RIGHT;
   else
      return 0;
}
int main()
{
   int t,n,i,side,t1,t2,maxst,maxstval;
   scanf("%d",&t);
   while(t--)
   {
      maxst = 0;
      stpos = 0;
      scanf("%d",&n);
      for(i=0;i<n;i++)
         scanf("%d",&x[i]);
      maxstval = x[n-1];
      st[0][1] = x[n-1];
      st[0][0] = -INF;
      st[0][2] = INF;
      for(i=(n-2);i>=0;i--)
      {
         if(side=inside(x[i]))
         {
            if(side==LEFT)
            {
               //Then Ranges should be built as left.
               //We need [0] and [1]
               t1 = st[stpos][0];
               t2 = st[stpos][1];
               stpos++;
               st[stpos][0] = t1;
               st[stpos][1] = x[i];
               st[stpos][2] = t2;
            }
            else if (side==RIGHT)
            {
               t1 = st[stpos][1];
               t2 = st[stpos][2];
               stpos++;
               st[stpos][0] = t1;
               st[stpos][1] = x[i];
               st[stpos][2] = t2;
            }
            if(stpos>=maxst)
            {
               maxst = stpos;
               maxstval = x[i];
            }
         }
         else
         {
            stpos--;
            i++;
         }
      }
      printf("%d %d\n",maxstval,maxst);
   }
   return 0;
}
