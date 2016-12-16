#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int d;
    struct node *next;
};

typedef struct node NODE;
typedef NODE *LINK;

LINK adj_list[100005];

int topo_sort[100005];
int in_deg[100005];

int heap[100005];
int size;

void insert(int x)
{
    int i=++size;
    for(;i>1 && heap[i/2]>x;i/=2)
    {
        heap[i]=heap[i/2];
    }
    heap[i]=x;
}

int pop()
{
    int ans=heap[1];
    int last=heap[size--];

    int i,minchild;
    for(i=1;i<=size/2;i=minchild)
    {
        minchild=2*i;
        if(2i!=size && heap[2*i+1]<heap[2*i])
            minchild=2*i+1;
        if(heap[minchild]<last)
            heap[i]=heap[minchild];
        else
            break;
    }
    heap[i]=last;
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,a,b;
    
    memset(in_deg,0,n*sizeof(int));
    for(i=1;i<=n;i++)
    {
        adj_list[i]=NULL;
    }

    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        LINK temp;
        temp=(LINK)malloc(sizeof(NODE));
        temp->d=b;
        temp->next=adj_list[a];
        adj_list[a]=temp;
        
        in_deg[b]++;
    }
    size=0;
    for(i=1;i<=n;i++)
    {
        if(in_deg[i]==0)
            insert(i);
    }
    int topo_num=0;
    while(size!=0)
    {
        topo_sort[++topo_num]=pop();
        LINK var;
        for(var=adj_list[topo_sort[topo_num]];var!=NULL;var=var->next)
        {
            if(!(--in_deg[var->d]))
                insert(var->d);
        }
        adj_list[topo_sort[topo_num]]=NULL;
    }
    
    printf("%d",topo_sort[1]);
    for(i=2;i<=n;i++)
    {
        printf(" %d",topo_sort[i]);
    }
    putchar('\n');
return 0;
}
