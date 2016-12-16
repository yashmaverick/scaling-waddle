#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Level[1000005];
int visited[1000005];
int Q[1000005];
int front,end;

struct node
{
    int d;
    struct node *next;
};
typedef struct node NODE;
typedef NODE *LINK;

LINK adj_list[1000005];

int bfs(int root)
{
    visited[root]=-1;
    Level[root]=1;
    front=end=0;
    Q[front]=root;
    LINK i;
    int p;
    while(front<=end)
    {
        p=Q[front++];
        for(i=adj_list[p];i!=NULL;i=i->next)
        {
            if(visited[i->d]==0)
            {
                Level[i->d]=Level[p]+1;
                //printf("level of %d is %d\n",i->d,Level[i->d]);
                visited[i->d]=-1;
                Q[++end]=i->d;
            }
        }
        visited[p]=1;
    }
    return p;
}

int diameter()
{
    int far1=bfs(1);
    memset(Level,-1,sizeof(Level));
    memset(visited,0,sizeof(visited));
    return Level[bfs(far1)];
}

int main()
{
      int t,n,i,a,b;
      scanf("%d",&t);
      while(t--)
      {
         scanf("%d",&n);
         for(i=1;i<=n;i++)
         {
             adj_list[i]=NULL;
         }
         
         for(i=1;i<=n-1;i++)
         {
             scanf("%d%d",&a,&b);

             LINK temp;
             temp=(LINK)malloc(sizeof(NODE));
             temp->d=b;
             temp->next=adj_list[a];
             adj_list[a]=temp;

             temp=(LINK)malloc(sizeof(NODE));
             temp->d=a;
             temp->next=adj_list[b];
             adj_list[b]=temp;
         }
         front=end=-1;
         memset(Level,-1,sizeof(Level));
         memset(visited,0,sizeof(visited));
         printf("%d\n",diameter());

      }

return 0;
}
