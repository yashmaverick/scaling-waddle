#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int val;
    int weight;
    struct node *next;
}node;
node *a[100010];
int queue[100010];
int indx[100010];
long long int dist[100010];
int heap[100010];
int heapcount=0;
int rear=-1;
int n;
int front=-1;
void initheap(int x,long long int distance)
{
    heapcount++;
    heap[heapcount]=x;
    indx[x]=heapcount;
    dist[x]=distance;
    int i=heapcount;
    while(i!=1)
    {
        int parent=i/2;
        if(dist[heap[parent]]>dist[heap[i]])
        {
            int temp=heap[i];
            int tempindex=i;
            heap[i]=heap[parent];
            indx[heap[i]]=indx[heap[parent]];
            indx[heap[parent]]=tempindex;
            heap[parent]=temp;
            i=parent;
        }
        else
            break;
    }
}
void delminheap()
{
    int min=heap[1];
    heap[1]=heap[heapcount];
    indx[heap[heapcount]]=1;
    heapcount=heapcount-1;
    int i=1;
    while(i<=heapcount/2)
    {
        if(dist[heap[i]]>dist[heap[2*i]] || dist[heap[i]]>dist[heap[2*i+1]])
        {
            if(dist[heap[2*i]]<=dist[heap[2*i+1]])
            {
                int temp=heap[2*i];
                indx[heap[2*i]]=i;
                indx[heap[i]]=2*i;
                heap[2*i]=heap[i];
                heap[i]=temp;
                i=2*i;
            }
            else
            {
                int temp=heap[2*i+1];
                indx[heap[2*i+1]]=i;
                indx[heap[i]]=2*i+1;
                heap[2*i+1]=heap[i];
                heap[i]=temp;
                i=2*i+1;
            }
        }
        else
            break;
    }
}
void shuffleup(int indexofx)
{
    int i=indexofx;
    while(i!=1)
    {
        int parent=i/2;
        if(dist[heap[parent]]>dist[heap[i]])
        {
            int temp=heap[i];
            int tempindex=i;
            heap[i]=heap[parent];
            indx[heap[i]]=indx[heap[parent]];
            indx[heap[parent]]=tempindex;
            heap[parent]=temp;
            i=parent;
        }
        else
            break;
    }
}
int bfs(int src,int dest)
{
    front++;
    rear++;
    queue[rear]=src;
    memset(dist,-1,sizeof(dist));
    dist[src]=0;
    while(front!=-1)
    {
        int p=queue[front];
        if(front==rear)
            front=rear=-1;
        else
            front++;
        node *temp=a[p];
        temp=temp->next;
        while(temp!=NULL)
        {
            if(dist[temp->val]==-1)
            {
                dist[temp->val]=dist[p]+1;
                if(front==-1)
                    front=0;
                rear++;
                queue[rear]=temp->val;
            }
            temp=temp->next;
        }
    }
    return dist[dest];
}
void dijkstra(int src,int dest)
{
    int i;
    for(i=1;i<=n;i++)
    {
        dist[i]=1000000000000010;
    }
    for(i=1;i<=n;i++)
    {
        if(i==src)
            initheap(i,0);
        else
            initheap(i,1000000000000010);
    }
    int min=heap[1];
    while(heapcount!=0)
    {
        node *temp=a[min];
        temp=temp->next;
        while(temp!=NULL)
        {
            long long int distance=dist[min]+temp->weight;
            if(distance<dist[temp->val])
            {
                dist[temp->val]=distance;
                shuffleup(indx[temp->val]);
            }
            temp=temp->next;
        }
        delminheap();
        min=heap[1];
    }
}
void insert(node *a,int num,int w)
{
    node *p;
    p=malloc(sizeof(node));
    p->val=num;
    p->weight=w;
    p->next=a->next;
    a->next=p;
}
void printedges(node *a)
{
    node *temp=a;
    a=a->next;
    while(a!=NULL)
    {
        printf("%d-->",a->val);
        a=a->next;
    }
    printf("\n");
}
int main()
{
    int i;
    scanf("%d",&n); // no of vertices
    for(i=0;i<100010;i++)
        a[i]=NULL;
    for(i=1;i<=n;i++)
    {
        a[i]=malloc(sizeof(node));
        a[i]->next=NULL;
    }
    int m;
    scanf("%d",&m); // no of edges
    for(i=0;i<m;i++)
    {
        int v1,v2,w;
        scanf("%d%d%d",&v1,&v2,&w); // edge
        insert(a[v1],v2,w);
    }
    int source,destination;
    scanf("%d%d",&source,&destination);
    int q=bfs(source,destination);
    if(q==-1)
        printf("NO\n");
    else if(source==destination)
        printf("NO\n");
    else
    {
        dijkstra(source,destination);
        printf("%lld\n",dist[destination]);
    }
    return 0;
}
