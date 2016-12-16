#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int i , c=0 , heapsize ;
#define max 1000001
#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d " , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)
#define loop(initial , final , jump) for(i=initial ; i<final ; i=i+jump)
#define iter(end) loop(0 , end , 1)

int dis[max] , vis[max] , inorder[max] , ans[max];

// struct heapnode
// {
//     int v;
//     int wt;
// };

// typedef struct heapnode heap;

int h[max];


struct Adjnode 
{
        int dest;
        struct Adjnode* next;
};

typedef struct Adjnode list;

list* vec[max];

void Init()
{
        heapsize = 0;
        h[0] = -INT_MAX;
        iter(max)
        {
            dis[i] = INT_MAX;
            vis[i] = 0;
        }
}

list* newnode(int dest)
{
        list * new = (list*)malloc(sizeof(list));
        new->dest = dest;
        new->next = NULL;
        return new;
}

void addedge(int src , int dest)
{
        list* new = newnode(dest);
        new->next = vec[src];
        vec[src] = new;
}

void Insert(int element)
{
        heapsize++;
        h[heapsize] = element; 
        int now = heapsize;
        while(h[now/2] > element) 
        {
                h[now] = h[now/2];
                now /= 2;
        }
        h[now] = element;
}

int DeleteMin()
{
        int minElement,lastElement;
        int child,now;
        minElement = h[1];
        lastElement = h[heapsize--];
        for(now = 1; now*2 <= heapsize ;now = child)
        {
                child = now*2;
                if(child != heapsize && h[child+1] < h[child] ) 
                {
                        child++;
                }
                if(lastElement > h[child])
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

void TopoSort(int N)
{
    int j;
    for(j=1 ; j<=N ; j++)
        if(inorder[j] == 0)
            Insert(j);
    while(heapsize>0)
    {
        int pre = DeleteMin();
        ans[c++] = pre;
        list* crawl = vec[pre];
        while(crawl != NULL)
        {
            int vertex = crawl->dest;
            inorder[vertex]--;
            if(inorder[vertex] == 0)
                Insert(vertex);
            crawl = crawl->next;
        }
    }
}


int main()
{
    int N , M , u , v;
    ini(N);
    ini(M);
    iter(M)
    {
        ini(v);
        ini(u);
        addedge(v , u);
        inorder[u]++;
    }
    TopoSort(N);
    iter(N)
    {
        if(i != (N-1))
            outi(ans[i]);
        else
            printf("%d" , ans[i]);
    }
    outstr("");
    return 0;
}