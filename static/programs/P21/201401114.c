#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<limits.h>
typedef long long ll;

/* struct which represents a node in the adjacency list  */
typedef struct BLOCK{
    ll dist;
    int node;
}BLOCK;

/* struct which represents a node in the min_heap  */
typedef struct node{
    int v;
    int wt;
    struct node*next;
}node;

BLOCK min_heap[1000001];  //min_heap
node * G[100001];    //graph
int N; //count of the number of elements in the min heap

void swap(int i,int j)  //swap two nodes in the min_heap given their indices
{
    ll tmp=min_heap[i].dist;
    min_heap[i].dist=min_heap[j].dist;
    min_heap[j].dist=tmp;
    tmp=min_heap[i].node;
    min_heap[i].node=min_heap[j].node;
    min_heap[j].node=tmp;
    return;
}
void heapify(int n)  //heapify min_heap at node index n
{
    if(2*n>N)   //nth node is th leaf node
        return;
    if(2*n+1>N)  //nth node has only left child, no right child
    {
        if(min_heap[2*n].dist<min_heap[n].dist)  //left child is less than nth node
        {
            swap(2*n,n);
            heapify(2*n);
        }
        else  //no problem
            return;
    }
    if(min_heap[2*n].dist>=min_heap[n].dist && min_heap[2*n+1].dist>=min_heap[n].dist)  //both children are greater than nth node
        return;
    // find the minimum of the children and swap nth node with them
    if(min_heap[2*n].dist>min_heap[2*n+1].dist)  
    {
        swap(2*n+1,n);
        heapify(2*n+1);
    }
    else
    {
        swap(2*n,n);
        heapify(2*n);
    }
    return;
}
void heap_insert(ll dist,int node)  //insert an element in min_heap which also heapifies it after inserting
{
    min_heap[++N].dist=dist;
    min_heap[N].node=node;
    int i=N;
    while(i/2>0 && min_heap[i/2].dist>min_heap[i].dist)
    {
        swap(i,i/2);
        i/=2;
    }
}
BLOCK deletemin()    //delete the minimum element in the min_heap
{
    BLOCK tmp;
    tmp.dist=min_heap[1].dist;
    tmp.node=min_heap[1].node;
    min_heap[1].dist=min_heap[N].dist;
    min_heap[1].node=min_heap[N--].node;
    heapify(1);
    return tmp;
}
/*void printheap()
  {
  int i;
  for(i=1;i<=N;i++)
  printf("%d ",min_heap[i].dist);
  printf("\n");
  return;
  }*/
node * new_node(int v,int w)
{
    node * tmp=(node *)malloc(sizeof(node));
    tmp->v=v;
    tmp->wt=w;
    tmp->next=NULL;
    return tmp;
}
node *push(int u,int v,int w)   //add an edge in adjacency list
{
    node * head=G[u];
    if(head==NULL)
    {
        head=new_node(v,w);
        return head;
    }
    node * tmp=(node *)malloc(sizeof(node));
    tmp->v=v; tmp->wt=w; tmp->next=head;
    head=tmp;
    return head;
}
void dijkstra(int start,int cnt_nodes,int dest)   //cnt_nodes is the number of nodes in the graph
{
    ll D[100001];
    int i;
    for(i=1;i<=cnt_nodes;i++)
    {
        if(i!=start)
        {
            D[i]=LLONG_MAX;
            heap_insert(D[i],i);
        }
    }
    D[start]=0;
    heap_insert(D[start],start);
    int cnt=0;
//    while(N>0)
    while(cnt<cnt_nodes)
    {
        BLOCK tmp=deletemin();
        int u=tmp.node;
        int d=tmp.dist;
//        printf("node : %d   distance of node : %d\n",u,d);
        if(d<=D[u])    //Important
        {
            cnt++;
            node * temp=G[u]; //for each child of u
            while(temp!=NULL)
            {
                int v=temp->v;
                int cost=temp->wt;
                if(D[v]>D[u]+cost)  //update
                {
                    D[v]=D[u]+(ll)cost;
                    heap_insert(D[v],v);
                }
                temp=temp->next;
            }
        }
    }
    //print the distances
    //    for(i=1;i<=cnt_nodes;i++)
    if(D[dest]==LLONG_MAX)
            printf("NO\n");
    else
        printf("%lld\n",D[dest]);
    return;
}
int main()
{
//    int T;
    int i,n,u,v,w,m;
//    scanf("%d",&T);
//    while(T--)
//    {
        N=0;
        scanf("%d%d",&n,&m); //number of node and edges
        for(i=1;i<=n;i++)
            G[i]=NULL;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u]=push(u,v,w);
        }
        //print the adjacency list
        /*    for(i=1;i<=n;i++)
              {
              printf("adjacency list of %d\n",i);
              node * tmp=G[i];
              while(tmp!=NULL)
              {
              printf("node : %d wt : %d\n",tmp->v,tmp->wt);
              tmp=tmp->next;
              }
              }*/
        int s,t;
        scanf("%d%d",&s,&t);
        dijkstra(s,n,t);  //start dijstra from node 1 in graph G which has n nodes
//    }
    return 0;
}
