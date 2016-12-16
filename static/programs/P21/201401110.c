#include<stdio.h>
#include<stdlib.h>
#define LLONG_MAX 10000000000000000
typedef long long int ll;
ll n,m;
ll minsize;
ll hasharray[100001];
ll visited[100001];
ll distance[100001];
typedef struct graph
{
      ll v;
      ll w;
      struct graph *next;
}node;

typedef struct heap
{
  ll v;
  ll dist;
}heapnode;

node *arr[100001];
heapnode minheap[100001];

void swap(ll i,ll child)
{
  heapnode *tempnode = malloc(sizeof(heapnode));
  ll temp;
 
  tempnode->v=minheap[i].v;
  tempnode->dist=minheap[i].dist;

  minheap[i].v=minheap[child].v;
  minheap[i].dist=minheap[child].dist;

  minheap[child].v=tempnode->v;
  minheap[child].dist=tempnode->dist;

  hasharray[minheap[i].v]=i;
  hasharray[minheap[child].v]=child;
}

node *insertgraph(ll v,ll w,node *root,ll i)
{
  node *temp=malloc(sizeof(node));
  node *tempnode;
  temp->v=v;
  temp->w=w;
  if(root==NULL)
  {
    root=malloc(sizeof(node));
    root->v=temp->v;
    root->w=temp->w;
    root->next=NULL;
  }
  else
  {
    tempnode=root;
    root=temp;
    root->next=tempnode;
  }
  return root;
}

int deletemin()
{
  ll child,i,deletedelement;
  deletedelement=minheap[1].v;
  if(minsize==1)
  {
    minsize--;
    return deletedelement;
  }

  swap(1,minsize);
  minsize--;
  for(i=1;i<=minsize/2 && (( minheap[i].dist > minheap[2*i].dist ) || ( minheap[i].dist > minheap[(2*i)+1].dist )) ;i=child)
  {
    child=i*2;
    if(child+1<=minsize && minheap[child+1].dist < minheap[child].dist )
      child++;
    swap(i,child);
  }
  return deletedelement;
}

void update(ll pos)
{
  ll i=pos,child1,child2,child;

  child1=2*i;
  child2=child1+1;

  if( (i>1) && minheap[i].dist < minheap[i/2].dist )
  {
    while((i>1) && minheap[i].dist < minheap[i/2].dist )
    {
   //printf("heapify up:\n");
      swap(i,i/2);
      i=i/2;
    }
  }

  else if (((child1<=minsize) && (minheap[i].dist>minheap[child1].dist))||((child2<=minsize) &&(minheap[i].dist>minheap[child2].dist)))
  {
    printf(" %lld > ( %lld || %lld )\n",minheap[i].dist,minheap[child1].dist,minheap[child2].dist);
    for(;i<=minsize/2 && ((minheap[i].dist > minheap[2*i].dist ) ||(minheap[i].dist > minheap[(2*i)+1].dist)) ;i=child)
    {
//      printf("heapify down:\n");
      child=i*2;
      if(child+1<=minsize && minheap[child+1].dist < minheap[child].dist)
        child++;
      swap(i,child);
    }
  }
}

ll maxw;

void dijkstra(ll src,ll dest)
{
  ll i;
  for(i=1;i<=n;i++)
  {
    //heapnode[i]=malloc(sizeof(heapnode));
    minheap[i].v=i;
    minheap[i].dist=LLONG_MAX;
    hasharray[i]=minheap[i].v;
    visited[i]=0;
    distance[i]=LLONG_MAX;
  }
  minsize=n;
  minheap[hasharray[src]].dist=0;
  distance[src]=0;
  update(hasharray[src]);

  while(minsize>0)
  {
  //  printf("CURRENT MIN: %lld\n",minheap[1].v);
    ll V=minheap[1].v;
    ll VDIST=distance[V];
    visited[V]=1;
    node *a=arr[V];
    ll deletedelement=deletemin();
    //printf("DELETED %lld\n",deletedelement);
    node *temp=a;
    while(temp!=NULL)
    {
    //printf("adj vertex : %lld having w: %lld at minheap[%lld]\n",temp->v,temp->w,hasharray[temp->v]);
      if( (distance[temp->v]>(VDIST+temp->w)) && (visited[temp->v]==0) ) 
      {
        minheap[hasharray[temp->v]].dist=VDIST+temp->w;
        distance[temp->v]=VDIST+temp->w;
      //  printf("Going to update for %lld as dist=%lld:%lld\n",temp->v,distance[temp->v],minheap[hasharray[temp->v]].dist);
        update(hasharray[temp->v]);
      }
      temp=temp->next;
    }
  }
}

int main()
{
  ll i,u,v,w,src,dest,j;

  scanf("%lld%lld",&n,&m);
  for(i=0;i<m;i++)
  {
    scanf("%lld%lld%lld",&u,&v,&w);
    arr[u]=insertgraph(v,w,arr[u],i);
  //  arr[v]=insertgraph(u,w,arr[v],i);
  }
  scanf("%lld%lld",&src,&dest);
  dijkstra(src,dest);
/*  for(i=1;i<=n;i++)
  {
    printf("distance[%lld] : %lld\n",i,distance[i]);
    printf("hasharray[%lld] : %lld\n",i,hasharray[i]);
  }*/
  if(visited[dest]==0||distance[dest]==LLONG_MAX)
    printf("NO\n");
 else 
    printf("%lld\n",distance[dest]);

  return 0;
}
