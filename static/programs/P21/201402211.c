#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

struct edge {
    ll toNode;
    ll weight;
    ll next;
} edges[500005];

ll N, M, fEdge[500005], lEdge[500005], u, v, S, T, edgeCount = 1, minDist[500005], heapSize = 1;
ll distance[500005];
short vis[500005];

void swap ( ll i, ll j )
{
    minDist[i] += minDist[j];
    minDist[j] = minDist[i] - minDist[j];
    minDist[i] -= minDist[j];
}

void addToHeap ( ll node )
{
    minDist[heapSize] = node;
    ll curr = heapSize;
    while ( distance[ minDist[curr] ] < distance[ minDist[curr/2] ] && curr > 1 )
    {
        swap(curr,curr/2);
        curr /= 2;
    }
    heapSize++;
}

ll popHeap ()
{
    heapSize--;
    ll ret = minDist[1], curr = 1;
    minDist[1] = minDist[heapSize];
    while ( ( curr*2 < heapSize && distance[ minDist[curr] ] > distance[ minDist[curr*2] ] ) || ( curr*2 + 1 < heapSize && distance[ minDist[curr] ] > distance[ minDist[curr*2+1] ] ) )
    {
        if ( curr*2 == heapSize - 1 || distance[ minDist[curr*2] ] < distance[ minDist[curr*2+1] ] )
        {
            swap(curr,curr*2);
            curr *= 2;
        }
        else
        {
            swap(curr,curr*2+1);
            curr = curr*2 + 1;
        }
    }
    return ret;
}

void dijkstra ( ll node )
{
    //printf("dijkstra %d\n",node); getchar();
    vis[node] = 1;
    ll i, j;
    for ( i = fEdge[node]; i != 0; i = edges[i].next )
    {
        //if ( vis[edges[i].toNode] )
        //{
            //if ( distance[node] + edges[i].weight < distance[ edges[i].toNode ] )
            //{
                //distance[ edges[i].toNode ] = distance[node] + edges[i].weight;
            //}
        //}
        //else
        if ( !vis[ edges[i].toNode ] )
        {
            if ( distance[ edges[i].toNode ] == -1 )
            {
                distance[edges[i].toNode] = distance[node] + edges[i].weight;
                addToHeap(edges[i].toNode);
            }
            else
            {
                if ( distance[ edges[i].toNode ] > distance[node] + edges[i].weight )
                {
                    distance[edges[i].toNode] = distance[node] + edges[i].weight;
                }
            }
        }
        if ( i == lEdge[node] )
            break;
    }
    //printf("considered all neightbours\n");

    if ( heapSize > 1 ) dijkstra(popHeap());
}



void addEdge ( ll fr, ll to, ll wt )
{
    if ( fEdge[fr] == 0 )
    {
        fEdge[fr] = lEdge[fr] = edgeCount;
    }
    else
    {
        edges[ lEdge[fr] ].next = edgeCount;
        lEdge[fr] = edgeCount;
    }
    edges[ lEdge[fr] ].weight = wt;
    edges[ lEdge[fr] ].toNode = to;
    edgeCount++;
}

int main()
{
    llin(N); llin(M);
    ll i, j, k;
    for ( i = 0; i < M; i++ )
    {
        llin(u); llin(v); llin(k);
        addEdge(u,v,k);
        //printf(".");
    }
    llin(S); llin(T);

    memset(distance,-1,sizeof(distance));
    distance[S] = 0;
    edgeCount = heapSize = 1;
    dijkstra(S);
    if ( vis[T] ) printf("%lld\n",distance[T]);
    else printf("NO\n");
    return 0;
}
