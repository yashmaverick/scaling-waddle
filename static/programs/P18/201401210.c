#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int i , counter ;
#define max 10001
#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)
#define loop(initial , final , jump) for(i=initial ; i<final ; i=i+jump)
#define iter(end) loop(0 , end , 1)

int vis[max];

struct Adjnode 
{
        int dest;
        int weight;
        struct Adjnode* next;
};

typedef struct Adjnode list;

list* stronger[max] , *weaker[max];

list* newnode(int dest)
{
        list * new = (list*)malloc(sizeof(list));
        new->dest = dest;
        new->next = NULL;
        return new;
}

void initialize()
{
    counter = 0;
    iter(max)
        vis[i] = 0;
}

void addedge(int src , int dest , list* graph[])
{
        list* new = newnode(dest);
        new->next = graph[src];
        graph[src] = new;
}

void dfs(int src , list* graph[])
{
    vis[src] = 1;
    counter++;
    list* head=graph[src];
        while(head!=NULL)
        {
                if(vis[head->dest]!=1)
                        dfs(head->dest , graph);
                head=head->next;
        }
}

int main()
{
    int t , N , M , w , k , j , x;
    ini(t);
    while(t--)
    {
        iter(max)
        {
            stronger[i] = NULL;
            weaker[i] = NULL;
        }
        int ans = 0  , f = 0;
        ini(N);
        for(k=1 ; k<=N ; k++)
        {
            ini(M);
            for(j=1 ; j<=M ; j++)
            {
                ini(x);
                addedge(k , x , stronger);
                addedge(x , k , weaker);
            }
        }
        initialize();
        for(k=1 ; k<=N ; k++)
        {
            dfs(k , weaker);
            if(counter == N)
            {
                f = 1;
                break;
            }
            else
                initialize();
        }
        if(f == 1)
        {
            ans++;
            initialize();
            dfs(k , stronger);
            ans += (counter-1);
        }
        outi(ans);
    }
    return 0;
}