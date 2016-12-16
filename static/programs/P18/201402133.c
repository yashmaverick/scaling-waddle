#include <stdio.h>
#include <string.h>

int n, cnt, ans;
int Adj[1019][1019];
int Vis[1019];

void dfs(int u)
{
    int i;
    
    Vis[u] = 1;
    cnt++;
    
    for(i=1; i<=n; ++i)
    {
        if(Adj[u][i]==1 && Vis[i]==0)
            dfs(i);
    }
}
void compute(int u)
{
    int i;
    
    Vis[u] = 1;
    ans++;
    
    for(i=1; i<=n; ++i)
    {
        if(Adj[i][u]==1 && Vis[i]==0)
            compute(i);
    }
}

int main()
{
    int t; scanf("%d",&t);
    
    while(t--)
    {
        int i, j;
        scanf("%d",&n);
        
        memset(Adj,0,sizeof(Adj));
        
        for(i=1;i<=n;++i)
        {
            int d; scanf("%d",&d);
            
            for(j=0; j<d; ++j)
            {
                int v; scanf("%d",&v);
                
                Adj[v][i] = 1;
            }
        }
        
        ans = 0;
        
        for(i=1;i<=n;++i)
        {
            cnt = 0;
            memset(Vis,0,sizeof(Vis));
            dfs(i);
            
            if(cnt == n)
            {
                memset(Vis,0,sizeof(Vis));
                compute(i);
                break;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}