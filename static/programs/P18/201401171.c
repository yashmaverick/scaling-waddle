#include<stdio.h>
#include<string.h>

#define maxN 1234

int graph[maxN][maxN], grapr[maxN][maxN],n,vis,visit[maxN];

int dfs(int u)
{
    visit[u]=1;
    vis++;
    int i;
    for(i=1;i<=n;i++)
    {
        if (graph[u][i]==1 && visit[i]==0)
        {
            dfs(i);
        }
    }
}

int dfr(int u)
{
    visit[u]=1;
    vis++;
    int i;
    for(i=1;i<=n;i++)
    {
        if (grapr[u][i]==1 && visit[i]==0)
        {
            dfr(i);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(graph,0,sizeof(graph));
        memset(grapr,0,sizeof(grapr));
        int i;
        for(i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m);
            while(m--)
            {
                int k;
                scanf("%d",&k);
                grapr[i][k]=1;
                graph[k][i]=1;
            }
        }
        int flag=0;
        for(i=1;i<=n;i++)
        {
            vis=0;
            memset(visit,0,sizeof(visit));
            dfs(i);
            if(vis==n)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("0\n");
        }
        else
        {
            vis=0;
            memset(visit,0,sizeof(visit));
            dfr(i);
            printf("%d\n",vis);
        }
    }
    return 0;
}
