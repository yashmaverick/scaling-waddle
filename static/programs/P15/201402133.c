#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n, k, i;
        scanf("%d %d",&n,&k);
        
        int q[n+5], p[n+5];
        int h = 0, t = 0;
        
        for(i=0;i<n;++i)
        {
            int v;
            scanf("%d",&v);
            
            while(1)
            {
                if(t==h)
                {
                    q[t] = v;
                    p[t] = i;
                    t++;
                    break;
                }
                if(q[t-1]<v)
                {
                    q[t] = v;
                    p[t] = i;
                    t++;
                    break;
                }
                
                t--;
            }
            
            if(i>=k-1)
            {
                printf("%d",q[h]);
                if(i!=n-1) printf(" ");
                if(p[h]==i-k+1)
                    h++;
            }
        }
        printf("\n");
    }
    return 0;
}