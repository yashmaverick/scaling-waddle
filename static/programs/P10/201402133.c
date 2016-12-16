#include <stdio.h>
#include <assert.h>

char str[100005][105];
    
int main()
{
    long long n, s, m, i, cur, d;
    
    scanf("%lld",&n);
    assert(n>=0);
    assert(n<=10000);
    
    s = 0, cur = 0, d = 0;
    
    while(1)
    {
        char c;
        scanf(" %c",&c);
        
        if(c == 'A')
        {
            scanf("%lld",&m);
            d += m;
            
            while(m--)
            {
                scanf(" %s",str[cur]);
                cur++;
                if(cur==100005) cur = 0;
            }
            
            if(d > n)
            {
                s = (s+d-n)%100005;
                d = n;
            }
        }
        else if(c == 'R')
        {
            scanf("%lld",&m);
            
            assert(d>=m);
            
            d -= m;
            s = (s+m)%100005;
        }
        else if(c == 'L')
        {
            for(i=s;i!=cur;i++)
            {
                printf("%s\n",str[i]);
                
                if(i==100005) i = 0;
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}