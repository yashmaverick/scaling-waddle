#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

int edges[2000005][2];
int fEdge[1000005];
int lEdge[1000005];
short vis[1000005];
int edgeCount;

void insertEdge ( int j, int k )
{
    if ( !fEdge[j] )
    {
        fEdge[j] = lEdge[j] = edgeCount;
        edges[edgeCount][0] = k;
        edgeCount++;
    }
    else
    {
        edges[lEdge[j]][1] = edgeCount;
        lEdge[j] = edgeCount;
        edges[edgeCount][0] = k;
        edgeCount++;
    }
}

int maxDepth, maxNode;

void findMaxDepth ( int node, int dep )
{
    //printf("node %d\n",node);
    vis[node] = 1;
    int i, j;
    if ( dep > maxDepth )
    {
        maxDepth = dep;
        maxNode = node;
    }
    for ( i = fEdge[node]; i != 0 ; i = edges[i][1] )
    {
        if ( !vis[edges[i][0]] )
            findMaxDepth(edges[i][0],dep+1);
        if ( i == lEdge[node] )
            break;
    }
}
int main()
{
    int tcases, N, i, j, k;
    din(tcases);
    while ( tcases-- )
    {
        din(N);
        edgeCount = 1;
        for ( i = 0; i < N-1; i++ )
        {
            din(j); din(k);
            insertEdge(j,k);
            insertEdge(k,j);
            //printf("done\n");
        }

        maxDepth = maxNode = 0;
        findMaxDepth(1,1);
        memset(vis,0,sizeof(vis)); maxDepth = 0;
        findMaxDepth(maxNode,1);
        memset(vis,0,sizeof(vis));
        printf("%d\n",maxDepth);

        memset(fEdge,0,sizeof(fEdge));
        memset(lEdge,0,sizeof(lEdge));
        memset(edges,0,sizeof(edges));
    }

    return 0;
}
