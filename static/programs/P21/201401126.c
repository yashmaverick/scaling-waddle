#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define parent(i) i/2
#define left(i) 2*i
#define right(i) (2*i)+1

typedef long long int ll;

typedef struct adj
{
    ll val;
    ll weight;
    struct adj *link;
}adj;

adj *list[1000000],*temp;

ll weight[1000000],vertex[1000000],heapsize=0;

ll visited[1000000],dist[1000000];

ll nextvertex,nextweight;

void insert(ll b,ll w)
{
    ll i;

    heapsize++;

    weight[heapsize]=w;
    vertex[heapsize]=b;

    for(i=heapsize; weight[parent(i)] > w; i=parent(i))
    {
        weight[i]=weight[parent(i)];
        vertex[i]=vertex[parent(i)];
    }

    weight[i]=w;
    vertex[i]=b;
}

void deletemin()
{
    ll i,child;
    ll minelement,lastelement;
    ll minvertex,lastvertex;

    minelement=weight[1]; minvertex=vertex[1];
    lastelement=vertex[heapsize]; lastvertex=vertex[heapsize];

    heapsize--;

    for(i=1; left(i) <= heapsize;i=child)
    {
        child=left(i);

        if(child!=heapsize && weight[child+1] < weight[child])
            child++;

        if(lastelement > weight[child])
        {
            weight[i]=weight[child];
            vertex[i]=vertex[child];
        }
        else
            break;
    }

    weight[i]=lastelement;
    vertex[i]=lastvertex;

    nextweight=minelement;
    nextvertex=minvertex;
}

void adjins(ll a,ll b,ll w)
{
    adj *newnode;

    newnode=(adj *)malloc(sizeof(adj));

    newnode->val=b;
    newnode->weight=w;

    newnode->link=list[a];
    list[a]=newnode;
}


ll ans=0,found=0;
ll n,m; // n-> no. of vertices ; m-> no. of edges
ll flag=0;

void dijk(ll source,ll dest,ll numvertex)
{
    //printf("%lld\n",numvertex);

    //while(heapsize!=0)
    //{
    if(source==dest)
    {
        found=1;
        return;
    }
    else if(numvertex>=n && found==0)
    {
        /*
           temp=list[source];

           while(temp!=NULL && !visited[temp->val])
           {
           if(temp->val==dest)
           flag=1;
           }
           */

        //if(flag==0)
        //{
        found=-1;
        return;
        //}
    }

    //while(heapsize!=0)
    //{

    temp=list[source];

    while(temp!=NULL && !visited[temp->val])
    {
        //temp=temp->link;

        if(dist[source]+temp->weight < dist[temp->val])
        {
            /* update */
            dist[temp->val]=dist[source]+temp->weight;
            insert(temp->val,dist[temp->val]);
        }
        temp=temp->link;
    }

    visited[source]=1;

    deletemin();

    //source=nextvertex;
    //}

    dijk(nextvertex,dest,numvertex+1);
}


int main()
{
    ll a,b,w;
    // ll n,m; // n->no. of vertices ; m-> no. of edges
    ll source,dest;

    ll i;

    //ll t;
    
    //scanf("%lld",&t);

    //memset(visited,0,1000000);
    //memset(dist,INT_MAX,1000000);
    //while(t-->0)
    //{
        heapsize=0;
        flag=0;
        found=0;
        ans=0;    

        for(i=0;i<1000000;i++)
        {
            visited[i]=0;
            dist[i]=INT_MAX;
        }

        scanf("%lld %lld",&n,&m);

        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&a,&b,&w);

            adjins(a,b,w);
        }

        scanf("%lld %lld",&source,&dest);

        // printf("everrything scanned\n");

        dist[source]=0;
        visited[source]=1;

        // printf("entering dijkstra\n");
        dijk(source,dest,1);
        // printf("dijk done :)\n");

        if(found==1)
            printf("%lld\n",dist[dest]);
        else if(found==-1)
            printf("NO\n");

    return 0;
}
