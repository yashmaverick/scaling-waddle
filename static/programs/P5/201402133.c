#include <stdio.h>
#include <assert.h>

char dummy[100000];

typedef struct node
{
    int id;
    long long val;
    struct node* nxt;
};

struct node* hash[1000000];

const int LIM = 1e6;

int hashfunc(unsigned long long val)
{
    val *= (unsigned long long)(1e9+7);
    val *= (unsigned long long)(1e18+6);
    val *= val;
    val %= LIM;
    
    return val;
}

int main()
{
    int t, i; scanf("%d",&t);
    
    for(i=0;i<LIM;++i)
        hash[i] = NULL;
    
    while(t--)
    {        
        long long k;
        int n, j; scanf("%d%lld",&n,&k);
        
        long long v[n];
        for(i=0;i<n;++i)
        {
            int h;
            scanf(" %s",dummy);
            scanf("%lld",v+i);
            
            h = hashfunc(v[i]);
            
            struct node* newnode = malloc(sizeof (struct node));
            newnode->val = v[i];
            newnode->id = i;
            newnode->nxt = hash[h];
            hash[h] = newnode;
        }
        
        int done = 0;
        
        for(i=0;i<n && done == 0;++i)
            for(j=i+1;j<n && done == 0;++j)
            {
                int h;
                long long req = k-v[i]-v[j];
                
                h = hashfunc(req);
                struct node* ptr = hash[h];
                
                while(ptr != NULL)
                {
                    if(ptr->val == req && ptr->id != i && ptr->id != j)
                    {
                        
                        printf("YES\n");
                        done = 1;
                        break;
                    }
                    else
                    {
                        ptr = ptr->nxt;
                    }
                }
            }
        
        for(i=0;i<n;++i)
        {
            int h = hashfunc(v[i]);
            hash[h] = NULL;
        }
        
        if(done==0)
            printf("NO\n");
    }
    
    return 0;
}