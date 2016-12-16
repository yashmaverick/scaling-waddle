#include <stdio.h>

typedef struct bleh {
    int depth, val;
}bleh;

bleh calc(int l, int r, int rev[])
{
    if(l==r) {
        bleh ret;
        ret.depth = 0;
        ret.val = rev[l];
        return ret;
    }
    
    int a = l-1, b = r;
    
    while(b-a!=1)
    {
        int m = (a+b)/2;
        
        if(rev[m]<rev[r])
        {
            a = m;
        }
        else
        {
            b = m;
        }
    }
    
    if(a==l-1 || b==r)
    {
        bleh ret = calc(l,r-1,rev);
        ret.depth++;
        
        return ret;
    }
    
    bleh left = calc(l,a,rev);
    bleh right = calc(b,r-1,rev);
    
    left.depth++;
    right.depth++;
    
    if(left.depth >= right.depth)
    {
        return left;
    }
    return right;
}

int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n, i;
        scanf("%d",&n);
        
        int rev[n];
        for(i=0;i<n;++i)
        {
            scanf("%d",&rev[i]);
        }
        
        bleh ans = calc(0,n-1,rev);
        
        printf("%d %d\n",ans.val,ans.depth);
    }
    
    return 0;
}