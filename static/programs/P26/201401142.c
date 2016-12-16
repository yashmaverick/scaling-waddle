#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define PSIZE 10001
int esieve[PSIZE];bool visited[PSIZE];
int alprimes[1061];int alprimesc; //1061 Primes From 1K to 10K.
int adj_mat[1061][15]; //Max is 14
int dist[1061][1061];
int LEN;
void adjlistmaker()
{
   int i,j,temp,x;
   for(i=0;i<alprimesc;i++)
   {
      x = alprimes[i]; //Find all possible direct connections between this vertex and others.
      temp = x%1000;
      for(j=1;j<10;j++)
      {
         if(esieve[j*1000 + temp]==0) //If the number is a prime number.
         {
            if((j*1000+temp)!=x){
               adj_mat[i][0]++;
               adj_mat[i][adj_mat[i][0]] = j*1000 + temp;}
         }
      }
      temp = x - ((x%1000)/100)*100;
      for(j=0;j<10;j++)
      {
         if(esieve[j*100 + temp]==0) //If the number is a prime number.
         {
            if((j*100+temp)!=x)
            {
               adj_mat[i][0]++;
               adj_mat[i][adj_mat[i][0]] = j*100 + temp;
            }
         }
      }
      temp = x - (((x%100)/10)*10);
      for(j=0;j<10;j++)
      {
         if(esieve[j*10 + temp]==0) //If the number is a prime number.
         {
            if((j*10+temp)!=x){
               adj_mat[i][0]++;
               adj_mat[i][adj_mat[i][0]] = j*10 + temp;}
         }
      }
      temp = x - x%10;
      for(j=0;j<10;j++)
      {
         if(esieve[j + temp]==0) //If the number is a prime number.
         {
            if((j+temp)!=x)
            {
               adj_mat[i][0]++;
               adj_mat[i][adj_mat[i][0]] = j + temp;
            }
         }
      }
   }
}
typedef struct node{
   int data;
   int dist;
   struct node* next;
}N;
N *start,*end;
int enq(int x,int tance)
{
   if(start==NULL)
   {
      start = (N*)malloc(sizeof(N));
      start->data = x;
      end = start;
      start->dist = tance;
   }
   else
   {
      N* new;
      new = (N*)malloc(sizeof(N));
      new->data = x;
      new->dist = tance;
      end->next = new;
      end = new;
      end->next = NULL;
   }
   return 0;
}
int empty()
{
   if(start==NULL)
      return 1;
   else
      return 0;
}
int deq()
{
   if(end==start)
   {
      int da;
      da = start->data;
      LEN = start->dist;
      free(start);
      start=end=NULL;
      return da;
   }
   N *temp;
   int da;
   da = start->data;
   LEN = start->dist;
   temp = start;
   start = temp->next;
   free(temp);
   return da;
}
void bfs()
{
   int i,j;
   for(i=0;i<alprimesc;i++)
   {
      for(j=0;j<alprimesc;j++)                   //Make the vistited array empty//
         visited[alprimes[j]] = 0;
      LEN = 0;
      start = end = NULL;
      enq(alprimes[i],0);                        //Start Prep For BFS
      visited[alprimes[i]] = 1;
      while(!empty())
      {
         int d = deq();
         d = esieve[d];
         dist[i][d] = dist[d][i] = LEN;
         int count = adj_mat[d][0];
         for(j=1;j<=count;j++)
            if(!visited[adj_mat[d][j]])
            {
               visited[adj_mat[d][j]] = 1;
               enq(adj_mat[d][j],LEN+1);
            }
      }
   }
}
int main()
{
   long long int i,j,count;
   esieve[1] = 1;
   for(i=1;i<PSIZE;i++)
      if(esieve[i]==0)
         for(j=i*i;j<PSIZE; j += i)
            esieve[j] = 1;
   for(i=1000;i<PSIZE;i++)
      if(esieve[i]==0)
         alprimes[alprimesc++] = i;
   adjlistmaker();
   count = 0;
   for(i=1000;i<PSIZE;i++)
      if(esieve[i]==0)
         esieve[i] = count++;
   bfs();
   int t,v1,v2;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&v1,&v2);
      printf("%d\n",dist[esieve[v1]][esieve[v2]]);
   }
   return 0;
}
