/*
   _____________________________________________
   PROBLEM STATEMENT: you are given graph in following form : 
   num_vertex   num_edges
   v1  v2   weight   ---- edge between v1 to v2  with weight =weight   // such query for num_edges times
   A   B             ---- find shortest distance between A to B
   your task is to apply dijkstra algorithm and find the minimum distance between A and B
COMMENTS:
To apply dijkstra's shortest path algorithm : 
you have to maintain a distance array storing the absolute distances of each vertex from source 
initialize distance[source] with 0 and others with inf
now push each vertex in heap (managed according to its absolute distance) 
now while the heap is not empty do :
pop the minimum of heap
for neighbours of vertex u:
if d(v) > d(u) + weight (u->v) :
update d(v)

SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int nodename;
    int weight;
    node *next;
};

//global variables
node *arr[100001];
int size;
int distance[100001];
int heap[1000001];
int visited[100001];


node *insert(node *head,int edgename,int weight)          // func to insert in a branch of adjacency list
{
    node *temp=(node *)malloc(sizeof(node));
    temp->nodename=edgename;
    temp->weight=weight;
    temp->next=head;
    head=temp;
    return head;

}

void swap(int arr[],int i,int j)
{
    if(i==j) return ;
    arr[i]=arr[i]+arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]=arr[i]-arr[j];
}

int delete_min()                                //popping the min from heap and shuffle up
{
    int i;
    swap(heap,1,size-1);  
    size--;              
    int s=1;
    for(i=1;2*i+1<size;)
    {
        if(distance[heap[i]]>distance[heap[2*i]]   || distance[heap[i]]>distance[heap[2*i+1]])
        {
            int temp;
            temp=distance[heap[2*i]]<distance[heap[2*i+1]]?2*i:2*i+1;
            swap(heap,i,temp);
            i=temp;
        }
        else  break;
    }
    if(2*i+1==size)   if(distance[heap[i]]>distance[heap[2*i]])   swap(heap,i,2*i);
    return heap[size];
}

void insert_heap(int n)                //inserting in heap
{ 
    int i;
    heap[size++]=n;
    int temp=size-1;
    for(i=size-1; i>0;i=i/2)
    {
        if(distance[heap[temp]]<distance[heap[i]])
        {
            swap(heap,temp,i);
            temp=i;
        }
        else if(distance[heap[temp]]>distance[heap[i]]) break;
    }
}

int main()
{
    int t,vertex,edges,i,a,b,c,A,B;
    //initializing each array
    for(i=0;i<100001;i++) visited[i]=0;
    for(i=0;i<100001;i++) distance[i]=2000000000;
    for(i=0;i<100001;i++) heap[i]=0;
    for(i=0;i<100001;i++) arr[i]=NULL;
    size=1;
    heap[0]=-1;

    //input
    scanf("%d %d",&vertex,&edges);
    for(i=0;i<edges;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        arr[a]=insert(arr[a],b,c);
    }
    scanf("%d %d",&A,&B);


    distance[A]=0;
    insert_heap(A);
    //
    //applying dijkstra's algorithm
    while(size!=1)
    {
        int start=delete_min();
        while(visited[start]==1 && size!=1){start=delete_min(size);}
        visited[start]=1;
        node *temp=arr[start];
        while(temp!=NULL)
        {
            if(distance[temp->nodename]> distance[start]+temp->weight)
            {
                distance[temp->nodename]=distance[start]+temp->weight;
                insert_heap(temp->nodename);
            }
            temp=temp->next;
        }
    }
    //end

    if(distance[B]==2000000000) printf("NO\n");
    else printf("%d\n",distance[B]);
    return 0;
}
