#include<stdio.h>
#include<stdlib.h>
#define size 100005
#define MAX 100005
#define inf  1000000007
int dist[size];
int position_in_heap[size];
int n,m;
typedef struct element
{
    int ver,weight;
    struct element *next;
}element;
element *adj[size];


void insert(int src,int dest,int weight)
{
    element *p = (element*)malloc(sizeof(element));
    p->ver=dest;
    p->weight=weight;

    if(adj[src]==NULL)
        adj[src]=p;
    else
    {
        p->next=adj[src];
        adj[src]=p;
    }

    return;


}

typedef struct minheapelement
{
    int ver,weight;
}minheapelement;

minheapelement myheap[size];

void swap(minheapelement heap[],int i,int j)
{
    minheapelement t;
    t.ver=heap[i].ver;
    t.weight=heap[i].weight;

	heap[i].ver=heap[j].ver;
	heap[i].weight=heap[j].weight;
	
    heap[j].ver=t.ver;
	heap[j].weight=t.weight;
}

void minheapify(minheapelement heap[],int beg, int end)
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
            if(heap[r].weight<heap[l].weight)
                largest=r;
            else 
                largest=l;
        }

        if(heap[largest].weight<heap[beg].weight)
        {
            
	//ignore largest, means smallest
        minheapelement smallestelement;
        smallestelement.ver=myheap[largest].ver;
        smallestelement.weight=myheap[largest].weight;
        minheapelement begNode;
        begNode.ver=myheap[beg].ver;
        begNode.weight=myheap[beg].weight;
 
        int u=smallestelement.ver,v=heap[beg].ver;
        position_in_heap[u]=beg;
        position_in_heap[v]=largest;
 
        swap(myheap,largest, beg);
            minheapify(heap,largest,end);
        }
    

    }

}

void deleteHeap_min(minheapelement heap[],int *last)
{
    if(*last<0)
        return ;

    else
    {

	minheapelement root;
    root.ver=myheap[0].ver;
    root.weight=myheap[0].weight;
 
    minheapelement lastNode;
    lastNode.ver=heap[*last].ver;
    lastNode.weight=heap[*last].ver;

    heap[0].ver=lastNode.ver;
    heap[0].weight=lastNode.weight;
 
    position_in_heap[root.ver] = *last;//????????
    position_in_heap[lastNode.ver] = 0;
 
    *(last)=*last -1;
    minheapify(heap, 0,*last);


    }

}

void updateHeap_min(minheapelement heap[],int *last,int vertex)
{
        int index=position_in_heap[vertex];
        heap[index].weight=dist[vertex];  
        
while (index && heap[index].weight < heap[(index-1)/2].weight)
    {
      position_in_heap[heap[index].ver]=(index-1)/2;
      position_in_heap[heap[(index-1)/2].ver]=index;
      swap(heap,index,  (index-1)/2);
         index=(index-1)/2;
    }


}

int isinheap(minheapelement heap[],int *last,int v)
{
    if(position_in_heap[v]<=*last)
        return 1;
    else
        return 0;
}


void update(int v,int dist_u,int dist_u_v)
{
    if(dist[v]>(dist_u+dist_u_v))
        dist[v]=dist_u+dist_u_v;

}
void dijkistra_main(int curr,int el)
{

    int last;
    int i;
	minheapelement temp;
    for(i=0;i<n;++i)
    {
	       
        myheap[i].ver=i;
        myheap[i].weight=inf;
        position_in_heap[i]=i;
    }
    last=n-1;
    position_in_heap[curr]=curr;
    myheap[curr].weight=inf;
    dist[curr]=0;
    updateHeap_min(myheap,&last,curr);
    
  //  printf("ver%dweight%d\n",myheap[0].ver,myheap[0].weight);
    while(last>=0)
    {
        element  top;
        top.ver=myheap[0].ver;
        top.weight=myheap[0].weight;
        deleteHeap_min(myheap,&last);
		int u=top.ver;
        if(top.ver==el)
            return;
        element *ptr=adj[top.ver];	
        while(ptr)
        {
            if(isinheap(myheap,&last,ptr->ver)&&dist[u]!=inf&&(ptr->weight+dist[u])<dist[ptr->ver])
            {
                dist[ptr->ver]=ptr->weight+dist[u];
                updateHeap_min(myheap,&last,ptr->ver);
            }
            ptr=ptr->next;

        }
        

    }

}//fn

void dijkistra(int src,int dest)
{
    int i;

    for(i=0;i<=size;++i)

    {
        dist[i]=inf;

    }


    dijkistra_main(src,dest);

}


int main()
{
    int src,dest,w;
    int s,t,i;
    int test;
        scanf("%d%d",&n,&m);

        for(i=0;i<n;++i)
            adj[i]=NULL;
        for(i=0;i<m;++i)
        {
            scanf("%d%d%d",&src,&dest,&w);
            insert(src-1,dest-1,w);
        }
        scanf("%d%d",&s,&t);


        dijkistra(s-1,t-1);    

        if(dist[t-1]<inf)
            printf("%d\n",dist[t-1]);
        else
            // printf("NONE\n");
            printf("NO\n");



    return 0;
}
