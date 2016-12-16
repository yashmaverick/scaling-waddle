#include <stdio.h>

int main()
{
    int t; scanf("%d",&t);
    
    while(t--)
    {
        int p, q, r, i, j, k;
        long long ans = 0;
        
        scanf("%d",&p);
        int A[p];
        for(i=0;i<p;++i)
            scanf("%d",A+i);
        
        scanf("%d",&q);
        int B[q]; long long DP[q];
        for(i=0;i<q;++i)
            scanf("%d",B+i);
        
        scanf("%d",&r);
        int C[r];
        for(i=0;i<r;++i)
            scanf("%d",C+i);
        
        k = 0;
        for(j=0;j<q;++j)
        {
            while(k<r && (C[k]<B[j] || k<j))
                k++;
            
            DP[j] = r-k;
        }
        for(j=q-2;j>=0;--j)
            DP[j] += DP[j+1];
        
        i = j = k = 0;
        for(i=0;i<p;++i)
        {
            while(j<q && (B[j]<A[i] || j<i))
                j++;
            if(j==q) break;
            
            ans += DP[j];
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}