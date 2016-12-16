#include <stdio.h>

int main()
{
    while(1)
    {
        int n, i;
        scanf("%d",&n);
        
        if(n==0) break;
        
        long long stack[100005][2];
        int l = 0;
        long long best = 0;
        
        for(i=0;i<n;++i)
        {
            long long s;
            scanf("%lld",&s);
            
            while(1)
            {
                if(l==0)
                {
                    stack[l][0] = s;
                    stack[l][1] = i;
                    l++;
                    break;
                }
                
                if(stack[l-1][0]>=s)
                {
                    long long d = 0;
                    d += (i-stack[l-1][1]);
                    if(l!=1) d += (stack[l-1][1]-stack[l-2][1]-1);
                    else d += (stack[l-1][1]);
                    
                    if(d*stack[l-1][0] > best)
                        best = d*stack[l-1][0];
                    l--;
                }
                else
                {
                    stack[l][0] = s;
                    stack[l][1] = i;
                    l++;
                    break;
                }
            }
        }
        
        long long dr;
        if(l) dr = stack[l-1][1]+1;
        
        while(l)
        {
            if(l==1)
            {
                if(stack[l-1][0]*dr > best)
                    best = stack[l-1][0]*dr;
                l--;
                break;
            }
            
            long long d = dr-stack[l-2][1]-1;
            
            if(d*stack[l-1][0] > best)
                best = d*stack[l-1][0];
            
            l--;
        }
        
        printf("%lld\n",best);
    }
    
    return 0;
}