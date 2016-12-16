#include <stdio.h>

int Heap[100019], last;
int n, m;

int Deg[100019], In[100019];
int Edges[500019][2];
int* Adj[100019];

void swap(int* a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int u)
{
    int s = u;
    
    if(u*2 < last)
        if(Heap[s] > Heap[u*2])
            s = u*2;
    if(u*2+1 < last)
        if(Heap[s] > Heap[u*2+1])
            s = u*2+1;
    
    if(s==u)
        return;
    
    swap(&Heap[s], &Heap[u]);
    heapify(s);
}

void insert(int val)
{
    int u = last;
    Heap[last++] = val;
    
    
    while(u > 1)
    {
        if(Heap[u] > Heap[u/2])
            return;
        swap(&Heap[u], &Heap[u/2]);
        
        u /= 2;
    }
}

void extractmin()
{
    swap(&Heap[1], &Heap[last-1]);
    last--;
    heapify(1);
}

int main()
{
    int i, r;
    last = 1;
    
    scanf("%d %d", &n, &m);
    for(i=0; i<m; ++i)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        
        Edges[i][0] = a;
        Edges[i][1] = b;
        
        Deg[a]++; In[b]++;
    }
    for(i=1; i<=n; ++i)
    {
        Adj[i] = (int*)(malloc(sizeof(int)*(Deg[i])));
        Deg[i] = 0;
        
        if(In[i] == 0)
        {
            insert(i);
//             printf("insert %d\n",i);
        }
    }
    for(i=0; i<m; ++i)
    {
        int a = Edges[i][0], b = Edges[i][1];
        Adj[a][Deg[a]++] = b;
    }
    
    r = n;
    while(r--)
    {
        int u = Heap[1];
        extractmin();
//         printf("extracted %d\n",u);
        
        printf("%d%c",u,(r==0)?('\n'):(' '));
        
        for(i=0; i<Deg[u]; ++i)
        {
            int v = Adj[u][i];
            In[v]--;
            
            if(In[v] == 0)
            {
                insert(v);
//                 printf("insert %d\n",v);
            }
        }
    }
    
//     printf("\n");
    
    return 0;
}