#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int dest;
    struct node* next;
}node;
typedef struct vertex
{   
    int visited;
    struct node* head;
}vertex;
typedef struct graph
{
    int v;
    struct vertex* list;
}graph;
node* newnode(int dest)
{
    node* new=(node*)malloc(sizeof(node));
    new->dest=dest;
    new->next=NULL;
    return new;
}
graph* create(int v)
{   int i;
    graph* g=(graph*)malloc(sizeof(graph));
    g->v=v;
    g->list=(vertex*)malloc((v+1)*sizeof(vertex));
    for(i=1;i<=v;i++)
        g->list[i].head=NULL;
    return g;
}
void addedge(graph* g,int s,int d)
{
    node* nv=newnode(d);
    nv->next=g->list[s].head;
    g->list[s].head=nv;
}
int size;
void swap(int* a,int* b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
void insert(int heap[],int val)
{   int i,p;
    heap[++size]=val;
    i=size;
    while(i>1)
    {   
        p=i/2;
        if(heap[p]>heap[i])
            swap(&heap[p],&heap[i]);
        i=p;
    }   
}
int delete(int heap[])
{
    int mini=heap[1];
    heap[1]=heap[size];
    int min,mindex,i=1;
    while(i<=(size-1)/2 && (heap[i]>heap[2*i] || heap[i]>heap[2*i+1]))
    {   
        if(heap[2*i]<heap[2*i+1])
        {   
            min=heap[2*i];
            mindex=2*i;
        }   
        else
        {   
            min=heap[2*i+1];
            mindex=2*i+1;
        }   
        swap(&heap[i],&min);
        i=mindex;
        heap[mindex]=min;
    }
    size--;
    return mini;
}
/*void printgraph(graph* g)
{   int i;
    for(i=1;i<=g->v;i++)
    {   
        node* temp=g->list[i].head;
        printf("Adjacent vertices of %d are\n",i);
        while(temp)
        {
            printf("%d ",temp->dest);
            temp=temp->next;
        }
        printf("\n");
    }   
}*/

int main()
{   
    size=0;
    int j,n,m,i,v1,v2,x;
    scanf("%d%d",&n,&m);
    int* count=(int*)malloc((n+1)*sizeof(int));
    int* ans=(int*)malloc((n+1)*sizeof(int));
    int* heap=(int*)malloc((n+1)*sizeof(int));
    graph* g=create(n);
    for(i=1;i<=n;i++)
        count[i]=0;
    for(i=0;i<m;i++)
    {   
        scanf("%d%d",&v1,&v2);
        addedge(g,v1,v2);
        count[v2]++;
    }
//    printgraph(g);
    for(i=1;i<=n;i++)
    {
        if(count[i]==0)
            insert(heap,i);
    }
    i=0;
    while(size)
    {
        x=delete(heap);
        ans[i++]=x;
        node* temp=g->list[x].head;
        while(temp)
        {
            count[temp->dest]--;
            if(count[temp->dest]==0)
                insert(heap,temp->dest);
            temp=temp->next;
        }
    }
    for(j=0;j<(i-1);j++)
	    printf("%d ",ans[j]);
    printf("%d\n",ans[j]);
    return 0;
}


