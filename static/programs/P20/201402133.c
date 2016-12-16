#include <stdio.h>

int n;
int Deg[1000019];
int Edges[1000019][2];
int* Adj[1000019];

int Dist[1000019];

void dfs(int u, int p)
{
    int i;
    
    if(p != -1)
        Dist[u] = Dist[p]+1;
    else
        Dist[u] = 0;
    
    for(i=0; i<Deg[u]; ++i)
    {
        int v = Adj[u][i];
        
        if(v != p)
        {
            dfs(v, u);
        }
    }
}

int main()
{
    int t; scanf("%d",&t);
    
    while(t--)
    {
        int i, j;
        scanf("%d",&n);
        
        for(i=0; i<n-1; ++i)
        {
            int a, b;
            scanf("%d %d",&a,&b);
            
            Edges[i][0] = a;
            Edges[i][1] = b;
            
            Deg[a]++, Deg[b]++;
        }
        for(i=1; i<=n; ++i)
        {
            Adj[i] = (int*)(malloc(sizeof(int)*(Deg[i])));
            Deg[i] = 0;
        }
        for(i=0; i<n-1; ++i)
        {
            int a = Edges[i][0], b = Edges[i][1];
            Adj[a][Deg[a]++] = b;
            Adj[b][Deg[b]++] = a;
        }
        
        dfs(1,-1);
        
        int flag = -1, best = -1;
        for(i=1; i<=n; ++i)
        {
            if(Dist[i] > best)
            {
                flag = i;
                best = Dist[i];
            }
        }
        
        dfs(flag,-1);
        
        flag = -1, best = -1;
        for(i=1; i<=n; ++i)
        {
            if(Dist[i] > best)
            {
                flag = i;
                best = Dist[i];
            }
        }
        
        printf("%d\n",best+1);
        
        for(i=1; i<=n; ++i)
            free(Adj[i]);
    }
    
    return 0;
}