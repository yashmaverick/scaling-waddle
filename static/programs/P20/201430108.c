#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
    int num;
    struct list * next;
}*head;
typedef struct list list;
list * a[1000010];
void insert(int e1,int e2);
void dfs(int v,int n);
int vis[1000010],dist[1000010],k;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int i;
    int n;
    scanf("%d",&n);
    if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(n==0)
        {
            printf("0\n");
            continue;
        }
    for(i=0;i<1000010;i++)
        {
            a[i]=NULL;
            dist[i]=0;
            vis[i]=0;
        }
    for(i=1;i<n;i++)
    {
        int e1,e2;
        scanf("%d%d",&e1,&e2);
        insert(e1,e2);
        insert(e2,e1);
    }
                dist[0]=0;
                 dfs(1,0);
                int node=0;
                 for(i=1;i<=n;i++)
                  if(dist[i]>dist[node])
                    node=i;
                int ans=dist[node];
                for(i=0;i<1000010;i++)
                {
                    dist[i]=0;
                    vis[i]=0;
                }
            dfs(node,0);
            node=0;
                 for(i=0;i<=n;i++)
                  if(dist[i]>dist[node])
                    node=i;
                printf("%d\n",(dist[node])+1);


    }
    return 0;
}
void dfs(int v,int n)
  {           
            vis[v]=1;
            dist[v]=n;
            list *temp;
    //temp=(list *)malloc(sizeof(list));
    temp=a[v];
    while(temp!=NULL)
        {
            
            if(vis[temp->num])
                {
                    temp=temp->next;
                      continue;
                }
            dfs(temp->num,n+1);
            temp=temp->next;
        }
   }
void insert(int e1,int e2)
{
    
    list *temp;
    temp=(list *)malloc(sizeof(list));
    temp->next=a[e1];
    a[e1]=temp;
    temp->num=e2;
}