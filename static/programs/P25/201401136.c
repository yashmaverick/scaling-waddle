#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int val;
    int weight;
    struct node *next;
}node;
node *a[100010];
int indx[100010];
long long int dist[100010];
int heap[100010];
int heapcount=0;
int visited[100010]={0};
int n;
long long int sum;
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
            indx[heap[parent]]=tempindex;
            indx[heap[i]]=tempindex/2;
            heap[i]=heap[parent];
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
            indx[heap[i]]=tempindex/2;
            indx[heap[parent]]=tempindex;
            heap[i]=heap[parent];
            heap[parent]=temp;
            i=parent;
        }
        else
            break;
    }
}
void mst()
{
    int i;
    for(i=1;i<=n;i++)
    {
        dist[i]=100010;
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
            initheap(i,0);
        else
            initheap(i,100010);
    }
    int min=heap[1];
    visited[min]=1;
    while(heapcount!=0)
    {
        sum=sum+dist[min];
        node *temp=a[min];
        temp=temp->next;
        delminheap();
        while(temp!=NULL)
        {
            long long int distance=temp->weight;
            if(distance<dist[temp->val] && visited[temp->val]==0)
            {
                dist[temp->val]=distance;
                shuffleup(indx[temp->val]);
            }
            temp=temp->next;
        }
        min=heap[1];
        visited[min]=1;
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
        insert(a[v2],v1,w);
    }
    sum=0;
    mst();
    int flag=0;
    for(i=1;i<=n;i++)
    {
        if(dist[i]==100010)
        {
            printf("-1\n");
            flag=1;
            break;
        }
    }
    if(flag!=1) 
        printf("%lld\n",sum);
    return 0;
}
