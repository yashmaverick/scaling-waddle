#include <stdio.h>

int t, T;

int n, k;

int A[10000];
int lmin[10000], rmin[10000];

int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
void compute(int l, int r)
{
    int i;
    rmin[r] = A[r];
    for(i=r-1;i>=l;--i)
        rmin[i] = min(A[i],rmin[i+1]);
    
    lmin[l] = A[l];
    for(i=l+1;i<=r;++i)
        lmin[i] = min(A[i],lmin[i-1]);
}
void input()
{
    int i;
    scanf("%d%d",&n,&k);
    
    for(i=0;i<n;++i)
        scanf("%d",&A[i]);
}
void prep()
{
    int i;
    for(i=0;i<n;i+=k)
    {
        if(i+k-1<n) compute(i,i+k-1);
        else compute(i,n-1);
    }
}
void solve()
{
    int i;
//     for(i=0;i<n;++i)
//         printf("%d ",lmin[i]);
//     printf("\n");
//     for(i=0;i<n;++i)
//         printf("%d ",rmin[i]);
//     printf("\n");
    for(i=0;i+k-1<n;++i)
    {
        printf("%d",min(lmin[i+k-1],rmin[i]));
        if(i+k!=n) printf(" ");
    }
    printf("\n");
}

int main()
{
    scanf("%d",&T);
    for(t=0;t<T;++t)
    {
        input();
        prep();
        solve();
    }
    
    return 0;
}