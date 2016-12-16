#include<stdio.h>
#include<stdlib.h>
#define maxN 2234567

typedef struct edges{
    long long int i,u,v,w;
}edges;

long long int n,m,ead,ans,rank[maxN],par[maxN];
edges edge[maxN];

int cmpfunc(const void *p1, const void *p2)
{
    const struct edges *a=p1;
    const struct edges *b=p2;
    return (a->w-b->w);
}

long long int findPar(long long int v)
{
    if (par[v]==v)
        return v;
    return par[v]=findPar(par[v]);
}

void merge(long long int a ,long long int b)
{
        par[b]=a;
}

int main()
{
    long long int i;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++)
    {
        long long int a,b,e;
        scanf("%lld %lld %lld",&a,&b,&e);
        edge[i].u=a;
        edge[i].v=b;
        edge[i].i=i;
        edge[i].w=e;
    }
    for(i=1;i<=n;i++)
    {
        rank[i]=i;
        par[i]=i;
    }
    qsort(edge,m,sizeof(edges),cmpfunc);
    for(i=0;i<m;i++)
    {
         if (findPar(edge[i].u)!=findPar(edge[i].v))
         {
                merge(findPar(edge[i].u),findPar(edge[i].v));
                ead++;
                ans=ans+edge[i].w;
         }
         if(ead==n-1)
             break;
    }
    if(ead==n-1)
        printf("%lld\n",ans);
    else
        printf("-1\n");
    return 0;
}
