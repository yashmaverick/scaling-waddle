#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct node{
    int val;
    int inedge;
    struct node *next;
}node;
node *a[500010];
int indx[500010];
int heap[500010];
int ans[500010];
int heapcount=0;
int n;
int r=0;
void initheap(int x)
{
    heapcount++;
    heap[heapcount]=x;
    int i=heapcount;
    while(i!=1)
    {
        int parent=i/2;
        if(heap[parent]>heap[i])
        {
            int temp=heap[i];
            heap[i]=heap[parent];
            heap[parent]=temp;
            i=parent;
        }
        else
            break;
    }
}
int delminheap()
{
    int min=heap[1];
    heap[1]=heap[heapcount];
    heapcount=heapcount-1;
    int i=1;
    while(i<=heapcount/2)
    {
        if(heap[i]>heap[2*i] || heap[i]>heap[2*i+1])
        {
            if(heap[2*i]<heap[2*i+1])
            {
                int temp=heap[2*i];
                heap[2*i]=heap[i];
                heap[i]=temp;
                i=2*i;
            }
            else if(heap[2*i]>heap[2*i+1])
            {
                int temp=heap[2*i+1];
                heap[2*i+1]=heap[i];
                heap[i]=temp;
                i=2*i+1;
            }
        }
        else
            break;
    }
    return min;
}
void topo()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i]->inedge==0)
            initheap(i);
    }
    while(heapcount!=0)
    {
        int min=delminheap();
        ans[r]=min;
        r++;
        node *temp=a[min];
        temp=temp->next;
        while(temp!=NULL)
        {
            (a[temp->val])->inedge=((a[temp->val])->inedge)-1;
            if(a[temp->val]->inedge==0)
                initheap(temp->val);
            temp=temp->next;
        }
    }
}
void insert(node *c,int num)
{
    node *temp;
    temp=a[num];
    node *p;
    p=malloc(sizeof(node));
    p->val=num;
    p->next=c->next;
    c->next=p;
    temp->inedge=(temp->inedge)+1;
}
int main()
{
    int i;
    scanf("%d",&n); // no of vertices
    for(i=1;i<=n;i++)
    {
        a[i]=malloc(sizeof(node));
        a[i]->inedge=0;
        a[i]->next=NULL;
    }
    int m;
    scanf("%d",&m); // no of edges
    for(i=0;i<m;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2); // edge
        insert(a[v1],v2);
    }
    topo();
    for(i=0;i<n-1;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n-1]);
    return 0;
}
