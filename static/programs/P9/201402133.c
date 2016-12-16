#include <stdio.h>

int main()
{
    int n, mod, i, j, m, beg[1001], end[1001], w[1000001], wt[1001], id[1001], x, y;
    scanf("%d%d",&n,&mod);
    
    for(i=0;i<n;++i)
    {
        id[i] = i;
        wt[i] = 0;
        
        scanf("%d",&m);
        
        if(i==0) beg[i] = 0;
        else beg[i] = end[i-1];
        
        for(j=0;j<m;++j)
        {
            scanf("%d",&w[beg[i]+j]);
            wt[i] = (wt[i]+w[beg[i]+j])%mod;
        }
        
        end[i] = beg[i]+m;
    }
    
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<n-1;++j)
        {
            if(wt[j]>wt[j+1])
            {
                x = wt[j];
                y = id[j];
                
                wt[j] = wt[j+1];
                id[j] = id[j+1];
                
                wt[j+1] = x;
                id[j+1] = y;
            }
        }
    }
    
    for(i=0;i<n;++i)
    {
        printf("%d\n",wt[i]);
        
        for(j=beg[id[i]];j<end[id[i]];++j)
        {
            printf("%d\n",w[j]);
        }
        printf("\n");
    }
    
    return 0;
}