#include <stdio.h>
#define SIZE 200001
#define GETINT(X) scanf("%lld",&X);
#define MODBY 1000000007
int MINHEAP[SIZE],MAXHEAP[SIZE],SIZEmax,SIZEmin;
void insertmin(int x);
void insertmax(int x);
int deletemin();
int deletemax();
void clearmin();
void clearmax();
int shufupmin(int pos);
int shufupmax(int pos);
int shufdowmin(int pos);
int shufdowmax(int pos);
int main()
{
   long long int i,t,a,b,c,n,result,temp;
   GETINT(t);
   while(t--)
   {
      clearmin();
      clearmax();
      result = 1;
      GETINT(a);
      GETINT(b);
      GETINT(c);
      GETINT(n);
//      printf("Scanned a=%lld,b=%lld,c=%lld n=%lld\n",a,b,c,n);
      insertmax(1);
      for(i=2;i<=n;i++)
      {
         //We will calculate F[i];
         while(MAXHEAP[1]>MINHEAP[1] && SIZEmax>1 && SIZEmin>1)
         {
  //          printf("Balancing Heaps Here\n");
            int te = deletemax();
            int tu = deletemin();
            insertmax(tu);
            insertmin(te);
         }
         temp = MAXHEAP[1];
    //     printf("Extracting %lld from Heap\n",temp);
         temp = (a*temp + b*i + c)%MODBY;
      //   printf("Adding %lld to result\n",temp);
         result += temp;
         SIZEmax > SIZEmin ? insertmin(temp):insertmax(temp);
      }
      printf("%lld\n",result);
   }
   return 0;
}
void clearmin()
{SIZEmin = 1;}
int deletemin()
{
   SIZEmin--;
   int ans = MINHEAP[1];
   MINHEAP[1] = MINHEAP[SIZEmin];
   shufdowmin(1);
   return ans;
}
void insertmin(int x)
{
   MINHEAP[SIZEmin] = x;
   SIZEmin++;
   shufupmin(SIZEmin-1);
   return;
}
int shufupmin(int pos)
{
   if(pos<1)
      return 0;
   if(MINHEAP[pos/2]>MINHEAP[pos])
   {
      int t = MINHEAP[pos/2];
      MINHEAP[pos/2] = MINHEAP[pos];
      MINHEAP[pos] = t;
      shufupmin(pos/2);
   }
   return 0;
}
int shufdowmin(int pos)
{
   if(pos>SIZEmin)
      return 0;
   //Check Existence of children.
   if((2*pos+1)<SIZEmin)
   {
      //Both Children exist.
      int m = 2*pos;
      if(MINHEAP[2*pos]>MINHEAP[2*pos+1])
         m += 1;
      int temp = MINHEAP[pos];
      if(MINHEAP[pos]>MINHEAP[m])
      {
         MINHEAP[pos] = MINHEAP[m];
         MINHEAP[m] = temp;
         shufdowmin(m);
      }
      else
         return 0;
   }
   else if(2*pos+1==SIZEmin)
   {
      if(MINHEAP[pos]>MINHEAP[2*pos])
      {
         int t = MINHEAP[pos];
         MINHEAP[pos] = MINHEAP[2*pos];
         MINHEAP[2*pos] = t;
      }
      return 0;
   }
   return 0;
}
void show_heap()
{
   int i;
   for(i=1;i<SIZEmin;i++)
      printf("%d ",MINHEAP[i]);
   printf("\n");
}  
int min(int a,int b)
{return a>b?b:a;}
void clearmax()
{SIZEmax = 1;}
int deletemax()
{
   SIZEmax--;
   int ans = MAXHEAP[1];
   MAXHEAP[1] = MAXHEAP[SIZEmax];
   shufdowmax(1);
   return ans;
}
void insertmax(int x)
{
   MAXHEAP[SIZEmax] = x;
   SIZEmax++;
   shufupmax(SIZEmax-1);
   return;
}
int shufupmax(int pos)
{
   if(pos<=1)
      return 0;
   if(MAXHEAP[pos/2]<MAXHEAP[pos])
   {
      int t = MAXHEAP[pos/2];
      MAXHEAP[pos/2] = MAXHEAP[pos];
      MAXHEAP[pos] = t;
      shufupmax(pos/2);
   }
   return 0;
}
int shufdowmax(int pos)
{
   if(pos>SIZEmax)
      return 0;
   //Check Existence of children.
   if((2*pos+1)<SIZEmax)
   {
      //Both Children exist.
      int m = 2*pos;
      if(MAXHEAP[2*pos]<MAXHEAP[2*pos+1])
         m += 1;
      int temp = MAXHEAP[pos];
      if(MAXHEAP[pos]<MAXHEAP[m])
      {
         MAXHEAP[pos] = MAXHEAP[m];
         MAXHEAP[m] = temp;
         shufdowmax(m);
      }
      else
         return 0;
   }
   else if(2*pos+1==SIZEmax)
   {
      if(MAXHEAP[pos]<MAXHEAP[2*pos])
      {
         int t = MAXHEAP[pos];
         MAXHEAP[pos] = MAXHEAP[2*pos];
         MAXHEAP[2*pos] = t;
      }
      return 0;
   }
   return 0;
}
