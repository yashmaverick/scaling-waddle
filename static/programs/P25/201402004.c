#include <stdio.h>
#include <stdlib.h>
#define ll long long int
struct edge
{ll v1, v2, w;};

ll ne,nv;
struct edge ed[1000100];
ll parent[1000100];
ll rank[1000100];
int vis[1000100];

ll find(ll i) {return parent[i]==i?i:find(parent[i]);}

int cmpfunc(const void* a, const void* b)
{
    struct edge* e1=(struct edge*)a;struct edge* e2=(struct edge*)b;
    return e1->w>e2->w;
}

void union_find(ll x,ll y)
{
    ll tmp1=find(x);
    ll tmp2=find(y);
    if(rank[tmp1]<rank[tmp2])parent[tmp1]=tmp2;
    else if(rank[tmp1]>rank[tmp2])parent[tmp2]=tmp1;
    else
    {parent[tmp2]=tmp1;rank[tmp1]++;}
}
 
ll kruskals()
{
    struct edge result[nv]; 
    ll e=0;
    ll i=0;
    ll j;
    qsort(ed,ne,sizeof(ed[0]),cmpfunc); 
    for(j=0;j<ne;j++)
    {
        struct edge next=ed[i++];
        ll x=find(next.v1);
        ll y=find(next.v2);
        if (x!=y)
        {
            result[e++]=next;
            union_find(x,y);
        }
        if(e==nv-1)break;
    }
    if(e!=nv-1)return -1;
    //for (i=0;i<e;i++)printf("%lld %lld %lld\n", result[i].v1, result[i].v2,result[i].w);
    ll cnt=0;
    for(i=0;i<e;i++)cnt+=result[i].w;
    return cnt;
}
 
int main()
{
    ll ans,x,y,z,i;
    scanf("%lld %lld",&nv,&ne);
    if(nv==1)printf("0\n");
    for(i=0;i<ne;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        ed[i].v1=x;
        ed[i].v2=y;
        ed[i].w=z;
    }
    //for(i=1;i<=nv;i++)if(vis[i]==0){printf("-1\n");return 0;}
    for(i=0;i<=nv+2;i++){parent[i]=i;rank[i]=0;}
    ans=kruskals();
    printf("%lld\n",ans);
    return 0;
}
