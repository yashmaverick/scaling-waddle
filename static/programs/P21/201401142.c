#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 2147483647
#define HEAP_SIZE 1000001
//Heap - Globals
typedef struct hp{
   int com;
   int nodeno;
}HEAPEL;
HEAPEL HEAP[HEAP_SIZE];
int SIZE;
//Heap Funcs
void insert(HEAPEL x);
int shufdow(int pos);
int shufup(int pos);
HEAPEL delete();
void clear();
int min(int a,int b);
void djk();
void show_heap();
//Struct
typedef struct node{
   struct node* next;
   int data,w;
}N;
//Function Globals
int source,destini;
N* ver[HEAP_SIZE];
int dist[HEAP_SIZE],hepos[HEAP_SIZE];
// Main....
void djk();
int main()
{
   int t;
//   scanf("%d",&t);
   t = 1;
   while(t--)
   {
      clear();
      int n,i,v1,v2,w,m;
      N *temp;
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;i++)
         ver[i] = NULL;
      for(i=0;i<m;i++)
      {   
         scanf("%d %d %d",&v1,&v2,&w);
         temp = (N*)malloc(sizeof(N));temp->w = w;temp->data = v2;temp->next = ver[v1];ver[v1] = temp;
      }
      scanf("%d %d",&source,&destini);
      //Initialize distance array.
      for(i=1;i<=n;i++)
         dist[i] = INF;
      dist[source] = 0;
      //Insert all to heap.
      for(i=1;i<=n;i++)
      {
         HEAPEL temp;
         temp.nodeno = i;
         temp.com = dist[i];
         //printf("Inserting %d %d\n",temp.com,temp.nodeno);
         insert(temp);
      }
      //show_heap();
      djk();
      //Position array will hold.
     /* for(i=1;i<=n;i++)
         printf("%d ",dist[i]);
      printf("\n");
      */
      if(dist[destini]==INF)
         printf("NO\n");
      else
         printf("%d\n",dist[destini]);
   }
   return 0;
}
void djk()
{
   while(SIZE!=1)
   {
      //Extract Minimum.
      HEAPEL mini = delete();
//      printf("Removing %d %d\n",mini.com,mini.nodeno);
      N* temp;
      temp = ver[mini.nodeno];
      while(temp!=NULL)
      {
//         printf("Found %d in list , is at distance of %d\n",temp->data,temp->w);
         //In all niegbours , update the distances and shuffleup them in heap
         dist[temp->data] = min(dist[mini.nodeno]+temp->w,dist[temp->data]);
//         printf("Distance maybe updated for %d , now is %d\n",temp->data,dist[temp->data]);
         HEAP[hepos[temp->data]].com = dist[temp->data];
         shufup(hepos[temp->data]);
         temp = temp->next;
//         printf("After Operations heap is \n");
//         show_heap();
      }
   }
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
   hepos[x.nodeno] = SIZE;
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
      hepos[HEAP[pos].nodeno] = pos;
      hepos[HEAP[pos/2].nodeno]  = pos/2;
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
         hepos[HEAP[pos].nodeno] = pos;
         hepos[HEAP[m].nodeno] = m;
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
         hepos[HEAP[pos].nodeno] = pos;
         hepos[HEAP[2*pos].nodeno] = 2*pos;
      }
      return 0;
   }
   return 0;
}
void show_heap()
{
   int i;
   for(i=1;i<SIZE;i++)
   {
      printf("%d,%d ",HEAP[i].com,HEAP[i].nodeno);
   }
   printf("\n");
}
/*

//Heap-Test.
int t,i;
scanf("%d",&t);
clear();
while(t--)
{
int command;
scanf("%d",&command);
if(command==1)
{
int el;
scanf("%d",&el);
insert(el);
}
if(command==2)
{
printf("%d\n",delete());
}
if(command==3)
{
for(i=1;i<SIZE;i++)
printf("%d ",HEAP[i]);
putchar('\n');
}
}
*/
/* //View Scanned
   for(i=1;i<n;i++)
   {
   N *temp = ver[i];
   printf("%d ->",i);
   while(temp!=NULL)
   {
   printf("%d,%d",temp->data,temp->w);
   temp = temp->next;
   }
   putchar('\n');
   }
   */
