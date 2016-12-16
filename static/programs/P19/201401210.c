#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i , flag ;
#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)
#define loop(initial , final , jump) for(i=initial ; i<final ; i=i+jump)
#define iter(end) loop(0 , end , 1)

typedef struct trie_node node;
struct trie_node
{
    int val;
    node *child[10];
};

node *root;

node *new()
{
    node *n = NULL;
    n = (node *)malloc(sizeof(node));
    
    if(n)
    {
        n->val = 0;
        iter(10)
            n->child[i] = NULL;
    }
    
    return n;
}

void initialize()
{
    root = new();
    flag = 0;
}

void insert(int num[] , int len)
{
    node* t;
    t = root;
    int lev;
    for(lev = len-1 ; lev >= 0 ; lev--)
    {
        if(t->val == 1)
        {
//             outstr("ping");
            flag = 1;
            return;
        }
        if(!t->child[num[lev]])
        {
            flag = 0;
            t->child[num[lev]] = new();
        }
        else
            flag = 1;
        t = t->child[num[lev]];
    }
    if(t->val == 1)
    {
        flag = 1;
        return ;
    }
    else
        t->val = 1;
}

int main()
{
    int t , N ;
    long long number;
    ini(t);
    while(t--)
    {
        initialize();
        ini(N);
        while(N--)
        {
            inll(number);
            int num[10];
            int j = 0;
            while(number != 0)
            {
                num[j++] = number%10;
                number /= 10;
            }
            if(flag == 0)
                insert(num, j);
        }
        if(flag == 0)
            outstr("YES");
        else
            outstr("NO");
    }
    return 0;
}