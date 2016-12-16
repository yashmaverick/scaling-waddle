#include<stdio.h>
#include<math.h>

int lowest(int n)
{
    int a = 1;
    while(a <= n)
    {
        a= a*2;
        
    }
    a=a/2;
    
    return a;
}

int main()
{
    int N, n, number, ans;
    
    scanf("%d", &N);
    
    while (N--)
    {
        scanf("%d", &n);
    
        number = lowest(n);
        
        if (number + number/2 <= n)
        {
            ans = 2*(int)log2(n);
        }
        
        else
        {
            ans = 2*(int)log2(n) - 1;
        }
        
        printf("%d\n", ans);
    }
        
    //~ printf("%d", (int)log2(n));
    
    return 0;
}
    
