#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int d;
    struct node *next;
};
typedef struct node REALM;
typedef REALM *LINK;

LINK adj_list[1001];
LINK parent[1001];

int visited[1001];

void dfs(int root)
{
    visited[root]=1;

    LINK i;
    for(i=adj_list[root];i!=NULL;i=i->next)
    {
        if(visited[i->d]==0)
            dfs(i->d);
    }

}

int is_spanning(int root,int n)
{
    memset(visited,0,sizeof(visited));
    dfs(root);
    int i;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    return 1;
}

int calculate(int root)
{
    visited[root]=1;
    //printf("visited is %d and %d calculating\n",visited[root],root);
    int count=1;
    LINK i;
    for(i=parent[root];i!=NULL;i=i->next)
    {
        if(visited[i->d]==0)
        {
            count+=calculate(i->d);
        }
    }
    return count;
}

int main()
{
    int t,n,m;
    int i,j;
    int r;
    LINK temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            adj_list[i]=parent[i]=NULL;
        }

        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&r);
                temp=(LINK)malloc(sizeof(REALM));
                temp->d=i;

                //insert i in adj_list of r as r defeats i
                temp->next=adj_list[r];
                adj_list[r]=temp;

                //insert r as parent of i
                temp=(LINK)malloc(sizeof(REALM));
                temp->d=r;
                temp->next=parent[i];
                parent[i]=temp;
            }
        }

        int count=0;
        for(i=1;i<=n;i++)
        {
            if(is_spanning(i,n))
            {
                memset(visited,0,sizeof(visited));
                count=calculate(i);
                break;
            }
            memset(visited,0,sizeof(visited));
        }
        printf("%d\n",count);
    }
    return 0;
}
