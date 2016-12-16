#include <stdio.h>

int i, j;

int n, q;

long long s[50], l[50], r[50];

void input()
{
    scanf("%d",&n);
}

void pre()
{
    s[0] = 2;
    l[0] = 2;
    r[0] = 3;
    
    for(i=1;i<50;++i)
    {
        s[i] = s[i-1]*2;
        l[i] = l[i-1]*2+1;
        r[i] = r[i-1]*2+1;/*
        
        printf("%lld %lld %lld\n",s[i],l[i],r[i]);*/
    }
}

void solve()
{
    for(i=0;i<n;++i)
    {
        scanf("%d",&q);
        
        if(q==1)
        {
            printf("0\n");
        }
        else
        {
            for(j=0;j<50;++j)
            {
                if(q>=s[j] && q<=l[j])
                {
                    printf("%d\n",(j+1)*2-1);
                    break;
                }
                if(q>l[j] && q<=r[j])
                {
                    printf("%d\n",(j+1)*2);
                    break;
                }
            }
        }
    }
}

int main()
{
    input();
    pre();
    solve();
    
    return 0;
}