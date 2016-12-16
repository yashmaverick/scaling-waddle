#include <stdio.h>
#include <string.h>
#include <assert.h>

long long n, m;
long long Heap[1000019][2];
long long last;

long long Deg[1000019];
long long Edges[1000019][3];
long long* Adj[1000019][2];
long long Dist[1000019];
long long Done[1000019];

long long s, t;

void swap(long long* a, long long *b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}
void swapNode(long long a, long long b)
{
    swap(&Heap[a][0],&Heap[b][0]);
    swap(&Heap[a][1],&Heap[b][1]);
}
void heapify(long long u)
{
    long long s = u;
    
    if(u*2 < last)
        if(Heap[s][0] > Heap[u*2][0])
            s = u*2;
    if(u*2+1 < last)
        if(Heap[s][0] > Heap[u*2+1][0])
            s = u*2+1;
    
    if(s==u)
        return;
    
    swapNode(s, u);
    heapify(s);
}
void insert(long long val, long long id)
{
    long long u = last;
    Heap[last][0] = val;
    Heap[last++][1] = id;
    
    while(u > 1)
    {
        if(Heap[u][0] > Heap[u/2][0])
            return;
        swapNode(u, u/2);
        
        u /= 2;
    }
}
void extractmin()
{
    swapNode(1, last-1);
    last--;
    heapify(1);
}

int main()
{
    long long i, j;
    last = 1;
    
    scanf("%lld %lld",&n,&m);
    
    for(i=0; i<m; ++i)
    {
        long long a, b, w;
        scanf("%lld %lld %lld",&a,&b,&w);
        
        Edges[i][0] = a;
        Edges[i][1] = b;
        Edges[i][2] = w;
        
        Deg[a]++;
    }
    for(i=1; i<=n; ++i)
    {
        Adj[i][0] = (long long*)(malloc(sizeof(long long)*(Deg[i])));
        Adj[i][1] = (long long*)(malloc(sizeof(long long)*(Deg[i])));
        
        assert(Adj[i][0] != NULL);
        assert(Adj[i][1] != NULL);
        
        Deg[i] = 0;
    }
    for(i=0; i<m; ++i)
    {
        long long a = Edges[i][0], b = Edges[i][1];
        Adj[a][0][Deg[a]] = b;
        Adj[a][1][Deg[a]++] = Edges[i][2];
    }
    
    memset(Dist,-1,sizeof(Dist));
    scanf("%lld %lld",&s,&t);
    Dist[s] = 0;
    
    insert(0,s);
    
    while(last!=1)
    {
        long long u = Heap[1][1], i;
        extractmin();
        
        if(Done[u] == 1)
            continue;
        
        Done[u] = 1;
        
        if(u == t)
            break;
        
        for(i=0;i<Deg[u];++i)
        {
            long long v = Adj[u][0][i];
            long long w = Adj[u][1][i];
            
            if(Dist[v] == -1 || Dist[u]+w < Dist[v])
            {
                Dist[v] = Dist[u]+w;
                insert(Dist[v],v);
            }
        }
    }
    
    if(Dist[t]!=-1)
        printf("%lld\n",Dist[t]);
    else
        printf("NO\n");
    
    return 0;
}