#include <stdio.h>
#include <string.h>

typedef struct {
    struct node* Adj[10];
    int Vis;
}node;

int main()
{
    int t; scanf("%d",&t);
    
    while(t--)
    {
        int i, j;
        int n; scanf("%d",&n);
        
        node* root = malloc(sizeof(node));
        memset(root,0,sizeof(node));
        
        int failed = 0;
        
        for(i=0; i<n; ++i)
        {
            char Num[15];
            scanf(" %s", Num);
            
            node* cur = root;
            for(j=0; Num[j]; ++j)
            {
                int d = Num[j]-'0';
                
                if(cur->Vis != 0)
                    failed = 1;
                
                if(cur->Adj[d] == 0)
                {
                    cur->Adj[d] = malloc(sizeof(node));
                    cur = cur->Adj[d];
                    
                    memset(cur,0,sizeof(node));
                }
                else
                {
                    cur = cur->Adj[d];
                }
            }
            
            if(cur->Vis != 0)
                failed = 1;
            
            cur->Vis = 1;
            for(j=0;j<10;++j)
            {
                if(cur->Adj[j] != 0)
                    failed = 1;
            }
        }
        
        if(failed)
            printf("NO\n");
        else
            printf("YES\n");
    }
    
    return 0;
}