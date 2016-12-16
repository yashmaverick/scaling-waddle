#include <stdio.h>

int t, T;
int n;

int A[100007];

int max(int a, int b)
{
    if(a<b)
        return b;
    return a;
}
int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
void input()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&A[i]);
}
void solve()
{
    int stack[100007][3], i, t = 0;
    
    int bestd = 0, bestval = A[n-1];
    
    stack[0][0] = A[n-1];
    stack[0][1] = 1;
    stack[0][2] = n;
    
    for(i=n-2;i>=0;--i)
    {
        while(A[i]<stack[t][1] || A[i]>stack[t][2])
        {
            t--;
        }
        
        if(A[i]>stack[t][0])
        {
            t++;
            stack[t][0] = A[i];
            stack[t][1] = max(stack[t-1][1],stack[t-1][0]+1);
            stack[t][2] = stack[t-1][2];
        }
        else
        {
            t++;
            stack[t][0] = A[i];
            stack[t][1] = stack[t-1][1];
            stack[t][2] = min(stack[t-1][2],stack[t-1][0]-1);
        }
        
        if(t>bestd || (t==bestd && A[i]<bestval))
        {
            bestd = t;
            bestval = A[i];
        }
    }
    
    printf("%d %d\n",bestval,bestd);
}

int main()
{
    scanf("%d",&T);
    for(t=0;t<T;++t)
    {
        input();
        solve();
    }
    
    return 0;
}