#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 1000000
int m,n;
typedef struct node
{
    int data;
    struct node *next;
}node;
node *adj[size];
int visited[size];
int stack[size];
int Set[size];
int indeg[size];
int top;
int heap[size];
void swap(int a[], int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;

}
void heapup(int heap[],int newnode)
{
    if (newnode==0)
        return;
    else
    {
        int parent=(newnode-1)/2;
        if(heap[newnode]<heap[parent])
        {
            //for maxheap
            swap(heap,parent,newnode);
            heapup(heap,parent);
        }

    }
}
void heapdown(int heap[],int beg, int end)
{
    if(2*beg+1<=end) //one child exists
    {
        int l,r,largest;
        l=2*beg+1;
        largest=l;
        if(2*beg+2<=end)
        {
            //right child exists
            r=2*beg+2;
            if(heap[r]<heap[l])
                largest=r;
            else 
                largest=l;
        }

        if(heap[largest]<heap[beg])
        {
            swap(heap,largest,beg);
            heapdown(heap,largest,end);
        }
    }

}


int insertHeap(int heap[],int *last,int data)
{
    if (*last==size)
        return 0;
    else
    {
        *last=*last+1;
        heap[*last]=data;
        heapup(heap,*last);
        return 1;
    }

}

int deleteHeap(int heap[],int *last)
{
    if(*last<0)
        return 0;

    else
    {
        heap[0]=heap[*last];
        *last=*last-1;
        heapdown(heap,0,*last);
        return 1;
    }

}
int inheap[size];

void insert1(int src,int dest)
{
    indeg[dest]++;
    node *p = (node*)malloc(sizeof(node));
    p->data=dest;

    if(adj[src]==NULL)
    
        adj[src]=p;
    else
    {

            p->next=adj[src];
            adj[src]=p;
            return;


    }
}
void topo();

void topo()
{

    top=-1;
    int last=-1;
    int i,ct=0;
    for(i=0;i<n;++i)
        if(indeg[i]==0)
        {
            insertHeap(heap,&last,i);
        //      inheap[i]=1;  printf("%dindeg0\n",i+1);
        }
    int ctr=0;
    while(last>=0)
    {
        int v=heap[0];
        deleteHeap(heap,&last);           
       //      printf("%din\n",popped);
            if(visited[v])
                continue;
        visited[v]=1;

        stack[++top]=v+1;


        node *ptr=adj[v];
        while(ptr)
        {

            int m=ptr->data;
            adj[v]=ptr->next;
            indeg[ptr->data]--;
            if(indeg[m]==0&&!inheap[m])
            {
                insertHeap(heap,&last,ptr->data);
          //      printf(":%d ",m+1);
                inheap[i]=1;
            }
            ptr=ptr->next;
        }    


    }
    i=0;
    while(i<top)
        printf("%d ",stack[i++]);
        printf("%d",stack[i++]);
    printf("\n");
}


int main()
{
    int test,src,dest,i; 
    scanf("%d%d",&n,&m);
    top=-1;
    for(i=0;i<n;++i)
    {
        adj[i]=NULL;
        indeg[i]=0;
        inheap[i]=0;
    }
    for(i=0;i<m;++i)
    {
        scanf("%d%d",&src,&dest);
        insert1(src-1,dest-1);//adj 3->2
        //printf("%d ",src);
        //insert1(src,dest);//adj 3->2
    }
/*
    for(i=0;i<n;++i)
    {
        printf("%d:",i+1);
       node* ptr=adj[i];
        while(ptr)
        {
            printf("%d ",ptr->data+1);
            ptr=ptr->next;
        }
        printf("\n");
    }

  */  
    
    topo();
    return 0;

}
