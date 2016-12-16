#include <stdio.h>
#include <string.h>

int notPrime[10019];
int primes[1500], id[10019], p;

int D[1500][1500];

int main()
{
    int i, j, t;
    
    notPrime[0] = 1;
    notPrime[1] = 1;
    
    for(i=2; i<10019; ++i)
    {
        if(notPrime[i] == 0)
        {
            if(i>999 && i<=9999)
            {
                primes[p] = i;
                id[i] = p++;
            }
            for(j=i+i;j<10019;j+=i)
            {
                notPrime[j] = 1;
            }
        }
    }
    
    memset(D,-1,sizeof(D));
    
    for(i=0;i<p;++i)
    {
        int q[1500], l = 0, h = 0;
        int s = primes[i];
        
        D[i][i] = 0;
        q[l++] = i;
        
        while(h<l)
        {
            int u = primes[q[h++]];
            
            for(j=1;j<1001;j*=10)
            {
                int d = (u/j)%10;
                int k = 0;
                
                int v = u-(d*j);
                if(v<1000) v += 1000, k++;
                
                for(;k<10;++k)
                {
                    if(notPrime[v]==0)
                    {
                        if(D[i][id[v]] == -1)
                        {
                            q[l++] = id[v];
                            D[i][id[v]] = D[i][id[u]]+1;
                        }
                    }
                    
                    v += j;
                }
            }
        }
    }
    
    scanf("%d",&t);
    while(t--)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        
        printf("%d\n",D[id[a]][id[b]]);
    }
}