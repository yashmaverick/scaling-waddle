#include<stdio.h>
#include<stdlib.h>

#define INF 1234562

struct node{
    int vertex;
    int weight;
    struct node *next;
};

int min(int A, int B)
{
    return (A<B)?A:B;
}

int parent[100006];
long long int dist[500006];
int heap[500005];         // Initial values are much bigger
int store=1;
int mapping_node_to_heap[100006];
int mapping_heap_to_node[100006];
int visited[100006];

int min_value(int A,int B)
{
    return (A<B)?A:B;
}

void insert_in_heap(int data)
{
    heap[store]=data;
    mapping_node_to_heap[store]=store;
    mapping_heap_to_node[store]=store;
    store++;
}


void swap_in_heap(int pos1, int pos2)
{
    // Updates the reverse mappings of the 2 arrays
    // pos 1 and pos 2 are positions in heap

    int node1=mapping_heap_to_node[pos1];
    int node2=mapping_heap_to_node[pos2];
    mapping_node_to_heap[node1]=pos2;
    mapping_node_to_heap[node2]=pos1;

    mapping_heap_to_node[pos1]=node2;
    mapping_heap_to_node[pos2]=node1;

    return;
}

int deletemin()
{
    if(store==1)
        return (-INF);

    int RET=heap[1];
    heap[1]=heap[store-1];

    swap_in_heap(1,store-1);        // node at pos 1 is not requored anymore as deleted in heap
    int check=1;
    while (min(heap[check*2],heap[check*2 + 1]) < heap[check])
    {
        int MIN = (heap[check*2]<heap[check*2 + 1])?(check*2):(check*2+1);
        if (MIN>=store)
            break;
        int temp=heap[MIN];
        heap[MIN]=heap[MIN/2];
        heap[MIN/2]=temp;

        swap_in_heap(MIN,check);
        check=MIN;
    }
    store--;
    return RET;
}

void update_in_heap(int node, int d)
{
    // pos is the location where we have to change, heap[pos] = d

    int pos=mapping_node_to_heap[node];
    heap[pos]=d;
    while(heap[pos/2] > heap[pos])
    {
        if (pos==1)
            return;
        int temp=heap[pos];
        heap[pos]=heap[pos/2];
        heap[pos/2]=temp;

        swap_in_heap(pos,pos/2);
        pos=pos/2;
    }

}


struct node* insert(struct node *head, int v, int w)
{
    if(head==NULL)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->vertex=v;
        newnode->weight=w;
        newnode->next=NULL;
        return newnode;
    }
    else
    {
        head->next=insert(head->next,v,w);
        return head;
    }
}

int main()
{
    int v,k;
    scanf("%d %d",&v ,&k);

    //parent=(int*)malloc((v+1)*sizeof(int));
    //dist=(long long int*)malloc((v+1)*sizeof(long long int));
    //mapping_node_to_heap=(int*)malloc((v+1)*sizeof(int));
    //mapping_heap_to_node=(int*)malloc((v+1)*sizeof(int));
    //visited=(int*)malloc((v+1)*sizeof(int));

    struct node* graph[v+1];
    heap[0]=-111;

    int i=0;
    parent[0]=0;
    for(i=1;i<=v;i++)
    {
        parent[i]=0;
        (graph[i]) = NULL;
        insert_in_heap(INF);
        heap[i]=INF;
        dist[i]=INF;
    }

    while(k--)
    {
        int a,b,c;
        scanf("%d %d %d",&a ,&b ,&c);
        graph[a]=insert(graph[a],b,c);
        //graph[b]=insert(graph[b],a,c);
    }

    int A,B;
    scanf("%d %d",&A ,&B);
    update_in_heap(A,0);

    while(visited[B]!=1 )
    {
        if (mapping_heap_to_node[1] == -INF)
        {
            printf("NO\n");
            return 0;
        }
        int MIN_ELEM = mapping_heap_to_node[1];
        dist[MIN_ELEM]=deletemin();
        struct node *pointer=graph[MIN_ELEM];

        while(pointer!=NULL)
        {
            int new_distance = dist[MIN_ELEM] + pointer->weight;
            if (new_distance < dist[pointer->vertex])
            {
                parent[pointer->vertex] = MIN_ELEM;
                dist[pointer->vertex] = new_distance;
                update_in_heap(pointer->vertex,new_distance);
            }
            pointer=pointer->next;
        }
        visited[MIN_ELEM]=1;
    }

    if (dist[B]==INF)
        printf("NO\n");
    else
        printf("%lld\n",dist[B]);

    return 0;
}
