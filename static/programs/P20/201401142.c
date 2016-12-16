/* Program to scan UNWEIGHTED list of edges and store them as adjacency list .
 * Array ver represents the lists of all the vertices adjacent to ver.
 * Size of that array is the number of nodes.
 * THE **WHOLE** INPUT is assumed to consist of n lines where n is specified in first line.
 */
#include<string.h>
#define SIZE 1000001
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
   int data;
   struct node* next;
}N;
N* ver[SIZE];
char visited[SIZE];
typedef long long int LL;
int GLOB_MAXH = 0;
int GLOB_V = 1;
void dfs(int start,int height)
{
//   printf("here\n");
   if(height>GLOB_MAXH)
   {
      GLOB_MAXH = height;
      GLOB_V = start;
   }
   visited[start] = 1;
   N* temp = ver[start];
   while(temp!=NULL)
   {
      if(!visited[temp->data])
         dfs(temp->data,height+1);
      temp = temp->next;
   }
   return ;
}
int main()
{
   int t;
  scanf("%d",&t);
   while(t--)
   {
      int n,i,v1,v2;
      N *temp;
      scanf("%d",&n);
      for(i=1;i<=n;i++)
         ver[i] = NULL;
      for(i=1;i<n;i++)
      {
         scanf("%d %d",&v1,&v2);
         temp = malloc(sizeof(N));temp->data = v2;temp->next = ver[v1];ver[v1] = temp;
         temp = malloc(sizeof(N));temp->data = v1;temp->next = ver[v2];ver[v2] = temp;
      }
  /*    for(i=1;i<n;i++)
      {
         printf("%d ->",i);
         N* temp = ver[i];
         while(temp!=NULL)
         {
            printf("%d ",temp->data);
            temp = temp->next;
         }
         printf("\n");
      }
      */
      GLOB_MAXH = 0;
      GLOB_V = 1;
//      printf("Size of visited %d\n",sizeof(visited));
      memset(visited,0,sizeof(visited));
      dfs(1,0);
//      printf("GLOB_H %d GLOB_V %d\n",GLOB_MAXH,GLOB_V);
      memset(visited,0,sizeof(visited));
      dfs(GLOB_V,0);
      printf("%d\n",GLOB_MAXH+1);
   }
   return 0;
}
