#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define GETINT(X) scanf("%d",&X)
#define PSIZE 100001
#define HEAP_SIZE 100001
typedef long long int LL;
//Structs
//Global Variables
int inedge[PSIZE];
//Functions
//Heap
typedef struct hp{
   int com;
}HEAPEL;
typedef struct node{
   struct node* next;
   int data;
}N;
N* ver[PSIZE];    //Normal Adjacency list scan.
HEAPEL HEAP[HEAP_SIZE];
void insert(HEAPEL x);
HEAPEL delete();
int shufdow(int pos);
int shufup(int pos);
void clear();
int SIZE;
int main()
{
   int m,n,i,v1,v2,flag=0;
   N* temp;
   clear();
   GETINT(n);GETINT(m);
   for(i=0;i<m;i++)
   {
      scanf("%d %d",&v1,&v2);
      temp = (N*)malloc(sizeof(N));temp->data = v2;temp->next = ver[v1];ver[v1] = temp;
      inedge[v2]++;
   }
   for(i=1;i<=n;i++) 
      if(!inedge[i])
      {
         HEAPEL new;
         new.com = i;
         insert(new);
      }
   while(SIZE!=1)
   {
      HEAPEL new = delete();
      i = new.com;
      if(flag)
         printf(" %d",i);
      else
      {
         printf("%d",i);
         flag = 1;
      }
      temp = ver[i];
      while(temp!=NULL)
      {
         inedge[temp->data]--;
         if(inedge[temp->data]==0)
         {
            new.com = temp->data;
            insert(new);
         }
         temp = temp -> next;
      }
   }
   printf("\n");
   return 0;
}
//HEAP
int min(int a,int b)
{
   return a>b?b:a;
}
void clear()
{
   SIZE = 1;
}
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
   if((2*pos+1)<SIZE)
   {
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
void show_heap()
{
   int i;
   for(i=1;i<SIZE;i++)
      printf("%d ",HEAP[i].com);
   printf("\n");
}
