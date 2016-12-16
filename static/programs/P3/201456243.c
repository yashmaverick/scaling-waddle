#include <stdio.h>

int main()
{
    int i, j, k, t;
    
    int T;
    scanf("%d",&T);
    
    for(t=0;t<T;++t)
    {
        int N;
        scanf("%d",&N);
        
        int Price[N], Max[N];
        for(i=0;i<N;++i)
            scanf("%d",&Price[i]);
        
        Max[N-1] = Price[N-1];
        for(i=N-2;i>=0;--i)
        {
            Max[i] = Price[i];
            if(Max[i+1] > Max[i])
                Max[i] = Max[i+1];
        }
        
        int profit = 0;
        for(i=0;i<N;++i)
        {
            if(Max[i]-Price[i] > profit)
                profit = Max[i]-Price[i];
        }
        
        printf("%d\n",profit);
    }
    
    return 0;
}