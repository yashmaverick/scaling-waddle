#include <stdio.h>

#define ll long long

const ll mod = 1e5+5;

ll P[3] = {1, 50012, 75045 };

int state[] = {0,0,0};

typedef struct node
{
    int occ[3];
    struct node* nxt;
    int cnt;
};

char S[100005];
struct node* hash[100005];

int hashfunc()
{
    int i;
    ll val = 0;
    
    for(i=0;i<3;++i)
    {
        val += (P[i]*state[i])%mod;
        val %= mod;
    }
    
    return val;
}
int conv(char c)
{
    if(c=='J') return 0;
    if(c=='M') return 1;
    return 2;
}

void init()
{
    int i;
    for(i=0;i<mod;++i)
        hash[i] = NULL;
}
void push()
{
    int i, id = hashfunc();
    struct node* n = (struct node*)malloc(sizeof(struct node));
    
    for(i=0;i<3;++i)
    {
        n->occ[i] = state[i];
    }
    n->cnt = 1;
    
    n->nxt = hash[id];
    hash[id] = n;
}
void update()
{
    int i;
    int id = hashfunc();
    
    struct node* ptr = hash[id];
    
    while(ptr != NULL)
    {
        int same = 1;
        for(i=0;i<3;++i)
        {
            if(state[i] != ptr->occ[i])
                same = 0;
        }
        
        if(same)
        {
            (ptr->cnt)++;
            return;
        }
        
        ptr = ptr->nxt;
    }
    
    push();
}
int add()
{
    int i, id = hashfunc();
    
    struct node* ptr = hash[id];
    
    while(ptr != NULL)
    {
        int same = 1;
        for(i=0;i<3;++i)
        {
            if(state[i] != ptr->occ[i])
                same = 0;
        }
        
        if(same)
        {
            return ptr->cnt;
        }
        
        ptr = ptr->nxt;
    }
    
    return 0;
}


int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        long long ans = 0;
        int i;
        init();
        scanf(" %s",S);
        
        update();
//         printf("%d %d %d %d\n",state[0],state[1],state[2],hashfunc());
        
        for(i=0;S[i];++i)
        {
            state[conv(S[i])]++;
            
            while(state[0] && state[1] && state[2])
            {
                state[0]--;
                state[1]--;
                state[2]--;
            }
            
//             printf("%d %d %d %d\n",state[0],state[1],state[2],hashfunc());
            
            ans += add();
            update();
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}