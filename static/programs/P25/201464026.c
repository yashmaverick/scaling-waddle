#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct heapstruct
{
    long long int n;
    long long int w;
}heapstruct;
typedef struct ll
{
    long long int node;
    long long int weight;
    struct ll *next;
}ll;
heapstruct heap[1000000];
long long int heapcounter;
ll* create(ll *g,long long int v,long long int w)
{
    ll *h = (ll *)malloc(sizeof(ll));
    h->node=v;
    h->weight=w;
    h->next=g;
    return h;
}
void printgraph(ll **g,long long int n)
{
    long long int i=0;
    for(i=0;i<n;i++)
    {
        ll* temphead;
        temphead = g[i];;
        while(temphead!=NULL)
        {
            printf("Node: %lld ,Weight: %lld , Link: %lld\n",temphead->node,temphead->weight,i);
            temphead = temphead->next;
        }
    }
}
void printheap();

heapstruct pop()
{
    heapstruct ans = heap[1],temp;
    temp = heap[heapcounter--];
    long long int i,j;
    for(i=1;2*i<=heapcounter;i=j)
    {
        j=2*i;
        if(j!=heapcounter && heap[j+1].w < heap[j].w)
            j++;
        if(temp.w > heap[j].w)
            heap[i] = heap[j];
        else
            break;
    }
    heap[i] = temp;
    return ans;
}
void inheap(heapstruct a)
{
    heapcounter++;
    heap[heapcounter]=a;
    long long int i=heapcounter;
    while(heap[i/2].w >a.w)
    {
        heap[i]=heap[i/2];
        i /= 2;
    }
    heap[i]=a;
//    printheap();
}
void printheap()
{
    long long int i=0;
    printf("I am printing Heap\n");
    for(i=1;i<=heapcounter;i++)
        printf("%lld %lld\n",heap[i].n,heap[i].w);
    printf("\nHeap printed successfully\n");
}
long long int prim(long long int u,long long int num,ll **g)
{
    long long int i,final=0;
    long long int visited[num];
    heapstruct temp;
    for(i=0;i<num;i++)
        visited[i] = 0;
    temp.n = u;
    temp.w = 0;
    inheap(temp);
    while(heapcounter!=0)
    {
        ll *temphead;
        heapstruct ans = pop();
        if(visited[ans.n])
            continue;
        visited[ans.n]=1;
        final += ans.w;
        temphead = g[ans.n];
        while(temphead!=NULL)
        {
            if(visited[temphead->node]==0)
            {
                temp.n = temphead->node;
                temp.w = temphead->weight;
                inheap(temp);
            }
            temphead = temphead->next;
        }
    }
    for(i=0;i<num;i++)
    	if(visited[i]==0)
    		break;
    if(i==num)
    	return final;
    else
    	return -1;
}
int main()
{
    long long int n,m,i;
    scanf("%lld %lld",&n,&m);
    ll **g = (ll **)malloc(sizeof(ll*)*n);
    for(i=0;i<n;i++)
        g[i]=NULL;
    for(i=0;i<m;i++)
    {
        long long int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        u--;v--;
        g[u]=create(g[u],v,w);
        g[v]=create(g[v],u,w);
    }
    heapcounter=0;
    long long int ans = prim(0,n,g);
    printf("%lld\n",ans);
    return 0;
}