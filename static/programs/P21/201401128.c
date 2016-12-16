#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 1000000000000005LL 

struct node
{
    int d;
    long long int w;
    struct node *next;
};
typedef struct node NODE;
typedef NODE *LINK;

LINK heap[100005];
int size;
long long int dist[100001];
int P[100001];

LINK adj_list[100001];

void shuffle_up(int v)
{
    long long int x=heap[P[v]]->w;
    int i;
    for(i=P[v];i>1 && heap[i/2]->w>x;i/=2)   
    {
        heap[i]->w=heap[i/2]->w;
        heap[i]->d=heap[i/2]->d;
        P[heap[i/2]->d]=i;
    }
    heap[i]->d=v;
    heap[i]->w=x;
    P[v]=i;
}

int pop()
{
    if(size==0)
        return -1;
    int min=heap[1]->d;
    long long int last=heap[size]->w;
    int last_v=heap[size--]->d;
    int i,min_child;
    for(i=1;i<=size/2;i=min_child)
    {   
        min_child=2*i;
        if(2*i!=size && heap[2*i+1]->w<heap[min_child]->w)
            min_child=2*i+1;
        if(last<heap[min_child]->w)
            break;
        else
        {
            heap[i]->d=heap[min_child]->d;
            heap[i]->w=heap[min_child]->w;
            P[heap[min_child]->d]=i;
        }
    }
    heap[i]->d=last_v;
    heap[i]->w=last;
    P[last_v]=i;
    return min;
}

int main()
{
    int i,v,k,a,b,w;
    int s,d;	
    scanf("%d%d",&v,&k);
    for(i=1;i<=v;i++)
    {
        dist[i]=INF;
        adj_list[i]=NULL;
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        LINK temp;
        temp=(LINK)malloc(sizeof(NODE));
        temp->d=b;
        temp->w=w;
        temp->next=adj_list[a];
        adj_list[a]=temp;
    }
    size=0;
    scanf("%d%d",&s,&d);
    dist[s]=0;
    for(i=1;i<=v;i++)
    {
        if(i==s)
            continue;
        LINK temp;
        temp=(LINK)malloc(sizeof(NODE));
        temp->d=i;
        temp->w=INF;
        heap[++size]=temp;
        P[i]=size;
    }

    for(i=s;i!=d;)
    {

        LINK j;
        for(j=adj_list[i];j!=NULL;j=j->next)
        {
            if(dist[j->d]>dist[i]+j->w)
            {
                dist[j->d]=dist[i]+j->w;
                heap[P[j->d]]->w=dist[i]+j->w;
                shuffle_up(j->d);
            }
        }
        i=pop();	
    }
    if(dist[d]!=INF)
        printf("%lld\n",dist[d]);
    else
        printf("NO\n");


    return 0;
}
