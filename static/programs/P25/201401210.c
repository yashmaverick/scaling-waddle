#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int i , heapsize ;
#define max 1000001
#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)
#define loop(initial , final , jump) for(i=initial ; i<final ; i=i+jump)
#define iter(end) loop(0 , end , 1)

int dis[max] , vis[max] ;

struct heapnode
{
    int v;
    int wt;
};

typedef struct heapnode heap;

heap h[max];


struct Adjnode 
{
        int dest;
        int weight;
        struct Adjnode* next;
};

typedef struct Adjnode list;

list* vec[max];

void Init()
{
        heapsize = 0;
        h[0].wt = -INT_MAX;
        iter(max)
        {
            dis[i] = INT_MAX;
            vis[i] = 0;
        }
}

list* newnode(int dest , int w)
{
        list * new = (list*)malloc(sizeof(list));
        new->dest = dest;
        new->next = NULL;
        new->weight = w;
        return new;
}

void addedge(int src , int dest , int w)
{
        list* new = newnode(dest , w);
        new->next = vec[src];
        vec[src] = new;
        
        list* new1 = newnode(src , w);
        new1->next = vec[dest];
        vec[dest] = new1;
        
}

void Insert(heap element)
{
        heapsize++;
        h[heapsize] = element; 
        int now = heapsize;
        while(h[now/2].wt > element.wt) 
        {
                h[now] = h[now/2];
                now /= 2;
        }
        h[now] = element;
}

heap DeleteMin()
{
        heap minElement,lastElement;
        int child,now;
        minElement = h[1];
        lastElement = h[heapsize--];
        for(now = 1; now*2 <= heapsize ;now = child)
        {
                child = now*2;
                if(child != heapsize && h[child+1].wt < h[child].wt ) 
                {
                        child++;
                }
                if(lastElement.wt > h[child].wt)
                {
                        h[now] = h[child];
                }
                else 
                {
                        break;
                }
        }
        h[now] = lastElement;
        return minElement;
}

void MST()
{
    dis[1] = 0;
    heap s;
    s.v = 1;
    s.wt = 0;
    Insert(s);
    
    while(heapsize>0)
    {
        heap pre = DeleteMin();
        int vertex = pre.v;
        if(vis[vertex] == 1)
            continue;
        vis[vertex] = 1;
        list* crawl = vec[vertex];
        
        while(crawl != NULL)
        {
            int v = crawl->dest;
            
            if(!vis[v])
            {
                if(dis[v] > crawl->weight)
                {
                    dis[v] = crawl->weight;
                    heap temp;
                    temp.v = v;
                    temp.wt = dis[v];
                    Insert(temp);
                }
            }
            
            crawl = crawl->next;
        }
    }
}

int main()
{
    long long sum = 0;
    int N , M , W , U , V , f=0 , j;
    ini(N);
    ini(M);
    Init();
    iter(M)
    {
        ini(U);
        ini(V);
        ini(W);
        addedge(U , V , W);
    }
    MST();
    for(j=1 ; j<=N ; j++)
    {
        if(dis[j] == INT_MAX)
        {
            f = 1;
            outi(-1);
            break;
        }
        else
            sum += dis[j];
    }
    if(f == 0)
        outll(sum);
    return 0;
}