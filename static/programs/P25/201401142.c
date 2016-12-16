#include <stdio.h>
#include <stdlib.h>
#define HEAP_SIZE 1000001
#define MSIZE 1000001
typedef struct hp{
   int com;
   int node1;
   int node2;
}HEAPEL;
int SIZE;
HEAPEL HEAP[HEAP_SIZE];
void insert(HEAPEL x);
int shufdow(int pos);
int shufup(int pos);
HEAPEL delete();
void clear();
int min(int a,int b);
typedef struct node{
   int data;
   struct node* next;
   int w;
}N;
N* ver[MSIZE];
char used[MSIZE];
int vercount;
int nothing;
void prims(int start)
{
   vercount++;
   used[start] = 1;
   N* temp = ver[start];
   while(temp!=NULL)
   {
      if(!used[temp->data])
      {
         HEAPEL new;
         new.node1 = start;
         new.node2 = temp->data;
         new.com = temp->w;
         insert(new);
      }
      temp = temp->next;
   }
}
long long result;
int main()
{
   clear();
   int m,n,i,v1,v2,w;
   N *temp;
   scanf("%d%d",&n,&m);
   for(i=0;i<m;i++)
   {
      scanf("%d%d%d",&v1,&v2,&w);
      temp = malloc(sizeof(N));temp->w = w;temp->data = v2;temp->next = ver[v1];ver[v1] = temp;
      temp = malloc(sizeof(N));temp->w = w;temp->data = v1;temp->next = ver[v2];ver[v2] = temp;
   }
   prims(1);
   while(vercount!=n)
   {
      HEAPEL least;
      int a=1,b=1;
      while(a*b)
      {
         if(SIZE<=1)
         {
            printf("-1\n");
            return 0;
         }
         least = delete();
         a = used[least.node1];
         b = used[least.node2];
      }
      result += least.com;
      if(a==0)
         prims(least.node1);
      else if(b==0)
         prims(least.node2);
   }
   printf("%lld\n",result);
   return 0;
}
//Heap - Functions
int min(int a,int b)
{return a>b?b:a;}
void clear()
{SIZE = 1;}
HEAPEL delete()
{
   SIZE--;
   HEAPEL ans = HEAP[1];
   HEAP[1] = HEAP[SIZE];
   shufdow(1);
   return ans;
}
void insert(HEAPEL x)
{
   HEAP[SIZE] = x;
   SIZE++;
   shufup(SIZE-1);
   return;
}
int shufup(int pos)
{
   if(pos<1)
      return 0;
   if(HEAP[pos/2].com>HEAP[pos].com)
   {
      HEAPEL t = HEAP[pos/2];
      HEAP[pos/2] = HEAP[pos];
      HEAP[pos] = t;
      shufup(pos/2);
   }
   return 0;
}
int shufdow(int pos)
{
   if(pos>SIZE)
      return 0;
   //Check Existence of children.
   if((2*pos+1)<SIZE)
   {
      //Both Children exist.
      int m = 2*pos;
      if(HEAP[2*pos].com>HEAP[2*pos+1].com)
         m += 1;
      HEAPEL temp = HEAP[pos];
      if(HEAP[pos].com>HEAP[m].com)
      {
         HEAP[pos] = HEAP[m];
         HEAP[m] = temp;
         shufdow(m);
      }
      else
         return 0;
   }
   else if(2*pos+1==SIZE)
   {
      if(HEAP[pos].com>HEAP[2*pos].com)
      {
         HEAPEL t = HEAP[pos];
         HEAP[pos] = HEAP[2*pos];
         HEAP[2*pos] = t;
      }
      return 0;
   }
   return 0;
}
