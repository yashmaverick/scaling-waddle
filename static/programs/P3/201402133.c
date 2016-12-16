#include<stdio.h>

int max(int a, int b)
{
    if(a<b)
        return b;
    return a;
}

int main()
{
    int t; scanf("%d",&t);
    
    while(t--)
    {
        int n, i, ans = 0; scanf("%d",&n);
        
        int A[n];
        
        for(i=0;i<n;++i)
            scanf("%d",A+i);
        
        for(i=n-2;i>=0;--i)
        {
           ans = max(ans, A[i+1]-A[i]);
           A[i] = max(A[i],A[i+1]);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}