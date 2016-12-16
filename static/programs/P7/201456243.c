#include <stdio.h>
#include <string.h>

int occ[1000001];
int hval;

int main()
{
    int i, j, k, t;
    
    int T;
    scanf("%d",&T);
    
    while(T--)
    {
        memset(occ,0,sizeof occ);
        
        int N;
        scanf("%d",&N);
        
        int A[N];
        hval = 1e9;
        for(i=0;i<N;++i)
        {
            scanf("%d",&A[i]);
            if(A[i]<hval)
                hval = A[i];
        }
        
        hval *= -1;
        
        for(i=0;i<N;++i)
        {
            occ[A[i]+hval]++;
        }
        long long ans = 0;
        for(i=0;i<(int)(1e6+1);++i)
        {
            ans += ((long long)occ[i]*(occ[i]-1))/2;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}